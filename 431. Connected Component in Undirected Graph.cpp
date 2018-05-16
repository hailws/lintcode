/**
ind the number connected component in the undirected graph. Each node in the graph contains a label and a list of its neighbors. (a connected component (or just component) of an undirected graph is a subgraph in which any two vertices are connected to each other by paths, and which is connected to no additional vertices in the supergraph.)

 Notice
Each connected component should sort by label.

Clarification
Learn more about representation of graphs

Example
Given graph:

A------B  C
 \     |  |
  \    |  |
   \   |  |
    \  |  |
      D   E
Return {A,B,D}, {C,E}. Since there are two connected component which is {A,B,D}, {C,E}
 */
/**
无向图中找连通区域，利用dfs做。由于可能有环，因此需要记录每个顶点的访问情况。方法一中的查找下标函数以及记录定点访问情况的向量V，可以用set来替代。方法二是并查集法，可参见并查集趣味说明[https://blog.csdn.net/the_best_man/article/details/62416938]
*/

class Solution {
public:
    /*
     * @param nodes: a array of Undirected graph node
     * @return: a connected set of a Undirected graph
     */
    int lookup(vector<UndirectedGraphNode*> nodes,int target){
        int len=nodes.size();
        for(int i=0;i<len;i++){
            if(nodes[i]->label==target) return i;
        }
    }
    void dfs(vector<UndirectedGraphNode*> nodes,vector<int>& ans,vector<int>& visit,int i){
        int len=nodes[i]->neighbors.size();
        if(visit[i]==1) return;
        visit[i]=1;
        ans.push_back(nodes[i]->label);
        for(int j=0;j<len;j++){
            if(visit[lookup(nodes,nodes[i]->neighbors[j]->label)]==0){
                dfs(nodes,ans,visit,lookup(nodes,nodes[i]->neighbors[j]->label));
            }
        }
    }
    vector<vector<int>> connectedSet(vector<UndirectedGraphNode*> nodes) {
        int len=nodes.size();
        vector<vector<int>> rst;
        vector<int> visit(len);
        for(int i=0;i<len;i++){
            vector<int> ans;
            dfs(nodes,ans,visit,i);
            if(ans.size()==0) cout<<i;
            sort(ans.begin(),ans.end());
            if(ans.size()!=0) rst.push_back(ans);
        }
        return rst;// write your code here
    }
};

class Solution {
public:
    /*
     * @param nodes: a array of Undirected graph node
     * @return: a connected set of a Undirected graph
     */
    int lookup(vector<UndirectedGraphNode*> nodes,int target){
        int len=nodes.size();
        for(int i=0;i<len;i++){
            if(nodes[i]->label==target) return i;
        }
    }
    void dfs(vector<UndirectedGraphNode*> nodes,vector<int>& ans,vector<int>& visit,int i){
        int len=nodes[i]->neighbors.size();
        if(visit[i]==1) return;
        visit[i]=1;
        ans.push_back(nodes[i]->label);
        for(int j=0;j<len;j++){
            if(visit[lookup(nodes,nodes[i]->neighbors[j]->label)]==0){
                dfs(nodes,ans,visit,lookup(nodes,nodes[i]->neighbors[j]->label));
            }
        }
    }
    vector<vector<int>> connectedSet(vector<UndirectedGraphNode*> nodes) {
        int len=nodes.size();
        vector<vector<int>> rst;
        vector<int> visit(len);
        for(int i=0;i<len;i++){
            vector<int> ans;
            dfs(nodes,ans,visit,i);
            if(ans.size()==0) cout<<i;
            sort(ans.begin(),ans.end());
            if(ans.size()!=0) rst.push_back(ans);
        }
        return rst;// write your code here
    }
};
//Union-Find
class Solution {
public:
    /*
     * @param nodes: a array of Undirected graph node
     * @return: a connected set of a Undirected graph
     */
    unordered_map<int,int> father;
    int findFather(int label){
        if(father.count(label)==0) father[label]=label;
        while(label!=father[label]){
            label=father[label];
        }
        return label;
    }
    vector<vector<int>> connectedSet(vector<UndirectedGraphNode*> nodes) {
        int len=nodes.size();
        for(int i=0;i<len;i++){
            int label=nodes[i]->label;
            for(int j=0;j<nodes[i]->neighbors.size();j++){
                int nlabel=nodes[i]->neighbors[j]->label;
                father[findFather(label)]=findFather(nlabel);
            }
        }
        unordered_map<int,vector<int>> v;
        for(int i=0;i<len;i++){
            v[findFather(nodes[i]->label)].push_back(nodes[i]->label);
        }
        vector<vector<int>> rst;
        for(auto i:v){
            rst.push_back(i.second);
        }
        return rst;// write your code here
    }
};