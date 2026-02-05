/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:

    void inn(TreeNode* root,vector<int>& in){
        if(root==NULL) return ;
        
        inn(root->left,in);
        in.push_back(root->val);
        inn(root->right,in);
        
    }
    bool findTarget(TreeNode* root, int k) {
        vector<int> ss;
        inn(root,ss);

        int s=ss.size();

        int l=0;
        int r=s-1;

        while(l<r){
            if(ss[l]+ss[r]==k) return true;
            if(ss[l]+ss[r]<k) l++;
            if(ss[l]+ss[r]>k) r--;
        }
        return false;
    }
};