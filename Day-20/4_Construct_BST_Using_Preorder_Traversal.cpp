#include <bits/stdc++.h> 
/*************************************************************

    Following is the Binary Tree node structure

    template <typename T>

    class TreeNode{
    public:
        T data;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T data) {
            this->data = data;
            left = NULL;
            right = NULL;
        }
        ~TreeNode() {
            if (left){
                delete left;
            }
            if (right){
                delete right;
            }
        }
    };

*************************************************************/
TreeNode<int>* buildTree(vector<int>& preorder, int& index, int minVal, int maxVal)
{
    if(index >= preorder.size() || preorder[index] < minVal || preorder[index] > maxVal)
        return NULL;

    TreeNode<int>* root = new TreeNode<int>(preorder[index]);
    index++;

    root->left = buildTree(preorder, index, minVal, root->data);
    root->right= buildTree(preorder, index, root->data, maxVal);

    return root;
}

TreeNode<int>* preOrderTree(vector<int> &preorder)
{
    int index=0;
    return buildTree(preorder, index, INT_MIN, INT_MAX);
}