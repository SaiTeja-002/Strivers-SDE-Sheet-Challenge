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

class BSTiterator
{
    stack<TreeNode<int>*> st;

public:
    BSTiterator(TreeNode<int>* root)
    {
        while(root)
        {
            st.push(root);
            root = root->left;
        }
    }

    int next()
    {
        TreeNode<int>* top = st.top();
        st.pop();

        TreeNode<int>* temp = top->right;

        while(temp)
        {
            st.push(temp);
            temp = temp->left;
        }

        return top->data;
    }

    bool hasNext()
    {
        return (!st.empty());
    }
};


/*
    Your BSTIterator object will be instantiated and called as such:
    BSTIterator iterator(root);
    while(iterator.hasNext())
    {
       print(iterator.next());
    }
*/