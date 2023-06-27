#include <bits/stdc++.h> 
/************************************************************

    Following is the Binary Tree node structure:
    
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

bool isLeaf(TreeNode<int> *node)
{
    return (!node->left && !node->right); 
}

void addLeftBoundary(TreeNode<int> *node, vector<int> &ans)
{
  TreeNode<int> *cur=node->left;

  while(cur)
  {
    if(!isLeaf(cur))
      ans.push_back(cur->data);
    if(cur->left)
      cur = cur->left;
    else
      cur = cur->right;
  }
}

void addLeaves(TreeNode<int> *node, vector<int> &ans)
{
  if(node->left)
    addLeaves(node->left, ans);

  if(isLeaf(node))
    ans.push_back(node->data);

  if(node->right)
    addLeaves(node->right, ans);
}

void addRightBoundary(TreeNode<int> *root, vector<int> &ans)
{
  TreeNode<int> *cur = root->right;
  stack<int> st;
  
  while(cur)
  {
    if(!isLeaf(cur))
      st.push(cur->data);
    if(cur->right)
      cur = cur->right;
    else
      cur = cur->left;
  }

  while(!st.empty())
  {
    ans.push_back(st.top());
    st.pop();
  }
}

vector<int> traverseBoundary(TreeNode<int> *root)
{
  vector<int> ans;

  if(!root)
    return {};

  if(!isLeaf(root))
    ans.push_back(root->data);

  addLeftBoundary(root, ans);
  addLeaves(root, ans);
  addRightBoundary(root, ans);

  return ans;
}
