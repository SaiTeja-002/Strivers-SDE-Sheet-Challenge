#include <bits/stdc++.h>

void insertInSortedOrder(stack<int>& stack, int value)
{
    if (stack.empty() || value >= stack.top())
	{
        stack.push(value);
        return;
    }

    int temp = stack.top();
    stack.pop();
    insertInSortedOrder(stack, value);
    stack.push(temp);
}

void sortStack(stack<int>& stack)
{
    if (stack.empty() || stack.size() == 1)
        return;

    int temp = stack.top();
    stack.pop();

    sortStack(stack);
    insertInSortedOrder(stack, temp);
}