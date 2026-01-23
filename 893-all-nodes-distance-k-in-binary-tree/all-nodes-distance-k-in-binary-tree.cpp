/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    void marking(TreeNode* root, unordered_map<TreeNode*,TreeNode*> &parentt, TreeNode* target){
        queue<TreeNode*> quee;
        quee.push(root);
        while(!quee.empty()){
            TreeNode* curr=quee.front();
            quee.pop();

            if(curr->left!=NULL){
                parentt[curr->left]=curr;
                quee.push(curr->left);
            }

            if(curr->right!=NULL){
                parentt[curr->right]=curr;
                quee.push(curr->right);
            }
        }
    }
    

    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        unordered_map<TreeNode*, TreeNode*> parentt;
        marking(root,parentt,target);

        unordered_map<TreeNode*,bool> visitedd;
        queue<TreeNode*> qq;

        qq.push(target);
        visitedd[target]=true;
        int dist=0;

        while(!qq.empty()){
            int sizee=qq.size();
            if(dist++==k) break;

            for(int i=0;i<sizee;i++){
                TreeNode* nn=qq.front();
                qq.pop();

                if(nn->left && !visitedd[nn->left]){
                    qq.push(nn->left);
                    visitedd[nn->left]=true;
                }


                if(nn->right && !visitedd[nn->right]){
                    qq.push(nn->right);
                    visitedd[nn->right]=true;
                }

                if(parentt[nn] && !visitedd[parentt[nn]]){
                    qq.push(parentt[nn]);
                    visitedd[parentt[nn]]=true;
                }
            }
        }

        vector<int> result;
        while(!qq.empty()){
            TreeNode* q=qq.front();
            qq.pop();
            result.push_back(q->val);
        }

        return result;

    }
};