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
    TreeNode* prev;
    TreeNode* first;
    TreeNode* middle;
    TreeNode* last;

    void joinn(TreeNode* root){
        if(root==NULL) return;

        joinn(root->left);

        if(prev!=NULL && (root->val < prev->val)){

            if(first==NULL){
                first=prev;
                middle=root;
            }
            else{
                last=root;
            }
        }
        prev=root;
        joinn(root->right);
    }

/*
    void innn(TreeNode* root,vector<int>& in){
        if(root==NULL) return ;
        
        innn(root->left,in);
        in.push_back(root->val);
        innn(root->right,in);
        
    }
    void create(TreeNode* root, int& i,vector<int>& ii){
        if(root==NULL) return;
        create(root->left,i,ii);
        root->val=ii[i++];
        create(root->right,i,ii);
    }
    */

    void recoverTree(TreeNode* root) {

        first=middle=last=NULL;
        prev = new TreeNode(INT_MIN);
        joinn(root);
        if(first && last)  swap(first->val,last->val);
        else if(first && middle)  swap(first->val, middle->val);

        /*
        vector<int> inn;
        innn(root,inn);

        sort(inn.begin(),inn.end());
        int i=0;
        create(root,i,inn);
        */
    }
};