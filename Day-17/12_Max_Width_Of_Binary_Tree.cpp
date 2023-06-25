void traverse(TreeNode<int>* node, unordered_map<int, int>& mp, int level)
{
    if(!node)
        return ;
    
    mp[level]++;
    traverse(node->left, mp, level+1);
    traverse(node->right, mp, level+1);
}

int getMaxWidth(TreeNode<int> *root)
{
    unordered_map<int, int> mp;
    traverse(root, mp, 0);

    int width = 0;

    for(auto e:mp)
        width = max(width, e.second);

    return width;
}