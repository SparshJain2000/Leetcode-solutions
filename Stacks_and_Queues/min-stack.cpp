//Problem Statement
/*
Design a stack that supports push, pop, top, and retrieving the minimum element in constant time.

push(x) -- Push element x onto stack.
pop() -- Removes the element on top of the stack.
top() -- Get the top element.
getMin() -- Retrieve the minimum element in the stack.
 */

#include <bits/stdc++.h>
class MinStack
{
public:
    /** initialize your data structure here. */
    stack<long int> st;
    long int min;

    void push(int x)
    {
        if (st.size() == 0)
        {
            min = (long int)x;
            st.push((long int)x);
            return;
        }
        if (min > x)
        {
            st.push((2 * (long int)x - (long int)min));
            min = (long int)x;
        }
        else
            st.push((long int)x);
    }

    void pop()
    {
        if (st.top() < min)
            min = (2 * (long int)min - (long int)st.top());
        st.pop();
    }

    int top()
    {
        if (st.top() < min)
            return min;
        return (int)st.top();
    }

    int getMin()
    {
        return (int)min;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */