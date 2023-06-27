/************************************************************
   
   Following is the TreeNode class structure
   
   class TreeNode<T>
   { 
   public:
        T data; 
        TreeNode<T> *left;
        TreeNode<T> *right;
   
        TreeNode(T data) 
  		{ 
            this -> data = data; 
            left = NULL; 
            right = NULL; 
        }
   };
   
   
 ************************************************************/
TreeNode<int>* build(vector<int>& inorder, vector<int>& postorder, int inLeft, int inRight, int postLeft, int postRight)
{
     if(inRight < inLeft || postRight < postLeft)
          return NULL;
     
     TreeNode<int>* node = new TreeNode<int>(postorder[postRight]);
     int index = inLeft;

     while(inorder[index] != postorder[postRight])
          index++;
     
     node->left = build(inorder, postorder, inLeft, index-1, postLeft, postLeft+index-inLeft-1);
     node->right = build(inorder, postorder, index+1, inRight, postLeft+index-inLeft, postRight-1);

     return node;
}

TreeNode<int>* getTreeFromPostorderAndInorder(vector<int>& postorder, vector<int>& inorder) 
{
     int rootIndex = inorder.size()-1;
     
     return build(inorder, postorder, 0, rootIndex, 0, rootIndex);
}
