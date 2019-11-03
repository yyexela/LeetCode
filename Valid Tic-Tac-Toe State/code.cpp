#include<iostream>
#include<vector>
#include<string>
#include<cmath>

using namespace std;

class Solution {
private:
    int xCount = 0;
    int oCount = 0;
    bool xSolve = false;
    bool oSolve = false;

public:
    bool validTicTacToe(vector<string>& board) {
        //count all X's and O's
        for(auto i = board.begin(); i != board.end(); ++i){
            //check if rows are filled
            if(*i == "XXX") xSolve = true;
            if(*i == "OOO") oSolve = true;
            //increment count
            for(char&c : *i){
                if(c == 'X') ++xCount;
                if(c == 'O') ++oCount;
            }
        }

        //see if O's started first
        //see if there is an uneven distribution of marks
        if(oCount > xCount || abs(xCount - oCount) > 1) return false;

        //check columns in a row
        for(int i = 0; i < 3; ++i){
            if((board[0][i] == 'X' || board[0][i] == 'O') && board[0][i] == board[1][i] && board[1][i] == board[2][i]){
                if(board[0][i] == 'X') xSolve = true;
                if(board[0][i] == 'O') oSolve = true;
            }
        }

        //check crosses
        if((board[0][0] == 'X' || board[0][0] == 'O') && board[0][0] == board[1][1] && board[1][1] == board[2][2]){
            if(board[0][0] == 'X') xSolve = true;
            if(board[0][0] == 'O') oSolve = true;
        };
        if((board[0][2] == 'X' || board[0][2] == 'O') && board[0][2] == board[1][1] && board[1][1] == board[2][0]){
            if(board[0][2] == 'X') xSolve = true;
            if(board[0][2] == 'O') oSolve = true;
        };
        
        if(xCount == oCount && xSolve) return false;
        if(xCount > oCount && oSolve) return false;
        if(xSolve == true && oSolve == true) return false;


        return true;
    }
};

int main(){
    vector<string> board = {"XXX", "XOO", "OO "};

    Solution sol;
    if(sol.validTicTacToe(board))
        cout<<"true"<<endl;
    else
        cout<<"false"<<endl;
}