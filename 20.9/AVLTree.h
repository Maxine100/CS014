#ifndef AVLTREE_H
#define AVLTREE_H

#include "Node.h"

#include <string>

class AVLTree {
    private:
        Node* root;
        
    public:
        AVLTree();
        void insert(const std::string& item);
        int balanceFactor(Node* node);
        void printBalanceFactors();
        void visualizeTree(const std::string& outputFilename);
    
    private:
        Node* findUnbalancedNode();
        void rotate();
        void rotateLeft();
        void rotateRight();
        void printBalanceFactors(Node* node);
        void visualizeTree(ofstream& item, Node* node);
};

#endif