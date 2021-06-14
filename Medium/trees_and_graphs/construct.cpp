
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
     TreeNode * build(vector<int> &preorder, int ip, int jp, vector<int> &inorder, int ii, int ji){
        if(jp<ip || ji<ii) return nullptr;
        
        int root = preorder[ip];
        if(ip==jp) return new TreeNode(root);

        int i;
        for(i=ii; i<=ji; i++){
            if(inorder[i]==root) break;
        }

        int j = ip + i - ii;
        TreeNode* left  = build(preorder, ip+1, j, inorder, ii, i-1); 
        TreeNode* right = build(preorder, j+1, jp, inorder, i+1, ji); 
        
        return new TreeNode(root, left, right);
    }
    
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return build(preorder, 0, preorder.size()-1, inorder, 0, inorder.size()-1);
    } 
};

int main(){
    vector <int> preorder = {3,9,20,15,7};
    vector<int> inorder = {9, 3, 15, 20, 7};
    Solution sol;
    sol.buildTree(preorder, inorder);
    return 0;
}