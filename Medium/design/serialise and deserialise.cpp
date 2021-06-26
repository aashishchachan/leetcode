#include <bits/stdc++.h>
using namespace std;

//Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        queue <TreeNode> temp;
        vector<char> vec;
        temp.push(*root);
        for(){
            if(temp.front() == nullptr){
                vec.push_back('|');
                temp.pop();
            }
            vec.push_back(temp.front().val);
            temp.push(*(temp.front().left));
            temp.push(*(temp.front().right));
            temp.pop();
        }
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));