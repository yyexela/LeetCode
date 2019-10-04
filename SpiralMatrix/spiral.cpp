#include<iostream>
#include<vector>
#include<string>

using namespace std;

bool DEBUG = true;

void make3D(vector<vector<int>> &matrix, int rows, int cols){
	for(int i = 0; i < rows; i++){
		matrix.push_back(vector<int>());
		for(int j = 0; j < cols; j++){
			(matrix.at(i)).push_back(i*10+j);
		}
	}
}

void print(vector<int> vec){
	for(vector<int>::iterator i = vec.begin(); i != vec.end(); i++){
		cout<<*i<<"  ";
	}
	cout<<endl;
}

void print(vector<vector<int>> matrix){
	for(vector<vector<int> >::iterator i = matrix.begin(); i != matrix.end(); ++i){
		for(vector<int>::iterator j = (*i).begin(); j != (*i).end(); ++j){
			if(i == matrix.begin())
				cout<<" "<<*j<<" ";
			else
				cout<<*j<<" ";
		}
		cout<<endl;
	}
}

void readRow(vector<int> line, vector<int> &vec, string dir, int left, int right){
	if(dir == "forward"){
		for(int i = left; i <= right; ++i){
			vec.push_back(line.at(i));
		}
	} else if (dir == "backward"){
		for(int i = right; i >= left; --i){
			vec.push_back(line.at(i));
		}
	} else cout<<"Direction unknown"<<endl;
}

void readCol(vector<vector<int>> matrix, vector<int> &vec, string dir, int top, int bottom, int left, int right){
	if(dir == "down"){
		for(int i = top; i<= bottom; ++i){
			//cout<<"top: "<<top<<" : "<<*(matrix.at(i)).rbegin()<<endl;
			vec.push_back(matrix.at(i).at(right));
		}
	} else if (dir == "up"){
		for(int i = bottom; i >= top; --i){
			//cout<<"top: "<<top<<" : "<<*(matrix.at(i)).rbegin()<<endl;
			vec.push_back(matrix.at(i).at(left));
		}
	} else cout<<"Direction unknown"<<endl;
}

vector<int> spiralMatrix(vector<vector<int>> matrix){
	cout<<"Spiral"<<endl;
	if(matrix.size() == 0) return vector<int>();
	vector<int> vec;
	int c1 = 0, r1 = 0;
	int r2 = matrix.size()-1;
	int c2 = (*matrix.begin()).size()-1;

	while(c2 >= c1 && r1 <= r2){
		if(r2 >= r1 && c2 >= c1){
			//cout<<"c1: "<<c1<<" c2: "<<c2<<" r1: "<<r1<<" r2: "<<r2<<endl;
			readRow(matrix.at(r1), vec, "forward", c1, c2);
			++r1;
		}
		if(r2 >= r1 && c2 >= c1){
			//cout<<"c1: "<<c1<<" c2: "<<c2<<" r1: "<<r1<<" r2: "<<r2<<endl;
			readCol(matrix, vec, "down", r1, r2, c1, c2);
			--c2;
		}
		if(r2 >= r1 && c2 >= c1){
			//cout<<"c1: "<<c1<<" c2: "<<c2<<" r1: "<<r1<<" r2: "<<r2<<endl;
			readRow(matrix.at(r2), vec, "backward", c1, c2);
			--r2;
		}
		if(r2 >= r1 && c2 >= c1){
			//cout<<"c1: "<<c1<<" c2: "<<c2<<" r1: "<<r1<<" r2: "<<r2<<endl;
			readCol(matrix, vec, "up", r1, r2, c1, c2);
			++c1;
		}
	}

	return vec;
}

void testSpiralMatrix(int row, int col){
	vector<int> vec;
	vector<vector<int> > matrix;
	make3D(matrix, row, col);
	cout<<"===3D==="<<endl;
	print(matrix);
	vec = spiralMatrix(matrix);
	cout<<"===2D==="<<endl;
	print(vec);
	vec.clear();
	matrix.clear();
	cout<<endl<<"======================================================"<<endl<<endl;
}

int main(){
	cout<<"Program start"<<endl<<endl;
	testSpiralMatrix(0, 0);
	testSpiralMatrix(1, 1);
	testSpiralMatrix(1, 4);
	testSpiralMatrix(4, 1);
	testSpiralMatrix(4, 4);
	cout<<"Program end"<<endl;
}
