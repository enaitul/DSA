class Solution {
public:
    vector<string> path;
    vector<vector<string>> ans;
    bool isPalindrome (string &s, int left, int right){
        while (left < right){
            if (s[left] != s[right]) return false;
            left ++;
            right --;
        }
        return true;
    }
    void solve (int start, string&s){
        if (start == s.size()){
            ans.push_back(path);
            return;
        }

        for (int end = start; end < s.size(); end++){
            if (isPalindrome(s, start, end)){
                path.push_back(s.substr(start, end-start+1));
                solve (end+1, s);
                path.pop_back();
            }
        }
    }

    vector<vector<string>> partition(string s) {
        solve(0, s);
        return ans;
    }
};