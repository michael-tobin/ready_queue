#include "PCB_table.h"
#include "ready_queue.h"
#include <ctime>
#include <cstdlib>
using namespace std;

int main()
{
    cout << "====================================================\n"
         << "Michael Tobin and Travis Vensel\n"
         << "CS433 - Operating Systems\n"
         << "Assignment 1 - Priority Queue of Processes\n"
         << "Description\n" //Insert a description here
         << "====================================================\n"
         << "\n********************************************\n"
         << "Test 1"
         << "\n********************************************" << endl;

    //create table of 30 entries
    PCB_Table table;
    table.create_table(30);

    //Create a ReadyQueue q1. Then do the following tests:
    // 1) add processes 15, 6, 23, 29 and 8 to 𝑞1. Display the content of q1
    ready_queue q1;
    q1.add(*table.get_element(15));
    q1.add(*table.get_element(6));
    q1.add(*table.get_element(23));
    q1.add(*table.get_element(29));
    q1.add(*table.get_element(8));
    q1.display();

    // 2) remove the process with the highest priority from q1 and display q1.
    q1.remove_highest();
    q1.display();

    // 3) remove the process with the highest priority from q1 and display q1.
    q1.remove_highest();
    q1.display();

    // 4) add processes 3, 17, 22, 12, 19 to q1 and display q1.
    q1.add(*table.get_element(3));
    q1.add(*table.get_element(17));
    q1.add(*table.get_element(22));
    q1.add(*table.get_element(12));
    q1.add(*table.get_element(19));
    q1.display();

    // 5) One by one remove the process with the highest priority from the queue q1 and display the queue after each removal.
    for(int i=q1.size(); i>0; i--)
    {
        q1.remove_highest();
        q1.display();
    }

    cout << "\n********************************************\n"
         << "Test 2"
         << "\n********************************************\n";

    //Using a PCB_table of 30 PCB'ss with ID from 1 to 30 as in the first test but assign each process a random initial priority between 1 and 50.

    //create table of 30 entries
    PCB_Table table2;
    table2.create_table_rand(30); // Create a table of 30 PCB's with random priority levels

    table2.display();

    srand(time(0)); // Random number seed generated from the seconds since unix epoch

    // Initially randomly select 15 processes from the PCB_table and add them into q1.
    while (q1.size()<15)
    {
        int randIndex = rand() % 30; // Choose a random index between 0 and 29
        q1.add(*table2.get_element(randIndex));
    }


    // repeat the following steps 1,000,000 times and measure the total time of running the loop.
    time_t start = time(0);

    int prob;
    // With equal probability (50% chance), randomly decide either to remove a process from or insert a process to the ReadyQueue.
    for (int k = 0; k < 1000000; k++)
    {
        prob = rand() % 2 + 1; // Choose 1 or 2 randomly

        if (prob == 2)
        {
            q1.remove_highest();
        }

        else if (prob==1)
        {
            int randIndex = rand() % 30; // Choose a random index between 0 and 29
            q1.add(*table2.get_element(randIndex));
        }
    }

    double seconds_since_start = difftime(time(0), start);
    cout << endl << seconds_since_start << " second(s) to complete\n";

    q1.display();
    return 0;
}
