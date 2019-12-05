// Assignment_7 Priority Queues.cpp : Defines the entry point for the console application.
//TIMOS MUKOKO K00203438

#include "stdafx.h"
#include "PQType.h"
#include "HeapType.h"

void EnterPatient();
void DisplayPatientList();
void RemovePatient();
void ResetList();
void Exit();
int Menu();
bool QuitFlag = false;

Patient list[10];
Patient PT;
PQType PQ;

int main()
{
	int option;
	do
	{
		option = Menu();

		switch (option)
		{
			//============================= FUNCTIONS CALL =============================
		case 1:
			EnterPatient();
			break;
		case 2:			
			DisplayPatientList();
			break;
		case 3:
			RemovePatient();
			break;
		case 4:
			ResetList();
			break;
		case 5:
			Exit();	
			break;
		default:
			cout << " -- Invalid option ! -- " << endl;
			break;
		}
	} while (!QuitFlag);
    return 0;
}

// Menu
int Menu()
{
	int option = 0;
	cout << endl;

	cout << "\n\n\n\n";
	cout << "\t__________________________________________________________________" << endl;
	cout << "\t|                                                                |" << endl;
	cout << "\t|\t\t\t MENU OPTION                             |" << endl;
	cout << "\t|________________________________________________________________|" << endl;
	cout << "\t|                                                                |" << endl;
	cout << "\t|\t1. Enter Patient                                         |\n";
	cout << "\t|\t2. Display Patient List                                  |\n";
	cout << "\t|\t3. Call Next Patient                                     |\n";
	cout << "\t|\t4. Reset List                                            |\n";
	cout << "\t|\t5. Exit                                                  |\n";
	cout << "\t|________________________________________________________________|" << endl;
	cout << endl;
	cout << "\tOption: ";
	cin >> option;
	system("cls");
	cout << "\n";
	return option;
}

void EnterPatient()
{
	// Setup a Patient List

	/*PT.patient_Name = "George";
	PT.priority = 0;
	PQ.Enqueue(PT);

	PT.patient_Name = "Mary";
	PT.priority = 2;
	PQ.Enqueue(PT);

	PT.patient_Name = "John";
	PT.priority = 3;
	PQ.Enqueue(PT);

	PT.patient_Name = "Franklin";
	PT.priority = 4;
	PQ.Enqueue(PT);

	PT.patient_Name = "Bob";
	PT.priority = 5;
	PQ.Enqueue(PT);
*/
	char yesNo;

		/*cout << "\n\tThe System already contained Patients List in queue " << endl;*/
		cout << "\n\tWould you like to add Patient ? (Y / N): ";
		cin >> yesNo;
		while (yesNo == 'Y' || yesNo == 'y')
		{
			cout << "\n\tEnter Patient Name: ";
			cin >> PT.patient_Name;
			cout << "\tEnter Priority (0-5): ";
			cin >> PT.priority;
			cout << "\n\tWould you like to add one more Patients ? (Y/N):";
			cin >> yesNo;
			PQ.Enqueue(PT);

			if (yesNo == 'N' || yesNo == 'n')
			{
				break;
			}
	}
	cout << " \n\t\t\t --- Thank you !!! --- \n" << endl;
}

void DisplayPatientList()
{
	if (PQ.IsEmpty())
	{
		cout << "\n\n\t_N O   P A T I E N T S   I N   T H E   Q U E U E_\n\n";
		cout << "\t" << "|\tNumber of Patients:  \t\t| " << PQ.Size() << " |\n";
	}
	else
	{
		PQ.Display();
	}
}

void RemovePatient()
{
	if (PQ.IsEmpty())
	{
		cout << "n\n\t\t--- NO PATIENTS IN THE QUEUE : ";
		cout << PQ.Size() << endl;
	}
	else
	{
		PQ.Dequeue(PT);
		PQ.Display();
	}
}

void ResetList()
{
	if (PQ.IsEmpty())
	{
		cout << "\n\n\t\t NOTHING TO RESET ";
		cout << "\t" << PQ.Size() << " Patient\n";
	}
	else
	{
		PQ.MakeEmpty();
		cout << "\t --- THE LIST HAS BEEN RESETED ---" << endl;
	}
}

void Exit()
{
	QuitFlag = true;
}