#ifndef JOB_H_INCLUDED
#define JOB_H_INCLUDED
<<<<<<< HEAD

#include<iostream>
using namespace std;

=======
#include<string>
>>>>>>> origin/master
//Class for Job - Deshi Wu
//contains the information about a job - Deshi Wu

//This is the Job Class so far, it is pretty straightforward
//let me know if anything - Naief Perez Secin
class Job{

    private:
<<<<<<< HEAD
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
=======
        long Number;
        long Priority;
        long Size;
        long MaxCpu;
        long CurrentTime;
        long Location;

        bool InMemory;
        bool Latched;
        bool Blocked;
        bool Terminated;
        std::string direction;
        //MemoryManager Memory;

    public:
        Job(long Number, long Priority, long Size, long MaxCpu, long CurrentTime):
            Number(Number), Priority(Priority), Size(Size), MaxCpu(MaxCpu), CurrentTime(CurrentTime),
            InMemory(false), Latched(false), Blocked(false), Terminated(false)
            {}


        long GetNumber()const { return Number; }
        long GetPriority()const { return Priority; }
        long GetSize()const { return Size; }
        long GetMaxCpu()const { return MaxCpu; }
        long GetCurrentTime()const { return CurrentTime; }
        long GetLocation()const { return Location; }
        bool IsInMemory()const { return InMemory; }
        bool IsLatched()const { return Latched; }
        bool IsBlocked()const { return Blocked;}
        bool IsTerminated()const { return Terminated; }
        std::string GetDirection()const { return direction; }
        //MemoryManager GetMemory()const { return Memory; }

        void SetNumber(long Number) { this->Number = Number; }
        void SetPriority(long Priority){ this->Priority = Priority; }
        void SetSize(long Size) { this->Size = Size; }
        void SetMaxCpu(long MaxCpu) { this->MaxCpu = MaxCpu; }
        void SetCurrentTime(long CurrentTime) { this->CurrentTime = CurrentTime; }
        void SetLocation(long Location) { this->Location = Location; }
        void SetInMemory(bool InMemory) { this->InMemory = InMemory; }
        void SetLatched(bool Latched) { this->Latched = Latched; }
        void SetBlocked(bool Blocked) { this->Blocked = Blocked; }
        void SetTerminated(bool Terminated){ this->Terminated = Terminated; }
        void SetDirection(std::string direction) { this->direction = direction; }
>>>>>>> origin/master

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
