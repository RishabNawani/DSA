/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:



    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string rr="";
        if(root==NULL) {
            rr.append("#,");
            return rr;
        }

        rr.append(to_string(root->val));
        string hh=serialize(root->left);
        string gg=serialize(root->right);

        return rr+","+hh+gg;
    }
    TreeNode* build(vector<string> &v, int &i){
        if(v[i] == "#"){
            i++;
            return nullptr;
        }
        TreeNode* root=new TreeNode(stoi(v[i++]));
        root->left=build(v,i);
        root->right=build(v,i);

        return root;
    }
    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        vector<string> v;
        string token;

        for (char c : data) {
            if (c == ',') {
                v.push_back(token);
                token.clear();
            } else {
                token += c;
            }
        }
        int i=0;
        return build(v,i);
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));