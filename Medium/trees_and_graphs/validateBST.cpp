#include <bits/stdc++.h>
using namespace std;

// Definition for a binary tree node.
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
    
    bool isValid (TreeNode *root, long long min, long long max){
        if(root == nullptr) return true;
        else if(root!=nullptr && 
           root->val > min &&
           root->val < max
          );
        else return false;
        
        if (root->left == nullptr);
        else if(root->left!=nullptr && 
           root->left->val < root->val && 
           root->left->val < max &&
           root->left->val > min
          ){
            long long tmax = max;
            if(root->val < max) max = root->val;
            bool left = isValid(root->left, min, max);
            if(!left) return false;
            max = tmax;
        }
        else return false;
        
        if(root->right == nullptr);
        else if(root->right!=nullptr && 
           root->right->val > root->val && 
           root->right->val < max &&
           root->right->val > min
          ){
            long long tmin = min;
            if(root->val > min) min = root->val;
            bool right = isValid(root->right, min, max);
            if(!right) return false;
            min = tmin;
        }
        else return false;
        
      return true;  
    }
    
    bool validateBST(TreeNode* root) {
        return isValid(root, LLONG_MIN, LLONG_MAX);
    }
};