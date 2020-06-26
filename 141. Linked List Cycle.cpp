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
    bool hasCycle(ListNode *head) {
        if(head == NULL || head->next == NULL){
            return false;
        }
        ListNode *slow = head;
        ListNode *fast = head;
        fast = fast->next;
        while(slow != NULL && fast != NULL) {
            if(slow == fast) {
                return true;
            }
            slow = slow->next;
            fast = fast->next->next;
        }
        return false;
    }
};

//Alternative
bool hasCycle(ListNode *head) 
{
    ListNode *fast;
    fast = head;
    while (head)
    {
        head = head->next;
        if (fast->next && fast->next->next)
            fast = fast->next->next;
        else
            return false;
            
        if (fast == head)
            return true;
    }
    
    return false;
}

bool hasCycle(struct ListNode *head) {
    struct ListNode *fast=head, *slow=head;
    while( slow && fast && fast->next ){
        fast=fast->next->next;
        slow=slow->next;
        if(fast==slow) return true;
    }
    return false;
}

Complexity analysis

Time complexity : O(n)O(n). Let us denote nn as the total number of nodes in the linked list. To analyze its time complexity, we consider the following two cases separately.

List has no cycle:
The fast pointer reaches the end first and the run time depends on the lists length, which is O(n)O(n).

List has a cycle:
We break down the movement of the slow pointer into two steps, the non-cyclic part and the cyclic part:

The slow pointer takes "non-cyclic length" steps to enter the cycle. At this point, the fast pointer has already reached the cycle. \text{Number of iterations} = \text{non-cyclic length} = NNumber of iterations=non-cyclic length=N

Both pointers are now in the cycle. Consider two runners running in a cycle - the fast runner moves 2 steps while the slow runner moves 1 steps at a time. Since the speed difference is 1, it takes \dfrac{\text{distance between the 2 runners}}{\text{difference of speed}} 
difference of speed
distance between the 2 runners
​	
  loops for the fast runner to catch up with the slow runner. As the distance is at most "\text{cyclic length K}cyclic length K" and the speed difference is 1, we conclude that
\text{Number of iterations} = \text{almost}Number of iterations=almost "\text{cyclic length K}cyclic length K".

Therefore, the worst case time complexity is O(N+K)O(N+K), which is O(n)O(n).

Space complexity : O(1)O(1). We only use two nodes (slow and fast) so the space complexity is O(1)O(1).


If there are n nodes, the slow pointer is guaranteed to travel no more than n steps before the fast pointer either meets the slow pointer or finds an end to the list. That means you do O(n) work advancing the slow pointer, and you advance the fast pointer about twice that, which is also O(n). Thus, the whole algorithm is O(n).



