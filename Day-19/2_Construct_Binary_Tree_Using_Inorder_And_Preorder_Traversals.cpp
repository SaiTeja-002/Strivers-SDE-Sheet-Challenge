#include <bits/stdc++.h> 
/************************************************************

    Following is the TreeNode class structure

    template <typename T>
    class TreeNode {
       public:
        T data;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T data) {
            this->data = data;
            left = NULL;
            right = NULL;
        }
    };

************************************************************/
TreeNode<int>* buildTree(vector<int>& inorder, vector<int>& preorder, int& rootIndex, int left, int right)
{
    if(left > right)
        return NULL;
    
    int inorderIndex = left;
    while(inorder[inorderIndex] != preorder[rootIndex])
        inorderIndex++;

    TreeNode<int>* node = new TreeNode<int>(preorder[rootIndex]);
    rootIndex++;

    node->left = buildTree(inorder, preorder, rootIndex, left, inorderIndex-1);
    node->right = buildTree(inorder, preorder, rootIndex, inorderIndex+1, right);

    return node;
}

TreeNode<int> *buildBinaryTree(vector<int> &inorder, vector<int> &preorder)
{
	int rootIndex = 0;

    return buildTree(inorder, preorder, rootIndex, 0, preorder.size()-1);
}