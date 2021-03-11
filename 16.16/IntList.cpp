#include "IntList.h"

#include <iostream>

using namespace std;

IntList::IntList() {
    dummyHead = 0;
    dummyTail = 0;
}

IntList::~IntList() {
    
}

void IntList::push_front(int value) {
    IntNode* temp = new IntNode(value);
    if (dummyHead == 0 && dummyTail == 0) {
        dummyHead = temp;
        dummyTail = temp;
    }
    else {
        temp->next = dummyHead;
        dummyHead->prev = temp;
        dummyHead = temp;
    }
}

void IntList::pop_front() {
    if (dummyHead == dummyTail && dummyHead != 0) {
        IntNode* currObj = dummyHead;
        delete currObj;
        dummyHead = 0;
        dummyTail = 0;
    }
    else {
        IntNode* currObj = dummyHead;
        dummyHead = currObj->next;
        dummyHead->prev = 0;
        delete currObj;
    }
}

void IntList::push_back(int value) {
    IntNode* temp = new IntNode(value);
    if (dummyHead == 0 && dummyTail == 0) {
        dummyHead = temp;
        dummyTail = temp;
    }
    else {
        dummyTail->next = temp;
        temp->prev = dummyTail;
        dummyTail = temp;
    }
}

void IntList::pop_back() {
    if (dummyHead == dummyTail && dummyHead != 0) {
        IntNode* currObj = dummyHead;
        delete currObj;
        dummyHead = 0;
        dummyTail = 0;
    }
    else {
        IntNode* currObj = dummyTail;
        dummyTail = currObj->prev;
        dummyTail->next = 0;
        delete currObj;
    }
}

bool IntList::empty() const {
    if (dummyHead == 0 && dummyTail == 0) {
        return true;
    }
    return false;
}

ostream& operator<<(ostream& out, const IntList& rhs) {
    IntNode* currObj = rhs.dummyHead;
    while (currObj != 0) {
        out << currObj->data;
        if (currObj != rhs.dummyTail) {
            out << " ";
        }
        currObj = currObj->next;
    }
    return out;
}

void IntList::printReverse() const {
    IntNode* currObj = dummyTail;
    while (currObj != 0) {
        cout << currObj->data;
        if (currObj != dummyHead) {
            cout << " ";
        }
        currObj = currObj->prev;
    }
}