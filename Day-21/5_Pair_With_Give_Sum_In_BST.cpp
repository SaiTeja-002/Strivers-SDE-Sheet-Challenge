#include <bits/stdc++.h> 
/**********************************************************

    Following is the Binary Tree Node structure:

    template <typename T>
    class BinaryTreeNode {
        public: 
        T data;
        BinaryTreeNode<T> *left;
        BinaryTreeNode<T> *right;

        BinaryTreeNode(T data) {
            this->data = data;
            left = NULL;
            right = NULL;
        }

        ~BinaryTreeNode() {
            if (left)
                delete left;
            if (right)
                delete right;
        }
    };
***********************************************************/
bool traverse(BinaryTreeNode<int>* node, unordered_set<int>& st, int k)
{
    if(!node)
        return false;
    
    if(st.find(k-node->data) != st.end())
        return true;
    
    st.insert(node->data);

    return (traverse(node->left, st, k) || traverse(node->right, st, k));
}

bool pairSumBst(BinaryTreeNode<int> *root, int k)
{
    unordered_set<int> st;
    return traverse(root, st, k);
}