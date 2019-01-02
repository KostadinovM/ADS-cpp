#include <iostream>
#include <cstdlib>

struct node
{
	int data;
	node *next;
};

class LinkedList
{
private:
	node *head, *tail;
public:
	LinkedList();
	void insert_last(int val);
	void insert_first(int val);
	void insert_position(int val, int pos);
	void delete_last();
	void delete_first();
	void delete_position(int pos);
	void reverse_list();
};

LinkedList::LinkedList()
{
	head = nullptr;
	tail = nullptr;
}

void LinkedList::insert_first(int val)
{
	node *temp = new node;
	temp->data = val;
	temp->next = head;
	head = temp;		
}

void LinkedList::insert_last(int val)
{
	node *temp = new node;
	temp->data = val;
	temp->next = NULL;
	tail->next = temp;
	tail = temp;
}

void LinkedList::insert_position(int val, int pos)
{
	node *temp = new node;
	node *current = new node;
	node *previous = new node;
	current = head;
	for (int i = 0; i < pos; i++)
	{
		previous = current;
		current = current->next;
	}
	temp->data = val;
	previous->next = temp;
	temp->next = current;
	
}

void LinkedList::delete_last()
{
	node *previous = new node;
	node *current = new node;
	current = head;
	while (current->next != nullptr)
	{
		previous = current;
		current = current->next;
	}
	tail = previous;
	previous->next = nullptr;
	delete current;
}

void LinkedList::delete_first()
{
	node *temp = new node;
	temp = head;
	head = head->next;
	delete temp;
}

void LinkedList::delete_position(int pos)
{
	node *previous = new node;
	node *current = new node;
	current = head;
	for (int i = 0; i < pos; i++)
	{
		previous = current;
		current = current->next;
	}
	previous->next = current->next;
	delete current;
}

void LinkedList::reverse_list()
{
	node *current = head;
	node *previous = nullptr;
	node *next = nullptr;

	while (current != nullptr)
	{
		next = current->next;
		current->next = previous;
		previous = current;
		current = next;
	}
	head = previous;
}
