
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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector <TreeNode*> parents;
        vector <vector<int>> sol; 
        if(root==nullptr) return sol;
        parents.push_back(root);
        bool rev = false;
        while(parents.size()>0){
            vector <int> temp;
            if(rev){
                for(int i=parents.size()-1; i>=0; i--){
                    temp.push_back(parents[i]->value);
                }
            }
            else{
                for(int i=0; i<parents.size(); i++){
                    temp.push_back(parents[i]->value);
                }
            }
            sol.push_back(temp);
            rev=!rev;

            vector <TreeNode*> children;
            for(int i=0; i<parents.size(); i++){
                if(parents[i]->left!=nullptr){
                    children.push_back(parents[i]->left);
                }
                if(parents[i]->right!=nullptr){
                    children.push_back(parents[i]->right);
                }
            }
            parents = children;
        }
        return sol;
    }   
};
