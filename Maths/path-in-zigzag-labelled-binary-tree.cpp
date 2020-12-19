//Problem Statement
/*
In an infinite binary tree where every node has two children, the nodes are labelled in row order.
In the odd numbered rows (ie., the first, third, fifth,...), the labelling is left to right, while in the even numbered rows (second, fourth, sixth,...), the labelling is right to left.

Given the label of a node in this tree, return the labels in the path from the root of the tree to the node with that label.
*/
#include <bits/stdc++.h>
using namespace std;
class Solution {
   public:
    vector<int> pathInZigZagTree(int label) {
        vector<int> ans;
        while (label) {
            ans.push_back(label);
            label /= 2;
            if (!label)
                break;
            int n = (int)log2(label) + 1;
            label = pow(2, n - 1) + (pow(2, n) - label - 1);
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};