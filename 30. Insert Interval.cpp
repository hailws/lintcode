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
合并区间的题目，第一次接触这类问题，思维比较僵化。开始的考虑是，对于已给定的集合，如果给定一个点，该点所可能处的位置下标如下，{#,(),#,(),#...,(),#},其中每个（）代表一个区间，#代表区间的间隙。记录下需要插入区间的左坐标l和右坐标r在所处的位置。之后分类讨论，两个坐标同属一个区域的情况下，如果同属于某个区间，则不用操作，如果同属于空隙，则只要在左坐标/2的位置插入新区间。两坐标同属于不同区间又有4个情况，分别针对不同情况对新区间进行边界修改。并统一删除下标在[l/2，（r+1）/2]之间的的区间(这里取r+1是因为如果l为偶数，r为奇数时若取r/2会造成原区间少删去1一个)。之后在l/2处插入新区间即可。
借用了别人的方法，分为多个两区间合并的问题，两个区间合并有两种情况，重合和不重合，不重合分为在前和在后。A1. 两个interval有重合有很多种可能性，但判断它们不重合则比较简单直观。无非两种情况：

(1) [s1, e1]  [s2, e2]：即s2>e1 
(2) [s2, e2]  [s1, e1]：即s1>e2

不重合的条件为：s2>e1 || s1>e2，反之则重合。

A2. 对于两个有重合的interval： [s1, e1]，[s2, e2]。合并后变为[min(s1,s2), max(e1,e2)]。
所以插入interval a的算法为：扫描队列中每个interval I[i]：
如果a已经被插入了，则只要插入I(i)就行。
如果a在I(i)前，则先插入a再插入I(i)到结果。
如果a和I(i)有重合，则将I(i)合并入a，但并不插入结果。
如果a在I(i)后，则插入I(i)到结果。
关键步骤是如果有重合就将区间合并，再和下一个区间进行插入比较。
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