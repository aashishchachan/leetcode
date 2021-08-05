#include <bits/stdc++.h>
using namespace std;

#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL);
#define external_io() freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
#define secsort() bool sortbysec(const pair<int,int> &a, const pair<int,int> &b){return (a.second < b.second);}
#define MOD 1000000007
#define MAXN 100005

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};


// iterative
ListNode* reverseList(ListNode* head) {
    if(head==nullptr) return head;
    ListNode* temp1, *temp2, *temp3;
    
    temp1 = head;
    temp2 = head;
    temp3 = temp2->next;
    
    while( temp3!=nullptr && temp2!=nullptr && temp2->next!=nullptr ){
        temp2->next = temp3->next;
        temp3->next = temp1;
        temp1=temp3;
        temp3=temp2->next;
    }
    return temp1;
}

// recursive
ListNode* reverse(ListNode* head, ListNode* &sol) {
    ListNode *temp;

    if (head->next==NULL) {
        sol=head;
        head->next=head;
        temp=head;
        return temp;
        }
    temp=reverse(head->next, sol);
    temp->next=head;
    temp=head;
    return temp; 
}
ListNode* reverseList(ListNode* head){
    if (head==NULL) return head;
    ListNode* sol;
    ListNode* temp;
    temp=reverse(head, sol );
    temp->next=NULL;
    return sol;
}

int main(){
    fast_cin();
    int n;
    cin>>n;
    vector <int> arr(n);
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
    solve(arr);
    return 0;
}