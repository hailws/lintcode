/**
Given a list, each element in the list can be a list or integer. flatten it into a simply list with integers.

 Notice
If the element in the given list is a list, it can contain list too.

Have you met this question in a real interview?
Example
Given [1,2,[1,2]], return [1,2,1,2].

Given [4,[3,[2,[1]]]], return [4,3,2,1].

Challenge
Do it in non-recursive.
 */

/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Return true if this NestedInteger holds a single integer,
 *     // rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds,
 *     // if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Return the nested list that this NestedInteger holds,
 *     // if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */

/**
��ƽǶ���б�����ÿ��Ԫ�ض���һ��nestedList�������������ֱ�Ӳ�������������Ҫ��vector<nestedList>��֣����ֲ��Ƕ�׵Ľṹ����Ȼ�������뵽�ݹ���⣬�緽��һ��
�����õݹ飬��������dfs˼�����Ҫ������stack��ʵ�֣���Ϊ��Ҫ�Ӻ���ǰ��ֲ��ܱ�֤˳��Ĺ̶�������stack��pop��Ԫ���ǵ���ģ���˽�������һ��stack���ٴε���ȥ��
*/

class Solution {
public:
    // @param nestedList a list of NestedInteger
    // @return a list of integer
    void dfs(vector<NestedInteger> nestedList,vector<int>& rst){
        for(int i=0;i<nestedList.size();i++){
            if(nestedList[i].isInteger()){
                rst.push_back(nestedList[i].getInteger());
            }
            else{
                dfs(nestedList[i].getList(),rst);
            }
        }
    }
    vector<int> flatten(vector<NestedInteger> &nestedList) {
        vector<int> rst;
        dfs(nestedList,rst);
        return rst;// Write your code here
    }
};

class Solution {
public:
    // @param nestedList a list of NestedInteger
    // @return a list of integer
    vector<int> flatten(vector<NestedInteger> &nestedList) {
        vector<int> rst;
        if(nestedList.size()==0) return rst;
        stack<NestedInteger> q;
        stack<int> s;
        for(int i=0;i<nestedList.size();i++){
            q.push(nestedList[i]);
        }
        while(!q.empty()){
            NestedInteger tmp=q.top();
            q.pop();
            if(tmp.isInteger()){
                s.push(tmp.getInteger());
            }
            else{
                for(auto i:tmp.getList()){
                    q.push(i);
                }
            }
        }
        while(!s.empty()){
            int tmp=s.top();
            s.pop();
            rst.push_back(tmp);
        }
        return rst;// Write your code here
    }
};