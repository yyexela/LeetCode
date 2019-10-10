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
	cout<<"] ";
}

vector<int> makePerson(int h, int k){
	vector<int> temp;
	temp.push_back(h);
	temp.push_back(k);
	return temp;
}

vector<vector<int>> reconstructQueue(vector<vector<int>> &people){
	if(people.size() == 0){
	       vector<vector<int>> empty;
	       return empty;
	}
	//vector to return
	bool swap = false;
	do{
		swap = false;
		if(DEBUG) print(people);
		//int sorted changes if the back most person is in order
		int sorted = 1;
		for(vector<vector<int>>::iterator i = (people.end()-sorted); i != people.begin()-1; --i){
			int count = 0;
			if(DEBUG) cout<<"starting from end"<<endl;
			for(vector<vector<int>>::iterator j = people.begin(); j != i; ++j){
				if((*j).at(0) >= (*i).at(0)) ++count;
			}
			if(DEBUG){
				cout<<"count for ";
				if(DEBUG) print(*i);
				cout<<" is: "<<count<<endl;
			}
			if(i == people.end()-sorted && count == (*i).at(1)){
				if(DEBUG) cout<<"last element in right position"<<endl;
			        sorted++;
			} else if(count > (*i).at(1) && count > 0){
				if(DEBUG) cout<<"swap"<<endl;
				(*i).swap(*(i-1));
				if(DEBUG) print(people);
				swap = true;
			} else if (count < (*i).at(1) && i+1 != people.end()){
				if(DEBUG) cout<<"swap back"<<endl;
				(*i).swap(*(i+1));
				if(DEBUG) print(people);
				swap = true;
			}
		}
	} while (swap);
	if(DEBUG) print(people);
	return people;
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

	cout<<endl<<"Final: "<<endl;
	print(reconstructQueue(given));
}
