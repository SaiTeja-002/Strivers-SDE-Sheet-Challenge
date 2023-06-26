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

int lowestCommonAncestor(TreeNode<int> *root, int p, int q)
{
	if(!root)
        return -1;

    if(root->data == p || root->data == q)
        return root->data;

    int p1 = lowestCommonAncestor(root->left, p, q);
    int p2 = lowestCommonAncestor(root->right, p, q);

    if(p1 != -1 && p2 != -1)
        return root->data;

    if(p1 != -1)
        return p1;
    return p2;
}