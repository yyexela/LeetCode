#include<iostream>
#include<vector>
#include<string>

using namespace std;

bool DEBUG = false;


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

void makeEmpty(vector<vector<int>> &matrix, int n){
	for(int i = 0; i < n; ++i){
		matrix.push_back(vector<int>());
		for(int j = 0; j < n; ++j){
			matrix.at(i).push_back(0);
		}
	}
}

void spiralMatrix(vector<vector<int>> &matrix, int n){
	int x = 0, y = 0, c = 1;
	if(DEBUG)cout<<"spiralMatrix"<<endl;
	if(DEBUG)cout<<"x: "<<x<<" y: "<<y<<" c: "<<c<<endl;
	while(c <= n * n){
		//RIGHT
		while(x < n && matrix.at(y).at(x) == 0){
			if(DEBUG)cout<<"x: "<<x<<" y: "<<y<<" c: "<<c<<endl;
			if(DEBUG)print(matrix);
			matrix.at(y).at(x) = c;
			++c;
			++x;
		}
		//increment row
		++y;
		//reset col
		--x;
		//DOWN
		while(y < n && matrix.at(y).at(x) == 0){
			if(DEBUG)cout<<"x: "<<x<<" y: "<<y<<" c: "<<c<<endl;
			if(DEBUG)print(matrix);
			matrix.at(y).at(x) = c;
			++c;
			++y;
		}
		//increment col
		--x;
		//reset row
		--y;
		//LEFT
		while(x >= 0 && matrix.at(y).at(x) == 0){
			if(DEBUG)cout<<"x: "<<x<<" y: "<<y<<" c: "<<c<<endl;
			if(DEBUG)print(matrix);
			matrix.at(y).at(x) = c;
			++c;
			--x;
		}
		//increment row
		--y;
		//reset col
		++x;
		if(DEBUG)cout<<"x: "<<x<<" y: "<<y<<" c: "<<c<<endl;
		//UP
		while(y >= 0 && matrix.at(y).at(x) == 0){
			if(DEBUG)cout<<"x: "<<x<<" y: "<<y<<" c: "<<c<<endl;
			if(DEBUG)print(matrix);
			matrix.at(y).at(x) = c;
			++c;
			--y;
		}
		//increment col
		++x;
		//reset row
		++y;
	}
}

void testSpiral(){
	for(int n = 0; n <= 6; n++){
		cout<<"Size "<<n<<endl;
		vector<vector<int>> matrix;
		makeEmpty(matrix, n);
		spiralMatrix(matrix, n);
		print(matrix);
		cout<<endl;
	}
}

int main(){
	cout<<"Program start"<<endl<<endl;
	testSpiral();
	cout<<endl<<"Program end"<<endl;
}
