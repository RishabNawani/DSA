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
    int hh(TreeNode* rr){
        if(rr==NULL) return 0;

        int ll=hh(rr->left);
        if(ll==-1) return -1;
        int rrr=hh(rr->right);
        if(rrr==-1) return -1;

        if(abs(ll-rrr)>1) return -1;

        return 1 + max(ll,rrr);
    }
    bool isBalanced(TreeNode* root) {
        if(root==NULL) return 1;
        TreeNode* rightt=root->right;
        TreeNode* leftt= root->left;
        int ll=hh(leftt);
        int rr=hh(rightt);
        if(ll==-1 || rr==-1) return false;
        if(abs(ll-rr)<=1) return true;
        return false;
    }
};