class Solution {
public:
    ListNode* DiffereceList(ListNode* L1, ListNode* L2) {
        if(!L1) {
            return L2;
        }
        if(!L2) {
            return L1;
        }
        int numOne = 0;
        int numTwo = 0;
        while(L1 != NULL) {
            numOne *= 10;
            numOne += L1->val;
            L1 = L1->next;
        }
        while(L2 != NULL) {
            numTwo *= 10;
            numTwo += L2->val;
            L2 = L2->next;
        }
        int difference = (numOne >= numTwo) ? (numOne-numTwo) : (numTwo - numOne);
        ListNode *head = new ListNode(difference % 10);
        difference /= 10;
        ListNode *temp = head;
        while(difference > 0) {
            temp->next = newNode(difference % 10);
            difference / = 10;
            temp = temp->next;
        }
        return head;

    }
};