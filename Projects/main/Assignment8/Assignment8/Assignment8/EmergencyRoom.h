/// Group Members: Itz, Thien
/// CMPR 131
/// Date: 10.28.2021
/// Description: A simulation of a front desk registration/ transfer of emergency room patients
///
///

#pragma once
#include <concurrent_priority_queue.h>
#include <iostream>
#include <queue>
#include "Patient.h"
#include "input.h"
#include <ctime>

char emergencyRoomOption();
void registerPatient(priority_queue<Patient>& waiting);
void transferPatient(priority_queue<Patient>& waiting, queue<Patient>& seen);
void displayTransferred(queue<Patient> seen);

//////////////////////////
// MAIN DRIVER FUNCTION //
//////////////////////////
/// Precondition: N/A
/// Postcondition: Will simulate a menu driven emergency room registration and transfer software
void runEmergencyRoom()
{
    clrScrn();
    std::cout << "\n\t2> Simulation of an emergency room (ER) using priority queue";
    priority_queue<Patient> waitingRoom;
    queue<Patient> seenQueue;

    do
    {
        switch (emergencyRoomOption())
        {
        case ('0'): return; break;
        case ('A'): registerPatient(waitingRoom); break;
        case ('B'): transferPatient(waitingRoom, seenQueue); break;
        case ('C'): displayTransferred(seenQueue); break;
        default: cout << "\t\tERROR - Invalid option. Please re-enter."; break;
        }
        pause();
        clrScrn();
    } while (true);
    cout << "\n";
    pause();
    clrScrn();
}

/// Precondition: There must be elements in the seen queue 
/// Postcondition: will outputf the patients and their properties that have been tranferred in order to the seen queue 
void displayTransferred(queue<Patient> seen)
{
    if (!seen.empty())
    {
        queue<Patient> tempQueue;
        while (!seen.empty())
        {
            cout << seen.front();

            tempQueue.push(seen.front());
            seen.pop();
        }
    }
    else
    {
        cout << "\n\tNo patients have been transferred.";
    }
}

/// Precondition: Priority queue msut have Patient elements stored 
/// Postcondition: Will transfer from the priority queue to the queue which represents the waiting room,
///                which represents patients that have been attended to in the emergency room
void transferPatient(priority_queue<Patient>& waiting, queue<Patient> &seen)
{
    if (!waiting.empty())
    {

        if (waiting.top().getPriority() == 5)
        {
            seen.push(waiting.top());
            cout << waiting.top();
            waiting.pop();

        }
        else if (waiting.top().getPriority() == 4)
        {
            seen.push(waiting.top());
            cout << waiting.top();
            waiting.pop();
        }
        else if (waiting.top().getPriority() == 3)
        {
            seen.push(waiting.top());
            cout << waiting.top();
            waiting.pop();
        }
        else if (waiting.top().getPriority() == 2)
        {
            seen.push(waiting.top());
            cout << waiting.top();
            waiting.pop();
        }
        else if (waiting.top().getPriority() == 1)
        {
            seen.push(waiting.top());
            cout << waiting.top();
            waiting.pop();
        }
    }
    else
    {
        cout << "\n\tThere are no patients in the waiting room";
    }
}

/// Precondition: Object and the queue must be initialize
/// Postcondition: will bring up a series of regitration demographic questions that set the values to the patient
void registerPatient(priority_queue<Patient> &waiting)
{
    Patient patient1;
    patient1.setName(inputString("\n\tEnter the patients name: ", true));
    patient1.setAge(inputInteger("\n\tEnter the patient's age: ", true));
    patient1.setGender(inputChar("\n\tChoose the patient's gender (F-female or M - male or U - Unknown) : ", string("FMU")));
    patient1.setPriority(inputInteger("\n\tChoose the ER level 1)Non-urgent, 2)Less Urgent, 3)Urgent, 4)Emergency, or 5)Red Zone....", 1, 5));
    patient1.setCheckedInTime(time(0));

    waiting.push(patient1);

    cout << "\n\t\tPatient information has been registered.\n";
}

/// Precondition: N/A
/// Postcondition: will return the char that corresponding to the option the user has selected
char emergencyRoomOption()
{
    header("CMPR131 Chapter 8 - Assignmnet 8 by  Ben, Thien , Itz, Tony, Jose, and Jesus");
    cout << "\n\t\t  A> Register a patient";
    cout << "\n\t\t  B> Transfer patient(s) to the designation";
    cout << "\n\t\t  C> Display transferred patients";
    cout << "\n\t\t  0> return\n";
    header("");

    int optionChar = inputChar("\n\t\tOption: ", string("abc0"));
    clrScrn();

   return optionChar;
}