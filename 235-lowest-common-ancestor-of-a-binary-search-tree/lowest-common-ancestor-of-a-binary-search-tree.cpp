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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
/*

        if(root==NULL || root==p || root==q) return root;

        TreeNode* left=lowestCommonAncestor(root->left,p,q);
        TreeNode* right=lowestCommonAncestor(root->right,p,q);

        if(left==NULL) return right;
        if(right==NULL) return left;
        else{
            return root;
        }
        */
/*
        if(root==NULL) return root;

        if(root->val>p->val && root->val>q->val) return lowestCommonAncestor(root->left,p,q);
        if(root->val<p->val && root->val<q->val) return lowestCommonAncestor(root->right,p,q);

        return root;
*/
        while(true){
            if(root->val>p->val && root->val>q->val) root=root->left;
            else if(root->val<q->val && root->val<p->val) root=root->right;
            else return root;
        }

        return NULL;
    }
};