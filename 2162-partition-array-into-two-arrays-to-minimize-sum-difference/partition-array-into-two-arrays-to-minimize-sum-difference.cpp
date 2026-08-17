class Solution {
public:
    void generate (vector<int> &arr, vector<vector<int>> &sums, int index, int count, int sum){
        if (index == arr.size()){
            sums[count].push_back(sum);
            return;
        }
        //don't take
        generate (arr, sums, index + 1, count, sum);
        //take
        generate (arr, sums, index + 1, count + 1, sum + arr[index]);
    }
    int minimumDifference(vector<int>& nums) {
        int total = accumulate (nums.begin(), nums.end(), 0);
        int n = nums.size()/2;

        vector<int>left (nums.begin(), nums.begin() + n);
        vector<int>right (nums.begin() + n, nums.end());

        vector<vector<int>> leftsums(n + 1);
        vector<vector<int>> rightsums (n + 1);

        generate (left, leftsums, 0, 0, 0);
        generate (right, rightsums, 0, 0 ,0);

        for (int i = 0; i<=n; i++){
            sort(rightsums[i].begin(), rightsums[i].end());
        }

        int ans = INT_MAX;
        for (int k = 0; k <= n; k++){
            for (int leftsum : leftsums[k]){
                int target = total/2 - leftsum;
                auto &arr = rightsums [n - k];
                auto it = lower_bound (arr.begin(), arr.end(), target);
                if (it != arr.end()){
                    int rightsum = *it;
                    int selectedsum = leftsum + rightsum;
                    ans = min (ans, abs(total - 2 * selectedsum));
                }
                if (it != arr.begin()){
                    --it;
                    int rightsum = *it;
                    int selectedsum = leftsum + rightsum;
                    ans = min (ans, abs(total - 2 * selectedsum));
                }
            } 
            
        }
        return ans;
    }
};