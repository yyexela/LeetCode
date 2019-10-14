#include<iostream>
#include<vector>

using namespace std;

void print(vector<int> vec){
	for(int i = 0; i < vec.size(); ++i){
		cout<<vec.at(i)<<" ";
	}
	cout<<endl;
}

vector<int> twoSum(vector<int> nums, int target){
	vector<int> vec;
	for(int i = 0; i < nums.size(); ++i){
		for(int j = i+1; j < nums.size(); ++j){
			if(nums.at(i) + nums.at(j) == target){
				vec.push_back(i);
				vec.push_back(j);
				return vec;
			}
		}
	}
	return vec;
}

int main(){
	vector<int> vec;
	vec.push_back(3);
	vec.push_back(2);
	vec.push_back(4);

	print(vec);

	print(twoSum(vec, 6));
	cout<<"end"<<endl;
}
