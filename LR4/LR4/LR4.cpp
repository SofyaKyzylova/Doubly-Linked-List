// LR4.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include "Header.h"

using namespace std;

int main()
{
	setlocale(LC_ALL, "Russian");
	Node* head = NULL;
	Node* tail = NULL;
	
	cout << " Добавление элементов в начало списка" << endl;
	head = AddHead(head, tail, 5);
	head = AddHead(head, tail, 2);
	head = AddHead(head, tail, 7);

	cout << " Вывод содержания связанного списка в прямом обходе: " << endl;
	outListHead(head);
	cout << " Вывод содержания связанного списка в обратном обходе: " << endl;
	outListTail(tail);
	cout << endl;

	cout << " Добавление элементов в конец списка" << endl;
	tail = AddTail(tail, head, -3);
	tail = AddTail(tail, head, 4);
	tail = AddTail(tail, head, 10);

	cout << " Вывод содержания связанного списка в прямом обходе: " << endl;
	outListHead(head);
	cout << " Вывод содержания связанного списка в обратном обходе: " << endl;
	outListTail(tail);
	cout << endl;

	insert(head, tail, 2, 1);
	cout << " Вставка элемента со значением '1' на 2-ю позицию списка: " << endl;
	outListHead(head);

	findDataHead(head, 7);
	cout << endl;
	findDataTail(tail, 7);
	cout << endl << endl;

	cout << " Удаление начала списка: " << endl;
	head = removeHead(head);
	outListHead(head);

	cout << " Удаление конца списка: " << endl;
	tail = removeTail(tail);
	outListHead(head);

	cout << " Удаление 3-го элемента списка: " << endl;
	remove(head, tail, 3);
	outListHead(head);
	cout << endl;
	
	cout << " Значение 3-го элемента списка равно ";
	retrieve(head, 3);
	cout << endl;

	//Задание 2. Вариант С
	cout << " ЗАДАНИЕ 2" << endl;
	Node* head_ = NULL;
	Node* tail_ = NULL;

	cout << " Отсортированный список 1:" << endl;
	Sort(head);
	outListHead(head);

	head_ = AddHead_(head_, tail_, 3);
	head_ = AddHead_(head_, tail_, 7);
	head_ = AddHead_(head_, tail_, -1);
	head_ = AddHead_(head_, tail_, 2);
	head_ = AddHead_(head_, tail_, 5);
	cout << " Список 2:" << endl;
	outListHead_(head_);

	cout << " Отсортированный список 2:" << endl;
	Sort_(head_);
	outListHead_(head_);

	cout << " Объединение двух упорядоченных списков в один упорядоченный список:" << endl;
	head = merge(head, tail, head_);
	Sort(head);
	outListHead(head);

	removeAll(head);
	if (isEmpty(head))
		cout << " Список пуст (" << isEmpty(head) << ")" << endl;
	else
		cout << " Список не пуст (" << isEmpty(head) << ")" << endl;
}
