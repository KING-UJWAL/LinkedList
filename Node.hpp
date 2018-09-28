#include <iostream>

using namespace std;

template <class T>
class Node
{
public:
	T data;
	Node *next;

	Node()
	{
		next = NULL;
	}

	Node(T data)
	{
		this->data = data;
		next = NULL;
	}

	void toString()
	{
		cout << "Data: " << this->data;
	}
};