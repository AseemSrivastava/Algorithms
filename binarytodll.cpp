Node *pre = NULL,*head = NULL; 
void convert(Node *root) 
{ 
    if (!root) return;
    convert(root->left); 
    if (pre==NULL)head = root; 
    else
    { 
        root->left = pre; 
        pre->right = root; 
    } 
    pre = root; 
    convert(root->right); 
} 
Node * bToDLL(Node *root)
{
    pre = NULL;
    convert(root);
    return head;
}
