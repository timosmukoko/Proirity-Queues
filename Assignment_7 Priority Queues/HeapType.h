#pragma once
#include "stdafx.h"


struct Patient
{	
	string patient_Name;
	int numPatients;
	int priority;
	int count;
};

//template <class ItemType>
class HeapType
{
public:
	HeapType();
	~HeapType();
	void ReheapDown(int root, int bottom);
	void HeapSort(Patient patients[], int numPatients);
	void ReheapUp(int root, int bottom);
	Patient listPatient[10];
};

HeapType::HeapType()
{
	Patient listPatient[10];
}

HeapType::~HeapType()
{
}

void Swap(Patient& root, Patient& bottom)
{
	Patient tempItem;
	tempItem.numPatients = bottom.numPatients;
	tempItem.patient_Name = bottom.patient_Name;
	tempItem.priority = bottom.priority;

	bottom.numPatients = root.numPatients;
	bottom.patient_Name = root.patient_Name;
	bottom.priority = root.priority;

	root.numPatients = tempItem.numPatients;
	root.patient_Name = tempItem.patient_Name;
	root.priority = tempItem.priority;
}
		   		 

void HeapType::ReheapUp(int root, int bottom)
//Post: Heap property is restored.
{
	int parent;
	if (bottom > root)
	{
		parent = (bottom - 1) / 2;
		if (listPatient[parent].numPatients < listPatient[bottom].numPatients)
		{
			Swap(listPatient[parent], listPatient[bottom]);
			ReheapUp(root, parent);
		}
	}
}
			     
void HeapType::ReheapDown(int root, int bottom)
// Post: Heap property is restored.
{
	int maxChild;
	int rightChild;
	int leftChild;
	leftChild = root * 2 + 1;
	rightChild = root * 2 + 2;

	if (leftChild <= bottom)
	{
		if (leftChild == bottom)
			maxChild = leftChild;
		else
		{
			if (listPatient[leftChild].numPatients <= listPatient[rightChild].numPatients)
				maxChild = rightChild;
			else
				maxChild = leftChild;
		}
		if (listPatient[root].numPatients < listPatient[maxChild].numPatients)
		{
			Swap(listPatient[root], listPatient[maxChild]);
			ReheapDown(maxChild, bottom);
		}
	}
}

void HeapType::HeapSort(Patient patients[], int numPatients)
// Post: The elements in the array values are sorted by key.
{
	int index;
	// Convert the array of values into a heap.
	for (index = numPatients / 2 - 1; index >= 0; index--)
		ReheapDown(index, numPatients - 1);
	// Sort the array.
	for (index = numPatients - 1; index >= 1; index--)
	{
		Swap(patients[0], patients[index]);
		ReheapDown(0, index - 1);
	}
}



