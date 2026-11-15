class Solution {
public:
    const long long mod = 1e9 + 7;
    long long numOfSubarrays(vector<int>& arr) {
        long long odd = 0;
        long long even = 1;
        long long prefix = 0;
        long long ans = 0;

        for (long long x : arr){
            prefix += x;

            if (prefix % 2 == 1){
                ans = (ans + even) % mod;
                odd++;
            }
            else{
                ans = (ans + odd) % mod;
                even++;
            }
            
        }
        return ans;
    }
};