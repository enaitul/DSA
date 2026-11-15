class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {

        // 1. Initialize matrix
        vector<vector<int>> ans(n, vector<int>(n, 0));

        // 2. Initialize boundaries
        int top = 0;
        int bottom = n - 1;
        int left = 0;
        int right = n - 1;

        // 3. Number to insert
        int num = 1;

        // 4. Fill matrix in spiral order
        while (top <= bottom && left <= right) {

            // Left -> Right
            for (int j = left; j <= right; j++) {
                ans[top][j] = num++;
            }
            top++;

            // Top -> Bottom
            for (int i = top; i <= bottom; i++) {
                ans[i][right] = num++;
            }
            right--;

            // Right -> Left
            if (top <= bottom) {
                for (int j = right; j >= left; j--) {
                    ans[bottom][j] = num++;
                }
                bottom--;
            }

            // Bottom -> Top
            if (left <= right) {
                for (int i = bottom; i >= top; i--) {
                    ans[i][left] = num++;
                }
                left++;
            }
        }

        return ans;
    }
};