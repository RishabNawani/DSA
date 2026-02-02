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

    TreeNode* buildd(vector<int>&preorder,int sp,int ep,vector<int>&inn,int si,int ei,map<int,int>ss){
        if(sp>ep || si>ei) return nullptr;

        TreeNode* root=new TreeNode(preorder[sp]);

        int iroot=ss[root->val];
        int leftt=iroot-si;

        root->left=buildd(preorder,sp+1,sp+leftt,inn,si,iroot-1,ss);
        root->right=buildd(preorder,sp+leftt+1,ep,inn,iroot+1,ei,ss);

        return root;

    }

    TreeNode* bstFromPreorder(vector<int>& preorder) {
        vector<int> inorderr=preorder;
        sort(inorderr.begin(),inorderr.end());
        map<int,int> ss;
        for(int i=0;i<inorderr.size();i++){
            ss[inorderr[i]]=i;
        }
        return buildd(preorder,0,preorder.size()-1,inorderr,0,inorderr.size()-1,ss);
    }
};