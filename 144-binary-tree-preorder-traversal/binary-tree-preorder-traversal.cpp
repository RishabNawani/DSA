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
    void pree(TreeNode* rr, vector<int>& arrr){

        if(rr==nullptr) return;
        arrr.push_back(rr->val);

        pree(rr->left,arrr);
        pree(rr->right,arrr);

    }
*/
    vector<int> preorderTraversal(TreeNode* root) {
        /*
        vector<int> arrr;
        pree(root,arrr);
        return arrr;
        */

        vector<int> preorder;
        TreeNode* curr=root;
/// Morris traversal preorder
        while(curr!=NULL){
            if(curr->left==NULL){
                preorder.push_back(curr->val);
                curr=curr->right;

            }

            else{
                TreeNode* prev= curr->left;
                while(prev->right && prev->right!=curr){
                    prev=prev->right;
                }

                if(prev->right==NULL){
                    prev->right=curr;
                    preorder.push_back(curr->val);
                    curr=curr->left;
                }
                else{
                    prev->right=NULL;
                    
                    curr=curr->right;
                }
            }
        }

        return preorder;
        /*
        vector<int> pree;
        if(root==NULL) return pree;
        stack<TreeNode*> stt;
        stt.push(root);

        while(!stt.empty()){
            TreeNode* rr= stt.top();
            stt.pop();
            pree.push_back(rr->val);
            if(rr->right!=NULL) stt.push(rr->right);
            if(rr->left!=NULL) stt.push(rr->left);
        }

        return pree;

        */
    }
};