vector<int> morrisInorderTraversal(TreeNode* root)
{
    vector<int> vec;
    TreeNode* cur = root;

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

            while(prev->right && prev->right != cur)
                prev = prev->right;

            if(!prev->right)
            {
                prev->right = cur;
                cur = cur->left;
            }
            else
            {
                prev->right = nullptr;
                vec.push_back(cur->data);
                cur = cur->right;
            }
        }
    }

    retrun vec;
}
