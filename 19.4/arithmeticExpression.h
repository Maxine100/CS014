#ifndef ARITHMETICEXPRESSION_H
#define ARITHMETICEXPRESSION_H
#include <iostream>
#include <cstdlib>

using namespace std;
struct TreeNode{
    char data;
    char key;
    TreeNode* left;
    TreeNode* right;
    TreeNode(char data, char key):data(data),key(key),left(0),right(0){}
};

class arithmeticExpression{
  private:
    string infixExpression;
    TreeNode* root;

  public:
    arithmeticExpression(const string &ex);
    
    void buildTree();
    
    void infix();
    
    void prefix();
    
    void postfix();
    
    void visualizeTree(const string & filename);

 private:
 
    int priority(char op);
    
    string infix_to_postfix();
    
    void infix(TreeNode *node);
    
    void prefix(TreeNode *node);
    
    void postfix(TreeNode *node);
    
    void visualizeTree(ofstream &name, TreeNode *node);
};
#endif