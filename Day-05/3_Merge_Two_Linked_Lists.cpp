#include <bits/stdc++.h>

/************************************************************

    Following is the linked list node structure.
    
    template <typename T>
    class Node {
        public:
        T data;
        Node* next;

        Node(T data) {
            next = NULL;
            this->data = data;
        }

        ~Node() {
            if (next != NULL) {
                delete next;
            }
        }
    };

************************************************************/

Node<int>* sortTwoLists(Node<int>* first, Node<int>* second)
{
    if(!first)
        return second;
    if(!second)
        return first;

    Node<int> *final = new Node<int>(0), *iter = final;

    while(first && second)
    {
        if(first->data < second->data)
        {
            iter->data = first->data;
            first = first->next;
        }
        else
        {
            iter->data = second->data;
            second = second->next;
        }

        iter->next = new Node<int>(0);
        iter = iter->next;
    }

    Node<int> *ptr = (first) ? (first) : (second);

    while(ptr)
    {
        iter->data = ptr->data;
        ptr = ptr->next;

        if(ptr)
        {
            iter->next = new Node<int>(0);
            iter = iter->next;
        }
    }

    return final;
}
