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
    ListNode* oddEvenList(ListNode* head) {
        if(!head || !head->next) {
            return head;
        }
        ListNode* odd = head;
        ListNode* even = head->next;
        ListNode* secondHead = head->next;
        while(even && even->next) {
            odd->next = odd->next->next;
            odd = odd->next;
            even->next = even->next->next;
            even = even->next;
        }
        if(odd != NULL) {
            odd->next = secondHead;
        }
        else {
            odd = secondHead;
        }
        return head;
    }
};

//O(N) O(1)
//Test Case Even and Od d Length;