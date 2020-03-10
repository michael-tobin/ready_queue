#include "PCB_table.h"
#include <ctime>
#include <cstdlib>
using namespace std;


// PURPOSE: Default constructor
// PARAMETER: None
PCB_Table::PCB_Table()
{}


// PURPOSE: Default deconstructor
// PARAMETER: None
PCB_Table::~PCB_Table()
{}


// PURPOSE: Creates a new PCB element where PCB_ID and current_priority are the same (=i)
// PARAMETER: The number of entries is the size of the table
void PCB_Table::create_table(int entries)
{
    for (int i = 1; i <= entries ; i++)
    {
        PCB newProcess = PCB(i, i);
        process_list.push_back(newProcess);
    }
}

// PURPOSE: Creates a new PCB element where current_priority is random
// PARAMETER: The number of entries is the size of the table
void PCB_Table::create_table_rand(int entries)
{
    srand(time(0)); // Random number seed generated from the seconds since unix epoch

    for (int i = entries; i > 0 ; i--)
    {
        int x = rand() % 50 + 1;
        PCB newProcess = PCB(i, x);
        process_list.push_back(newProcess);
    }
}

// PURPOSE: Retrieves an element from the table of elements
// PARAMETER: The ID of the requested element
PCB* PCB_Table::get_element(int id)
{
    return &process_list[id];
}

void PCB_Table::display()
{
    cout << "Table:" << endl;
    for (int i=0; i<process_list.size(); i++)
    {
        cout << process_list.at(i);
    }
}