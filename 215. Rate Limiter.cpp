/**
Implement a rate limiter, provide one method: is_ratelimited(timestamp, event, rate, increment).

timestamp: The current timestamp, which is an integer and in second unit.
event: The string to distinct different event. for example, "login" or "signup".
rate: The rate of the limit. 1/s (1 time per second), 2/m (2 times per minute), 10/h (10 times per hour), 100/d (100 times per day). The format is [integer]/[s/m/h/d].
increment: Whether we should increase the counter. (or take this call as a hit of the given event)
The method should return true or false to indicate the event is limited or not.
F
Example
is_ratelimited(1, "login", "3/m", true), return false.
is_ratelimited(11, "login", "3/m", true), return false.
is_ratelimited(21, "login", "3/m", true), return false.
is_ratelimited(30, "login", "3/m", true), return true.
is_ratelimited(65, "login", "3/m", true), return false.
is_ratelimited(300, "login", "3/m", true), return false.

 */
/**
速率限制，针对不同操作的出现情况，以及限制速率，来决定是否限制当前操作。
很自然想到用map来做。一个key为操作名，另一个为出现时间。值为该操作的次数。
*/

class Solution {
public:
    /*
     * @param timestamp: the current timestamp
     * @param event: the string to distinct different event
     * @param rate: the format is [integer]/[s/m/h/d]
     * @param increment: whether we should increase the counter
     * @return: true or false to indicate the event is limited or not
     */
    unordered_map<string,unordered_map<int,int>> mp;
    bool isRatelimited(int timestamp, string event, string rate, bool increment) {
        int times=stoi(rate);
        int len=rate.size();
        int coe=0;
        if(rate[len-1]=='s'){
            coe=1;
        }
        else if(rate[len-1]=='m'){
            coe=60;
        }
        else if(rate[len-1]=='h'){
            coe=60*60;
        }
        else{
            coe=60*60*24;
        }
        int total=0;
        for(auto i:mp[event]){
            if(i.first>=timestamp-coe+1) total+=i.second;
        }
        bool rst = total >= times;
        if (increment && !rst) {
            mp[event][timestamp]++;
        }
        return rst;// write your code here
    }
};