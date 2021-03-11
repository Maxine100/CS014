#ifndef NODE_H
#define NODE_H

#include <string>

using namespace std;

class Node {
    friend class Tree;
    
    private:
        string small;
        string large;
        Node* left;
        Node* middle;
        Node* right;
        Node* parent;
    
    public:
        Node();
        Node(string s);
        void setSmall(string s);
        void setLarge(string s);
        string getSmall();
        string getLarge();
        void setLeft(Node* node);
        void setMiddle(Node* node);
        void setRight(Node* node);
        Node* getLeft();
        Node* getMiddle();
        Node* getRight();
        // Node* findParent(Node* child);
        // void setParent();
        // Node* getParent();
};
#endif