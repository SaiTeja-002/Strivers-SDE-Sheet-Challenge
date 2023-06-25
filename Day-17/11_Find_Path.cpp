#include <bits/stdc++.h> 
/*   
    template <typename T = int>
	class TreeNode
	{
		public:
		T data;
		TreeNode<T> *left;
		TreeNode<T> *right;

		TreeNode(T data)
		{
			this->data = data;
			left = NULL;
			right = NULL;
		}

		~TreeNode()
		{
			if (left != NULL)
			{
		  		delete left;
			}
			if (right != NULL)
			{
			 	delete right;
			}
		}
	};
*/

void inorderTraversal(TreeNode<int>* node, vector<int>& path, int req)
{
	if(!node)
		return ;
	
	path.push_back(node->data);

	if(node->data == req)
		return ;

	inorderTraversal(node->left, path, req);
	inorderTraversal(node->right, path, req);

	if(path.back() != req)
		path.pop_back();
}

vector<int> pathInATree(TreeNode<int> *root, int x)
{
    vector<int> path;
	inorderTraversal(root, path, x);

	return path;
}
