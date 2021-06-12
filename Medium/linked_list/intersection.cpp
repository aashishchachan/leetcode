
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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode *temp = headA;
        int i = 0;
        while(temp!=nullptr){
            i++;
            temp=temp->next;
        }
        temp = headB;
        int j = 0;
        while(temp!=nullptr){
            i++;
            temp=temp->next;
        }
        ListNode* tempA =headA;
        ListNode* tempB =headB;
        if(i>j){
            for (int k = 0; k<=i-j; k++){
                k++;
                temp = temp->next;
            }
        }
        else if(j>i){
            for (int k = 0; k<=i-j; k++){
                k++;
                temp = temp->next;
            }
        }

        while(tempA!=nullptr){
            if (tempA==tempB) return tempA;
            else {
                tempA=tempA->next;
                tempB=tempB->next;
            }
        }
        return new ListNode();
    }
    
};