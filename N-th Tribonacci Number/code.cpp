#include<iostream>

using namespace std;

class Solution {
public:
   int tribonacci(int n){
        //base cases
        if(n == 0) return 0;
        if(n == 1 || n == 2) return 1;
        int a1 = 0; //n-3
        int a2 = 1; //n-2
        int a3 = 1; //n-1
        int a4 = a1+a2+a3; //n
        n -= 3;
        while(n > 0){
            a1=a2;
            a2=a3;
            a3=a4;
            a4 = a1+a2+a3;
            --n;
        }
        return a4;
   }
};

int main(){
    Solution sol;
    int input = 0;
    do{
        cout<<"Enter number, -1 to exit: "<<endl;
        cin>>input;
        cout<<sol.tribonacci(input)<<endl<<endl;
    } while(input != -1);
}