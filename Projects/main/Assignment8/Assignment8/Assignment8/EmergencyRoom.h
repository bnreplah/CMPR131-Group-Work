/// Itz, Thien
///
///
///
///
///

#pragma once
#include <concurrent_priority_queue.h>
#include <queue>
#include "Patient.h"
#include "input.h"

char emergencyRoomOption();
void registerPatient(priority_queue<Patient>& waiting);
void transferPatient(priority_queue<Patient>& waiting, queue<Patient>& seen);
void displayTransferred(queue<Patient> seen);



///Precondition:
///Postcondition:
void runEmergencyRoom() {

    clrScrn();
    std::cout << "\n1\t2> Simulation of an emergency room (ER) using priority queue";
    priority_queue<Patient> waitingRoom;
    queue<Patient> seenQueue;

    do
    {
        switch (emergencyRoomOption()) {
        case ('0'): return; break;
        case ('A'):registerPatient(waitingRoom); break;
        case ('B'):transferPatient(waitingRoom, seenQueue); break;
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

void displayTransferred(queue<Patient> seen)
{

    if (!seen.empty())
    {
        queue<Patient> tempQueue;
        while (!seen.empty())
        {
            cout << "\n";
            cout << "\n\t\tTRANSFER  TO SURGERY ROOM";
            cout << "\n\t_______________________________________________";
            cout << "\n\t Checked in-time: " << seen.front().getCheckedInTime();
            cout << "\n\t Name: " << seen.front().getName();
            cout << "\n\t Age: " << seen.front().getAge();
            cout << "\n\t Gender: " << seen.front().getGender();

            tempQueue.push(seen.front());
            seen.pop();
        }
    }
    else
    {
        cout << "\n\tNo patients have been transferred.";
    }


}



///Precondition:
///Postcondition:
void transferPatient(priority_queue<Patient>& waiting, queue<Patient> &seen)
{
    if (!waiting.empty())
    {

        if (waiting.top().getPriority() == 5)
        {
            seen.push(waiting.top());
            cout << "\n\t\t- TRANSFER TO ICU";
            cout << "\n\t_______________________________________________";
            cout << "\n\t Name: " << waiting.top().getName();
            cout << "\n\t Age: " << waiting.top().getAge();
            cout << "\n\t Gender: " << waiting.top().getGender();
            waiting.pop();

        }
        else if (waiting.top().getPriority() == 4)
        {
            seen.push(waiting.top());
            cout << "\n\t\t- TRANSFER  TO SURGERY ROOM";
            cout << "\n\t_______________________________________________";
            cout << "\n\t Name: " << waiting.top().getName();
            cout << "\n\t Age: " << waiting.top().getAge();
            cout << "\n\t Gender: " << waiting.top().getGender();
            waiting.pop();
        }
                
        else if (waiting.top().getPriority() == 3)
        {
            seen.push(waiting.top());
            cout << "\n\t\t- TRANSFER TO EMERGENCY ROOM";
            cout << "\n\t_______________________________________________";
            cout << "\n\t Name: " << waiting.top().getName();
            cout << "\n\t Age: " << waiting.top().getAge();
            cout << "\n\t Gender: " << waiting.top().getGender();
            waiting.pop();
        }
                
        else if (waiting.top().getPriority() == 2)
        {
            seen.push(waiting.top());
            cout << "\n\t\t- TRANSFER TO X-RAY LAB";
            cout << "\n\t_______________________________________________";
            cout << "\n\t Name: " << waiting.top().getName();
            cout << "\n\t Age: " << waiting.top().getAge();
            cout << "\n\t Gender: " << waiting.top().getGender();
            waiting.pop();
        }
                
        else if (waiting.top().getPriority() == 1)
        {
            seen.push(waiting.top());
            cout << "\n\t\t- TRANSFER EXAMINES AND GIVES PRESCRIPTION";
            cout << "\n\t_______________________________________________";
            cout << "\n\t Name: " << waiting.top().getName();
            cout << "\n\t Age: " << waiting.top().getAge();
            cout << "\n\t Gender: " << waiting.top().getGender();
            waiting.pop();
        }
    }
    else
    {
        cout << "\n\tThere are no patients in the waiting room";
    }
    

}




///Precondition:
///Postcondition:
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


///Precondition:
///Postcondition:
char emergencyRoomOption() {

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




////Professor Q's code ... do not copy but understand.... if you copy i will come after you... and ill know.... 
//void option2()
//{
//
//    system("cls");
//    cout << "\n\t2> Simulation of an emergency room (ER) using priority queue STL\n";
//
//    priority_queue<Patient> pq2;
//    vector<Patient> submit;
//
//    do
//    {
//        cout << "\n\t\t  A> Register a patient";
//        cout << "\n\t\t  B> Transfer patient(s) to the designation";
//        cout << "\n\t\t  C> Display transferred patients";
//        cout << "\n\t\t  0> return\n";
//
//        switch (toupper(inputChar("\t\t  Option: ", "ABC0")))
//        {
//        case '0': return;
//        case 'A':
//        {
//            Patient patient;
//            string name;
//            cout << "\n\t\tEnter the patient's name: ";
//            getline(cin, name);
//            patient.setName(name);
//            patient.setAge(inputInteger("\t\tEnter the patient's age: ", true));
//            patient.setCheckedInTime(time(0));
//            patient.setGender(toupper(inputChar("\t\tChoose the patient's gender (F-female or M - male) : ", 'F', 'M')));
//            patient.setPriority(inputInteger("\t\tChoose the ER level 1)Non-urgent, 2)Less Urgent, 3)Urgent, 4)Emergent, or 5)Resuscitation: ", 1, 5));
//
//            pq2.push(patient); // enqueue 
//            cout << "\n\t\tPatient information has been registered.\n";
//        }
//        break;

        //case 'B':
        //{
        //    if (!pq2.empty())
        //    {
        //        if (pq2.top().getPriority() == 5)
        //        {
        //            submit.push_back(pq2.top());
        //            cout << "\n\t\t" << pq2.top().getName() << " - transfers to ICU...\n";
        //            pq2.pop(); // dequeue 
        //            break;
        //        }
        //        else if (pq2.top().getPriority() == 4)
        //        {
        //            submit.push_back(pq2.top());
        //            cout << "\n\t\t" << pq2.top().getName() << " - transfers to surgery room...\n";
        //            pq2.pop();
        //            break;
        //        }
        //        else if (pq2.top().getPriority() == 3)
        //        {
        //            submit.push_back(pq2.top());
        //            cout << "\n\t\t" << pq2.top().getName() << " - transfers to emergency room...\n";
        //            pq2.pop();
        //            break;
        //        }
        //        else if (pq2.top().getPriority() == 2)
        //        {
        //            submit.push_back(pq2.top());
        //            cout << "\n\t\t" << pq2.top().getName() << " - transfers to x-ray lab...\n";
        //            pq2.pop();
        //            break;
        //        }
        //        else if (pq2.top().getPriority() == 1)
        //        {
        //            submit.push_back(pq2.top());
        //            cout << "\n\t\t" << pq2.top().getName() << " - examines and gives prescription...\n";
        //            pq2.pop();
        //            break;
        //        }
        //    }
        //}
//        break;
//        case 'C':
//        {
//            if (!submit.empty())
//            {
//
//                sort(submit.begin(), submit.end());
//                reverse(submit.begin(), submit.end());
//                cout << '\n';
//                for (int i = 0; i < submit.size(); i++)
//                    cout << "\t\t" << i + 1 << " - " << submit[i] << '\n';
//            }
//            else
//                cout << "\n\t\tNo patient has been transferred.\n";
//        }
//        break;
//        }
//
//
//    } while (true);
//}