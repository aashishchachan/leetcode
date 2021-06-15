
#include <bits/stdc++.h>
using namespace std;
//  Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    int get_val(TreeNode* root, int k, int &i){
        int val;
        if(root->left!=nullptr) {
            val=get_val(root->left,k,i);
            if(i==k) return val;
        }
        val = root->val;
        i++; 
        if(i==k) return val;
        if(root->right!=nullptr) {
            val=get_val(root->right,k, i);
            if(i==k) return val;
        }
        return val;
    }

    int kthSmallest(TreeNode* root, int k) {
        int i=0;
        return get_val(root, k, i);    
    } 
};

int main(){
    // vector <int> preorder = {3,9,20,15,7};
    // vector<int> inorder = {9, 3, 15, 20, 7};
    // Solution sol;
    // sol.buildTree(preorder, inorder);
    // return 0;
}