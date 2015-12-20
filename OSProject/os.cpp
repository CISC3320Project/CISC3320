/* CISC3320 Project                 */
/*Authors:                          */
/*Zakareya Alatoli                  */
/*Deshi Wu                          */
#include<iostream>
#include<queue>
#include <vector>
#include "Job.h"
#include "CpuScheduler.h"
#include "MemoryManager.h"

using namespace std;

void ontrace();
void offtrace();
void siodisk(long jobnum);
void siodrum(long jobnum, long jobsize, long coreaddress, long direction);
void swapper(long);
void bookKeep(long);
void getNextIoJob();
long getNewJob();
void loadAndRun(long&, long []);
void ioRequest(long);


static vector<Job> jobsList; // list of jobs in System
static queue<long> ioQueue; //queue of jobs that waiting for IO.
long runningJob = -1; //The job location from joblist that is running on CPU
long ioJob = 0;//The job location from joblist that is doing IO
MemoryManager memory;
cpuScheduler cpu;
long direction=-1; //contains direction of job swapped (0: swap to Core & 1 swap to Drum))
long transitjob=-1; //contains jobnum swapped
bool drumBusy=false; // when a job is being swapped, then its value is true


void startup(){
offtrace();
}

// Put new jobs to job list---Deshi Wu
void Crint (long &a, long p[])
{
    bookKeep(p[5]);
    Job job(p[1],p[2],p[3],p[4],p[5]);
    jobsList.push_back(job);
    swapper(p[1]);
    runningJob = cpu.shortestJob(jobsList);
    loadAndRun(a,p);
}


// Interrupt occur after job finishes doing IO--Deshi Wu
void Dskint (long &a, long p[])
{
    bookKeep(p[5]);
    getNextIoJob(); // get top job on queue

    // reduce the pending IO left
    jobsList[ioJob].setPendingIo(jobsList[ioJob].getPendingIo()-1);
    // Unblock and unlatch if there are no more IO for that job
    if(jobsList[ioJob].getPendingIo()==0)
    {
        jobsList[ioJob].setBlocked(0);
        jobsList[ioJob].setLatched(0);
    }

    // remove job from list if it is terminated
    if(jobsList[ioJob].isTerminated()== 1 && jobsList[ioJob].isInMemory()==1 && jobsList[ioJob].getPendingIo()==0){
        memory.removeJob(jobsList[ioJob].getLocation());
        jobsList.erase(jobsList.begin()+ioJob);
    }

    ioQueue.pop();  //jobnum will be deleted from queue

    // get next job to do IO from queue
    if(!ioQueue.empty())
    {
        getNextIoJob();
        siodisk(jobsList[ioJob].getNumber());
    }

    swapper((getNewJob()));
    runningJob = cpu.shortestJob(jobsList);
    loadAndRun(a,p);
}

//Interrupt occurs after swapping -- Deshi Wu
void Drmint (long &a, long p[])
{
    bookKeep(p[5]);
    //swapping is finished for a job, so drumbusy set to false
    drumBusy = false;

    //find the location in memory of job just swapped
    //set inmemory to true
    long location = memory.searchJob(jobsList,transitjob);
    jobsList[location].setInMemory(true);

    //look for new job from list that is not in memory yet, then put it in memory
   // long jobNum = getNewJob();
    //if(jobNum!=-1 && !jobsList[index].isInMemory())
      //  swapper(jobNum);

    swapper((getNewJob()));
    runningJob = cpu.shortestJob(jobsList);
    loadAndRun(a,p);
}


//Interrupt occurs if there has abnormal job termination--Deshi Wu
void Tro (long &a, long p[])
{
    bookKeep(p[5]);

    //if there is no more pending io, terminated
    //else terminated after io finished
    if (jobsList[runningJob].getPendingIo() == 0){
    memory.removeJob(jobsList[runningJob].getLocation());//remove job
    jobsList.erase(jobsList.begin()+runningJob);
    }

    else
        jobsList[runningJob].setTerminated(1);

    swapper((getNewJob()));
    runningJob = cpu.shortestJob(jobsList);
    loadAndRun(a,p);
}

void Svc(long &a, long p[])
{
    bookKeep(p[5]);

if(a==5){

//check if there is pending io and isTerminated is true
//else setTerminated true, so it will terminated later
if (jobsList[runningJob].getPendingIo() == 0 && jobsList[runningJob].isTerminated()==1){
                memory.removeJob(jobsList[runningJob].getLocation());//remove job
                jobsList.erase(jobsList.begin()+runningJob);
            }
else
                jobsList[runningJob].setTerminated(1);

}

else if(a==6){
if(ioQueue.empty())
                siodisk(jobsList[runningJob].getNumber());
                ioRequest(runningJob);

}

else if(a==7){
//check if there has pending IO job
//if yes, block it
if(jobsList[runningJob].getPendingIo()!= 0)
                jobsList[runningJob].setBlocked(1);
}

else
cout<<"ERROR: 'a' value is invalid!"<<endl;

    swapper((getNewJob()));
    runningJob = cpu.shortestJob(jobsList);
    loadAndRun(a,p);
}


// bookKeep function
// check remaining Max CPU Time when job enters interrupt -- Deshi Wu
void bookKeep(long currentTime)
{

    //if a job is running
    //timeleft=MaxCputime-(cuttentTime-enteredTime)
    if (runningJob!= -1)
    {
        long val = currentTime - jobsList[runningJob].getEnteredTime();
        jobsList[runningJob].setCurrentTime(jobsList[runningJob].getMaxCpuTime());
        jobsList[runningJob].setMaxCpuTime(jobsList[runningJob].getMaxCpuTime() - val);
    }
}


//find the next IO job that is in front of IOqueue -- Deshi WU
void getNextIoJob()
{
    for(long i=0; i< jobsList.size(); i++)
    {
        if(jobsList[i].getNumber() == ioQueue.front())
            ioJob = i;

    }
}

//put job number on IoQueue and set latched -- Deshi Wu
void ioRequest(long Job){
            ioQueue.push(jobsList[Job].getNumber());
            jobsList[Job].setPendingIo(jobsList[Job].getPendingIo()+1);
            jobsList[Job].setLatched(1);

            getNextIoJob();
}


// Updates memory
//Swaps jobs between memory and drum-- Deshj Wu
void swapper(long jobNum)
{
    if (!drumBusy && jobNum!=-1)
    {
        // Updates memory table
        //if it is in memory, add it to memory table
        //then delete that job from memory
        for(long i=0; i<jobsList.size(); i++)
    {
        if(jobsList[i].isInMemory()==1)
            memory.setJob(i,jobsList);
        if(jobsList[i].isTerminated()==1 && jobsList[i].getPendingIo()==0){
        memory.removeJob(jobsList[i].getLocation());//remove job
        jobsList.erase(jobsList.begin()+i);
        }

    }

        // find where is the job located in memory
        long jobInMem = memory.searchJob(jobsList,jobNum);
        //check if there has enough memory space for a job
        long free =memory.Memcheck((jobsList[jobInMem].getSize()));

        //if fit
        if(free<100 && free >=0)
        {
            // if the job was not already in memory, set it in
            //place it in the free space
            if(!jobsList[jobInMem].isInMemory())
            {
                transitjob=jobNum;
                direction=0;
                drumBusy=true;// swapper is busy now
                jobsList[jobInMem].setLocation(free);
                memory.setMemTable(jobsList,jobInMem,free);
                siodrum(jobsList[jobInMem].getNumber(),jobsList[jobInMem].getSize(),jobsList[jobInMem].getLocation(),0);
            }
        }
    }
}



//find next job(not in mem yet) with shortest time from the list--Deshi Wu
long getNewJob()
{
    long index=0;//job location in vector
    long mintime=1000000;// minimum time
    for(long i=0; i<jobsList.size(); i++)
    {
        if(jobsList[i].isInMemory()==0)
            if(memory.Memcheck(i)<100)
                if(jobsList[i].getMaxCpuTime()<mintime){
                    mintime=jobsList[i].getMaxCpuTime();
                    index=i;
                }
    }
    if(index!=0)
        return jobsList[index].getNumber();
    return -1;
}

//dispatcher--Deshi WU
void loadAndRun(long &a, long p[])
{
    //set cpu to idle if can't find a job to run
    if(jobsList[runningJob].isInMemory()==0 || jobsList[runningJob].isBlocked() || runningJob == -1)
        a=1;

    //set CPU active and set p[]
    else
    {
        a = 2;
        p[2] = jobsList[runningJob].getLocation();
        p[3] = jobsList[runningJob].getSize();
        p[4] = jobsList[runningJob].getMaxCpuTime();
        jobsList[runningJob].setEnteredTime(p[5]);
    }
}
