#include<iostream>

using namespace std;

#include"CQueue.h"
#include"CStack.h"

class CStudent
{
public:
	CStudent(DWORD dwStudentId):dwStudentId(dwStudentId){}
	static DWORD GetStudentId(CStudent* student)
	{
		DWORD dwValue = student->GetId();
		return dwValue;
	}
	DWORD GetId() const
	{
		return dwStudentId;
	}
private:
	DWORD dwStudentId;
};

int main()
{
	CQueue<int>* cQueue = new CQueue<int>();
	CStack<double>* cStack = new CStack<double>();

	for (int i = 0; i < 10; i++)
	{
		cQueue->Enqueue(new int(i));
		cStack->Push(new double(i / 10.0));
	}

	cout << "Queue - integer collection:" << endl;
	for (; cQueue->Count();)
	{
		cout << *cQueue->Dequeue() << " ";
	}

	cout << endl << endl << "Stack - double collection:" << endl;
	for (; cStack->Count();)
	{
		cout << *cStack->Pop() << " ";
	}

	delete cQueue;
	delete cStack;

	cout << endl << endl;

	CList<CStudent>* list = new CList<CStudent>();
	list->Insert(new CStudent(1));
	list->Insert(new CStudent(2));
	list->Insert(new CStudent(3));
	CStudent* s = list->Find(&CStudent::GetStudentId, 2);
	if (s != NULL)
	{
		cout << "Find the number." << endl;
	}
	return system("pause");
}