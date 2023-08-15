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
    ListNode* partition(ListNode* head, int x) {
        ListNode *l = new ListNode(); // Dummy node for left partition
        ListNode *left = l; // Pointer for nodes less than x
        ListNode *r = new ListNode(); // Dummy node for right partition
        ListNode *right = r, *curr = head; 

        while(curr){
            if(curr->val < x){
                left->next = curr;
                left = left->next;
            }
            else{
                right->next = curr;
                right = right->next;
            }
            curr = curr->next;
        }
        
        right->next = NULL;
        left->next = r->next;
        
        return l->next;

    }
};