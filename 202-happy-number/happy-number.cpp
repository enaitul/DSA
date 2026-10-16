class Solution {
public:
    int sumofsquare(int n) {
        long long sum = 0;
        while (n) {
            long long digit = n % 10;
            n = n / 10;
            sum += digit * digit;
        }
        return sum;
    }
    bool isHappy(int n) {
        unordered_set<int> seen; //if there is a cycle, that is one number repeats, that means it is an unhappy number

        while (n != 1 && seen.find(n) == seen.end()) {
            seen.insert(n);
            n = sumofsquare(n);
        }

        return n == 1;
    }
};