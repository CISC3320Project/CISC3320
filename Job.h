#ifndef JOB_H_INCLUDED
#define JOB_H_INCLUDED

#include<iostream>

//Class for Job - Deshi Wu
//contains the information about a job - Deshi Wu

//This is the Job Class so far, it is pretty straightforward
//let me know if anything - Naief Perez Secin
class Job{

    private:
        int Number;
        int Priority;
        int Size;
        int MaxCpu;
        int CurrentTime;
        int Location;

        boolean InMemory = false;
        boolean Latched = false;
        boolean Blocked = false;
        boolean Terminated = false;
        String direction;
        MemoryManager Memory;

    public:
        Job(int Number, int Priority, int Size, int MaxCpu, int CurrentTime, MemoryManager Memory):
            Number(Number), Priority(Priority), Size(Size), MaxCpu(MaxCpu), CurrentTime(CurrentTime),
            location = Memory.Find_Space(Size)
            {}


        int GetNumber()const { return Number; }
        int GetPriority()const { return Priority; }
        int GetSize()const { return Size; }
        int GetMaxCpu()const { return MaxCpu; }
        int GetCurrentTime()const { return CurrentTime; }
        int GetLocation()const { return Location; }
        boolean IsInMemory()const { return InMemory; }
        boolean IsLatched()const { return Latched; }
        boolean IsBlocked()const { return Blocked;}
        boolean IsTerminated()const { return Terminated; }
        String GetDirection()const { return direction; }
        MemoryManager GetMemory()const { return Memory; }

        void SetNumber(int Number) { this.Number = Number; }
        void SetPriority(int Priority){ this.Priority = Priority; }
        void SetSize(int Size) { this.Size = Size; }
        void SetMaxCpu(int MaxCpu) { this.MaxCpu = MaxCpu; }
        void SetCurrentTime(int CurrentTime) { this.CurrentTime = CurrentTime; }
        void SetLocation(int Location) { this.Location = Location; }
        void SetInMemory(boolean InMemory) { this.InMemory = InMemory; }
        void SetLatched(boolean Latched) { this.Latched = Latched; }
        void SetBlocked(boolean Blocked) { this.Blocked = Blocked; }
        void SetTerminated(boolean Terminated){ this.Terminated = Terminated; }
        void SetDirection(String direction) { this.direction = direction; }


};
#endif // JOB_H_INCLUDED
