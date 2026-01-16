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
    bool fff(TreeNode* pp, TreeNode* qq){
        if(pp==NULL && qq==NULL) return true;
        if(pp==NULL || qq==NULL) return false;
        return((pp->val==qq->val)&&fff(pp->left,qq->left)&&fff(pp->right,qq->right));
    }

    bool isSameTree(TreeNode* p, TreeNode* q) {
        return fff(p,q);
    }
};