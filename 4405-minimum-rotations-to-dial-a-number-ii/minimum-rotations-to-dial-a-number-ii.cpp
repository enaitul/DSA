class Solution {
public:
    int cost (int a, int b){
        int diff = abs(a - b);
        return min(diff, 10 - diff);
    }
    int minRotations(int n, string s) {
       vector<int> pref(n + 1, 0);
       vector<int> suff(n + 1, 0);
        //pref
        for (int i = 0; i< n; i++){
            int prev = (i == 0)? 0:s[i-1] - '0';
            int curr = s[i] - '0';
            pref[i + 1] = pref[i] + cost(prev, curr);
        }
        //suff
        for (int i = n -2; i>= 0; i--){
            int beforelast = s[i] - '0';
            int last = s[i + 1] - '0';
            
            suff[i] = suff[i + 1] +  cost(beforelast, last);
        }

        int ans = pref[n];
        for (int k = 0; k < n; k++){
            int prev = (k == 0)? 0: s[k-1] - '0';
            int last = s[n - 1] - '0';
            int total = pref[k] + cost(prev, last) + suff[k];
            ans = min(ans, total);
        }
        return ans;
        
    }
};