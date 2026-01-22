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
    int findleff(TreeNode* root){
        int height=0;
        while(root){
            height++;
            root=root->left;
        }

        return height;
    }
    int findrigg(TreeNode* root){
        int height=0;
        while(root){
            height++;
            root=root->right;
        }

        return height;
    }

    int countNodes(TreeNode* root) {
        if(root==NULL) return 0;
       
        int lh=findleff(root->left);
        int rh=findrigg(root->right);

        if(lh==rh){
            return (2<<lh)-1;
        }

        return 1+countNodes(root->left)+countNodes(root->right);
    }
};