#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define INVALID_SWAP -2
#define INVALID_IDX -3
#define INVALID_SUBSTR_LEN -4
#define SUBSTR_NOT_FOUND -5

// Swap characters of s at indices idx1 and idx2
long swap(char* s, int len, long idx1, long idx2){
    // Check indices
    if ((idx1-1 != idx2) && (idx1+1 != idx2)) return INVALID_SWAP;
    if ((idx1 < 0 || idx1 >= len) || (idx2 < 0 || idx2 >= len)) return INVALID_IDX;

    // Perform swap
    char tmp = s[idx1];
    s[idx1] = s[idx2];
    s[idx2] = tmp;

    return 0;
}

// Check if completed task (return 1, 0 otherwise)
// flipped = 0: 0...01...1
// flipped = 1: 1...10...0
int complete(char* s, int len, int flipped){
    int switched = 0;
    for(int i = 0; i < len; i++){
        //printf("Checking s[%d]=%c, switched=%d, flipped=%d\n", i, s[i], switched, flipped);
        if (!flipped){
            if (!switched){
                if (s[i] == '0') continue;
                else {
                    switched = 1;
                    continue;
                }
            } else {
                if (s[i] == '1') continue;
                else return 0;
            }
        } else {
            if (!switched){
                if (s[i] == '1') continue;
                else {
                    switched = 1;
                    continue;
                }
            } else {
                if (s[i] == '0') continue;
                else return 0;
            }
        }
    }
    return 1;
}

// Return integer > 0 if substring found, otherwise integer < 0
int leftMostSubstr(char* s, char* substr, int s_len, int substr_len){
    // Find index of left-most substring `substr`
    if (!(substr_len >= 1)) return INVALID_SUBSTR_LEN;
    for (int i = 0; i <= s_len-substr_len; i++){
        if (strncmp((char*)(&s[i]), substr, substr_len) == 0) return i;
    }
    return SUBSTR_NOT_FOUND;
}

long long minimumSteps(char* s) {
    // Get string length
    int len = strlen(s);

    // First, count minimum steps to have 0...01...1
    // Allocate string we can manipulate: s1
    char* s1 = (char *) malloc(strlen(s)+1);
    memcpy(s1, s, strlen(s)+1);

    // Keep swapping left-most "10"
    int leftMostIdx = SUBSTR_NOT_FOUND;
    int swapCount = 0;
    do {
        leftMostIdx = leftMostSubstr(s1, "10\0", len, 2);
        printf("String s1:\"%s\" count: %d swapping %d <-> %d\n", s1, swapCount, leftMostIdx, leftMostIdx+1);
        if (leftMostIdx != SUBSTR_NOT_FOUND){
            swap(s1, len, leftMostIdx, leftMostIdx + 1);
            swapCount += 1;
        }
    } while(leftMostIdx != SUBSTR_NOT_FOUND && !complete(s1, len, 0));

    return swapCount;
}

int main(){
    char* str = "111111111100100010\0";
    char* s = (char *) malloc(strlen(str)+1);
    memcpy(s, str, strlen(str)+1);

    printf("Input: %s\n", s);
    long out = minimumSteps(s);
    printf("Output: %d\n", out);

    return 0;
}