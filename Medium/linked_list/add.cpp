
//  Definition for singly-linked list.
 struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int carry=0;
        ListNode* curr = new ListNode(0);
        ListNode *sol = curr;
        while(l1!=nullptr || l2!=nullptr){

            int l1val, l2val;
            if(l1==nullptr) l1val = 0;
             else {
                l1val = l1->val;
                l1=l1->next;
            }    
            if(l2==nullptr) l2val = 0;
            else {
                l2val = l2->val;
                l2=l2->next;
            }
            int sum = l1val + l2val + carry;
            if(sum>9){
                carry = 1;
                sum = sum % 10;
            }
            else{
                carry = 0;
            }
            curr->next = new ListNode(sum);
            
            curr = curr->next;
            l1=l1->next;
            l2=l2->next;
        }
        if(carry>0){
            curr->next = new Listnode(carry);
        }
        return sol->next;
    }
};