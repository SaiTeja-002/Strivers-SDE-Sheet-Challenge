#include<bits/stdc++.h>

class Queue {
private:
   stack<int> s1;
   stack<int> s2;
   int size;
   
public:
   Queue()
   {
       size = 0;
   }

   void enQueue(int val)
   {
       // Put all the elements from s1 to  s2
       while(!s1.empty())
       {
           int val = s1.top();
           s1.pop();
           s2.push(val);
       }

       // Push the val in s1
       s1.push(val);


       // Put all the elements from s2 to  s1
       while(!s2.empty())
       {
           int val = s2.top();
           s2.pop();
           s1.push(val);
       }

       size++;
   }

   int deQueue() 
   {
       if(s1.empty())
           return -1;
       else
       {
           int val = s1.top();
           s1.pop();
           size--;
           
           return val;
       }
   }

   int peek() 
   {
       if(s1.empty())
           return -1;
       else
           return s1.top();
   }

   bool isEmpty()
   {
       return s1.empty();
   }
};