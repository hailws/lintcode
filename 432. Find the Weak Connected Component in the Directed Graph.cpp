/**
Find the number Weak Connected Component in the directed graph. Each node in the graph contains a label and a list of its neighbors. (a connected set of a directed graph is a subgraph in which any two vertices are connected by direct edge path.)

 Notice
Sort the element in the set in increasing order

Example
Given graph:

A----->B  C
 \     |  |
  \    |  |
   \   |  |
    \  v  v
     ->D  E <- F
Return {A,B,D}, {C,E,F}. Since there are two connected component which are {A,B,D} and {C,E,F}
 */

/**
 * Definition for Directed graph.
 * struct DirectedGraphNode {
 *     int label;
 *     vector<DirectedGraphNode *> neighbors;
 *     DirectedGraphNode(int x) : label(x) {};
 * };
 */

/**
�ҳ�����ͼ����ͨ���򡣲��ò��鼯Union-Find�������ù�ϣ���¼ÿ���ڵ�ĸ��ڵ㡣��ʼʱÿ���ڵ�ĸ��ڵ�Ϊ������������㣬������ͨ�����޸ĸ��ڵ㡣���磬����A->B,��BΪA�ĸ��ڵ㣬��Aԭ�ȵĸ��ڵ�ĸ��ڵ��ΪB�ĸ��ڵ㡣��󽫸��ڵ���ͬ�Ľڵ���������ɡ�
*/

class Solution {
private:
    unordered_map<int, int> father;
public:
    /**
     * @param nodes a array of directed graph node
     * @return a connected set of a directed graph
     */
    vector<vector<int>> connectedSet2(vector<DirectedGraphNode*>& nodes) {
        for(int i = 0; i < nodes.size(); i++) {
            int label = nodes[i]->label;
            if (father.count(label) == 0) {
                father[label] = label;
            }

            for(int j = 0; j < nodes[i]->neighbors.size(); j++) {
                int neLabel = nodes[i]->neighbors[j]->label;
                father[findFather(label)] = findFather(neLabel);
            }
        }
        unordered_map<int, vector<int>> v;
        for(int i = 0; i < nodes.size(); i++) {
            int label = nodes[i]->label;
            v[findFather(label)].push_back(label);
        }

        vector<vector<int>> rst;
        for(auto i:v) {
            rst.push_back(i.second);
        }

        return rst;
    }

    int findFather(int label) {
        if (father.count(label) == 0) {
            father[label] = label;
            return label;
        }

        while (father[label] != label) {
            label = father[label];
        }
        return label;
    }
};