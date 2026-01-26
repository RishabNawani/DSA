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
    TreeNode* prev=nullptr;
    void flatten(TreeNode* root) {
        TreeNode* curr=root;
        while(curr){
            if(curr->left){
                TreeNode* rightt= curr->left;
                while(rightt->right){
                    rightt=rightt->right;
                }

                rightt->right=curr->right;
                curr->right=curr->left;
                curr->left=nullptr;
            }
            curr=curr->right;
        }


        /*
        here we take the reverse preorder approach in our recursion to execute what we desire
        
        if(!root) return ;

        flatten(root->right);
        flatten(root->left);

        root->right=prev;
        root->left=nullptr;
        prev=root;
        */
    }
};