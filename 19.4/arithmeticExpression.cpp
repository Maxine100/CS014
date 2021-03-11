#include <iostream>
#include <sstream>
#include <fstream>
#include <cstdlib>
#include <stack>
using namespace std;

#include "arithmeticExpression.h"

arithmeticExpression::arithmeticExpression(const string &ex) {
    infixExpression = ex;
    root = 0;
}

void arithmeticExpression::buildTree() {
    stack<TreeNode*> s;
    string postfixStr = infix_to_postfix();
    char c;
    char key = 'A';
    for (unsigned i = 0; i < postfixStr.size(); ++i) {
        c = postfixStr.at(i);
        TreeNode* newNode = new TreeNode(c, key);
        if (c == '+' || c == '-' || c == '*' || c == '/') {
            newNode->right = s.top();
            s.pop();
            newNode->left = s.top();
            s.pop();
            s.push(newNode);
        }
        else {
            s.push(newNode);
        }
        key = key + 1;
    }
    root = s.top();
}

void arithmeticExpression::infix() {
    infix(this->root);
}

void arithmeticExpression::prefix() {
    prefix(this->root);
}

void arithmeticExpression::postfix() {
    postfix(this->root);
}

void arithmeticExpression::visualizeTree(const string &outputFilename){
    ofstream outFS(outputFilename.c_str());
    if(!outFS.is_open()){
        cout<<"Error opening "<< outputFilename<<endl;
        return;
    }
    outFS<<"digraph G {"<<endl;
    visualizeTree(outFS,root);
    outFS<<"}";
    outFS.close();
    string jpgFilename = outputFilename.substr(0,outputFilename.size()-4)+".jpg";
    string command = "dot -Tjpg " + outputFilename + " -o " + jpgFilename;
    system(command.c_str());
}
    
int arithmeticExpression::priority(char op){
    int priority = 0;
    if(op == '('){
        priority =  3;
    }
    else if(op == '*' || op == '/'){
        priority = 2;
    }
    else if(op == '+' || op == '-'){
        priority = 1;
    }
    return priority;
}

string arithmeticExpression::infix_to_postfix(){
    stack<char> s;
    ostringstream oss;
    char c;
    for(unsigned i = 0; i< infixExpression.size();++i){
        c = infixExpression.at(i);
        if(c == ' '){
            continue;
        }
        if(c == '+' || c == '-' || c == '*' || c == '/' || c == '(' || c == ')'){ //c is an operator
            if( c == '('){
                s.push(c);
            }
            else if(c == ')'){
                while(s.top() != '('){
                    oss << s.top();
                    s.pop();
                }
                s.pop();
            }
            else{
                while(!s.empty() && priority(c) <= priority(s.top())){
                    if(s.top() == '('){
                        break;
                    }
                    oss << s.top();
                    s.pop();
                }
                s.push(c);
            }
        }
        else{ //c is an operand
            oss << c;
        }
    }
    while(!s.empty()){
        oss << s.top();
        s.pop();
    }
    return oss.str();
}

void arithmeticExpression::infix(TreeNode* node) {
    if (node == 0) {
        return;
    }
    else {
        if (node->data == '+' || node->data == '-' || node->data == '*' || node->data == '/') {
            cout << "(";
        }
        infix(node->left);
        cout << node->data;
        infix(node->right);
        if (node->data == '+' || node->data == '-' || node->data == '*' || node->data == '/') {
            cout << ")";
        }
    }
}

void arithmeticExpression::prefix(TreeNode* node) {
    if (node == 0) {
        return;
    }
    else {
        cout << node->data;
        prefix(node->left);
        prefix(node->right);
    }
}

void arithmeticExpression::postfix(TreeNode* node) {
    if (node == 0) {
        return;
    }
    else {
        postfix(node->left);
        postfix(node->right);
        cout << node->data;
    }
}

void arithmeticExpression::visualizeTree(ofstream &outFS, TreeNode* node) {
    TreeNode* curr = node;
    outFS << curr->key << "[label=\"" << curr->data << ", key=" << curr->key << "\"]" << endl;
    if (curr->left) {
        outFS << curr->key << " -> " << curr->left->key << endl;
        visualizeTree(outFS, curr->left);
    }
    if (curr->right) {
        outFS << curr->key << " -> " << curr->right->key << endl;
        visualizeTree(outFS, curr->right);
    }
}