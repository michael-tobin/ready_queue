#ifndef PCB_H
#define PCB_H

#include <iostream>
#include <fstream>
using namespace std;

enum State { NEW, READY, RUNNING, WAITING, TERMINATED };

class PCB
{
    private:
        int PCB_ID;             // Block ID 1-30
        int current_priority;   // Priority level 1-50
        State current_state;    // 1-5
        int ac;                 // Add counter, # of times added to ready queue
        int rc;                 // Delete counter, # of times removed from ready queue

    public:
        PCB();
        PCB(int ID, int priority);
        ~PCB();
        int get_PCB_ID();
        void update_add_counter();
        int get_add_counter();
        void update_remove_counter();
        int get_remove_counter();
        void set_priority(int priority);
        int get_priority();
        void set_current_state(State new_state);
        State get_current_state();
        friend ostream& operator<<(ostream& os, PCB& PCBout);
   //     friend class ready_queue;
};

#endif
