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
    int maxDepth(TreeNode* root) {
        if(root==NULL) return 0;

        int ll=maxDepth(root->left);
        int rr=maxDepth(root->right);

        return 1 + max(ll,rr);
        
/*
        queue<TreeNode*> qq;
        qq.push(root);
        int height=0;

        while(!qq.empty()){
            int lvl=qq.size();

            for(int i=0;i<lvl;i++){
                TreeNode* rrr= qq.front();
                qq.pop();

                if(rrr->left!=nullptr) qq.push(rrr->left);
                if(rrr->right!=nullptr) qq.push(rrr->right);
            }
            height++;
        }

        return height;
        */
    }
};