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
    ListNode* reverseList(ListNode* head) {
        if(head == NULL){
            return head;
        }
        head = reverse(head);
        return head;
    }
private: 
    ListNode* reverse(ListNode* current, ListNode* prev = NULL){
        ListNode *newHead = NULL;
        if(current->next == NULL){
            current->next = prev;
            newHead = current;
            return newHead;
        }
        else{
            newHead = reverse(current->next, current);
            current->next = prev;
            return newHead;
        }
        
    }
};


//COULD BE DONE USING STACK or multiple pointers as well


//MUST SEE
https://leetcode.com/problems/reverse-linked-list/discuss/58130/C%2B%2B-Iterative-and-Recursive