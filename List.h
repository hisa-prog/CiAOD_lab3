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
		
		void InsertElementInBeginning(int info); //������� �������� �� ������
		void DeleteElementInBeginning(); //�������� �������� �� ������
		int ViewItemFromTheBeginning(); //�������� �������� �� ������

		void InsertElementInEnd(int info); //������� �������� � �����
		void DeleteElementInEnd(); //�������� �������� � �����
		int ViewItemFromTheEnd(); //��������� �������� � ����� 

		void InsertElementByIndex(int index,int info);//������� �������� �� ��� �������
		void DeleteElementByIndex(int index); //�������� �������� �� ��� �������
		int ViewItemByIndex(int index); //�������� �������� �� ��� �������

		void PrintList(); //����� ������
	};

}
