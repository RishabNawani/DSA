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
    vector<int> rightSideView(TreeNode* root) {
    
        vector<int> ans;
        if(root==NULL) return ans;
        queue<TreeNode*> qq;
        qq.push(root);

        while(!qq.empty()){
            vector<int> lvll;
            int sizee=qq.size();
            for(int i=0;i<sizee;i++){
                TreeNode* q= qq.front();
                qq.pop();
                if(q->left!=NULL) qq.push(q->left);
                if(q->right!=NULL) qq.push(q->right);
                lvll.push_back(q->val);
            }

            ans.push_back(lvll.back());
        }

        return ans;
    }
};