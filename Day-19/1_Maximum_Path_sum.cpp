#include <bits/stdc++.h> 
/************************************************************

    Following is the Tree node structure
	
	template <typename T>
    class TreeNode 
    {
        public : 
        T val;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T val) 
        {
            this -> val = val;
            left = NULL;
            right = NULL;
        }
    };

************************************************************/

long long int fun(TreeNode<int>* root, long long int& ans)
{
    if(!root)
        return 0;

    long long int left = fun(root->left, ans);
    long long int right = fun(root->right, ans);

    ans = max(ans, root->val+left+right);

    return (root->val + max(left, right));
}

long long int findMaxSumPath(TreeNode<int> *root)
{
    if(!root || !root->left || !root->right)
        return -1;

    long long int ans=0;

    fun(root, ans);

    return ans;
}