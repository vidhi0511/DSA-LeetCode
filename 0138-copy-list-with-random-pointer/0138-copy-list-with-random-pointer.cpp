/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        //Using extra space

        // unordered_map<Node*,Node*> m;
        // Node* curr = head;
        // while(curr){
        //    m[curr] = new Node(curr->val);
        //     curr = curr->next; 
        // }
        // curr = head;
        // while(curr){
        //     m[curr]->next = m[curr->next];
        //     m[curr]->random = m[curr->random];
        //     curr = curr->next; 
        // }
        
        // return m[head];

        //without space

        Node* curr = head;
        while(curr){
            Node* temp = curr->next;
            curr->next  = new Node(curr->val);
            curr->next->next = temp;
            curr = temp;
        }
        
        curr = head;
        
        while(curr){
            if(curr->random) 
                curr->next->random = curr->random->next;
            curr = curr->next->next;
        }
        
        Node* ans = new Node(0);
        curr=ans;
        
        while(head){
            curr->next = head->next;
            curr = curr->next;
            head->next = head->next->next;
            head = head->next;
        }
        
        return ans->next;


    }
};