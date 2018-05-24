/**
Given a non-overlapping interval list which is sorted by start point.

Insert a new interval into it, make sure the list is still in order and non-overlapping (merge intervals if necessary).

Have you met this question in a real interview?
Example
Insert (2, 5) into [(1,2), (5,9)], we get [(1,9)].

Insert (3, 4) into [(1,2), (5,9)], we get [(1,2), (3,4), (5,9)].
 */

/**
 * Definition of Interval:
 * classs Interval {
 *     int start, end;
 *     Interval(int start, int end) {
 *         this->start = start;
 *         this->end = end;
 *     }
 * }
 */

/**
�ϲ��������Ŀ����һ�νӴ��������⣬˼ά�ȽϽ�������ʼ�Ŀ����ǣ������Ѹ����ļ��ϣ��������һ���㣬�õ������ܴ���λ���±����£�{#,(),#,(),#...,(),#},����ÿ����������һ�����䣬#��������ļ�϶����¼����Ҫ���������������l��������r��������λ�á�֮��������ۣ���������ͬ��һ�����������£����ͬ����ĳ�����䣬���ò��������ͬ���ڿ�϶����ֻҪ��������/2��λ�ò��������䡣������ͬ���ڲ�ͬ��������4��������ֱ���Բ�ͬ�������������б߽��޸ġ���ͳһɾ���±���[l/2����r+1��/2]֮��ĵ�����(����ȡr+1����Ϊ���lΪż����rΪ����ʱ��ȡr/2�����ԭ������ɾȥ1һ��)��֮����l/2�����������伴�ɡ�
�����˱��˵ķ�������Ϊ���������ϲ������⣬��������ϲ�������������غϺͲ��غϣ����غϷ�Ϊ��ǰ���ں�A1. ����interval���غ��кܶ��ֿ����ԣ����ж����ǲ��غ���Ƚϼ�ֱ�ۡ��޷����������

(1) [s1, e1]  [s2, e2]����s2>e1 
(2) [s2, e2]  [s1, e1]����s1>e2

���غϵ�����Ϊ��s2>e1 || s1>e2����֮���غϡ�

A2. �����������غϵ�interval�� [s1, e1]��[s2, e2]���ϲ����Ϊ[min(s1,s2), max(e1,e2)]��
���Բ���interval a���㷨Ϊ��ɨ�������ÿ��interval I[i]��
���a�Ѿ��������ˣ���ֻҪ����I(i)���С�
���a��I(i)ǰ�����Ȳ���a�ٲ���I(i)�������
���a��I(i)���غϣ���I(i)�ϲ���a����������������
���a��I(i)�������I(i)�������
�ؼ�������������غϾͽ�����ϲ����ٺ���һ��������в���Ƚϡ�
*/

class Solution {
public:
    /**
     * @param intervals: Sorted interval list.
     * @param newInterval: new interval.
     * @return: A new interval list.
     */
    vector<Interval> insert(vector<Interval> &intervals, Interval newInterval) {
        int last=INT_MIN,left=newInterval.start,right=newInterval.end,l=0,r=0,count=0;
        for(int it=0;it<intervals.size();it++){
            if(left>last && left<intervals[it].start){
                l=count;
            }
            if(right>last && right<intervals[it].start){
                r=count;
                break;
            }
            count++;
            if(left>=intervals[it].start && left<=intervals[it].end){
                l=count;
            }
            if(right>=intervals[it].start && right<=intervals[it].end){
                r=count;
                break;
            }
            count++;
            last=intervals[it].end;
        }
        if(intervals.size()!=0 && left>intervals[intervals.size()-1].end){
            l=count;
        }
        if(intervals.size()!=0 && right>intervals[intervals.size()-1].end){
            r=count;
        }
        Interval A;
        if(l==r){
            if(l%2==0){
                A=Interval(left,right);
            }
        }
        if(l%2==1 && r%2==1){
            A=Interval(intervals[(l-1)/2].start,intervals[(r-1)/2].end);
        }
        if(l%2==0 && r%2==0){
            A=Interval(left,right);
        }
        if(l%2==1 && r%2==0){
            A=Interval(intervals[(l-1)/2].start,right);
        }
        if(l%2==0 && r%2==1){
            A=Interval(left,intervals[(r-1)/2].end);
        }
        intervals.erase(intervals.begin()+l/2,intervals.begin()+(r+1)/2);
        intervals.insert(intervals.begin()+l/2,A);
        return intervals;// write your code here
    }
};

class Solution {
public:
    vector<Interval> insert(vector<Interval> &intervals, Interval newInterval) {
        vector<Interval> ret;
        bool isInsert = false;
        for(int i=0; i<intervals.size(); i++) {
            // already insert newInterval
            if(isInsert) {
                ret.push_back(intervals[i]);
                continue;
            }

            // insert newInterval before current interval
            if(newInterval.end < intervals[i].start) {
                ret.push_back(newInterval);
                ret.push_back(intervals[i]);
                isInsert = true;
                continue;
            }

            // combine newInterval with current interval
            if(newInterval.start<=intervals[i].end && intervals[i].start<=newInterval.end) {
                newInterval.start = min(newInterval.start, intervals[i].start);
                newInterval.end = max(newInterval.end, intervals[i].end);
                continue;
            }

            // newInterval after current interval
            ret.push_back(intervals[i]);
        }

        if(!isInsert) ret.push_back(newInterval);
        return ret;
    }
};