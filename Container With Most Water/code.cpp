#include<iostream>
#include<vector>
#include<cmath>

using namespace std;

void print(vector<int>& vec){
    if(vec.size() == 0){
        cout<<"[]";
        return;
    }
    cout<<"[";
    for(vector<int>::iterator i = vec.begin(); i != vec.end()-1; ++i){
        cout<<*i<<",";
   }
   cout<<*(vec.end()-1)<<"]"<<endl;
}

int maxArea(vector<int>& vec){
    int max = 0;
    int minOfH = 0;
    for(int i = 0; i < vec.size(); ++i){
        for(int j = vec.size()-1; j >= 0; --j){
            if(!(vec.at(i) < minOfH || vec.at(j) < minOfH)){
                int min = vec.at(i);
                if(vec.at(j) < vec.at(i))
                    min = vec.at(j);
                if(abs((i-j)*min )>max){
                    max = abs((i-j)*min);
                    minOfH = min;
                }
            }
        }
    }
    return max;
}

void setUp(vector<int>& vec){
    vec.push_back(1);
    vec.push_back(8);
    vec.push_back(6);
    vec.push_back(2);
    vec.push_back(5);
    vec.push_back(4);
    vec.push_back(8);
    vec.push_back(3);
    vec.push_back(7);
}

int main(){
    vector<int> vec;
    setUp(vec);
    print(vec);
    cout<<"Max: "<<maxArea(vec);
}