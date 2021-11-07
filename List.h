#pragma once

namespace vz_struct
{
	class List
	{
	private:
		int id;
		static int idCounter;

		struct NodeList
		{
			int Info;
			NodeList* Next;
		};

		NodeList* BeginList;

	public:
		List();
		~List();
		
		void InsertElementInBeginning(int info); //Вставка элемента из начала
		void DeleteElementInBeginning(); //Удаление элемента из начала
		int ViewItemFromTheBeginning(); //Просмотр элемента из начала

		void InsertElementInEnd(int info); //Вставка элемента с конца
		void DeleteElementInEnd(); //Удаление элемента с конца
		int ViewItemFromTheEnd(); //Просмотре элемента с конца 

		void InsertElementByIndex(int index,int info);//Вставка элемента по его индексу
		void DeleteElementByIndex(int index); //Удаление элемента по его индексу
		int ViewItemByIndex(int index); //Просмотр элемента по его индексу

		void PrintList(); //Вывод списка
	};

}
