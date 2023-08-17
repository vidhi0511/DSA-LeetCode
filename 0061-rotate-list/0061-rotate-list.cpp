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
    ListNode* rotateRight(ListNode* head, int k) {
        
        if(!head || !head->next || k==0) return head;
        
        ListNode *curr = head, *prev = head;
        int l = 0;
        
        while(curr){
            curr = curr->next;
            l++;
        }
        curr = head;
        k = k % l;
        
        while(l-k > 0){
            l--;
            prev = curr;
            curr = curr->next;
        }
        
        if(k==0) return head;
        
        prev->next = NULL;
        ListNode *temp = curr;
        
        while(curr->next) curr = curr->next;
        curr->next = head;
        
        return temp;
    }
};