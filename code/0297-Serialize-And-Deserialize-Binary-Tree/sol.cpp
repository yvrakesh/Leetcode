#pragma GCC optimize("Ofast")
static auto _ = [] () {ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);return 0;}();
class Codec {
#include<bits/stdc++.h>
public:
    
    string serialize(TreeNode* root){
        string s;
        serialize_helper(root,s);
        return s;
    }

    TreeNode* deserialize(string data) {
        // Enters string into stream
        istringstream in(data);
        return deserialize_helper(in);
    }

private:
    // Inorder Traversal
    void serialize_helper(TreeNode* root, string &s) {
        if (root){
            s += to_string(root->val)+" ";
            serialize_helper(root->left,s);
            serialize_helper(root->right,s);
        } 
        else
            s += "# ";
    }

    TreeNode* deserialize_helper(istringstream& in) {
        string val;
        // Stream takes string until white space encountered.
        // Head pointer moves to the next position
        in >> val;
        if (val == "#")
            return nullptr;
        // Again insert in Inorder Traversal format
        TreeNode* root = new TreeNode(stoi(val));
        root->left = deserialize_helper(in);
        root->right = deserialize_helper(in);
        return root;
    }
};
