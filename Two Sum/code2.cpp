#include<iostream>
#include<vector>
#include <unordered_map>

using namespace std;

void print(vector<int> vec){
	for(int i = 0; i < vec.size(); ++i){
		cout<<vec.at(i)<<" ";
	}
	cout<<endl;
}

vector<int> twoSum(vector<int> nums, int target){
	//map with first int being the value of vec and second being the index
	unordered_map<int, int> map;
	//populate map
	for(int i = 0; i < nums.size(); ++i){
		//check if map has a value to add to vec.at(i) to get target
		auto pos = map.find(target-nums.at(i));
		if(pos != map.end() ){
			return vector<int> {i, pos->second};
		}
		map.insert({nums.at(i),i});
	}
	return vector<int>();
}

int main(){
	unordered_map<int, int> map;
	/*
	map.insert({1, 3});
	cout<<map.at(1)<<endl;
	cout<<map.at(0)<<endl;
	*/
	vector<int> vec;
	vec.push_back(3);
	vec.push_back(2);
	vec.push_back(4);

	print(vec);

	print(twoSum(vec, 6));
	cout<<"end"<<endl;
}
