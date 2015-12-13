#ifndef JOB_H_INCLUDED
#define JOB_H_INCLUDED
#include<string>
//Class for Job - Deshi Wu
//contains the information about a job - Deshi Wu

//This is the Job Class so far, it is pretty straightforward
//let me know if anything - Naief Perez Secin
class Job{

    private:
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


};
#endif // JOB_H_INCLUDED
