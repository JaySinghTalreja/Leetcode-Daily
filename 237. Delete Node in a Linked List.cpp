/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    void deleteNode(ListNode* node) {
        ListNode* temp = node->next;
        ListNode *prev = node;
        while(temp->next != NULL) {
            prev->val = temp->val;
            prev = prev->next;
            temp = temp->next;
        }
        prev->val = temp->val;
        prev->next = NULL;
        delete temp;
    }
};
//Better Alternative O(1)
public void deleteNode(ListNode node) {
    node.val = node.next.val;
    node.next = node.next.next;
}

//Much Better Alternative
void deleteNode(ListNode* node) {
    auto next = node->next;
    *node = *next;
    delete next;
}