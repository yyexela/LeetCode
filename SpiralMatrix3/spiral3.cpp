#include<iostream>
#include<vector>
#include<string>

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

void makeEmpty(vector<vector<int>> &matrix, int R, int C){
	int count = 0;
	for(int i = 0; i < R; ++i){
		matrix.push_back(vector<int>());
		for(int j = 0; j < C; ++j){
			matrix.at(i).push_back(count++);
		}
	}
}

vector<int> position(int x, int y){
	int pos[] = {y, x};
	vector<int> vec;
	vec.push_back(y);
	vec.push_back(x);
	return vec;
}

vector<vector<int>> spiralMatrix(int R, int C, int r0, int c0){
	if(DEBUG)cout<<"spiralMatrix"<<endl;
	vector<vector<int>> matrix;
	vector<vector<int>> vec;
	makeEmpty(matrix, R, C);
	print(matrix);
	int x = c0, y = r0, length = 1, c = 0, max = R*C;
	if(DEBUG)cout<<"START x: "<<x<<" y: "<<y<<" c: "<<c<<" max: "<<max<<endl;
	while(c < max){
		//RIGHT
		for(int i = 0; i < length; i++){
			if(DEBUG)cout<<"x: "<<x<<" y: "<<y<<" c: "<<c<<endl;
			try{
				if(DEBUG)
					cout<<matrix.at(y).at(x)<<endl;
				else
					matrix.at(y).at(x);
				vec.push_back(position(x, y));
				++c;
			} catch (const out_of_range oor){
				if(DEBUG) cout<<"out of range"<<endl;	
			}
			++x;
		}
		//DOWN
		for(int i = 0; i < length; i++){
			if(DEBUG)cout<<"x: "<<x<<" y: "<<y<<" c: "<<c<<endl;
			try{
				if(DEBUG)
					cout<<matrix.at(y).at(x)<<endl;
				else
					matrix.at(y).at(x);
				vec.push_back(position(x, y));
				++c;
			} catch (const out_of_range oor){
				if(DEBUG) cout<<"out of range"<<endl;	
			}
			++y;
		}
		//Increment length
		++length;
		//LEFT
		for(int i = 0; i < length; i++){
			if(DEBUG)cout<<"x: "<<x<<" y: "<<y<<" c: "<<c<<endl;
			try{
				if(DEBUG)
					cout<<matrix.at(y).at(x)<<endl;
				else
					matrix.at(y).at(x);
				vec.push_back(position(x, y));
				++c;
			} catch (const out_of_range oor){
				if(DEBUG) cout<<"out of range"<<endl;	
			}
			--x;
		}
		//DOWN
		for(int i = 0; i < length; i++){
			if(DEBUG)cout<<"x: "<<x<<" y: "<<y<<" c: "<<c<<endl;
			try{
				if(DEBUG)
					cout<<matrix.at(y).at(x)<<endl;
				else
					matrix.at(y).at(x);
				vec.push_back(position(x, y));
				++c;
			} catch (const out_of_range oor){
				if(DEBUG) cout<<"out of range"<<endl;	
			}
			--y;
		}
		//Increment length
		++length;
	}
	return vec;
}

void testSpiralMatrix(){
	vector<vector<int>> output = spiralMatrix(1, 4, 0, 0);
	print(output);
	output.clear();
}

int main(){
	cout<<"Program start"<<endl<<endl;
	testSpiralMatrix();
	cout<<endl<<"Program end"<<endl;
}
