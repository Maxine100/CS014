#include "BSTree.h"

#include <iostream>
#include <string>

using namespace std;

BSTree::BSTree() {
    root = 0;
}

void BSTree::insert(const string& phrase) {
    Node* newNode = new Node(phrase);
    if (root == 0) {
        root = newNode;
    }
    else {
        Node* curr = root;
        bool duplicate = false;
        
        while (!duplicate && curr != 0) {
            if (curr->getPhrase() > phrase) {
                curr = curr->getLeft();
                if (curr != 0) {
                }
            }
            else if (curr->getPhrase() < phrase) {
                curr = curr->getRight();
                if (curr != 0) {
                }
            }
            else if (curr->getPhrase() == phrase) {
                curr->incrementCounter();
                duplicate = true;
            }
        }
        curr = root;
        if (!duplicate) {
            while (curr != 0) {
                if (phrase < curr->getPhrase()) {
                    if (curr->getLeft() == 0) {
                        curr->setLeft(newNode);
                        curr = 0;
                    }
                    else {
                        curr = curr->getLeft();
                    }
                }
                else {
                    if (curr->getRight() == 0) {
                        curr->setRight(newNode);
                        curr = 0;
                    }
                    else {
                        curr = curr->getRight();
                    }
                }
            }
        }
    }
}

bool BSTree::search(const string& phrase) const {
    Node* curr = root;
    bool found = false;
    while (curr != 0 && !found) {
        if (curr->getPhrase() > phrase) {
            curr = curr->getLeft();
        }
        else if (curr->getPhrase() < phrase) {
            curr = curr->getRight();
        }
        else if (curr->getPhrase() == phrase) {
            found = true;
        }
    }
    if (found) {
        return true;
    }
    else {
        return false;
    }
}

void BSTree::inOrder() const {
    inOrder(root);
}

void BSTree::postOrder() const {
    postOrder(root);
}

void BSTree::preOrder() const {
    preOrder(root);
}

string BSTree::largest() const {
    Node* curr = root;
    if (root == 0) {
        return "";
    }
    else {
        while (curr->getRight() != 0) {
            curr = curr->getRight();
        }
    }
    return curr->getPhrase();
}

string BSTree::smallest() const {
    Node* curr = root;
    if (root == 0) {
        return "";
    }
    else {
        while (curr->getLeft() != 0) {
            curr = curr->getLeft();
        }
    }
    return curr->getPhrase();
}

int BSTree::height(const string& phrase) const {
    
    if (search(phrase)) {
        Node* curr = root;
        while (curr->getPhrase() != phrase) {
            if (phrase > curr->getPhrase()) {
                curr = curr->getRight();
            }
            else if (phrase < curr->getPhrase()) {
                curr = curr->getLeft();
            }
            // else if node is found
            else {
            }
        }
        return findHeight(curr);
    }
    return -1;
}

void BSTree::remove(const string& phrase) {
    Node* curr = root;
    Node* temp = 0;
    bool removed = false;
    
    // increment through tree to find node to delete
    while (curr != 0) {
        if (phrase > curr->getPhrase()) {
            curr = curr->getRight();
        }
        else if (phrase < curr->getPhrase()) {
            curr = curr->getLeft();
        }
        // else if node is found
        else {
            // if counter > 1
            if (curr->getCounter() > 1) {
                curr->decrementCounter();
                removed = true;
            }
            // else make temp point to curr
            else {
                temp = curr;
            }
            curr = 0;
        }
    }
    
    // if node is found and counter is 1
    if (temp != 0 && !removed) {
        curr = root;
        Node* parentOfTemp = 0;
        Node* succ = 0;
        Node* parentOfSucc = 0;
        
        // if temp isn't tree's root, get temp's parent
        if (temp != root) {
            while (curr->getLeft() != temp && curr->getRight() != temp) {
                if (phrase < curr->getPhrase()) {
                    curr = curr->getLeft();
                }
                else {
                    curr = curr->getRight();
                }
            }
            parentOfTemp = curr;
        }
        
        // if temp is a leaf
        if (temp->getLeft() == 0 && temp->getRight() == 0) {
            // if temp is root
            if (temp == root) {
                root = 0;
                delete temp;
            }
            // else if temp isn't root
            else {
                // if temp is left child of parent
                if (parentOfTemp->getLeft() == temp) {
                    parentOfTemp->setLeft(0);
                }
                // else if temp is right child of parent
                else {
                    parentOfTemp->setRight(0);
                }
                delete temp;
            }
        }
        // else if temp isn't a leaf
        else {
            // find successor node
            succ = temp;
            // if temp has a left subtree, go left
            if (temp->getLeft() != 0) {
                succ = succ->getLeft();
                // go right until you can't anymore
                while (succ->getRight() != 0) {
                    succ = succ->getRight();
                }
            }
            // else if temp doesn't have a left subtree, go right
            else {
                succ = succ->getRight();
                // go left until you can't anymore
                while (succ->getLeft() != 0) {
                    succ = succ->getLeft();
                }
            }
            
            curr = root;
            
            // find succ's parent
            while (curr->getLeft() != succ && curr->getRight() != succ) {
                if (succ->getPhrase() < curr->getPhrase()) {
                    curr = curr->getLeft();
                }
                else {
                    curr = curr->getRight();
                }
            }
            parentOfSucc = curr;
            curr = root;
            
            // if temp is root
            if (parentOfTemp == 0) {
                // if succ is a child of root
                if (temp->getLeft() == succ || temp->getRight() == succ) {
                    // if succ is root's left child
                    if (temp->getLeft() == succ) {
                        succ->setRight(temp->getRight());
                        temp->setRight(0);
                        temp->setLeft(0);
                        root = succ;
                        delete temp;
                    }
                    // else if succ is root's right child
                    else {
                        temp->setRight(0);
                        root = succ;
                        delete temp;
                    }
                }
                // else if succ isn't a child of root
                else {
                    // if succ is a leaf
                    if (succ->getLeft() == 0 && succ->getRight() == 0) {
                        succ->setLeft(temp->getLeft());
                        succ->setRight(temp->getRight());
                        temp->setLeft(0);
                        temp->setRight(0);
                        delete temp;
                        root = succ;
                        // if succ is a right child
                        if (parentOfSucc->getRight() == succ) {
                            parentOfSucc->setRight(0);
                        }
                        // else if succ is a left child
                        else {
                            parentOfSucc->setLeft(0);
                        }
                    }
                    // else if succ isn't a leaf
                    else {
                        // if succ's right child is null
                        if (succ->getRight() == 0) {
                            parentOfSucc->setRight(succ->getLeft());
                            succ->setRight(temp->getRight());
                            succ->setLeft(temp->getLeft());
                            temp->setRight(0);
                            temp->setLeft(0);
                            delete temp;
                            root = succ;
                        }
                        // else if succ's left child is null
                        else {
                            parentOfSucc->setLeft(succ->getRight());
                            succ->setRight(temp->getRight());
                            succ->setLeft(temp->getLeft());
                            temp->setRight(0);
                            temp->setLeft(0);
                            delete temp;
                            root = succ;
                        }
                    }
                }
            }
            // else if temp isn't root
            else {
                // if succ is a child of temp
                if (temp->getLeft() == succ || temp->getRight() == succ) {
                    // if succ is right child of temp
                    if (temp->getRight() == succ) {
                        // if temp is right child of its parent
                        if (parentOfTemp->getRight() == temp) {
                            parentOfTemp->setRight(succ);
                        }
                        // else if temp is left child of its parent
                        else {
                            parentOfTemp->setLeft(succ);
                        }
                        temp->setRight(0);
                        delete temp;
                    }
                    // else if succ is left child of temp
                    else {
                        // if temp is right child of its parent
                        if (parentOfTemp->getRight() == temp) {
                            parentOfTemp->setRight(succ);
                        }
                        // else if temp is left child of its parent
                        else {
                            parentOfTemp->setLeft(succ);
                        }
                        succ->setRight(temp->getRight());
                        temp->setLeft(0);
                        temp->setRight(0);
                        delete temp;
                    }
                }
                // else if succ isn't child of temp
                else {
                    // if temp is a right child
                    if (parentOfTemp->getRight() == temp) {
                        // if succ is a leaf
                        if (succ->getLeft() == 0 && succ->getRight() == 0) {
                            succ->setLeft(temp->getLeft());
                            succ->setRight(temp->getRight());
                            parentOfTemp->setRight(succ);
                            // if succ is a left child
                            if (parentOfSucc->getLeft() == succ) {
                                parentOfSucc->setLeft(0);
                            }
                            // else if succ is a right child
                            else {
                                parentOfSucc->setRight(0);
                            }
                            temp->setRight(0);
                            temp->setLeft(0);
                            delete temp;
                        }
                        // else if succ isn't a leaf
                        else {
                            // if succ's right child is null
                            if (succ->getRight() == 0) {
                                parentOfSucc->setRight(succ->getLeft());
                            }
                            // else if succ's left child is null
                            else {
                                parentOfSucc->setLeft(succ->getRight());
                            }
                            succ->setLeft(temp->getLeft());
                            succ->setRight(temp->getRight());
                            temp->setLeft(0);
                            temp->setRight(0);
                            delete temp;
                            parentOfTemp->setRight(succ);
                        }
                    }
                    // else if temp is a left child
                    else {
                        // if succ is a leaf
                        if (succ->getLeft() == 0 && succ->getRight() == 0) {
                            succ->setLeft(temp->getLeft());
                            succ->setRight(temp->getRight());
                            parentOfTemp->setLeft(succ);
                            // if succ is a left child
                            if (parentOfSucc->getLeft() == succ) {
                                parentOfSucc->setLeft(0);
                            }
                            else {
                                parentOfSucc->setRight(0);
                            }
                            temp->setRight(0);
                            temp->setLeft(0);
                            delete temp;
                        }
                        // else if succ isn't a leaf
                        else {
                            // if succ's right child is null
                            if (succ->getRight() == 0) {
                                parentOfSucc->setRight(succ->getLeft());
                            }
                            // else if succ's left child is null
                            else {
                                parentOfSucc->setLeft(succ->getRight());
                            }
                            succ->setLeft(temp->getLeft());
                            succ->setRight(temp->getRight());
                            temp->setLeft(0);
                            temp->setRight(0);
                            delete temp;
                            parentOfTemp->setLeft(succ);
                        }
                    }
                }
            }
        }
    }
}

Node* BSTree::getRoot() {
    return root;
}

void BSTree::deleteRoot() {
    delete root;
}

void BSTree::setRoot(Node* node) {
    root = node;
}



void BSTree::inOrder(Node* node) const {
    if (node == 0) {
        return;
    }
    else {
        inOrder(node->getLeft());
        cout << node->getPhrase() << "(" << node->getCounter() << "), ";
        inOrder(node->getRight());
    }
}

void BSTree::postOrder(Node* node) const {
    if (node == 0) {
        return;
    }
    else {
        postOrder(node->getLeft());
        postOrder(node->getRight());
        cout << node->getPhrase() << "(" << node->getCounter() << "), ";
    }
}

void BSTree::preOrder(Node* node) const {
    if (node == 0) {
        return;
    }
    else {
        cout << node->getPhrase() << "(" << node->getCounter() << "), ";
        preOrder(node->getLeft());
        preOrder(node->getRight());
    }
}

int BSTree::findHeight(Node* subtreeRoot) const {
    if (subtreeRoot == 0) {
        return -1;
    }
    
    int lefth = findHeight(subtreeRoot->getLeft());
    int righth = findHeight(subtreeRoot->getRight());
    
    if (lefth > righth) {
        return lefth + 1;
    }
    else {
        return righth + 1;
    }
}