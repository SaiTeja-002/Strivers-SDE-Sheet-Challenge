/*
Following is the class structure of the Node class:

class Node
{
public:
    int data;
    Node *next;
    Node()
    {
        this->data = 0;
        next = NULL;
    }
    Node(int data)
    {
        this->data = data; 
        this->next = NULL;
    }
    Node(int data, Node* next)
    {
        this->data = data;
        this->next = next;
    }
};
*/

Node* removeKthNode(Node* head, int k)
{
    Node *fast=head, *slow=head;

    for(int i=0; i<k; i++)
        fast = fast->next;

    if(!fast)
    {
        head = head->next;
        delete slow;    // Since slow points to the first node
        return head;
    }
    
    while(fast && fast->next)
    {
        fast = fast->next;
        slow = slow->next;
    }

    if(slow && slow->next)
    {
        Node* temp = slow->next;
        slow->next = slow->next->next;
        delete temp;
    }

    return head;
}
