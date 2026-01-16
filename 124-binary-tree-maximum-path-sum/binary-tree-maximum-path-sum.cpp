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
    int ff(TreeNode* rr, int& maxii){
        if(rr==NULL) return 0;
        int ll=max(0,ff(rr->left,maxii));
        int rrr=max(0,ff(rr->right,maxii));

        maxii=max(maxii,ll+rrr+rr->val);

        return rr->val+max(ll,rrr);
    }

    int maxPathSum(TreeNode* root) {

        int maxii=INT_MIN;
        ff(root,maxii);
        return maxii;
    }
};