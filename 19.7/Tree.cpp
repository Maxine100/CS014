#include "Tree.h"
#include "Node.h"

#include <iostream>

using namespace std;

Tree::Tree() {
   root = 0; 
}

Tree::~Tree() {
    
}

void Tree::insert(const string& s) {
    // if no tree yet
    if (root == 0) {
        Node* newNode = new Node(s);
        root = newNode;
    }
    
    // else if there is a tree
    else {
        Node* curr = root;
        
        // find appropriate spot for string
        while (curr->getLeft() != 0) {
            if (s < curr->getSmall()) {
                curr = curr->getLeft();
            }
            else if (s < curr->getLarge()) {
                curr = curr->getMiddle();
            }
            else {
                curr = curr->getRight();
            }
        }
        
        // if curr node only has small
        if (curr->getLarge() == "") {
            // if new string is smaller than curr's small
            if (s < curr->getSmall()) {
                curr->setLarge(curr->getSmall());
                curr->setSmall(s);
            }
            // else if new string is bigger than curr's small
            else {
                curr->setLarge(s);
            }
        }
        
        // else if curr has 2 keys
        else {
            Node* nodeParent = curr->getParent();
            Node* splitLeft = new Node();
            Node* splitRight = new Node();
            string toBeMoved = "";
            
            // if string is less than small
            if (s < curr->getSmall()) {
                splitLeft->setSmall(s);
                splitRight->setSmall(curr->getLarge());
                toBeMoved = curr->getSmall();
                
            }
            
            // else if string is less than large
            else if (s < curr->getLarge()) {
                splitLeft->setSmall(curr->getSmall());
                splitRight->setSmall(curr->getLarge());
                toBeMoved = s;
            }
            
            // else
            else {
                splitLeft->setSmall(curr->getSmall());
                splitRight->setSmall(s);
                toBeMoved = curr->getLarge();
            }
            insert(toBeMoved);
        }
    }
}

void Tree::preOrder() const {
    preOrder(root);
}

void Tree::inOrder() const {
    inOrder(root);
}

void Tree::postOrder() const {
    postOrder(root);
}

// void Tree::remove(const string& s) {
    
// }

bool Tree::search(const string& s) const {
    Node* curr = root;
    while (curr != 0) {
        if (curr->getSmall() != s && curr->getLarge() != s) {
            if (s < curr->getSmall()) {
                curr = curr->getLeft();
            }
            else if (s < curr->getLarge() || curr->getLarge() == 0) {
                curr = curr->getMiddle();
            }
            else {
                curr = curr->getRight();
            }
        }
        else {
            return true;
        }
    }
    return false;
}

void Tree::preOrder(Node* node) const {
    if (node == 0) {
        return;
    }
    if (node->getSmall() != "") {
        cout << node->getSmall() << ", ";
    }
    preOrder(node->getLeft());
    if (node->getLarge() != "") {
        cout << node->getLarge() << ", ";
    }
    preOrder(node->getMiddle());
    preOrder(node->getRight());
}

void Tree::inOrder(Node* node) const {
    if (node == 0) {
        return;
    }
    inOrder(node->getLeft());
    if (node->getSmall() != "") {
        cout << node->getSmall() << ", ";
    }
    inOrder(node->getMiddle());
    if (node->getLarge() != "") {
        cout << node->getLarge() << ", ";
    }
    inOrder(node->getRight());
}

void Tree::postOrder(Node* node) const {
    if (node == 0) {
        return;
    }
    postOrder(node->getLeft());
    postOrder(node->getMiddle());
    if (node->getSmall() != "") {
        cout << node->getSmall() << ", ";
    }
    postOrder(node->getRight());
    if (node->getLarge() != "") {
        cout << node->getLarge() << ", ";
    }
}