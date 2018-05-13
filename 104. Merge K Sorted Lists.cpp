/**
Merge k sorted linked lists and return it as one sorted list.

Analyze and describe its complexity.

Have you met this question in a real interview?
Example
Given lists:

[
  2->4->null,
  null,
  -1->null
],
return -1->2->4->null.
 */
/**
һ�ַ�����divide&conquer��������ת��Ϊk-1����������������ϲ������⡣
��һ�ַ���������priority queue�����ʣ���ÿ��pop�Ľڵ���ǰ�����ӣ����ѵ�ǰ�ڵ����һ���ǿսڵ�push�����ȶ����С�����ظ�ֱ������Ϊ�ա�ֻ��Ҫ�������ݽṹ��д�Ƚ����㡣ע�����">"��С���ڸ�����"<"�Ǵ���ڸ�����
*/
/**
 * Definition of ListNode
 * class ListNode {
 * public:
 *     int val;
 *     ListNode *next;
 *     ListNode(int val) {
 *         this->val = val;
 *         this->next = NULL;
 *     }
 * }
 */
class Solution {
public:
    ListNode *mergeKLists(vector<ListNode *> &lists) {
        if(lists.empty()){
            return nullptr;
        }
        while(lists.size() > 1){
            lists.push_back(mergeTwoLists(lists[0], lists[1]));
            lists.erase(lists.begin());
            lists.erase(lists.begin());
        }
        return lists.front();
    }
    ListNode *mergeTwoLists(ListNode* l1, ListNode* l2) {
        if(l1 == nullptr){
            return l2;
        }
        if(l2 == nullptr){
            return l1;
        }
        if(l1->val <= l2->val){
            l1->next = mergeTwoLists(l1->next, l2);
            return l1;
        }
        else{
            l2->next = mergeTwoLists(l1, l2->next);
            return l2;
        }
    }
};

class Solution {
    struct compare {
        bool operator()(const ListNode* l, const ListNode* r) {
            return l->val > r->val;
        }
    };

public:
    ListNode *mergeKLists(vector<ListNode *> &lists) {
        priority_queue<ListNode *, vector<ListNode *>, compare> q;
        for (auto l : lists) {
            if (l) {
                q.push(l);
            }
        }

        if (q.empty()) {
            return NULL;
        }

        ListNode* result = q.top();
        q.pop();
        if (result->next) {
            q.push(result->next);
        }

        ListNode* tail = result;
        while (!q.empty()) {
            tail->next = q.top();
            q.pop();
            tail = tail->next;
            if (tail->next) {
                q.push(tail->next);
            }
        }

        return result;
    }
};