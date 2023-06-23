#include <bits/stdc++.h> 
// Implement class for minStack.
class minStack
{
private:
	// Maintain both the current element and the smallest element uptil that point
	stack<pair<int, int>> st;
	
public:
	minStack() 
	{ 
		
	}
	
	// Function to add another element equal to num at the top of stack.
	void push(int num)
	{
		if(st.empty())
			st.push({num, num});
		else if(st.top().second < num)
			st.push({num, st.top().second});
		else
			st.push({num, num});
	}
	
	// Function to remove the top element of the stack.
	int pop()
	{
		if(st.empty())
			return -1;

		int topElement = st.top().first;
		st.pop();
		return topElement;
	}
	
	// Function to return the top element of stack if it is present. Otherwise return -1.
	int top()
	{
		return (st.empty() ? (-1) : (st.top().first));
	}
	
	// Function to return minimum element of stack if it is present. Otherwise return -1.
	int getMin()
	{
		return (st.empty() ? (-1) : (st.top().second));
	}
};