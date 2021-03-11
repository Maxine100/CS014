#include "Node.h"

using namespace std;

Node::Node() {
    phrase = "";
    counter = 0;
    right = 0;
    left = 0;
}

Node::Node(string phrase) {
    this->phrase = phrase;
    right = 0;
    left = 0;
    counter = 1;
}

Node* Node::getRight() {
    return this->right;
}

Node* Node::getLeft() {
    return this->left;
}

string Node::getPhrase() {
    return this->phrase;
}

int Node::getCounter() {
    return this->counter;
}

void Node::incrementCounter() {
    ++counter;
}

void Node::setLeft(Node* newNode) {
    left = newNode;
}

void Node::setRight(Node* newNode) {
    right = newNode;
}

void Node::decrementCounter() {
    --counter;
}