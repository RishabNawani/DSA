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
/*
    void innn(TreeNode* rr, vector<int>& arrr){
        if(rr==nullptr) return;
        innn(rr->left,arrr);
        arrr.push_back(rr->val);
        innn(rr->right,arrr);

    }

*/
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> inorder;
        TreeNode* curr=root;

        while(curr!=NULL){
            if(curr->left==NULL){
                inorder.push_back(curr->val);
                curr=curr->right;

            }

            else{
                TreeNode* prev= curr->left;
                while(prev->right && prev->right!=curr){
                    prev=prev->right;
                }

                if(prev->right==NULL){
                    prev->right=curr;
                    curr=curr->left;
                }
                else{
                    prev->right=NULL;
                    inorder.push_back(curr->val);
                    curr=curr->right;
                }
            }
        }

        return inorder;

        /*
        stack<TreeNode*> stt;
        vector<int> innn;

        TreeNode* node = root;

        while(true){
            if(node!=NULL){
                stt.push(node);
                node=node->left;
            }
            else{
                if(stt.empty()) break;
                node=stt.top();
    
                stt.pop();

                innn.push_back(node->val);

                node=node->right;
            }
        }
        return innn;

        */

        /*
        vector<int> rrr;
        innn(root,rrr);
        return rrr;
        */
    }
};