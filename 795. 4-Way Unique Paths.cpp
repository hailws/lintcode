/**
 *
Description: A robot is located at the top-left corner of a m x n grid.
The robot can move any direction at any point in time, but every grid can only be up to once. The robot is trying to reach the bottom-right corner of the grid.
How many possible unique paths are there?

Example
Given m = 2 and n = 3, return 4.
Given m = 3 and n = 3, return 12.
 */
/**
һ�ʻ����Թ����⣬Ҫ��ó���ͬ·���ĸ��������û��ݷ���dfs����ÿ���ڵ���4�����ܵ����ڽڵ㣨ע��߽磩������visit[][�����¼������ķ��������
*/

class Solution {
public:
    /**
     * @param m: the row
     * @param n: the column
     * @return: the possible unique paths
     */
    void countpath(int m,int n,int x,int y,vector<vector<int>> visit, int &count){
        if(x==m-1 && y==n-1) {
            count++;
            return;
        }
        visit[x][y]=1;
        if(x+1<m && !visit[x+1][y]){
            countpath(m,n,x+1,y,visit,count);
        }
        if(x-1>=0 && !visit[x-1][y]){
            countpath(m,n,x-1,y,visit,count);
        }
        if(y+1<n && !visit[x][y+1]){
            countpath(m,n,x,y+1,visit,count);
        }
        if(y-1>=0 && !visit[x][y-1]){
            countpath(m,n,x,y-1,visit,count);
        }
        if((x-1<0 || (x-1>=0 && visit[x-1][y])) && (x+1>=m || (x+1<m && visit[x+1][y])) && (y-1<0 || (y-1>=0 && visit[x][y-1])) && (y+1>=n || (y+1<n && visit[x][y+1]))) return;
    }
    int uniquePaths(int m, int n) {
        vector<vector<int>> visit(m,vector<int>(n));
        int count=0;
        countpath(m,n,0,0,visit,count);
        return count;
        // Write your code here
    }
};