struct Node* addTwoLists(struct Node* first, struct Node* second)
{
    struct Node *prev = NULL,*next = NULL,*curr = first;
    while(curr)
    {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    struct Node *p1 = prev,*p2;
    prev = NULL,next = NULL,curr = second;
    while(curr)
    {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    p2 = prev;
    struct Node *head = NULL,*temp;
    int carry = 0;
    while(p1 && p2)
    {
        int sum = p1->data+p2->data+carry;
        struct Node *node;
        if(sum>9)
        {
            node = new Node(sum-10);
            carry = 1;
            if(!head)
            {
                head = node;
                temp = head;
            }
            else
            {
                temp->next = node;
                temp = temp->next;
            }
        }
        else
        {
            carry = 0;
            node = new Node(sum);
            if(!head)
            {
                head = node;
                temp = head;
            }
            else
            {
                temp->next = node;
                temp = temp->next;
            }
        }
        p1 = p1->next;
        p2 = p2->next;
    }
    while(p1)
    {
        int sum = p1->data+carry;
        struct Node *node;
        if(sum>9)
        {
            node = new Node(sum-10);
            carry = 1;
            if(!head)
            {
                head = node;
                temp = head;
            }
            else
            {
                temp->next = node;
                temp = temp->next;
            }
        }
        else
        {
            carry = 0;
            node = new Node(sum);
            if(!head)
            {
                head = node;
                temp = head;
            }
            else
            {
                temp->next = node;
                temp = temp->next;
            }
        }
        p1 = p1->next;
    }
    while(p2)
    {
        int sum = p2->data+carry;
        struct Node *node = new Node(sum-10);
        if(sum>9)
        {
            node = new Node(sum-10);
            carry = 1;
            if(!head)
            {
                head = node;
                temp = head;
            }
            else
            {
                temp->next = node;
                temp = temp->next;
            }
        }
        else
        {
            carry = 0;
            node = new Node(sum);
            if(!head)
            {
                head = node;
                temp = head;
            }
            else
            {
                temp->next = node;
                temp = temp->next;
            }
        }
        p2 = p2->next;
    }
    if(carry)
    {
        struct Node *node = new Node(1);
        temp->next = node;
        temp = temp->next;
    }
    prev = NULL,next = NULL,curr = head;
    while(curr)
    {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    return prev;
}
