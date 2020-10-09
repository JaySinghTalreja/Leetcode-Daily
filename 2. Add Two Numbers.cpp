/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        //ListNode *tempL1= l1, *tempL2=l2;
        ListNode *newHead=NULL;
        int carry = 0;
        ListNode* temp;
        while(l1 && l2) {
            int digitSum = l1->val + l2->val + carry;
            
            if(newHead == NULL) {
                temp = new ListNode();
                newHead = temp;
            }
            else{
                temp->next = new ListNode();
                temp = temp->next;
            }
            
            if(digitSum < 10) {
                temp->val = digitSum;
                carry = 0;
            }
            else{
                temp->val = digitSum % 10;
                carry = digitSum / 10;
            }
            l1 = l1->next;
            l2 = l2->next;
        }
        while(l1) {
            temp->next = new ListNode();
            temp = temp->next;
            if(l1->val + carry < 9) {
                temp->val = l1->val + carry;
                carry = 0;
            }
            else{
                temp->val = (l1->val + carry) % 10;
                carry = (l1->val + carry) / 10;
            }
            l1 = l1->next;
        }
        while(l2) {
            temp->next = new ListNode();
            temp = temp->next;
            if(l2->val + carry < 9) {
                temp->val = l2->val + carry;
                carry = 0;
            }
            else{
                temp->val = (l2->val + carry) % 10;
                carry = (l2->val + carry) / 10;
            }
            l2 = l2->next;
        }
        if(carry) {
            temp->next = new ListNode(carry);
        }
        return newHead;
    }
};



//Much Better Solution
ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
    ListNode preHead(0), *p = &preHead;
    int extra = 0;
    while (l1 || l2 || extra) {
        int sum = (l1 ? l1->val : 0) + (l2 ? l2->val : 0) + extra;
        extra = sum / 10;
        p->next = new ListNode(sum % 10);
        p = p->next;
        l1 = l1 ? l1->next : l1;
        l2 = l2 ? l2->next : l2;
    }
    return preHead.next;
}