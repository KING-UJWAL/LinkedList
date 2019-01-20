#include <iostream>
#include <vector>
#include "TreeNode.hpp"

using namespace std;

template <class T>
class BinarySearchTree {
        private:
                Node<T> *_root;
                int _count;

        public:
                BinarySearchTree() {
                        _root = nullptr;
                        _count = 0;
                }

                void insert(T value) {
                        // if root is not present
                        if(_count == 0)  {
                                _root = new Node<T>(value);
                        } else {
                                InsertTo(_root, value);
                        }
                        _count++;
                }

                void insert(vector<T> v) {
                        for(auto t : v) {
                                insert(t);
                        }
                }

                Node<T>* find(T element) {
                        if(_count == 0) {
                                return nullptr;
                        }
                        Node<T> *parentNode;
                         return findWithParent(element, parentNode);
                }

                void remove(T element) {
                        Node<T> *parentNode;
                        Node<T> *currentNode = findWithParent(element, parentNode);

                        if( currentNode == nullptr) return;

                        _count--;
                        // Case 1: currentNode -> Right  === null
                        if(currentNode->Right == nullptr) {
                                // if currentNode is root
                                if( parentNode == nullptr ) {
                                        _root = currentNode->Left;
                                } else {
                                        if( currentNode->Value < parentNode->Value ) {
                                                parentNode->Left = currentNode->Left;
                                        } else {
                                                parentNode->Right = currentNode->Left;
                                        }
                                }
                        }
                        // Case 2: currentNode -> Right -> Left === null
                        else if(currentNode->Right->Left == nullptr) {
                                currentNode->Right->Left = currentNode->Left;
                                if( parentNode == nullptr ) {
                                        _root = currentNode->Right;
                                } else {
                                        // is left tree
                                        if( currentNode->Value < parentNode->Value ) {
                                                parentNode->Left = currentNode->Right;
                                        }
                                        // if right tree
                                        else {
                                                parentNode->Right = currentNode->Right;
                                        }
                                }
                        }
                        // Case 3: currentNode -> Right -> Left != null
                        else {
                                Node<T> *leftMost = currentNode->Right->Left;
                                Node<T> *leftMostParent = currentNode->Right;

                                while(leftMost->Left != nullptr) {
                                        leftMostParent = leftMost;
                                        leftMost = leftMost->Left;
                                }

                                leftMostParent->Left = leftMost->Right;

                                leftMost->Left = currentNode->Left;
                                leftMost->Right = currentNode->Right;

                                if(parentNode == nullptr) {
                                        _root = leftMost;
                                } else {
                                        if( currentNode->Value < parentNode->Value ) {
                                                parentNode->Left = leftMost;
                                        } else {
                                                parentNode->Right = leftMost;
                                        }
                                }
                        }

                }

                // In-order traversal
                void InOrder(Node<T> *node) {
                        if(node  != nullptr) {
                                // 1. traverse Left
                                InOrder(node->Left);
                                // 2. process
                                cout << node->Value << endl;
                                // 3. traverse Right
                                InOrder(node->Right);
                        }
                }

                // Pre-order traversal
                void PreOrder(Node<T> *node) {
                        if(node  != nullptr) {
                                // 1. process
                                cout << node->Value << endl;
                                // 2. traverse Left
                                PreOrder(node->Left);
                                // 3. traverse Right
                                PreOrder(node->Right);
                        }
                }

                void PostOrder(Node<T> *node) {
                        if(node  != nullptr) {
                                // 1. traverse Left
                                PostOrder(node->Left);
                                // 2. traverse Right
                                PostOrder(node->Right);
                                // 1. process
                                cout << node->Value << endl;
                        }
                }

                void Print() {
                        cout << "Printing in ascending order: " << endl;
                        InOrder(this->_root);
                }

        private:
                Node<T>* findWithParent(T element, Node<T> *&parentNode) {
                        Node<T>* currentNode = _root;
                        parentNode = nullptr;

                        if(currentNode == nullptr) {
                                return currentNode;
                        }

                        while(currentNode != nullptr) {
                                // if element is less than node value than look toward Left tree
                                if(element < currentNode->Value) {
                                        parentNode = currentNode;
                                        currentNode = currentNode->Left;
                                }
                                // if element is more than node value than look toward Right tree
                                else if (element > currentNode->Value) {
                                        parentNode = currentNode;
                                        currentNode = currentNode->Right;
                                }
                                // if found
                                else {
                                        break;
                                }
                        }
                        return currentNode;
                }

                void InsertTo(Node<T> *node, T value) {
                        // if value to be inserted is less than node value than
                        // should be added to left of the node
                        if(value < node->Value) {
                                if(node->Left == nullptr) {
                                        node->Left = new Node<T>(value);
                                } else {
                                        InsertTo(node->Left, value);
                                }
                        }
                        // if value to be inserted is greater than or equal to node value
                        // then should be added to right of the node
                        else {
                                if(node->Right == nullptr) {
                                        node->Right = new Node<T>(value);
                                } else {
                                        InsertTo(node->Right, value);
                                }
                        }
                }

};
