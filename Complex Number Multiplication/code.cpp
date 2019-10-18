#include<iostream>
#include<string>
#include<sstream>

using namespace std;

bool DEBUG = true;

int getNum1(string a){
    int index = 0;
    if(a.substr(0,1) == "-"){
        index++;
    }
    if(DEBUG) cout<<"index:"<<index<<endl;   
    //get the first number from a.substr
    for(int i = index; i < a.size(); ++i){
        if(DEBUG) cout<<"i: "<<i<<endl;
        if(a.substr(i,1) == "+" || a.substr(i,1) == "-"){
            if(DEBUG) cout<<"a.substr:"<<a.substr(i,1)<<" index:"<<index<<endl;
            int num = stoi(a.substr(index, i));
            if(index == 1)
                return (-1* num);
            else
                return num;
        }
    }
    return 0;
}

int getNum2(string a){
    //get the second number from a.substr
    for(int i = a.size()-1; i > 0; --i){
        if(DEBUG) cout<<"i: "<<i<<endl;
        if(a.substr(i,1) == "+" || a.substr(i,1) == "-"){
            if(DEBUG) cout<<"a.substr:"<<a.substr(i+1,a.size()-2)<<" a.size:"<<a.size()<<endl;
            int num = stoi(a.substr(i+1,a.size()-1));
            if(a.substr(i,1) == "-")
                return (-1* num);
            else
                return num;
        }
    }
    return 0;
}

string complexNumberMultiply(string a, string b){
    int a1, a2, b1, b2, index = 0, size = 0;
    //offset index if number is negative
    a1 = getNum1(a);
    b1 = getNum1(b);
    a2 = getNum2(a);
    b2 = getNum2(b);
    cout<<"a1:"<<a1<<" b1:"<<b1<<" a2:"<<a2<<" b2:"<<b2<<endl;
    stringstream ss;
    ss<<a1*b1-a2*b2<<"+"<<a1*b2+a2*b1<<"i";
    return ss.str(); 
}
    
int main(){
    string str1 = "1-1i";
    string str2 = "1-1i";

    cout<<complexNumberMultiply(str1, str2)<<endl;
}