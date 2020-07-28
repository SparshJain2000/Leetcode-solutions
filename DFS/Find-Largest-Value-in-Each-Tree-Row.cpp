// Problem statement

/*
    You need to find the largest value in each row of a binary tree.
*/


/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    int h=0;
    map<int,int>mp;
    vector<int>visited;
    
     map<int,int>::iterator it;
    vector<int>v;
    
    void find(TreeNode* root)
    {
        if(root==NULL)
            return;
        
        h++;
        if(visited[h]==0)
        {
            visited[h]=1;
             mp[h]=root->val;
        }
    
         else
        {
        if(mp[h]<root->val)
            mp[h]=root->val;
        }
        if(root->left)
            find(root->left);
        if(root->right)
            find(root->right);
        
        h--;
        
    }
    
    
    
    vector<int> largestValues(TreeNode* root) {
        
        if(root==NULL)
            return v;
        
        for(int i=0;i<1001;i++)
    {
        visited.push_back(0);
    }
    
        find(root);
        
        for(it=mp.begin();it!=mp.end();it++)
        {
            v.push_back(it->second);
        }
        
        return v;
    }
};