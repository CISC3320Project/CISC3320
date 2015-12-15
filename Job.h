#ifndef JOB_H_INCLUDED
#define JOB_H_INCLUDED

#include<iostream>
using namespace std;

//Class for Job - Deshi Wu
//contains the information about a job - Deshi Wu

//This is the Job Class so far, it is pretty straightforward
//let me know if anything - Naief Perez Secin
class Job{

    private:
    long  number;
    long  priority;
    long  size;
    long  MaxCpuTime;
    long  currentTime;
    long  enteredTime;
    long  pendingIo;
    long  location;
    bool  inMemory;
    bool  latched;
    bool  blocked;
    bool  terminated;
    bool  inCpu;


    public:
        Job() {
        number = -1;
        priority=0;
        location=0;
        size=0;
        enteredTime=0;
        MaxCpuTime=0;
        pendingIo=0;
        inMemory=false;
        latched = false;
        blocked = false;
        terminated = false;
        inCpu=false;

    }
        Job(long number, long priority, long size, long MaxCpuTime, long enteredTime) {
        this->number=number;
        this->priority=priority;
        this->size=size;
        this->MaxCpuTime=MaxCpuTime;
        this->enteredTime=enteredTime;

        currentTime=MaxCpuTime;
        pendingIo=0;
        inMemory=false;
        latched = false;
        blocked = false;
        terminated = false;
        inCpu=false;
    }

    long getNumber() {
        return number;
    }

    void setNumber(long number) {
        this->number = number;
    }

     long getPriority() {
        return priority;
    }

    void setPriority(long priority) {
        this->priority = priority;
    }


    long getLocation() {
        return location;
    }


    bool isTerminated() {
        return terminated;
    }

    void setTerminated(bool terminated) {
        this->terminated = terminated;
    }


    bool isBlocked() {
        return blocked;
    }

    void setBlocked(bool blocked) {
        this->blocked = blocked;
    }
    bool isInMemory() {
        return inMemory;
    }

    void setInMemory(bool inMemory) {
        this->inMemory = inMemory;
    }

    bool isLatched() {
        return latched;
    }

    void setLatched(bool latched) {
        this->latched = latched;
    }


    void setLocation(long location) {
        this->location = location;
    }

    long getSize() {
        return size;
    }

    void setSize(long size) {
        this->size = size;
    }

    long getEnteredTime() {
        return enteredTime;
    }

    void setEnteredTime(long enteredTime ) {
        this->enteredTime = enteredTime;
    }



    long getMaxCpuTime() {
        return MaxCpuTime;
    }

    void setMaxCpuTime(long MaxCpuTime) {
        this->MaxCpuTime = MaxCpuTime;
    }

    long getCurrentTime() {
        return currentTime;
    }

    void setCurrentTime(long currentTime) {
        this->currentTime = currentTime;
    }

    long getPendingIo() {
        return pendingIo;
    }

    void setPendingIo(long pendingIo) {
        this->pendingIo = pendingIo;
    }

    bool IsInCpu() {
        return inCpu;
    }

    void setInCpu(bool inCpu) {
        this->inCpu= inCpu;
    }

};

#endif // JOB_H_INCLUDED
