/**
 * Definition of linked list:
 *
 * class Node {
 * public:
 *      int data;
 *      Node *next;
 *      Node() {
 *          this->data = 0;
 *          this->next = NULL;
 *      }
 *      Node(int data) {
 *          this->data = data;
 *          this->next = NULL;
 *      }
 *      Node (int data, Node *next) {
 *          this->data = data;
 *          this->next = next;
 *      }
 * };
 *
 *************************************************************************/

Node *addTwoNumbers(Node *l1, Node *l2)
{
    if(!l1)
        return l2;
    if(!l2)
        return l1;
    
    int carry = 0;
    Node *iter = new Node(), *head=iter;

    while(carry || l1 || l2)
    {
        int sum = 0;
        sum += (l1? (l1->data) : 0) + (l2? (l2->data) : 0) + carry;
        
        iter->data = sum%10;
        carry = sum/10;

        if(l1)
            l1 = l1->next;
        if(l2)
            l2 = l2->next;

        if(carry || l1 || l2)
        {
            iter->next = new Node();
            iter = iter->next;   
        }
    }

    return head;
}
