#ifndef MEMORYMANAGER_H_INCLUDED
#define MEMORYMANAGER_H_INCLUDED

#include<iostream>
#include <vector>


using namespace std;

class MemoryManager {
private:
    long mem[100];  //mem[] work as memory table.
                    //contains job size when job swap in

public:

    MemoryManager() {
        clear();
    }

    //Clear memory table
    void clear() {
        for(int i=0; i<100; i++)
            mem[i]=0;
    }
        //Get job size and equal to the size where it stored in mem
    void setJob(long num,vector<Job> jobsList) {

        long size = jobsList[num].getSize();
        long location = jobsList[num].getLocation();
        mem[location]=size;

    }
    //removes job from mem
    void removeJob(long location) {
        //make mem location usable after job deletion
        mem[location]=0;
    }

        //get size of job in mem and set
    void setMemTable(vector<Job> jobsList, long jobInMem,long free) {
        mem[free]= jobsList[jobInMem].getSize();
    }


    //returns 100 if can't find space that fit for the job
    long Memcheck(long size) {

        long i,tem;
        bool fit=false;
        for(i=0; i<100; i++) {
         if(i==0) {
            if(mem[i]!=0)
                i=i+mem[i];
                else {
                for(tem=1; tem<size; tem++) {
                    if(mem[i+tem]!=0) {
                        i=i+tem+mem[i+tem];
                        fit=false;
                        break;
                        } else fit=true;

                    }
                    if(fit==true) return i;
                }
            }
            while(mem[i]!=0)
                i = i + mem[i];
            if(mem[i]==0) {
                if(i+size<100) {
                    for(tem=1; tem<size; tem++) {
                        if(mem[i+tem]!=0) {
                            i=i+tem+mem[i+tem];
                            fit=false;
                            while(mem[i]!=0)
                                i = i + mem[i];
                            break;
                        } else fit=true;
                    }
                    if(fit) return i;
                } else if(i+size>=100) return 100;
            }
        }
    }

    //search for job by jobNum
    long searchJob(vector<Job> jobsList,long jobNum) {
        for(long i=0; i<=jobsList.size(); i++)
            if(jobsList[i].getNumber()==jobNum)
                return i ;
    }


};

#endif //MEMORYMANAGER_H_INCLUDED
