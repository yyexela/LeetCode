#include<iostream>
#include<vector>
#include<math.h>

using namespace std;

double distance(vector<int> p1, vector<int> p2){
	return sqrt( pow(p1.at(0) - p2.at(0),2) + pow(p1.at(1)-p2.at(1),2) );
}

bool validSquare(vector<int>& p1, vector<int>& p2, vector<int>& p3, vector<int>& p4){
	if(distance(p1,p2) == 0 || distance (p1,p3) == 0 || distance(p1,p4) == 0)
		return false;
	if(distance(p1,p2) != distance(p3,p4)){
		return false;
	}	double max = distance(p1,p2);
	double min = distance(p1,p2);
	bool maxChange = false;
	bool minChange = false;
	if(distance(p1,p3) != distance(p2,p4)){
		return false;
	} else {
		double dist = distance(p1,p3);
		if(dist > max){
			if(maxChange)
				return false;
			max = dist;
			maxChange = true;
		}
		if(dist < min){
			if(minChange)
				return false;
			min = dist;
			minChange = true;
		}
	}
	if(distance(p1,p4) != distance(p2,p3)){
		return false;
	} else {
		double dist = distance(p1,p4);
		if(dist > max){
			if(maxChange)
				return false;
			max = dist;
			maxChange = true;
		}
		if(dist < min){
			if(minChange)
				return false;
			min = dist;
			minChange = true;
		}
	}
	if(maxChange && minChange)
		return false;
	return true;
}

int main(){
	vector<int> p1 {0,0};
	vector<int> p2 {4,0};
	vector<int> p3 {4,-5};
	vector<int> p4 {0,-5};

	if(validSquare(p1, p2, p3, p4))
		cout<<"valid square"<<endl;
}
