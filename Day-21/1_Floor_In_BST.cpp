#include <bits/stdc++.h> 
/************************************************************

    Following is the TreeNode class structure

    template <typename T>
    class TreeNode {
       public:
        T val;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T val) {
            this->val = val;
            left = NULL;
            right = NULL;
        }
    };

************************************************************/

int floorInBST(TreeNode<int>* root, int target)
{
    int result = -1;

    while(root)
    {
        if(root->val == target)
            return target;
        else if(root->val < target)
        {
            result = root->val;
            root = root->right;
        }
        else
            root = root->left;
    }

    return result;
}