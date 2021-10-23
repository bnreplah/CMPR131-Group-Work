#include <concurrent_priority_queue.h>
#include <iostream>
#include <queue>
#include <deque>
#include "Patient.h"
#include "input.h"
using namespace std;

void option2()
{

    system("cls");
    cout << "\n\t2> Simulation of an emergency room (ER) using priority queue STL\n";

    priority_queue<Patient> pq2;
    vector<Patient> submit;

    do
    {
        cout << "\n\t\t  A> Register a patient";
        cout << "\n\t\t  B> Transfer patient(s) to the designation";
        cout << "\n\t\t  C> Display transferred patients";
        cout << "\n\t\t  0> return\n";

        switch (toupper(inputChar("\t\t  Option: ", "ABC0")))
        {
        case '0': return;
        case 'A':
        {
            Patient patient;
            string name;
            cout << "\n\t\tEnter the patient's name: ";
            getline(cin, name);
            patient.setName(name);
            patient.setAge(inputInteger("\t\tEnter the patient's age: ", true));
            patient.setCheckedInTime(time(0));
            patient.setGender(toupper(inputChar("\t\tChoose the patient's gender (F-female or M - male) : ", 'F', 'M'))); 
                patient.setPriority(inputInteger("\t\tChoose the ER level 1)Non-urgent, 2)Less Urgent, 3)Urgent, 4)Emergent, or 5)Resuscitation: ", 1, 5)); 

                pq2.push(patient); // enqueue 
            cout << "\n\t\tPatient information has been registered.\n";
        }
        break;
        case 'B':
        {
            if (!pq2.empty())
            {
                if (pq2.top().getPriority() == 5)
                {
                    submit.push_back(pq2.top());
                    cout << "\n\t\t" << pq2.top().getName() << " - transfers to ICU...\n" ; 
                        pq2.pop(); // dequeue 
                    break;
                }
                else if (pq2.top().getPriority() == 4)
                {
                    submit.push_back(pq2.top());
                    cout << "\n\t\t" << pq2.top().getName() << " - transfers to surgery room...\n"; 
                        pq2.pop();
                    break;
                }
                else if (pq2.top().getPriority() == 3)
                {
                    submit.push_back(pq2.top());
                    cout << "\n\t\t" << pq2.top().getName() << " - transfers to emergency room...\n"; 
                        pq2.pop();
                    break;
                }
                else if (pq2.top().getPriority() == 2)
                {
                    submit.push_back(pq2.top());
                    cout << "\n\t\t" << pq2.top().getName() << " - transfers to x-ray lab...\n"; 
                        pq2.pop();
                    break;
                }
                else if (pq2.top().getPriority() == 1)
                {
                    submit.push_back(pq2.top());
                    cout << "\n\t\t" << pq2.top().getName() << " - examines and gives prescription...\n"; 
                        pq2.pop();
                    break;
                }
            }
        }
        break;
        case 'C':
        {
            if (!submit.empty())
            {

                sort(submit.begin(), submit.end());
                reverse(submit.begin(), submit.end());
                cout << '\n';
                for (int i = 0; i < submit.size(); i++)
                    cout << "\t\t" << i + 1 << " - " << submit[i] << '\n';
            }
            else
                cout << "\n\t\tNo patient has been transferred.\n";
        }
        break;
        }


    } while (true);
}