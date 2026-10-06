/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:

bool findPath(
        TreeNode* node,
        TreeNode* target,
        vector<TreeNode*>& path
    ) {
        if (node == nullptr) {
            return false;
        }
 
        path.push_back(node);
 
        // The required ancestor chain is complete
        // once the target node is reached.
        if (node == target) {
            return true;
        }
 
        if (
            findPath(node->left, target, path) ||
            findPath(node->right, target, path)
        ) {
            return true;
        }
 
        // The node is removed when the target
        // is not present in this subtree.
        path.pop_back();
 
        return false;
    }
 
public:
    // Finds the last common node in
    // the root-to-p and root-to-q paths.
    TreeNode* lowestCommonAncestor(
        TreeNode* root,
        TreeNode* p,
        TreeNode* q
    ) {
        vector<TreeNode*> pathP;
        vector<TreeNode*> pathQ;
 
        findPath(root, p, pathP);
        findPath(root, q, pathQ);
 
        TreeNode* lca = nullptr;
 
        int limit = min(
            pathP.size(),
            pathQ.size()
        );
 
        // Both paths share the same prefix
        // until their Lowest Common Ancestor.
        for (int i = 0; i < limit; i++) {
            if (pathP[i] != pathQ[i]) {
                break;
            }
 
            lca = pathP[i];
        }
 
        return lca;
    }

/*
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root==NULL || root==p || root==q) return root;
        TreeNode* left = lowestCommonAncestor(root->left,p,q);
        TreeNode* right= lowestCommonAncestor(root->right,p,q);
        if(left==NULL) return right;
        else if(right==NULL) return left;
        else{
            return root;
        }
    }
    */
};