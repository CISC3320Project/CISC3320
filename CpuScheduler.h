#ifndef CPUSCHEDULER_H_INCLUDED
#define CPUSCHEDULER_H_INCLUDED
#include <iostream>
#include <vector>

using namespace std;
bool cpuOnTrace=false;


// This Class is use to schedule next job from memory
// Using Shortest Job first Algorithm
// Find shortest job in Memory ---Deshi Wu
class cpuScheduler {

public:

    long shortestJob(vector<Job> jobsList) {

        // default set to -1 (indicates job is not found)
        long shortJobNum = -1, i, minTime=1000000;

        for(i=0; i<jobsList.size(); i++) {
            // first checks that conditions for proper dispatching apply
            if(jobsList[i].isInMemory() && jobsList[i].getMaxCpuTime()!=0 && !jobsList[i].isTerminated() && !jobsList[i].isBlocked()) {
                // then looks for the job with the shortest remaining time left.
                if(jobsList[i].getMaxCpuTime() < minTime ) {
                    minTime = jobsList[i].getMaxCpuTime();
                    shortJobNum = i;
             }
            }
           }
        return shortJobNum;
    }
};
#endif// CPUSCHEDULER_H_INCLUDED
