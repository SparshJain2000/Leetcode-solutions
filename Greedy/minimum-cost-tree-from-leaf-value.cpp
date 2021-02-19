//Problem Statement
/*
    Given an array arr of positive integers, consider all binary trees such that:

    Each node has either 0 or 2 children;
    The values of arr correspond to the values of each leaf in an in-order traversal of the tree.  (Recall that a node is a leaf if and only if it has 0 children.)
    The value of each non-leaf node is equal to the product of the largest leaf value in its left and right subtree respectively.
    Among all possible binary trees considered, return the smallest possible sum of the values of each non-leaf node.  It is guaranteed this sum fits into a 32-bit integer.
*/
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int mctFromLeafValues(vector<int>& arr) {
        int res=0;
        while(arr.size()>1){
            int ind=min_element(arr.begin(),arr.end())-arr.begin();
            if(ind>0 && ind<arr.size()-1) res+=arr[ind]*min(arr[ind-1],arr[ind+1]);
            else res+=arr[ind]*(ind==0?arr[ind+1]:arr[ind-1]);
            arr.erase(ind+arr.begin());
        }
        return res;
    }
};