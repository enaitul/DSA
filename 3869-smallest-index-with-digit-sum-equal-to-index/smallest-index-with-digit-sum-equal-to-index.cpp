class Solution {
public:
    int sumofdigits(int num) {
        num = abs(num);
        int sum = 0;

        while (num) {
            sum += num % 10;
            num /= 10;
        }

        return sum;
    }
    int smallestIndex(vector<int>& nums) {
        int n = nums.size();
        int ind = -1;
        for (int i = 0; i< n; i++){
            if (sumofdigits(nums[i]) == i){
                ind = i;
                break;
            }
        }
        return ind;
    }
};