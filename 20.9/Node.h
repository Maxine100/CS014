#ifndef NODE_H
#define NODE_H

#include <string>

class Node {
    private:
        std::string item;
        int balanceFactor;
        Node* rightChild;
        Node* leftChild;
        Node* parent;
        
    public:
        Node();
        Node(item);
        std::string getItem();
        Node* getParent();
        void setParent();
        void setParent(Node* node);
        Node* getRightChild();
        void setRightChild(Node* newNode);
        Node* getLeftChild();
        void setLeftChild(Node* newNode);
};

#endif