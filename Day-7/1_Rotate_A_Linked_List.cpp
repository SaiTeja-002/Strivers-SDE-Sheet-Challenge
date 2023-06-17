/**
 * Definition for singly-linked list.
 * class Node {
 * public:
 *     int data;
 *     Node *next;
 *     Node() : data(0), next(nullptr) {}
 *     Node(int x) : data(x), next(nullptr) {}
 *     Node(int x, Node *next) : data(x), next(next) {}
 * };
 */

Node *rotate(Node *head, int k)
{
     if(!head || !head->next)
          return head;

     Node *iter=head, *prev;

     // Find the length of the list
     int length = 0;
     for(; iter; iter=iter->next, length++);

     int rots = k%length;
     iter = head;

     while(rots--)
     {
          while(iter && iter->next)
          {
               prev = iter;
               iter = iter->next;
          }

          prev->next->next = head;
          prev->next = NULL;

          head = iter;
     }

     return head;
}