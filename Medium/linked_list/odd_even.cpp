
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
    ListNode* oddEvenList(ListNode* head) {
        if(head==nullptr || head->next ==nullptr) return head;
        ListNode* odd = head;
        ListNode* even = head->next;

        ListNode* otemp = odd;
        ListNode* etemp = even;
        while(otemp!=nullptr && etemp!=nullptr){
            otemp->next = etemp->next;
            if(otemp->next==nullptr) break;
            otemp = otemp->next;
            etemp->next = otemp->next;
            etemp = etemp->next;
        }
        if(etemp==nullptr) otemp->next=even;
        else if(otemp->next==nullptr){ otemp->next = even; etemp->next ==nullptr;}
            
        return odd;   
    }
};