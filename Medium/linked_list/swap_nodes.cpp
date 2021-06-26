#include <bits/stdc++.h>
using namespace std;

#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL);
#define external_io() freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);

//Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode* swapPairs(ListNode* head) {
    if(head==nullptr || head->next==nullptr) return head;
    ListNode rt (0,head);
    ListNode *root = &rt;
    ListNode *sol = head->next;
    while(root!=nullptr && root->next!=nullptr && root->next->next!=nullptr){
        ListNode *temp1 = root->next;
        ListNode *temp2 = root->next->next;
        temp1->next = temp2->next;
        temp2->next=temp1;
        root->next=temp2;
        root=root->next->next;    
    }
    return sol;
}        

int main(){
    fast_cin();
    external_io();
    int n;
    cin >> n;
    vector<int> arr;
    int t;
    ListNode root(0);
    ListNode *node = &root;
    for (int i = 0; i < n; i++){
        cin >> t;
        node->next = new ListNode(t);
        node=node->next;
    }
    node=root.next;
    node = swapPairs(node);
    for (int i = 0; i < n; i++){
        cout<<node->val<<" ";
        node=node->next;
    }
    return 0;
}