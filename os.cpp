/* CISC3320 Project                 */
/*Authors:                          */
/*Zakareya Alatoli                  */
/*Deshi Wu                          */
#include<iostream>
#include "Job.h"
#include "CpuScheduler.h"
#include "MemoryManager.h"

/*
Deshi Wu
before you start, you MUST read the information from here very carefully,
please don't rush on reading them:
http://www.sci.brooklyn.cuny.edu/~jones/cisc3320/osproj1.pdf
http://www.sci.brooklyn.cuny.edu/~jones/cisc3320/osproj2.html
*/
/* ALREADY IMPLEMENTED BY PROFESSOR*/
void siodisk(long jobnum);
void siodrum(long jobnum, long jobsize, long coreaddress, long direction);
void ontrace(); // called without arguments
void offtrace(); // called without arguments
void swapper(long);
void bookkeep(long);
void updateMemory();
void getJob(long);
void removeJob(long);
void getIoJob();
void loadAndRun(long&, long[]);
long notInMemory();


void startup()
{
      // Allows initialization of (static) system variables declared above.
      // Called once at start of the simulation.

}

void Crint (long &a, long p[])
{
      // Indicates the arrival of a new job on the drum.
       // At call : p [1] = job number
       // p [2] = priority
       // p [3] = job size, K bytes
       // p [4] = max CPU time allowed for job
       // p [5] = current time

}


void Dskint (long &a, long p[])
{
      // Disk interrupt.
      // At call : p [5] = current time
}

void Drmint (long &a, long p[])
{
      // Drum interrupt.
      // At call : p [5] = current time
}

void Tro (long &a, long p[])
{
     // Timer-Run-Out.
     // At call : p [5] = current time
}

void Svc(long &a, long p[])
{
     // Supervisor call from user program.
      // At call : p [5] = current time
      // a = 5 => job has terminated
      // a = 6 => job requests disk i/o
      // a = 7 => job wants to be blocked until all its pending
      // I/O requests are completed
}

//to find the reamaining Max CPU time when job enter interrupt - Deshi Wu
void bookkeep(long time){


}

//this updates memory table - Deshi Wu
void updateMemory(){

}

//get IO job -  Deshi WU
void getIojob(){

}

//remove job from list - Deshi Wu
void removeJob(long num){

}

//Swaps jobs between Drum and Memory - Deshi Wu
//Updating memory
void swapper(long JobNum){



}

//dispatcher
void loadAndRun(){

}

//find the job that is not in memmory and return its number - Deshi Wu
long notInMemory(){
    return 0;
}
