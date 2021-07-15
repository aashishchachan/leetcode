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
    
    // bool isCorrected (TreeNode *root, TreeNode * min, TreeNode * max){
    // // true: corrected, false: yet to be corrected    
    //     if(root!=nullptr){
    //         if(root->val < min->val){
    //             swap(root->val, min->val);
    //             return true;
    //         }
    //         if (root->val > max->val){
    //             swap(root->val, min->val);
    //             return true;
    //         }
    //     } 
                
    //     if(root->left!=nullptr){
    //         if (root->left->val > root->val){
    //              swap(root->val, root->left->val);
    //              return true;
    //         } 
    //         if (root->left->val > max->val){
    //              swap(root->left->val, max->val);
    //              return true;
    //         }
    //         if (root->left->val < min->val){
    //              swap(root->left->val, min->val);
    //              return true;
    //         }
    //         if(root->val < max->val && isCorrected(root->left, min, root)) {
    //             return true;
    //         }
    //     }
        
    //     if(root->right!=nullptr){
    //         if (root->right->val < root->val){
    //              swap(root->val, root->right->val);
    //              return true;
    //         } 
    //         if (root->right->val > max->val){
    //              swap(root->right->val, max->val);
    //              return true;
    //         }
    //         if (root->right->val < min->val){
    //              swap(root->right->val, min->val);
    //              return true;
    //         }
    //         if(root->val > min->val && isCorrected(root->right, root, max)){
    //             return true;
    //         }
    //     }

    //     return false; 
    // }
    
    // void correct(TreeNode * root, TreeNode * first, TreeNode * second){
    //     if(root==nullptr)
    //         return;
    //     if(first!= nullptr && second!=nullptr){
    //         swap(first->val, second->val);
    //         return;
    //     }

    //     correct(root->left, first, second);
    //     //root
    //     correct(root->right, first, second);

    //     if(root->left!=nullptr){
    //         correct(root->left, first, second);
    //         if(root->left->val >root->val){
    //             if(first == nullptr)
    //                 first = root;
    //             else if(second == nullptr)
    //                 second = root;
    //         }
    //     }
    //     if(root->right !=nullptr){
    //         if(root->right->val < root->val){
    //             if(first == nullptr)
    //                 first = root->right;
    //             else if(second == nullptr)
    //                 second = root->right;
    //         }
    //         correct(root->right, first, second);
    //     }

    // }

    // void recoverTree(TreeNode* root) {
    //     TreeNode *min = new TreeNode(LLONG_MIN);
    //     TreeNode *max = new TreeNode(LLONG_MAX);
    //     isCorrected(root, min, max);
    //     delete min;
    //     delete max;
    //     return;
    // }
};