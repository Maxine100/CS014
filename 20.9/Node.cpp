#include "Node.h"

#include <string>

using namespace std;

Node::Node() {
    item = "";
    balanceFactor = -1;
    rightChild = 0;
    leftChild = 0;
    parent = 0;
}

Node::Node(string item) {
    this->item = item;
    balanceFactor = -1;
    rightChild = 0;
    leftChild = 0;
    parent = 0;
}

Node* Node::getParent() {
    return parent;
}

void Node::setParent() {
    parent = 0;
}

void Node::setParent(Node* node) {
    parent = node;
}

string Node::getItem() {
    return item;
}

Node* Node::getRightChild() {
    return rightChild;
}

Node* Node::setRightChild(Node* newNode) {
    rightChild = newNode;
}

Node* Node::getLeftChild() {
    return leftChild;
}

Node* Node::setLeftChild(Node* newNode) {
    leftChild = newNode;
}