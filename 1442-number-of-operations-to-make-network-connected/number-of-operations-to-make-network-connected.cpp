class Solution {
public:
    int findparent(int node, vector<int>& parent) {
        if (node == parent[node]) {
            return node;
        }
        return parent[node] = findparent(parent[node], parent);
    }
    void unionbysize(int u, int v, vector<int>& parent, vector<int>& size) {
        int pu = findparent(u, parent);
        int pv = findparent(v, parent);

        if (pu == pv)
            return;

        // attach smaller to larger
        if (size[pu] < size[pv]) {
            parent[pu] = pv;
            size[pv] += size[pu];
        }

        else {
            parent[pv] = pu;
            size[pu] += size[pv];
        }
    }
    int makeConnected(int n, vector<vector<int>>& connections) {
        if (connections.size() < n-1) return -1;

        vector<int> parent(n);
        vector<int> size(n, 1);

        for (int i = 0; i < n; i++){
            parent[i] = i;
        }

        for (auto &edge: connections){
            int u = edge[0];
            int v = edge[1];

            unionbysize(u, v, parent, size);
        }

        int components = 0;

        for (int i = 0; i< n; i++){
            if (findparent(i, parent) == i){
                components++;
            }
        }

        return components - 1;
    }
};