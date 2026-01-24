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
    TreeNode* build(vector<int>& preorder,int ps,int pend,vector<int>& inorder,int is,int iend,map<int,int>& inmap){
        if(ps>pend || is>iend) return nullptr;

        TreeNode* root=new TreeNode(preorder[ps]);

        int inroot=inmap[root->val];

        int leftt=inroot-is;

        root->left= build(preorder,ps+1,ps+leftt,inorder,is,inroot-1,inmap);
        root->right=build(preorder,ps+leftt+1,pend,inorder, inroot+1,iend,inmap);

        return root;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        map<int,int> inmap;

        for(int i=0;i<inorder.size();i++){
            inmap[inorder[i]]=i;
        }

        return build(preorder,0,preorder.size()-1,inorder,0,inorder.size()-1,inmap);
    }
};