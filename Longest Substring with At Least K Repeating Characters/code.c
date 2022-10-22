#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define PRINTS 1

int longestSubstring(char * s, int k);
int isValid(char* s, int k, int start, int end);

int main(int argc, char* argv[]){
    unsigned long k = strtoul(argv[2], NULL, 10);

    if(PRINTS){
        printf("Input is:\ns:%s\nk:%u\n", argv[1], k);
    }

    int out = longestSubstring(argv[1], k);

    printf("Output is: %d\n\n", out);
}

int longestSubstring(char* s, int k){
    int max = 0;
    int st_len = strlen(s);

    for(int start = 0; start < st_len-k+1;){
        for(int sub_len = k; start+sub_len <= st_len; sub_len++){
            if(sub_len < max){continue;}
            if(PRINTS){
                printf("Start: %d, sub_len, %d\n", start, sub_len);
            }
            if(isValid(s, k, start, start+sub_len-1)){
                max = sub_len > max ? sub_len : max;
            }
        }

        // Count consecutive numbers
        int count = 0;
        char c = s[start];
        while(c == s[start+count]){
            count++;
        }
        start += count;
    }

    return max;
}

int isValid(char* s, int k, int start, int end){
    if(PRINTS){
        printf("Start: %d, end: %d\n", start, end);
    }

    int counts[26]; // Each index is how many times a character appears
    memset(counts, 0, 26*sizeof(int));

    if(PRINTS){
        printf("Checking ");
    }
    // Count entries
    for(int i = start; i <= end; i++){
        if(PRINTS){
            printf("%c", s[i]);
        }
        int counts_idx = ((int)s[i])-97;
        counts[counts_idx] += 1;
    }
    if(PRINTS){
        printf("\n");
    }

    // Validate entries
    int is_valid = 1;
    for(int i = 0; i < 26; i++){
        if(counts[i] != 0 && counts[i] < k){
            is_valid = 0;
        }
    }

    if(PRINTS){
        printf("Validity: %d\n\n", is_valid);
    }
    return is_valid;
}