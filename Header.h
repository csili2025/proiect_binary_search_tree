#pragma once

#include <string>
#include <vector>
using namespace std;

struct TreeNode
{
    string data;
   
    TreeNode* left;
    TreeNode* right;
  
    TreeNode(const string& word) : data(word), left(nullptr), right(nullptr) {}
};

class BinarySearchTree
{
private:
    TreeNode* root;

    TreeNode* buildTree(vector<TreeNode*>& sortedWords, int start, int end);
    void printInOrder(TreeNode* node);
    void printPostOrder(TreeNode* node);

public:
    BinarySearchTree();
    ~BinarySearchTree();  
    void BinarySearchTreeDelet();    
    void deleteTree(TreeNode*);
    bool deleteWord(const string&);

    TreeNode* getutod(TreeNode* node);
  
    void buildTreeFromSortedWords(vector<TreeNode*>& sortedWords);
    void printTree();
    void printTree2();
 
    void buildTreeFromFile(const string&);

    TreeNode* insertWordRecursive(TreeNode*, const string&);
    void insertWord(const string&);


    TreeNode* deleteWordRecursive(TreeNode*, const string&);
    TreeNode* getMin(TreeNode*);

    bool searchWord(TreeNode*, const string&);
    void jatekpanel();
    TreeNode*searchByIndex(TreeNode*, int& , int);
    TreeNode* searchByIndex(int targetIndex);
    int PrintWord(string word, string letter);
    void Design(int hibak);
};
