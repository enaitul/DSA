class Solution {
public:
    // 1. Find ultimate parent
    int findParent(int node, vector<int>& parent) {

        if (node == parent[node])
            return node;

        return parent[node] = findParent(parent[node], parent);
    }

    // 2. Union by Size
    void unionBySize(int u, int v, vector<int>& parent, vector<int>& size) {

        int pu = findParent(u, parent);
        int pv = findParent(v, parent);

        if (pu == pv)
            return;

        if (size[pu] < size[pv]) {
            parent[pu] = pv;
            size[pv] += size[pu];
        } else {
            parent[pv] = pu;
            size[pu] += size[pv];
        }
    }
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {

        int n = accounts.size();
        vector<int> parent(n);
        vector<int> size(n, 1);

        for (int i = 0; i< n; i++){
            parent[i] = i;
        }

        //Map email -> index
        unordered_map<string, int> mp;
        for (int i = 0; i< n; i++){
            for (int j = 1; j < accounts[i].size(); j++){
                string email = accounts[i][j];

                if (mp.find(email) != mp.end()){
                    unionBySize(i, mp[email], parent, size);
                }

                else{
                    mp[email] = i;
                }
            }
        }

        //Group emails by node
        vector<vector<string>> mergedEmails(n);
        for (auto &it : mp){
            string email = it.first;
            int accountIndex = it.second;

            int node = findParent(accountIndex, parent);

            mergedEmails[node].push_back(email);
        }

        //Create the ans
        vector<vector<string>> ans;
        for (int i = 0; i < n; i++){
            if (mergedEmails[i].empty()) continue;

            sort(mergedEmails[i].begin(), mergedEmails[i].end());

            vector<string> temp;
            temp.push_back(accounts[i][0]);

            for(auto &email: mergedEmails[i]){
                temp.push_back(email);
            }

            ans.push_back(temp);
        }
        return ans;

    }
};