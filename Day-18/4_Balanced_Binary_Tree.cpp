
/* int findHeight(BinaryTreeNode<int>* node)
{
    if(!node)
        return 0;
    
    return 1 + max(findHeight(node->left), findHeight(node->right));
}

void traverse(BinaryTreeNode<int>* node, bool& balanced)
{
    if(!node)
        return ;

    traverse(node->left, balanced);
    traverse(node->right, balanced);

    int leftHeight = findHeight(node->left);
    int rightHeight = findHeight(node->right);

    if(abs(leftHeight-rightHeight) > 1)
        balanced = false;   
} */

int findHeight(BinaryTreeNode<int>* node)
{
    if(!node)
        return 0;
    
    int leftHeight = findHeight(node->left);
    int rightHeight = findHeight(node->right);

    if(leftHeight == -1 || rightHeight == -1 || abs(rightHeight - leftHeight)>1)
        return -1;

    return 1 + max(leftHeight, rightHeight);
}

bool isBalancedBT(BinaryTreeNode<int>* root)
{
    return findHeight(root) != -1;
    
    /* bool balanced = true;
    traverse(root, balanced);

    return balanced; */
}