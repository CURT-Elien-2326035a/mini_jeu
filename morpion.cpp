#include <iostream>
#include <vector>
#include <tuple>

using namespace std;

vector<vector<string>> grid{{" ", " ", " "},{" ", " ", " "},{" ", " ", " "}};

//Show grid
void showGrid(const vector<vector<string>> & grid){
    for(int line = 0; line < 3; line += 1){
        for(int column = 0; column < 3; column += 1){
            cout << grid[line][column];
            if(column < 2){
                cout << "|";
            }
        }
        cout << endl;
        if(line < 2){
            cout << "------" << endl;
        }
    }
}

//Place form
bool play(const string & form, const int & line, const int & column, vector<vector<string>> grid){
    if(grid[line][column] == " "){
        grid[line][column] = form;
        return true;
    }
    return false;
}

//Check If player "form" Win
bool isWinner(const string & form, vector<vector<string>> grid){
    //Check Line
    for(int line = 0; line < 3; line += 1){
        if(grid[line][0] == form && grid[line][1] == form && grid[line][2] == form){
            return true;
        }
    }
    //Check Column
    for(int column = 0; column < 3; column += 1){
        if(grid[0][column] == form && grid[1][column] == form && grid[2][column] == form){
            return true;
        }
    }
    //Check Diagonal
    if(grid[0][0] == form && grid[1][1] == form && grid[2][2] == form){
        return true;
    }
    //Check OppositeDiagonal
    if(grid[0][2] == form && grid[1][1] == form && grid[2][0] == form){
        return true;
    }

    return false;
}

tuple<int,int> select_emp(int x){
    int count = 0;
    for(int i = 0; i < 3; i += 1){
        for(int j = 0; j < 3; j += 1){
            if(count == x){
                tuple<int, int> result;
                result = make_tuple(i, j);
                return result;
            }
        }
    }
    //AYA
    return;
}

//Main Game
void TicTacToeGame(vector<vector<string>> grid){
    int count = 0;
    string form;
    while(true){
        if(count%2 == 0){
            form = "X";
        }else{
            form = "O";
        }
        showGrid(grid);

    }
}

int main()
{
    showGrid(grid);
    return 0;
}
