#include <iostream>
#include <string>
#include <vector>
#include "Tree.hpp"

using namespace std;

int main() {
        BinarySearchTree<int> bst;

        vector<int> A = {1,2,3,4,56, 22, 23, 34};

        bst.insert(A);

        bst.Print();

        return 0;
}
