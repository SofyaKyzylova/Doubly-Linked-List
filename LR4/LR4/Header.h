#pragma once
struct Node;

Node* AddHead(Node*& head, Node*& tail, int val);
Node* AddTail(Node*& tail, Node*& head, int val);

bool insert(Node*& head, Node*& tail, int pos, int val);

Node* removeHead(Node*& head);
Node* removeTail(Node*& tail);
void remove(Node*& head, Node*& tail, int pos);
void removeAll(Node*& head);

void outListHead(Node* head);
void outListTail(Node* tail);

Node* findDataHead(Node* head, int val);
Node* findPosHead(Node* head, int pos);
Node* findDataTail(Node* tail, int val);
Node* findPosTail(Node* tail, int pos);

bool isEmpty(Node* head);

Node* retrieve(Node*& head, int pos);

//Задание 2. Вариант С
Node* AddHead_(Node*& head_, Node*& tail_, int val);
void outListHead_(Node* head_);
void Sort(Node*& head);
void Sort_(Node*& head_);
Node* merge(Node* head, Node* tail, Node* head_);