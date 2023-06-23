#include <bits/stdc++.h> 

class Queue
{
private:
    int *arr;
    int qFront;
    int qBack;
    int capacity = 1001;
    
public:
    Queue()
    {
        arr = new int[capacity];
        qFront = 0;
        qBack = 0;
    }

    /*----------------- Public Functions of Queue -----------------*/

    bool isEmpty()
    {
        return (qFront == qBack);
    }

    void enqueue(int data)
    {
        if(qBack < capacity)
            arr[qBack++] = data;
    }

    int dequeue()
    {
        if(qFront == qBack)
        {
            qFront = 0;
            qBack = 0;
            return -1;
        }
        
        return arr[qFront++];
    }

    int front()
    {
        if(qFront == qBack)
        {
            qFront = 0;
            qBack = 0;
            return -1;
        }
        
        return arr[qFront];
    }
};