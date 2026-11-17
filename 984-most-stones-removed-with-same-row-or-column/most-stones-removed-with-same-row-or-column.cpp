class DSU {
public:
    vector<int> parent, size;

    DSU(int n) {
        parent.resize(n);
        size.resize(n, 1);

        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }
    }

    int find(int node) {
        if (parent[node] == node)
            return node;

        return parent[node] = find(parent[node]);
    }

    void unite(int u, int v) {
        u = find(u);
        v = find(v);

        if (u == v)
            return;

        if (size[u] < size[v]) {
            parent[u] = v;
            size[v] += size[u];
        } else {
            parent[v] = u;
            size[u] += size[v];
        }
    }
};

class Solution {
public:
    int removeStones(vector<vector<int>>& stones) {
        int offset = 10001;

        DSU dsu(20002);

        for (auto& stone : stones) {
            int row = stone[0];
            int col = stone[1] + offset;

            dsu.unite(row, col);
        }

        unordered_set<int> st;

        for (auto& stone : stones) {
            int row = stone[0];
            st.insert(dsu.find(row));
        }

        return stones.size() - st.size();
    }
};