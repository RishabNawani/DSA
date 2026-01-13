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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> anss;
        if(root==nullptr) return anss;
        queue<TreeNode*> qq;
        qq.push(root);

        while(!qq.empty()){
            int sizee=qq.size();
            vector<int> lvll;
            for(int i=0;i<sizee;i++){
                TreeNode* q= qq.front();
                qq.pop();
                if(q->left!=NULL) qq.push(q->left);
                if(q->right!=NULL) qq.push(q->right);

                lvll.push_back(q->val);
            }
            anss.push_back(lvll);
        }

        return anss;

    }
};