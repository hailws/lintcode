/**
Write code to remove duplicates from an unsorted linked list.

Example
Given 1->3->2->1->4.

Return 1->3->2->4

Challenge
(hard) How would you solve this problem if a temporary buffer is not allowed? In this case, you don't need to keep the order of nodes.
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
/**
ȥ���ظ��ڵ㡣�������ʹ�ö���ռ䣬��set��¼ĳֻ������񣬿���ֻ�õ�ѭ������������ɡ�������ö���ռ䣬��˫��ѭ����
*/


class Solution {
public:
    /**
     * @param head: The first node of linked list.
     * @return: Head node.
     */
    ListNode * removeDuplicates(ListNode * head) {
        if(!head) return NULL;
        ListNode* curr=head;
        while(curr!=NULL){
            ListNode* inner=curr;
            int c_v=curr->val;
            while(inner->next!=NULL){
                if(inner->next->val==c_v){
                    inner->next=inner->next->next;
                }
                else inner=inner->next;
            }
            curr=curr->next;
        }
        return head;// write your code here
    }
};