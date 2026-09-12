class Solution {
public:
    int countSpecialIntegers(vector<int>& nums) {
        int n = nums.size();
        vector<int> freq(101, 0);

        for (int x: nums){
            freq[x]++;
        }
        int ans = 0;
        for (int x = 0; x <= 100; x++){
            if (freq[x] == 3){
                vector<int> index;
                for (int i = 0; i<nums.size(); i++){
                    if (nums[i] == x){
                        index.push_back(i);
                    }
                }
                if (index[1] - index[0] == index[2] - index[1]){
                    ans++;
                } 
            }
        }
        return ans;
        
        
    }
};