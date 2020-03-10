#ifndef READY_QUEUE_H
#define READY_QUEUE_H

#include <iterator>
#include <vector>
#include "PCB.h"

using namespace std;

class ready_queue
{
    private:
        vector<PCB*> heap; // The actual ready queue


    public:
        ready_queue();
        ~ready_queue();
        void add(PCB& element);
        void remove_highest();
        void display();
        int size();
        void bubblesort(vector<PCB*>); // testing
       // friend class PCB;
};

#endif
