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
        if(root==NULL){
            return "NULL";
        }
        return to_string(root->val) + "," + serialize(root->left) + ","  + serialize(root->right);
    }

    // function to convert the given vector of nodes to a binary tree
    // since index is reference, after travelling i+1 to i+k for left subtree, it start at i+k+1 for right
    TreeNode* decodeUtil(vector<string> &nodes, int &i){
        if(i==nodes.size()){
            return NULL;
        }
        string currVal = nodes[i];
        i++;
        if(currVal=="NULL"){
            return NULL;
        }
        TreeNode* root = new TreeNode(stoi(currVal));
        root->left = decodeUtil(nodes,i);
        root->right = decodeUtil(nodes,i);
        return root;
    }
    
    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        vector<string> nodes;
        int i=0;
        string temp;
        while(i<=data.length()){
            if(data[i] == ',' || i==data.length()){
                nodes.push_back(temp);
                temp = "";
            }
            else {
                temp.push_back(data[i]);
            }
            i++;
        }
        int idx = 0;
        TreeNode* root = decodeUtil(nodes,idx);
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));