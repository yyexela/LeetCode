#include<iostream>
#include<vector>

using namespace std;

bool DEBUG = false;

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

void print(vector<int> vec){
	cout<<"[ ";
	for(vector<int>::iterator i = vec.begin(); i != vec.end(); i++){
		cout<<*i<<" ";
	}
	cout<<"]";
}

vector<int> makePerson(int h, int k){
	vector<int> temp;
	temp.push_back(h);
	temp.push_back(k);
	return temp;
}

void insertElement(vector<vector<int>> &vec, vector<int> element){
	int count = 0;
	if(vec.size() == 0){
		if(DEBUG){
			cout<<"adding ";
			print(element);
			cout<<" as first element"<<endl;
		}
		vec.push_back(element);
	} else {
		for(int j = 0; j < vec.size(); ++j){
			if(DEBUG) cout<<"iterate"<<endl;
			if(DEBUG) cout<<"count: "<<count<<endl;
			if((element).at(1) == count && vec.at(j).at(0) >= element.at(0) ){
				if(DEBUG){ 
					cout<<"adding ";
					print(element);
					cout<<" before ";
					print(vec.at(j));
					cout<<endl;
				}
				vec.insert(vec.begin()+j, element);
				break;
			} else if(vec.at(j) == *(vec.end()-1)){
				if(DEBUG){
					cout<<"adding ";
					print(element);
					cout<<" to end"<<endl;
				}
				vec.push_back(element);
				break;
			}else if((element).at(0) <= vec.at(j).at(0)){
				if(DEBUG){
					cout<<"since ";
					print(element);
					cout<<" is smaller or equal to ";
					print(vec.at(j));
					cout<<" increment count"<<endl;
				}
				count++;
			}
		}
	}
}

vector<vector<int>> reconstructQueue(vector<vector<int>> &people){
	vector<vector<int>> vec;
	if(DEBUG) cout<<"reconstruct"<<endl;
	if(people.size() == 0){
	       	return vec;
	}
	int size = people.size();
	for(int i = 0; i < size; ++i){
		//find the lowest k in i
		int index = 0;
		vector<int> tmp = people.at(0);
		for(int j = 0; j < people.size(); ++j){
			if(people.at(j).at(1) < tmp.at(1)){
				tmp = people.at(j);
				index = j;
			}
		}
		people.erase(people.begin()+index);
		if(DEBUG) cout<<endl;
		if(DEBUG) print(people);
		if(DEBUG) print(vec);
		if(DEBUG) cout<<endl;
		insertElement(vec, tmp);
	}
	return vec;
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
	print(reconstructQueue(given));
}
