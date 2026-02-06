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
    void innn(TreeNode* root,vector<int>& in){
        if(root==NULL) return ;
        
        innn(root->left,in);
        in.push_back(root->val);
        innn(root->right,in);
        
    }
    void create(TreeNode* root, int& i,vector<int>& ii){
        if(root==NULL) return;
        create(root->left,i,ii);
        root->val=ii[i++];
        create(root->right,i,ii);
    }

    void recoverTree(TreeNode* root) {
        vector<int> inn;
        innn(root,inn);

        sort(inn.begin(),inn.end());
        int i=0;
        create(root,i,inn);
        
    }
};