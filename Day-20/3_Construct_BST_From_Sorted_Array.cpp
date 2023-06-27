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

TreeNode<int>* build(vector<int>& nums, int left, int right)
{
    if(left > right)
        return NULL;
    
    int mid = (left+right)/2;

    TreeNode<int>* root = new TreeNode<int>(nums[mid]);
    root->left = build(nums, left, mid-1);
    root->right = build(nums, mid+1, right);

    return root;
}

TreeNode<int>* sortedArrToBST(vector<int> &nums, int n)
{
    return build(nums, 0, n-1);
}