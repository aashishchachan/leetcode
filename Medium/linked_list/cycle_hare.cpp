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
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        if(head == nullptr) return nullptr;
        ListNode * tortoise;
        ListNode * hare;
        tortoise = head;
        hare = head->next;
        if(hare == nullptr) return nullptr;
        
        while(tortoise != hare){
            tortoise = tortoise->next;
            if(hare ==nullptr || hare->next == nullptr || hare->next->next==nullptr) return nullptr;
            hare = hare->next->next;
        }
        ListNode* sol = head;
        hare = hare->next;
        while(sol != hare){
            sol = sol->next;
            hare = hare->next;
        }
        return sol;
    }
};