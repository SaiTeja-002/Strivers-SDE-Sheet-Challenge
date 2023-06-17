/****************************************************************

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


*****************************************************************/

Node *firstNode(Node *head)
{
    Node *fast=head, *slow=head;
    int fastLength=0, slowLength=0;

    while(fast && fast->next)
    {
        fast = fast->next->next;
        slow = slow->next;

        fastLength += 2;
        slowLength += 1;

        if(fast == slow)
            break;
    }

    if(fast == NULL || fast->next == NULL)
        return NULL;

    while(slow != head)
    {
        slow = slow->next;
        head = head->next;
    }

    return head;
}