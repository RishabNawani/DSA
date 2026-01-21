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
    int widthOfBinaryTree(TreeNode* root) {
        if(root==NULL) return 0;
        int ans=0;
        queue<pair<TreeNode*,int>> qq;
        qq.push({root,0});

        while(!qq.empty()){
            int sizee=qq.size();
            int minn=qq.front().second;
            int first , last;
            for(int i=0;i<sizee;i++){
                int curr=qq.front().second-minn;
                TreeNode* q=qq.front().first;
                qq.pop();
                if(i==0)first=curr;
                if(i==sizee-1)last=curr;

                if(q->left)qq.push({q->left,(long long)2*curr+1});
                if(q->right)qq.push({q->right,(long long)2*curr+2});
            }

            ans=max(ans,last-first+1);
        }

        return ans;
    }
};