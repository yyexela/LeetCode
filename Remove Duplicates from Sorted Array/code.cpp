#include<iostream>
#include<vector>

using namespace std;

bool DEBUG = true;

void print(vector<int> vec){
	for(vector<int>::iterator i = vec.begin(); i != vec.end(); i++){
		cout<<*i<<"  ";
	}
	cout<<endl;
}

int main(){
    cout<<"program start"<<endl;
}