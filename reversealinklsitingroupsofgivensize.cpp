struct node *reverse (struct node *head, int k)
{ 
    if(!head)return NULL;
    struct node *prev = NULL,*curr  = head,*next = NULL;
    int count = k;
    while(curr && count)
    {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
        --count;
    }
    if(next)head->next = reverse(next,k);
    return prev;
}