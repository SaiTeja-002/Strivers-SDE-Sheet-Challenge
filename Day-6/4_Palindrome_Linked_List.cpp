#include <bits/stdc++.h> 
/****************************************************************

    Following is the class structure of the LinkedListNode class:

    template <typename T>
    class LinkedListNode
    {
    public:
        T data;
        LinkedListNode<T> *next;
        LinkedListNode(T data)
        {
            this->data = data;
            this->next = NULL;
        }
    };

*****************************************************************/


LinkedListNode<int>* reverse(LinkedListNode<int>* ptr)
{
    LinkedListNode<int> *prev=NULL, *next=NULL;
    
    while(ptr)
    {
        next = ptr->next;
        ptr->next = prev;

        prev = ptr;
        ptr = next;
    }
    
    return prev;
}

bool isPalindrome(LinkedListNode<int> *head)
{
    if(!head || !head->next)
        return true;
        
    LinkedListNode<int> *fast=head, *slow=head;

    while(fast && fast->next && fast->next->next)
    {
        fast = fast->next->next;
        slow = slow->next;
    }

    slow->next = reverse(slow->next);
    slow = slow->next;

    while(slow)
    {
        if(slow->data != head->data)
            return false;

        slow = slow->next;
        head = head->next;
    }

    return true;
}
