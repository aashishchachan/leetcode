#include <bits/stdc++.h>
using namespace std;

#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL);
#define external_io() freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
#define secsort() bool sortbysec(const pair<int,int> &a, const pair<int,int> &b){return (a.second < b.second);}
#define MOD 1000000007
#define MAXN 100005

//Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    
    pair <ListNode* , ListNode*> reverseK(ListNode *head, int k){
        if(head == nullptr) return make_pair(nullptr, nullptr);
        if(k==1) return make_pair(head, head);
        pair <ListNode* , ListNode*> temp;
        temp = reverseK(head->next, --k);
        head->next = (temp.second)->next;
        (temp.second)->next = head;
        temp.second = head;
        return temp;
    }
    
    
    ListNode* reverseKGroup(ListNode* head, int k) {
        int i=0;
        ListNode *root = head;
        while(root!=nullptr){
            i++;
            root=root->next;
        }
        int j= i/k;
        pair <ListNode* , ListNode*> temp;
        temp.first = head;
        //cout<<(temp.first)->val;
        root = new ListNode();
        root->next = head;
        ListNode* sol = root;
        while(j--){
            if(root->next==nullptr) break;
            temp = reverseK(root->next, k);
            root->next = temp.first;
            root = temp.second;
            // cout<< root->val;
            // cout<< sol->next->val;
        }
        head = sol->next;
        delete sol;
        return head;
        
    }
};