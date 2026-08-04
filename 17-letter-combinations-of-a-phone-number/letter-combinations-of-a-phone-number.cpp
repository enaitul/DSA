class Solution {
public:

  vector<string> ans;
    string path;

    vector<string> mp = {
        "",     // 0
        "",     // 1
        "abc",  // 2
        "def",  // 3
        "ghi",  // 4
        "jkl",  // 5
        "mno",  // 6
        "pqrs", // 7
        "tuv",  // 8
        "wxyz"  // 9
    };


    void solve (int index, string &digits){
        if (index == digits.size()){
            ans.push_back(path);
            return;
        }

        string letters = mp[digits[index] - '0'];

        for (char ch: letters){
            path.push_back(ch);
            solve(index+1, digits);
            path.pop_back();
        }
    }
    vector<string> letterCombinations(string digits) {
        if (digits.empty()) return {};
        solve(0, digits);
        return ans;
    }
};