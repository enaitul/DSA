class Solution {
public:
   vector<string> maxNumOfSubstrings(string s) {

    int n = s.length();

    // First occurrence of each character
    vector<int> start(26, -1);

    // Last occurrence of each character
    vector<int> end(26, 0);

    // Whether a character can be the start
    // of a valid substring
    vector<bool> isValid(26, true);

    vector<string> result;


    // ----------------------------------
    // STEP 1: Find first and last occurrence
    // ----------------------------------

    for(int i = 0; i < n; i++) {

        int idx = s[i] - 'a';

        // First time seeing this character
        if(start[idx] == -1) {
            start[idx] = i;
        }

        // Keep updating last occurrence
        end[idx] = i;
    }


    // ----------------------------------
    // STEP 2: Find valid intervals
    // ----------------------------------

    for(int c = 0; c < 26; c++) {

        // Character doesn't exist
        if(start[c] == -1)
            continue;


        // Check everything inside
        // [start[c], end[c]]
        for(int i = start[c]; i <= end[c]; i++) {

            int currentChar = s[i] - 'a';


            // If this character appeared
            // before c, then c cannot
            // be the starting point
            if(start[currentChar] < start[c]) {

                isValid[c] = false;
                break;
            }


            // If this character's last occurrence
            // is farther right, extend our interval
            end[c] = max(
                end[c],
                end[currentChar]
            );
        }
    }


    // ----------------------------------
    // STEP 3: Select non-overlapping intervals
    // ----------------------------------

    int lastTakenStart = INT_MAX;


    // Start from right side
    for(int i = n - 1; i >= 0; i--) {

        int c = s[i] - 'a';


        // Can't start a valid substring here
        if(!isValid[c])
            continue;


        // We must be at the first occurrence
        // of this character
        if(i == start[c] && end[c] < lastTakenStart) {

            // Extract substring
            result.push_back(
                s.substr(
                    i,
                    end[c] - i + 1
                )
            );

            // Remember where this substring starts
            lastTakenStart = i;
        }
    }

    return result;
}
};