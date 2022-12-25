#include <iostream>
#include <iomanip>
#include "Header.h"

using namespace std;

struct Node {
	int data;
	Node* next;
	Node* prev;
};

Node* AddHead(Node*& head, Node*& tail, int val)
{
	Node* temp = new Node;
	temp->data = val;
	if (head == NULL)
	{
		head = temp;
		tail = temp;
		tail->next = NULL;
	}
	else
	{
		head->prev = temp;
		temp->next = head;
		head = temp;
		head->prev = NULL;
	}
	return head;
}

Node* AddTail(Node*& tail, Node*& head, int val) 
{
	Node* temp = new Node;
	temp->data = val;
	if (tail == NULL)
	{
		head = temp;
		tail = temp;
		tail->next = NULL;
	}
	else
	{
		tail->next = temp;
		temp->prev = tail;
		tail = temp;
		temp->next = NULL;
	}
	return tail;
}

bool insert(Node*& head, Node*& tail, int pos, int val)
{
	if (pos == 1)
		AddHead(head, tail, val);

	else
	{
		Node* p = findPosHead(head, pos);

		if (p == NULL)
			return false;

		Node* temp = new Node;
		temp->data = val;
		temp->next = p;
		temp->prev = p->prev;
		p->prev->next = temp;
		p->prev = temp;
	}
	return true;
}

Node* removeHead(Node*& head)
{
	if (head == NULL)
		return 0;
	else
	{
		Node* temp = head;
		head = temp->next;
		if (head != NULL)
			head->prev = NULL;
		delete temp;
	}       
	return head;
}

Node* removeTail(Node*& tail)
{
	if (tail == NULL)
		return 0;
	else
	{
		Node* temp = tail;
		tail = temp->prev;
		tail->next = NULL;
		delete temp;
	}
	return tail;
}

void remove(Node*& head, Node*& tail, int pos)
{
	Node* p = findPosHead(head, pos);
	if (head == p)
	{
		removeHead(head);
		return;
	}

	if (tail == p)
	{
		removeTail(tail);
		return;
	}

	if (p)
	{
		p->prev->next = p->next;
		p->next->prev = p->prev;
		delete p;
	}
}

void removeAll(Node*& head)
{
	Node* temp = head;
	int count = 0;
	while (temp->next != NULL)
	{
		temp = temp->next;
		count++;
	}

	for (int i = 0; i <= count; i++)
		removeHead(head);
}

void outListHead(Node* head)
{
	Node* temp = head;
	while (temp != NULL) 
	{
		cout << setw(5) << temp->data << ' ';
		temp = temp->next;
	}
	cout << endl;
}

void outListTail(Node* tail)
{
	Node* temp = tail;
	while (temp != NULL) 
	{
		cout << setw(5) << temp->data << ' ';
		temp = temp->prev;           
	}
	cout << endl;
}

Node* findDataHead(Node* head, int val)
{
	Node* temp = head;
	int pos = 0;

	while (temp != NULL)
	{
		if (temp->data == val)
		{
			cout << " Элемент " << val << " находится в ячейке " << pos + 1 << ", считая с начала";
			return temp;
		}
		pos++;
		temp = temp->next;
	}
	return NULL;
}

Node* findPosHead(Node* head, int pos)
{
	Node* temp = head;
	while (temp != NULL && pos > 1)
	{
		temp = temp->next;
		pos--;
	}
	return temp;
}

Node* findDataTail(Node* tail, int val)
{
	Node* temp = tail;
	int pos = 0;

	while (temp != NULL)
	{
		if (temp->data == val)
		{
			cout << " Элемент " << val << " находится в ячейке " << pos + 1 << ", считая с конца";
			return temp;
		}
		pos++;
		temp = temp->prev;
	}
	return NULL;
}

Node* findPosTail(Node* tail, int pos)
{
	Node* temp = tail;
	while (temp != NULL && pos > 1)
	{
		temp = temp->prev;
		pos--;
	}
	return temp;
}

bool isEmpty(Node* head) 
{
	return head == NULL;
}

Node* retrieve(Node*& head, int pos)
{
	Node* p = findPosHead(head, pos);

	if (p == NULL)
		return head;
	else
		cout << p->data << endl;

	return head;
}


//Задание 2. Вариант С
Node* AddHead_(Node*& head_, Node*& tail_, int val)
{
	Node* temp = new Node;
	temp->data = val;
	if (head_ == NULL)
	{
		head_ = temp;
		tail_ = temp;
		tail_->next = NULL;
	}
	else
	{
		head_->prev = temp;
		temp->next = head_;
		head_ = temp;
		head_->prev = NULL;
	}
	return head_;
}

void outListHead_(Node* head_)
{
	Node* temp = head_;
	while (temp != NULL)
	{
		cout << setw(5) << temp->data << ' ';
		temp = temp->next;
	}
	cout << endl;
}

void Sort(Node*& head)
{
	Node* temp;
	int x;
	temp = head->next;
	while (temp) 
	{
		x = temp->data;
		Node* ptr = temp->prev;
		while (ptr != NULL && x < ptr->data)
		{
			ptr->next->data = ptr->data;
			ptr = ptr->prev;
		}
		if (ptr == NULL) 
			head->data = x;
		else 
			ptr->next->data = x;
		temp = temp->next;
	}
}

void Sort_(Node*& head_)
{
	Node* temp;
	int x;
	temp = head_->next;
	while (temp) 
	{
		x = temp->data;
		Node* ptr = temp->prev;
		while (ptr != NULL && x < ptr->data)
		{
			ptr->next->data = ptr->data;
			ptr = ptr->prev;
		}
		if (ptr == NULL) 
			head_->data = x;
		else 
			ptr->next->data = x;
		temp = temp->next;
	}
}

Node* merge(Node* head, Node* tail, Node* head_)
{
	Node* temp = tail;
	Node* p = findPosTail(tail, 0);
	p->next = head_;
	head_->prev = p;

	return head;
}