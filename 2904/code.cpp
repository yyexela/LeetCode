using namespace std;
#include <iostream>
#include <vector>
#include <string.h>

class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {
        // Store start and end indices of substrings
        vector<int> start_idxs;
        vector<int> end_idxs;

        // First, find first substring containing k "ones"
        int valid_substr[2];
        firstSubstring(s, k, valid_substr);

        if (valid_substr[0] == -1) return "";
        if (valid_substr[1] == -1) return "";
        
        start_idxs.push_back(valid_substr[0]);
        end_idxs.push_back(valid_substr[1]);

        while(valid_substr[0] != -1 && valid_substr[1] != -1){
            // Then, remove first "one" and append a "one"
            // ie. find next valid substring
            // Continue doing this until we find all substrings
            nextSubstring(s, valid_substr);

            if (valid_substr[0] == -1) break;
            if (valid_substr[1] == -1) break;
            
            start_idxs.push_back(valid_substr[0]);
            end_idxs.push_back(valid_substr[1]);
        }

        // Return shortest substring
        string shortest_str = s.substr(start_idxs[0], end_idxs[0] - start_idxs[0]+1);
        for (int i = 0; i < start_idxs.size(); i++){
            string this_str = s.substr(start_idxs[i], end_idxs[i] - start_idxs[i]+1);

            // Compare to get shortest substring
            int this_str_len = this_str.length();
            int shortest_str_len = shortest_str.length();

            if (prints){
                cout << "Checking substring (" << start_idxs[i] << ", " << end_idxs[i] << "): " << this_str << endl;
            }

            if (this_str_len < shortest_str_len){
                shortest_str = this_str;
            } else if (this_str_len == shortest_str_len &&\
                    this_str.compare(shortest_str) < 0){
                shortest_str = this_str;
            }
        }

        return shortest_str;
    }
private:
    void nextSubstring(string s, int cur_substr[2]){
        // Check to make sure we're not at end of string
        if (cur_substr[1] + 1 >= s.length()){
            cur_substr[0] = -1;
            cur_substr[1] = -1;
            return;
        }

        // Find next valid "1"
        size_t idx1 = s.find('1', cur_substr[0]+1);
        size_t idx2 = s.find('1', cur_substr[1]+1);

        // Populate return
        cur_substr[0] = idx1;
        cur_substr[1] = idx2;

        return;
    }

    // Find start and end indices of first beautiful substring
    // Fill ret[2] with these indices
    void firstSubstring(string s, int k, int ret[2]) {
        // Set default return
        ret[0] = -1;
        ret[1] = -1;

        // Find first 1
        size_t idx1 = s.find('1');
        size_t idx2;

        // Check if 1 exists
        if (idx1 == string::npos) return;

        // Check if k is 1
        if (k == 1){
            ret[0] = idx1;
            ret[1] = idx1;
            return;
        }

        // Find k-th 1
        int count = 1;
        for (int i = idx1+1; i < s.length(); i++){
            if (s[i] == '1'){
                count++;
                if (count == k){
                    // Found first valid substring, break loop
                    idx2 = i;
                    break;
                }
            }
        }

        // Check for return condition
        // Make sure count is k, otherwise return -1's
        if (count == k){
            ret[0] = idx1;
            ret[1] = idx2;
        }

        return;
    }

    int prints = 1;
};

int main() {
    string s = "10";
    int k = 1;

    cout << "Input:  " << s << ", k=" << k << endl;

    Solution sol;
    string out = sol.shortestBeautifulSubstring(s, k);

    cout << "Output: " << out << endl;

    return 0;
}
