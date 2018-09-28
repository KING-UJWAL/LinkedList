#include <iostream>
#include "Node.hpp"

using namespace std;

template <class T>
class LinkedList
{
private:
	Node<T> *head;

public:
	LinkedList()
	{
		head = NULL;
	}

	void insertFront(int data)
	{
		Node<T> *newNode = new Node<T>(data);
		newNode->next = head;
		head = newNode;
	}

	void deleteFront()
	{
		Node<T> *newHead = head->next;
		delete head;
		head = newHead;
	}

	void toString()
	{
		cout << "{";

		Node<T> *currentNode = head;

		while (currentNode)
		{
			currentNode->toString();
			cout << " ,";
			currentNode = currentNode->next;
		}

		cout << "}" << endl;
	}
};