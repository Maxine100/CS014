#include "Node.h"

using namespace std;

Node::Node() {
    small = "";
    large = "";
    left = 0;
    middle = 0;
    right = 0;
    parent = 0;
}

Node::Node(string s) {
    small = s;
    large = "";
    left = 0;
    middle = 0;
    right = 0;
    parent = 0;
}

void Node::setSmall(string s) {
    small = s;
}

void Node::setLarge(string s) {
    large = s;
}

string Node::getSmall() {
    return small;
}

string Node::getLarge() {
    return large;
}

void Node::setLeft(Node* node) {
    
}

void Node::setMiddle(Node* node) {
    
}

void Node::setRight(Node* node) {
    
}

Node* Node::getLeft() {
    return left;
}

Node* Node::getMiddle() {
    return middle;
}

Node* Node::getRight() {
    return right;
}

// Node* Node::findParent(Node* child) {
//     Node* curr = root;
//     Node* parent = 0;
    
//     // if only root
//     if (curr->getLeft() == 0) {
//     }
    
//     // if not only root
//     else {
//         // while children aren't child
//         while (curr->getLeft() != child && curr->getMiddle() != child && curr->getRight() != child) {
//             // if child's small is less than curr's small
//             if (child->getSmall() < curr->getSmall()) {
//                 curr = curr->getLeft();
//             }
//             // else if child's small is less than curr's large or curr large doesn't exist
//             else if (child->getSmall() < curr->getLarge() || curr->getLarge() == 0) {
//                 curr = curr->getMiddle();
//             }
//             // else
//             else {
//                 curr = curr->getRight();
//             }
//         }
//         parent = curr;
//     }
//     return parent;
// }

// void Node::setParent() {
//     this->parent = findParent();
// }

// Node* Node::getParent() {
//     return parent;
// }