
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

    void trav_recursive(TreeNode * root, vector <int> &sol){
        if(root == nullptr) return;
        get_val(root->left, sol);
        sol.push_back(root->val);
        get_val(root->right, sol);
        return;
    }

    void trav_iterative(TreeNode * root, vector <int> &sol){
        stack<TreeNode *> stk;
        TreeNode *temp = root;
        while(!stk.empty() || temp!=nullptr){
            while(temp !=nullptr){
                stk.push(temp);
                temp = temp->left;
            }
            temp = stk.top();
            stk.pop();
            sol.push_back(temp->val);
            temp = temp->right;
        }
        return;
    }


    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> sol;
        trav_recursive(root, sol);
        return sol;
    }
};