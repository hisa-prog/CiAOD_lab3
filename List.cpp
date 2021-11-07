#include "List.h"
#include <iostream>

namespace vz_struct
{	
	int List::idCounter = 0;

	List::List()
	{
		BeginList = nullptr;
	}

	List::~List()
	{
		NodeList* pointer;
		while (BeginList != nullptr)
		{
			pointer = BeginList;
			BeginList = BeginList->Next;
			delete pointer;
		}
	}

	void List::InsertElementInBeginning(int info)
	{
		NodeList* pointer = new NodeList;
		pointer->Info = info;
		pointer->Next = BeginList;
		BeginList = pointer;
		pointer = nullptr;
	}

	void List::DeleteElementInBeginning()
	{
		NodeList* pointer = new NodeList;
		pointer = BeginList;
		BeginList = BeginList->Next;
		delete pointer;
	}

	int List::ViewItemFromTheBeginning()
	{
		return BeginList->Info;
	}

	void List::InsertElementInEnd(int info)
	{
		if (BeginList == nullptr)
		{
			BeginList = new NodeList;
			BeginList->Next = nullptr;
			BeginList->Info = info;
		}
		else {
			NodeList* pointer = new NodeList;
			pointer = BeginList;
			while (pointer->Next != nullptr)
			{
				pointer = pointer->Next;
			}
			NodeList* pointer2 = new NodeList;
			pointer2->Info = info;
			pointer2->Next = nullptr;
			pointer->Next = pointer2;

			pointer2 = nullptr;
			pointer = nullptr;
		}
	}

	void List::DeleteElementInEnd()
	{
		NodeList* pointer = new NodeList;
		pointer = BeginList;
		while (pointer->Next->Next != nullptr)
		{
			pointer = pointer->Next;
		}
		NodeList* pointer2 = new NodeList;
		pointer2 = pointer->Next;
		pointer->Next = nullptr;
		delete pointer2;
	}

	int List::ViewItemFromTheEnd()
	{
		NodeList* pointer = new NodeList;
		pointer = BeginList;
		while (pointer->Next != nullptr)
		{
			pointer = pointer->Next;
		}
		return pointer->Info;
	}

	void List::InsertElementByIndex(int index, int info)
	{
		NodeList* pointer = new NodeList;
		pointer = BeginList;
		NodeList* pointer2 = new NodeList;
		pointer2->Info = info;
		pointer2->Next = nullptr;
		if ((index == 0) && (BeginList == nullptr))
		{
			BeginList = new NodeList;
			BeginList->Next = nullptr;
			BeginList->Info = info;
		}
		else
			if (index == 0)
			{
				pointer->Info = info;
				pointer->Next = BeginList;
				BeginList = pointer;
				pointer = nullptr;
			}
		else if ((index != 0) && (BeginList == nullptr)) return throw;
		

		for (int i = 0; i < index - 1; i++)
		{
			if ((pointer->Next->Next == nullptr) && (i != index - 2)) throw;
			pointer = pointer->Next;
		}
		pointer2->Next = pointer->Next;
		pointer->Next = pointer2;
	}

	void List::DeleteElementByIndex(int index)
	{
		NodeList* pointer = new NodeList;
		pointer = BeginList;
		NodeList* pointer2 = new NodeList;
		if (BeginList == nullptr) throw;
		else
			if (index == 0)
			{
				BeginList = BeginList->Next;
				delete pointer;
			}
			else {
				for (int i = 0; i < index - 1; i++)
				{
					if ((pointer->Next->Next == nullptr) && (i != index - 2)) throw;
					pointer = pointer->Next;
				}
				pointer2 = pointer->Next;
				pointer->Next = pointer->Next->Next;
				delete pointer2;
			}
	}

	int List::ViewItemByIndex(int index)
	{
		NodeList* pointer = new NodeList;
		pointer = BeginList;
		
		if (BeginList == nullptr) throw;

		for (int i = 0; i < index; i++)
		{
			if ((pointer->Next == nullptr)) throw;
			pointer = pointer->Next;
		}
		return pointer->Info;
	}

	void List::PrintList()
	{
		NodeList* pointer = new NodeList;
		pointer = BeginList;
		std::cout << pointer->Info << " ";
		while (pointer->Next != nullptr)
		{
			pointer = pointer->Next;
			std::cout << pointer->Info << " ";
		}
		std::cout << "\n\n";
	}
}