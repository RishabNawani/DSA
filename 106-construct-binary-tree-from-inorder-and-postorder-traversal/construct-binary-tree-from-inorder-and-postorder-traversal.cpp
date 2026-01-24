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
    TreeNode* build(vector<int>& inorder,int is,int iend,vector<int>& postorder,int ps,int pend,map<int,int>& mapp){
        if(is>iend || ps>pend) return nullptr;

        TreeNode* root=new TreeNode(postorder[pend]);

        int inroot=mapp[postorder[pend]];

        int leftt=inroot-is;

        root->left=build(inorder,is,inroot-1,postorder,ps,ps+leftt-1,mapp);
        root->right=build(inorder,inroot+1,iend,postorder,ps+leftt,pend-1,mapp);

        return root;

    }


    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        map<int,int> mapp;

        for(int i=0;i<inorder.size();i++){
            mapp[inorder[i]]=i;
        }

        return build(inorder , 0, inorder.size()-1, postorder, 0, postorder.size()-1, mapp);
    }
};