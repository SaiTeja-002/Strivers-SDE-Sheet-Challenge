void completeTraversal(BinaryTreeNode<int>* node, vector<int>& inOrder, vector<int>& preOrder, vector<int>& postOrder)
{
    if(!node)
        return ;

    preOrder.push_back(node->data);
    completeTraversal(node->left, inOrder, preOrder, postOrder);
    inOrder.push_back(node->data);
    completeTraversal(node->right, inOrder, preOrder, postOrder);
    postOrder.push_back(node->data);
}

vector<vector<int>> getTreeTraversal(BinaryTreeNode<int> *root)
{
    vector<int> inOrder, preOrder, postOrder;
    completeTraversal(root, inOrder, preOrder, postOrder);

    return {inOrder, preOrder, postOrder};
}