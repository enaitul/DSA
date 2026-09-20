class Solution {
public:
    long long reverseDegree(string s) {
        long long ans = 0;

        for (int i = 0; i < s.length(); i++) {

       
            int reversedIndex = 26 - (s[i] - 'a');

            
            int stringIndex = i + 1;

            
            ans += reversedIndex * stringIndex;
        }

        return ans;
    }
};