#include <iostream>
#include "Node.hpp"

using namespace std;

template <class T>
class Stack
{
	int count;
	Node<T> *top;

public:
	Stack()
	{
		count = 0;
		top = NULL;
	}

	void push(T data)
	{

		Node<T> *newNode = new Node<T>(data);
		newNode->next = top;
		top = newNode;

		count += 1;
	}

	T pop()
	{
		T returnVal = NULL;
		// If stack is empty
		if (isEmpty())
		{
			cout << "Stack is empty. Cannot be pulled." << endl;
			return returnVal;
		}
		else
		{
			returnVal = top->data;
			Node<T> *newTop = top->next;
			delete top;
			top = newTop;
		}
		count -= 1;
		return returnVal;
	}

	T peak()
	{
		if (isEmpty())
		{
			cout << "Stack is empty. Cannot be pulled." << endl;
		}

		return top->data;
	}

	int size()
	{
		return count;
	}

	bool isEmpty()
	{
		if (count == 0)
			return true;
		return false;
	}

	void toString()
	{
		cout << "{ ";

		Node<T> *temp = top;

		while (temp)
		{
			cout << temp->data << ", ";
			temp = temp->next;
		}

		cout << " }" << endl;
	}
};