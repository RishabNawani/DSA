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
    void innn(TreeNode* rr, vector<int>& arrr){
        if(rr==nullptr) return;
        innn(rr->left,arrr);
        arrr.push_back(rr->val);
        innn(rr->right,arrr);

    }


    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> rrr;
        innn(root,rrr);
        return rrr;
    }
};