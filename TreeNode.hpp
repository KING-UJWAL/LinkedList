#include <iostream>

using namespace std;

template <class T>
class Node {
        public:
                Node *Left;
                Node *Right;
                T Value;

                Node(T _value) {
                        Value = _value;
                        Left = nullptr;
                        Right = nullptr;
                }
};