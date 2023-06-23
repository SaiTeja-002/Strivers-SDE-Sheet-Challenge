#include <bits/stdc++.h> 
// Stack class.
class Stack
{
private:
    int* arr;
    int capacity;
    int ind=0;
    
public:
    Stack(int cap)
    {
        capacity = cap;
        arr = new int[capacity];
    }

    void push(int num)
    {
        if(ind<0)
            ind = 0;
            
        if(ind < capacity)
            arr[ind++] = num;
    }

    int pop()
    {
        if(ind > 0)
            return arr[--ind];
        return -1;
    }
    
    int top()
    {
        if(ind > 0)
            return arr[ind-1];
        return -1;
    }
    
    int isEmpty()
    {
        return (ind == 0);
    }
    
    int isFull()
    {
        return (ind == capacity);
    }
    
};
