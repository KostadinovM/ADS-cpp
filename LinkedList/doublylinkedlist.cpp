struct node
{
	int data;
	node *next;
	node *previous;
};

class DoublyLinkedList
{
private:
	node *head, *tail;
public:
	DoublyLinkedList();
	void insert_first(int val);
	void insert_last(int val);
	void insert_position(int val, int pos);

	void delete_first();
	void delete_last();
	void delete_position(int pos);
};

DoublyLinkedList::DoublyLinkedList()
{
	head = nullptr;
	tail = nullptr;
}

void DoublyLinkedList::insert_first(int val)
{
	node *temp = new node;
	temp->data = val;
	temp->next = head;
	temp->previous = head->previous;
	head->previous = temp;
	head = temp;
}

void DoublyLinkedList::insert_last(int val)
{
	node *temp = new node;
	temp->data = val;
	node *current = new node;
	current = head;
	while (current->next!=nullptr)
	{
		current = current->next;
	}
	temp->next = current->next;
	temp->previous = current;
	current->next = temp;
	head->previous = temp;
	tail = temp;
}

void DoublyLinkedList::insert_position(int val, int pos)
{
	node *temp = new node;
	temp->data = val;
	node *current = new node;
	current = head;
	for (int i = 0; i < pos; i++)
	{
		current = current->next;
	}
	temp->next = current;
	temp->previous = current->previous;
	current->previous = temp;
	current->previous->next = temp;
}

void DoublyLinkedList::delete_first()
{
	node *temp = new node;
	temp = head;
	temp->next->previous = head->previous;

	head = head->next;
	tail->previous = head;
	delete temp;
}

void DoublyLinkedList::delete_last()
{
	node *temp = new node;
	temp = tail;
	temp->previous->next = head;
	tail = temp->previous->next;
	tail->previous = head;
	delete temp;
}

void DoublyLinkedList::delete_position(int pos)
{
	node *temp = new node;
	node *current = new node;
	current = head;
	for (int i = 0; i < pos; i++)
	{
		current = current->next;
	}
	node *previous = new node;
	previous = current->previous;
	previous->next = current->next;
	current->next->previous = previous;
	delete current;
}