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

int findHeight(TreeNode<int>* node)
{
    if(!node)
        return 0;

    return 1 + max(findHeight(node->left), findHeight(node->right));
}

void traverse(TreeNode<int>* node, int& maxHeight)
{
    if(!node)
        return ;

    int leftHeight = findHeight(node->left);
    int rightHeight = findHeight(node->right);

    maxHeight = max(maxHeight, leftHeight+rightHeight);

    traverse(node->left, maxHeight);
    traverse(node->right, maxHeight);
}

int diameterOfBinaryTree(TreeNode<int> *root)
{
    int maxHeight=0;
	traverse(root, maxHeight);

    return maxHeight;
}
