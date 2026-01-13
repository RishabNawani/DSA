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
    void poss(TreeNode* rr, vector<int>& arrr){
        if(rr==nullptr) return;
        poss(rr->left,arrr);
        poss(rr->right,arrr);
        arrr.push_back(rr->val);
    }
*/
    vector<int> postorderTraversal(TreeNode* root) {

        vector<int> poss;
        stack<TreeNode*> st1 , st2;
        if(root==NULL) return poss;
        st1.push(root);

        while(!st1.empty()){
            root=st1.top();
            st1.pop();

            st2.push(root);
            if(root->left!=NULL) st1.push(root->left);
            if(root->right!=NULL) st1.push(root->right);


        }

        while(!st2.empty()){
            poss.push_back(st2.top()->val);
            st2.pop();
        }
        return poss;
        /*
        vector<int> rrr;
        poss(root,rrr);
        return rrr;
        */
    }
};