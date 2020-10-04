int areMirror(Node* a, Node* b) {
    if(!a && !b)return 1;
    if(!a || !b)return 0;
    if(a->data!=b->data)return 0;
    return areMirror(a->left,b->right) && areMirror(a->right,b->left); 
}
