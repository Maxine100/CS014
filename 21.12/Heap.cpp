#include "Heap.h"

Heap::Heap() {
    numItems  = 0;
}

void Heap::enqueue(PrintJob* pj) {
    if (numItems = 0) {
        arr[0] = pj;
    }
    else {
        arr[numItems] = pj;
    }
    ++numItems;
}

void Heap::dequeue() {
    
}

PrintJob* Heap::highest() {
    
}

void Heap::print()  {
    
}

void Heap::trickleDown(int a) {
    
}