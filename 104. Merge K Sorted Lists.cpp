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
一种方法是divide&conquer，将问题转换为k-1个两个已排序链表合并的问题。
另一种方法是利用priority queue的性质，将每次pop的节点与前面的相接，并把当前节点的下一个非空节点push到优先队列中。如此重复直到队列为空。只需要根据数据结构来写比较运算。注意的是">"是小的在头部，"<"是大的在头部。
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