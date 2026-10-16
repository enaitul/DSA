class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int n = numbers.size();
        int i = 0;
        int j = n - 1;
        while (i < j){
            int sum = numbers[i] + numbers[j];
            if (sum == target){
                return {i + 1, j + 1}; //1 based index
            }

            else if (numbers[i] + numbers[j] < target){
                i++;
            }
            else{j--;}
        }
        return {};
    }
};