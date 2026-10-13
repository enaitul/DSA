class Solution {
public:
    string countAndSay(int n) {
        //seq er prothom number hocche 1
        string result = "1";

        for (int term = 2; term <= n; term++){
            string next = "";

            int i = 0;

            while (i < result.size()){

                char digit = result[i];

                int count = 0;

                while (i < result.size() && result[i] == digit){
                    count++;
                    i++;
                }

                next += to_string(count);
                next += digit;
            }

            result = next;
        }

        return result;

    }
};