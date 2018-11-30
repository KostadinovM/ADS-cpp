#include <iostream>
#include <cstdlib>

using namespace std;

class Queue
{
	int *arr;
	int capacity;
	int front;
	int rear;
	int count;

public:
	Queue(int size);
	void enqueue(int val);
	void dequeue();
	int peek();
	int size();
	bool isEmpty();
	bool isFull();
};

Queue::Queue(int size)
{
	arr = new int[size];
	capacity = size;
	front = 0;
	rear = 0;
	count = 0;
}

void Queue::enqueue(int val)
{
	if (isFull())
	{
		cout << "QUEUE IS FULL!" << endl;
	}
	else
	{
		rear = (rear + 1) % capacity;
		arr[rear] = val;
		count++;
	}

}

void Queue::dequeue()
{
	if (isEmpty())
	{
		cout << "QUEUE IS EMPTY!" << endl;
	}
	else
	{
		
		front = (front + 1) % capacity;
		count--;
	}
}

int Queue::peek()
{
	return arr[front];
}

bool Queue::isEmpty()
{
	return (count == 0);
}

bool Queue::isFull()
{
	return (count == capacity);
}

int Queue::size()
{
	return count;
}

int main()
{
	// create a queue of capacity 5
	Queue q(5);

	q.enqueue(1);
	q.enqueue(2);
	q.enqueue(3);

	cout << "Front element is: " << q.peek() << endl;
	q.dequeue();
	cout << "Front element is: " << q.peek() << endl;

	q.enqueue(4);

	cout << "Queue size is " << q.size() << endl;

	q.dequeue();
	q.dequeue();
	q.dequeue();
	//q.enqueue(5);

	if (q.isEmpty())
		cout << "Queue Is Empty\n";
	else
		cout << "Queue Is Not Empty\n";

	return 0;
}