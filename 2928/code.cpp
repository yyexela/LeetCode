using namespace std;
#include <iostream>
//#include <vector>
//#include <string.h>

class Solution {
public:
    int distributeCandies(int n, int limit) {
        int m = limit;
        int count = 0;
        for (uint a = 0; a <= m; a++){
            for (uint b = 0; b <= m; b++){
                int c = n - a - b;
                if (c >= 0 && c <= m) count += 1;
            }
        }
        return count;
    }
};

int main() {
    int n = 3;
    int limit = 3;

    Solution sol;
    int out = sol.distributeCandies(n, limit);

    printf("output: %d\n", out);

    return 0;
}
