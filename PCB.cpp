#include "PCB.h"
using namespace std;


// PURPOSE:
// PARAMETER:
PCB::PCB()
{}


// PURPOSE:
// PARAMETER:
PCB::PCB(int ID, int priority)
{
    PCB_ID = ID;
    current_priority = priority;
    current_state = NEW;
    ac = 0;
    rc = 0;
}


// PURPOSE:
// PARAMETER:
PCB::~PCB()
{}


// PURPOSE:
// PARAMETER:
int PCB::get_PCB_ID()
{
    return PCB_ID;
}


// PURPOSE: Change the priority of the PCB element that calls it.
// PARAMETER: The desired value of priority.
void PCB::set_priority(int priority)
{
    current_priority = priority;
}


// PURPOSE: Retrieves the current priority of the PCB element that calls it.
// PARAMETER: None
int PCB::get_priority()
{
    return current_priority;
}


// PURPOSE: Changes the state of the PCB element that calls it.
// PARAMETER: The desired state.
void PCB::set_current_state(State new_state)
{
    current_state = new_state;
}


// PURPOSE: Retrieves the current state of the PCB element that calls it.
// PARAMETER: None
State PCB::get_current_state()
{
    return current_state;
}


// PURPOSE: Increments the "add" counter by 1 for the PCB element that called it.
// PARAMETER: None
void PCB::update_add_counter()
{
    ac++;
}


// PURPOSE: Retrieves the value of the "add" counter for the PCB element that calls it.
// PARAMETER: None
int PCB::get_add_counter()
{
    return ac;
}


// PURPOSE: Increments the "remove" counter by 1 for the PCB element that called it.
// PARAMETER:
void PCB::update_remove_counter()
{
    rc++;
}


// PURPOSE: Retrieves the value of the "remove" counter for the PCB element that calls it.
// PARAMETER:
int PCB::get_remove_counter()
{
    return rc;
}

// PURPOSE:
// PARAMETER:
ostream& operator<<(ostream& os, PCB& PCBout)
{/*
    if (PCBout.get_PCB_ID() == 1)
    {
        PCBout.set_PCB_ID(2);
    }
    if (PCBout.get_priority() == 1)
    {
        PCBout.set_priority(2);
    }*/
    os << "PCB ID  " << PCBout.get_PCB_ID()  << " Added  " << PCBout.get_add_counter() << " times, removed " << PCBout.get_remove_counter() << " times\n";
    return os;
}
