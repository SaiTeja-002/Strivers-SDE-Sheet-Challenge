#include <bits/stdc++.h> 
/************************************************************

    Following is the Binary Tree node structure
    
    template <typename T>
    class TreeNode {
        public :
        T data;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }

        ~TreeNode() {
            if(left)
                delete left;
            if(right)
                delete right;
        }
    };

************************************************************/

class info
{
    public: 
        int maxi;
        int mini;
        bool isBST;
        int size;
};

info solve(TreeNode<int>* root, int &ans)
{
    if(!root)
    {
        return {INT_MIN, INT_MAX, true, 0};
    }

    info left = solve(root->left, ans);
    info right= solve(root->right, ans);

    info cur;

    cur.size = left.size + right.size + 1;
    cur.maxi = max(root->data, right.maxi);
    cur.mini = min(root->data, left.mini);

    if(left.isBST && right.isBST && (root->data > left.maxi && root->data < right.mini))
        cur.isBST=true;
    else
        cur.isBST=false;

    if(cur.isBST)
        ans = max(ans, cur.size);

    return cur;
}

int largestBST(TreeNode<int>* root) 
{
    int maxSize = 0;
    info temp = solve(root, maxSize);
    
    return maxSize;
}
