/**
Insert a node in a sorted linked list.

Example
Given list = 1->4->6->8 and val = 5.

Return 1->4->5->6->8.
 */

/**
 * Definition of singly-linked-list:
 * class ListNode {
 * public:
 *     int val;
 *     ListNode *next;
 *     ListNode(int val) {
 *        this->val = val;
 *        this->next = NULL;
 *     }
 * }
 */

class Solution {
public:
    /**
     * @param head: The head of linked list.
     * @param val: An integer.
     * @return: The head of new linked list.
     */
    ListNode * insertNode(ListNode * head, int val) {
        ListNode* node=new ListNode(val);
        if(head==NULL) return node;
        ListNode* curr=head;
        if(curr->val>val){
            node->next=head;
            return node;
        }
        while(curr->next!=NULL){
            if(val<curr->next->val){
                ListNode* tmp=curr->next;
                curr->next=node;
                node->next=tmp;
                return head;
            }
            curr=curr->next;
        }
        curr->next=node;
        return head;// write your code here
    }
};