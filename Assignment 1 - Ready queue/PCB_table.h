#ifndef PCB_TABLE_H
#define PCB_TABLE_H

#include "PCB.h"
#include <vector>


class PCB_Table : public PCB
{
    private:
        vector<PCB> process_list; // A table to hold processes awaiting their turn in the queue

    public:
        PCB_Table();
        ~PCB_Table();
        void create_table(int entries);
        void create_table_rand(int entries);
        PCB* get_element(int id);
        void display();
};
#endif
