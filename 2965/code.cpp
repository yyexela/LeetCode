using namespace std;
#include <iostream>
#include <vector>
#include <string.h>

class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        // Get n
        int n = grid.size();

        // Create array of zeros of size n*n and see which number is double counted
        char flags[n*n];
        memset(flags, 0, n*n);

        // Iterate through array and update counts for values
        for (auto i = 0; i < n; i++){
            for (auto j = 0; j < n; j++){
                int val = grid[i][j];
                flags[val-1] += 1;
            }
        }

        // Get output
        int dub = -1;
        int miss = -1;
        for (auto i = 0; i < n*n; i++){
            if (flags[i] == 0) miss = i+1;
            if (flags[i] == 2) dub = i+1;
        }
        vector<int> out = {dub, miss};

        return out;
    }
};

int main() {
    //vector<vector<int>> grid = {{1,2},{2,4}};
    vector<vector<int>> grid = {{1,3},{2,2}};

    Solution sol;
    vector<int> out = sol.findMissingAndRepeatedValues(grid);

    printf("dub %d miss %d\n", out[0], out[1]);

    return 0;
}
