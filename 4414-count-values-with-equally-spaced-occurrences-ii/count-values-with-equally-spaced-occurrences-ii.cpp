class Solution {
public:
    int countSpecialIntegers(vector<int>& nums) {
        unordered_map<int, vector<int>> mp;
        for (int i = 0; i< nums.size(); i++){
            mp[nums[i]].push_back(i);
        } // element -> indices mapping
        int ans = 0;
        for (auto&[x, indices] : mp){
            if (indices.size() < 3){
                continue;
            }
            bool special = true;
            int gap = indices[1] - indices[0];
            for (int i = 2; i < indices.size(); i++){
                if (indices[i] - indices[i-1] != gap){
                    special = false;
                    break;
                }
            }
            if (special){
                ans++;
            }
            
        }
        return ans;
    }
};