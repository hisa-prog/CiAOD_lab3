#include <iostream>
#include <fstream>
#include "List.h"

using namespace vz_struct;

//Подготовить два текстовых файла, каждый из которых содержит не менее 12 целых чисел.
//Прочитать данные из этих файлов и сформировать два односвязных списка L1 и L2.
//Из этих двух списков формировать третий односвязный список L путем включения в него по одному разу чисел, 
//входящих в один из списков L1 и L2, но в то же время не входящих в другой из них.
//Вывести на экран исходные списки и сформированный список L.
//После завершения работы со списками освободите занимаемую ими динамическую память.
//
//В списке обязательно реализовать операции :
//1. Вставка\удаление\просмотр элемента из начала.
//2. Вставка\удаление\просмотр элемента с конца.
//3. Вставка\удаление\просмотр элемента по его индексу.

int main()
{
	system("chcp 1251 > nul");
	std::cout << "Открываем файл для чтения L1!";
	std::ifstream FileIn("L1.txt"); //открыли файл для чтения.

	if (FileIn.is_open())
		std::cout << "\nФайл успешно открыт!";
	else {
		std::cout << "\nФайл не был открыт!";
		return 1;
	}

	List L1 = List();
	int number;
	int counter = 0;

	std::cout << "\n\nЧисла, хранящиеся в файле L1: \n";
	while (!FileIn.eof())
	{
		FileIn >> number;
		counter++;
		std::cout << number << " ";
		L1.InsertElementInEnd(number);
	}

	std::cout << "\n\nЗакрываем файл L1!\n";
	FileIn.close(); //  закрываем файл

	std::cout << "Открываем файл для чтения L2!";
	FileIn.open("L2.txt");

	if (FileIn.is_open())
		std::cout << "\nФайл успешно открыт!";
	else {
		std::cout << "\nФайл не был открыт!";
		return 1;
	}

	List L2 = List();
	int counter2 = 0;

	std::cout << "\n\nЧисла, хранящиеся в файле L2: \n";
	while (!FileIn.eof())
	{
		FileIn >> number;
		counter2++;
		std::cout << number << " ";
		L2.InsertElementInEnd(number);
	}

	std::cout << "\n\nЗакрываем файл L2!\n";
	FileIn.close(); //  закрываем файл


	List L = List();
	for (int i = 0; i < counter; i++)
		for (int j = 0; j < counter2; j++) {
			if (L1.ViewItemByIndex(i) == L2.ViewItemByIndex(j)) break;
			if (j == counter2 - 1) L.InsertElementInEnd(L1.ViewItemByIndex(i));
		}

	for (int i = 0; i < counter2; i++)
		for (int j = 0; j < counter; j++) {
			if (L2.ViewItemByIndex(i) == L1.ViewItemByIndex(j)) break;
			if (j == counter - 1) L.InsertElementInEnd(L2.ViewItemByIndex(i));
		}

	L.PrintList();
}
