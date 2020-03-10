#include "ready_queue.h"
#include <iostream>
using namespace std;


// PURPOSE: Default constructor
// PARAMETER: None
ready_queue::ready_queue()
{}


// PURPOSE: Default deconstructor
// PARAMETER: None
ready_queue::~ready_queue()
{}


// PURPOSE: Retrieves the current size of the ready queue (number of elements)
// PARAMETER: None
int ready_queue::size()
{
    return heap.size();
}


// PURPOSE: Adds an element to the ready queue, while updating the elements status and add counter.
//          If that element is already in the queue, return without adding it.
// PARAMETER: The element to be added to the queue.
void ready_queue::add(PCB& element)
{
    for (int i = 0; i < heap.size(); i++)
    {
        if (element.get_PCB_ID() == heap[i]->get_PCB_ID())
        {
            return;
        }
    }
    element.set_current_state(READY);
    element.update_add_counter();
    heap.push_back(&element);
    //reHeap();
    bubblesort(heap);
}


// PURPOSE: If the heap is empty, return. Otherwise remove the element at the tail of the queue,
//          while updating its status to "running" and updating its remove counter.
//          Reheap the queue afterwards to ensure the order is maintained (may not be required)
// PARAMETER: None
void ready_queue::remove_highest()
{
    if (heap.empty())
    {
        return;
    }

    int x = heap.size()-1;
    heap[x]->PCB::update_remove_counter();
    heap[x]->set_current_state(RUNNING);
  //  heap[x].update_remove_counter();
    heap.pop_back();
}


void ready_queue::bubblesort(vector<PCB*> heap)
{
    int n = heap.size();
    for (int j = 0; j < n-1; j++)
    {
        for (int i = 0; i < n - 1; i++)
            if (heap[i]->get_priority() > (heap[i + 1])->get_priority())
            {
                PCB* temp = heap[i];
                heap[i] = heap[i + 1];
                heap[i + 1] = temp;
            }
    }
}




// PURPOSE:
// PARAMETER:
void ready_queue::display()
{
    if (heap.size() == 0)
        cout << "\nThe queue is empty!" << endl;
    else
        cout << "\nQueue: \n";
    for(int i=0; i<heap.size(); i++)
    {
        PCB* temp = heap.at(i);
        cout << "PCB ID " << temp->get_PCB_ID() << " Added  " << temp->get_add_counter() << " times, removed " << temp->get_remove_counter() << " times\n";
    }
    cout << endl;
}
