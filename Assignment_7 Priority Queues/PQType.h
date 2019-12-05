#pragma once
#include "stdafx.h"
#include "HeapType.h"

class PQType
{
public:
	PQType();
	~PQType();
	void Enqueue(Patient newItem);
	void Dequeue(Patient& item);
	void Display();
	bool IsEmpty() const;
	bool isFull() const;
	void MakeEmpty();
	int Size();
	HeapType items;
	/*HeapType items;*/
private:
	int numItems;
	int maxItems;
	int itemCount;
	Patient patients;
};

PQType::PQType()
	:numItems(0)
	,maxItems(0)
	,itemCount(0)
{
}

PQType::~PQType()
{
	delete[] items.listPatient;
}

void PQType::MakeEmpty()
{
	numItems = 0;
}

bool PQType::IsEmpty() const
{
	if (numItems == 0)
		return true;
	else
	return false;
}

bool PQType::isFull() const
{
	if (numItems == 10)
		return true;
	else
	return false;
}

void PQType::Enqueue(Patient newItem)
{
	bool found = false;

	if (numItems > 0)
	{
		for (int i = 0; i < numItems; i++) 
		{
		  if (newItem.priority > items.listPatient[i].priority && !found) 
		  {
			found = true;
			newItem.numPatients = items.listPatient[i].numPatients;
			items.listPatient[i].numPatients++;

			for (int d = i + 1; d < numItems; d++) 
			 {
				items.listPatient[d].numPatients++;
		     }
			break;
		  }
		}

		if (!found) {
			newItem.numPatients = numItems + 1;
		}
	}
	else 
	{
		newItem.numPatients = 1;
	}

	numItems++;
	items.listPatient[numItems - 1] = newItem;
	items.ReheapUp(0, numItems - 1);
	items.HeapSort(items.listPatient, numItems);
}

void PQType::Dequeue(Patient& item)
{
	item.numPatients = items.listPatient[0].numPatients;
	Swap(items.listPatient[0], items.listPatient[numItems - 1]);
	numItems--;
	items.ReheapDown(0, numItems - 1);
	items.HeapSort(items.listPatient, numItems);
}

int PQType::Size()
{
	return numItems;
}

void PQType::Display()
{
	cout << "\t _______________________________________________" << endl;
	cout << "\t|                                               |" << endl;
	cout << "\t|              CURRENT WAITING LIST             |" << endl;
	cout << "\t|_______________________________________________|" << endl;
	cout << "\t|                                               | " << endl;
	cout << "\t|Calling: "<< items.listPatient[numItems - 0].patient_Name << endl;
	cout << "\t|_______________________________________________|" << endl;
	cout << "\t|                                               | " << endl;
	cout << "\t|\t"<< setw(20) << left << "PATIENT NAME" << setw(25) << left << "PRIORITY\t\t|" << endl;
	cout << "\t|                                               | "<< endl;
	for (int i = 0; i < numItems; i++)
	{
		cout <<"\t|\t"<<setw(20)<< left << items.listPatient[i].patient_Name << setw(20)<< left<< items.listPatient[i].priority <<"|"<< endl;		
	}
	cout << "\t|_______________________________________________|" << endl;
}