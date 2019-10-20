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

int removeDuplicates(vector<int>& nums) {
    if(nums.size() <= 0) return 0;
    int prev = nums.at(0);
    for(int i = 1; i < nums.size(); ++i){
        if(nums.at(i) == prev){
            nums.erase(nums.begin() + i);
            cout<<prev<<endl;
            --i;
        } else {
            prev = nums.at(i);
        }
    }
    return nums.size();
}        

int main(){
    vector<int> vec; // [1,1,1,2,3,3]
    vec.push_back(1);
    vec.push_back(1);
    vec.push_back(1);
    vec.push_back(2);
    vec.push_back(3);
    vec.push_back(3);

    print(vec);
    cout<<removeDuplicates(vec)<<endl;
    print(vec);
}