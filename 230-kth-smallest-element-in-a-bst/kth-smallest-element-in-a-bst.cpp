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
    void inn(TreeNode* rr,vector<int>& aa){
        if(rr==nullptr) return;
        inn(rr->left,aa);
        aa.push_back(rr->val);
        inn(rr->right,aa);

    }

    int kthSmallest(TreeNode* root, int k) {
        vector<int> ss;
        inn(root, ss);
        return ss[k-1];
    }
};