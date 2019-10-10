#include<iostream>
#include<vector>

using namespace std;

void print(vector<vector<int>> vec){
	for(vector<vector<int>>::iterator i = vec.begin(); i != vec.end(); ++i){
		cout<<"[ ";
		for(vector<int>::iterator j = (*i).begin(); j != (*i).end(); ++j){
			cout<<*j<<" ";
		}
		cout<<"] ";
	}
	cout<<endl;
}

vector<int> makePerson(int h, int k){
	vector<int> temp;
	temp.push_back(h);
	temp.push_back(k);
	return temp;
}

int main(){
	cout<<"Program start"<<endl;
	vector<vector<int>> given;
	given.push_back(makePerson(7, 0));
	given.push_back(makePerson(4, 4));
	given.push_back(makePerson(7, 1));
	given.push_back(makePerson(5, 0));
	given.push_back(makePerson(6, 1));
	given.push_back(makePerson(5, 2));
	cout<<"Initial vector:"<<endl;
	print(given);
}
