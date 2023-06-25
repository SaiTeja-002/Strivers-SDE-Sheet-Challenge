vector<int> morrisPreorderTraversal(TreeNode* root)
{
    TreeNode* cur = root;
    vector<int> vec;
    
    while(cur)
    {
        if(!cur->left)
        {
            vec.push_back(cur->data);
            cur = cur->right;
        }
        else
        {
            TreeNode* prev = cur->left;

            while (prev->right && prev->right != cur)
                prev = prev->right;

            if (!prev->right)
            {
                prev->right = cur;
                vec.push_back(cur->data);
                cur = cur->left;
            } 
            else 
            {
                prev->right = nullptr;
                cur = cur->right;
            }
        }
    }

    return vec;
}
