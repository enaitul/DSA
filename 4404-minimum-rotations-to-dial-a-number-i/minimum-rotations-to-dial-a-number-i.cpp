class Solution {
public:
    int minRotations(string s) {
        int i = 0; //start
        int total = 0; //rotations

        for (char c : s){
            int dest = c - '0'; //next digit
            total += min (abs(i - dest), 10 - abs(i - dest));
            i = dest;
        }

        return total;
        
    }
};