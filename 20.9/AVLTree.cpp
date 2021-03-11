#include "AVLTree.h"
#include "Node.h"

#include <iostream>

using namespace std;

AVLTree::AVLTree() {
    root = 0;
}
// Insert an item to the binary search tree and perform rotation if necessary.
void AVLTree::insert(const string& item) {
    Node* newNode = new Node(item);
    if (root == 0) {
        root = newNode;
        newNode->setParent();
        return;
    }
    Node* curr = root;
    while (curr != 0) {
        if (newNode->item < curr->item) {
            if (curr->getLeftChild() == 0) {
                curr->setLeftChild(newNode);
                newNode->setParent(curr);
                curr = 0;
            }
            else {
                curr = curr->getLeftChild();
            }
        }
        else {
            if (curr->getRightChild() == 0) {
                curr->setRightChild(newNode);
                newNode->setParent(curr);
                curr = 0;
            }
            else {
                curr = curr->getRightChild();
            }
        }
    }
    Node* node = newNode->getParent();
    while (node != 0) {
        
        node = node->getParent();
    }
}
// Return the balance factor of a given node.
int AVLTree::balanceFactor(Node* node) {
    
}
// Traverse and print the tree in inorder notation. Print the string followed by its balance factor in parentheses followed by a , and one space.
void AVLTree::printBalanceFactors() {
    
}
// Generate dotty file and visualize the tree using dotty program. Call this function before and after rotation.
void AVLTree::visualizeTree(const string& outputFilename) {
    ofstream outFS(outputFilename.c_str());
    if(!outFS.is_open()){
        cout<<"Error"<<endl;
        return;
    }
    outFS<<"digraph G {"<<endl;
    visualizeTree(outFS, root);
    outFS<<"}";
    outFS.close();
    string jpgFilename = outputFilename.substr(0,outputFilename.size()-4)+".jpg";
    string command = "dot -Tjpg " + outputFilename + " -o " + jpgFilename;
    system(command.c_str());
}

// Find and return the closest unbalanced node (with balance factor of 2 or -2) to the inserted node.
Node* AVLTree::findUnbalancedNode() {
    
}
// Implement four possible imbalance cases and update the parent of the given node.
void AVLTree::rotate() {
    
}
// Rotate the subtree to left at the given node and returns the new subroot.
void AVLTree::rotateLeft() {
    
}
// Rotate the subtree to right at the given node and returns the new subroot.
void AVLTree::rotateRight() {
    
}

void AVLTree::printBalanceFactors(Node* node) {
    
}

void AVLTree::visualizeTree(ofstream& outFS, Node* node) {
    if (node) {
        if (node->left) {
            visualizeTree(outFS, node->left);
            outFS << node->data << " -> " << node->left->data << ";" << endl;
        }
        if (node->right) {
            visualizeTree(outFS, node->right);
            outFS << node->data << " -> " << node->right->data << ";" << endl;
        }
    }
}