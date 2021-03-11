#ifndef NODE_H
#define NODE_H

#include <string>

class Node {
    private:
        std::string phrase;
        int counter;
        Node* right;
        Node* left;
    
    public:
        Node();
        Node(std::string phrase);
        Node* getRight();
        Node* getLeft();
        std::string getPhrase();
        int getCounter();
        void incrementCounter();
        void setLeft(Node* newNode);
        void setRight(Node* newNode);
        void decrementCounter();
};

#endif