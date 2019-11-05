#include<iostream>

using namespace std;

class Solution {
public:
    int tribonacci(int n) {
        //base cases
        if(n <= 0) return 0;
        if(n == 1 || n == 2) return 1;
        return tribonacci(n-1) + tribonacci(n-2) + tribonacci(n-3);
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