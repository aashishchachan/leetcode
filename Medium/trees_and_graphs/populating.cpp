
#include <bits/stdc++.h>
using namespace std;

// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};

class Solution {
public:
    Node* connect(Node* root) {
        vector<Node*> parents;
        parents.push_back(root);
        while(parents[0]!=nullptr){
            vector<Node*> children;
            for (int i = 0; i<parents.size(); i++){
                if(i==parents.size()-1) parents[i]->next = nullptr;
                else parents[i]->next = parents[i+1];
                children.push_back(parents[i]->left);
                children.push_back(parents[i]->right);
            }
            parents = children;
        }
        return root;
    }
};

int main(){
    vector <int> preorder = {3,9,20,15,7};
    vector<int> inorder = {9, 3, 15, 20, 7};
    Solution sol;
    sol.buildTree(preorder, inorder);
    return 0;
}