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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ansss;
        if(root==NULL) return ansss;
        queue<TreeNode*> qq;
        qq.push(root);
        bool cnt=true;
        while(!qq.empty()){

            int sizee=qq.size();
            vector<int> ans(sizee);
        
            for(int i=0;i<sizee;i++){
                TreeNode* q=qq.front();
                qq.pop();

                int ind=cnt? i: sizee-i-1;
                ans[ind]=q->val;

                if(q->left!=NULL) qq.push(q->left);
                if(q->right!=NULL) qq.push(q->right);
                
            }
            cnt=!cnt;
            
            ansss.push_back(ans);
        }

        return ansss;
    }
};