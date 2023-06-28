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

void traverse(TreeNode<int> *node, int &ans, int &k)
{
    if(!node || k == 0)
        return;

    traverse(node->left, ans, k);

    if(--k == 0)
    {
        ans = node->data;
        return;
    }

    traverse(node->right, ans, k);
}

int kthSmallest(TreeNode<int> *root, int k)
{
    int ans = 0;
    traverse(root, ans, k);

    return ans;
}