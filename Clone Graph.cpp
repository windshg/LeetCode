/**
 * Definition for undirected graph.
 * struct UndirectedGraphNode {
 *     int label;
 *     vector<UndirectedGraphNode *> neighbors;
 *     UndirectedGraphNode(int x) : label(x) {};
 * };
 */
class Solution {
public:
    UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
        if (!node) return NULL;
        queue<UndirectedGraphNode *> q;
        q.push(node);
        unordered_map<UndirectedGraphNode *, UndirectedGraphNode *> visited;
        visited[node] = new UndirectedGraphNode(node->label);
        while (!q.empty()) {
            UndirectedGraphNode *f = q.front();
            q.pop();
            for (int i = 0; i < f->neighbors.size(); ++i) {
                UndirectedGraphNode *nb = f->neighbors[i];
                if (!visited[nb]) {
                    visited[nb] = new UndirectedGraphNode(nb->label);
                    q.push(nb);
                }
                visited[f]->neighbors.push_back(visited[nb]);
            }
        }
        return visited[node];
    }
};