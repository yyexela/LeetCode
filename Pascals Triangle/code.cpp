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

void print(vector<vector<int>> matrix){
	if(matrix.size() == 0) cout<<"Empty vector"<<endl;
	for(vector<vector<int> >::iterator i = matrix.begin(); i != matrix.end(); ++i){
		for(vector<int>::iterator j = (*i).begin(); j != (*i).end(); ++j){
			if(*j < 10) cout<<"0";
			cout<<*j<<" ";
		}
		cout<<endl;
	}
}

vector<vector<int>> generate(int numRows) {
	vector<vector<int>> vec;
	if(DEBUG) cout<<"generating"<<endl;
	for(int i = 0; i < numRows; ++i){
		if(DEBUG) cout<<"i: "<<i<<endl;
		vec.push_back(vector<int>());
		for(int j = 0; j <= i; ++j){
			if(DEBUG) cout<<"j: "<<j<<endl;
			if(j == 0 || j == i){
				if(DEBUG) cout<<"adding 1"<<endl;
				vec.at(i).push_back(1);
			} else {
				if(DEBUG) cout<<"adding "<<endl;
				vec.at(i).push_back(vec.at(i-1).at(j)+vec.at(i-1).at(j-1));
			}
		}
	}
	return vec;
}

int main(){
	cout<<"Program start"<<endl<<endl;
	print(generate(5));
	cout<<endl<<"Program end"<<endl;
}
