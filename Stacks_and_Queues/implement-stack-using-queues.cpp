//Problem Statement
/*
Given a string s of '(' , ')' and lowercase English characters. 

Your task is to remove the minimum number of parentheses ( '(' or ')', in any positions ) so that the resulting parentheses string is valid and return any valid string.

Formally, a parentheses string is valid if and only if:

It is the empty string, contains only lowercase characters, or
It can be written as AB (A concatenated with B), where A and B are valid strings, or
It can be written as (A), where A is a valid string.
 */

#include <bits/stdc++.h>

class MyStack
{
public:
    /** Initialize your data structure here. */
    queue<int> st;
    queue<int> help;
    MyStack()
    {
    }

    /** Push element x onto stack. */
    void push(int x)
    {
        st.push(x);
    }

    /** Removes the element on top of the stack and returns that element. */
    int pop()
    {
        while (st.size() != 1)
        {
            help.push(st.front());
            st.pop();
        }
        int temp = st.front();
        st.pop();
        while (!help.empty())
        {
            st.push(help.front());
            help.pop();
        }
        return temp;
    }

    /** Get the top element. */
    int top()
    {
        return st.back();
    }

    /** Returns whether the stack is empty. */
    bool empty()
    {
        return st.empty();
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */