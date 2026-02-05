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
class BSTIterator {
public:
    stack<TreeNode*> ss;
    bool rev;
    void pushh(TreeNode* root){
        while(root!=NULL){
            ss.push(root);
            if(rev==true)root=root->right;

            else root=root->left;
        }
    }

    BSTIterator(TreeNode* root, bool isrev) {
        rev=isrev;
        pushh(root);
    }
    
    int next() {
        TreeNode* topp= ss.top();
        ss.pop();
        if(!rev) pushh(topp->right);
        pushh(topp->left);
        return topp->val;
    }
    
    bool hasNext() {
        return !ss.empty();
    }
};


class Solution {
public:

/*
    void inn(TreeNode* root,vector<int>& in){
        if(root==NULL) return ;
        
        inn(root->left,in);
        in.push_back(root->val);
        inn(root->right,in);
        
    }
    */
    bool findTarget(TreeNode* root, int k) {
        /*
        vector<int> ss;
        inn(root,ss);

        int s=ss.size();

        int l=0;
        int r=s-1;

        while(l<r){
            if(ss[l]+ss[r]==k) return true;
            if(ss[l]+ss[r]<k) l++;
            if(ss[l]+ss[r]>k) r--;
        }
        return false;
        */
        if(!root) return false;
        BSTIterator l(root,false);
        BSTIterator r(root,true);

        int i=l.next();
        int j=r.next();

        while(i<j){
            if(i+j==k) return true;
            if(i+j<k) i=l.next();
            if(i+j>k) j=r.next();
        }

        return false;
    }
};