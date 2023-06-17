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

Node* findIntersection(Node *headA, Node *headB)
{
    int length1=0, length2=0;
    Node *p1=headA, *p2=headB;

    while(p1)
    {
        length1++;
        p1 = p1->next;
    }
    
    while(p2)
    {
        length2++;
        p2 = p2->next;
    }

    p1 = headA;
    p2 = headB;

    int diff = length1-length2;

    if(diff > 0)
        for(int i=0; i<diff; i++)
            p1 = p1->next;

    if(diff < 0)
        for(int i=0; i<abs(diff); i++)
            p2 = p2->next;
    
    while(p1 && p2)
    {
        if(p1 == p2)
            return p1;

        p1 = p1->next;
        p2 = p2->next;
    }

    return NULL;
}