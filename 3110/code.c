#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
    char* s = "hello";
    char* str = s;

    int sum = 0;
    
    for(int i = 0; i < strlen(str)-1; i++){
        sum += abs((int)(str[i]) - (int)(str[i+1]));
    }

    printf("Sum of \"%s\" %d\n", s, sum);
    return sum;
}