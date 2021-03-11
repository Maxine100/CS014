#ifndef TREE_H
#define TREE_H

#include "Node.h"

class Tree {
    private:
        Node* root;
    
    public:
        Tree();
        ~Tree();
        void insert(const string& s);
        void preOrder() const;
        void inOrder() const;
        void postOrder() const;
        // void remove(const string& s);
        bool search(const string& s) const;
    
    private:
        void preOrder(Node* node) const;
        void inOrder(Node* node) const;
        void postOrder(Node* node) const;
};
#endif