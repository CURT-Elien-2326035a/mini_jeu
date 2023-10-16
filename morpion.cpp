#include <iostream>
#include <vector>
#include <tuple>

using namespace std;

vector<vector<string>> grid{{" ", " ", " "},{" ", " ", " "},{" ", " ", " "}};
vector<vector<string>> exampleGrid{{"0", "1", "2"},{"3", "4", "5"},{"6", "7", "8"}};

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
    for(int i = 0; i < 4; i += 1){
        cout << endl;
    }
}

//Place form
bool isPlayable(const int & line, const int & column, vector<vector<string>> grid){
    if(grid[line][column] == " "){
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

vector<int> select_emp(int x){
    vector<int> result{0,0};
    int count = 0;
    for(int i = 0; i < 3; i += 1){
        for(int j = 0; j < 3; j += 1){
            if(count == x){
                result[0] = i;
                result[1] = j;
                return result;
            }
            count += 1;
        }
    }
    return result;
}

void clearConsole(){
    for(int i = 0; i < 50; i += 1){
        cout << endl;
    }
}

//Main Game
void TicTacToeGame(vector<vector<string>> grid, vector<vector<string>> exampleGrid){
    int count = 0;
    int selection = 0;
    int line = 0;
    int column = 0;
    string form;
    while(true){
        if(count%2 == 0){
            form = "X";
        }else{
            form = "O";
        }
        showGrid(exampleGrid);
        showGrid(grid);
        cout << "Joueur " << form << " c'est a vous de jouez : ";
        cin >> selection;
        line = select_emp(selection)[0];
        column = select_emp(selection)[1];
        if(isPlayable(line, column, grid)){
            count += 1;
            grid[line][column] = form;
            clearConsole();
        }else{
            clearConsole();
        }
        if(isWinner(form, grid)){
            clearConsole();
            cout << "Le joueur " << form << " à gagné, gg à lui" << endl;
            return;
        }
        if(count == 9){
            clearConsole();
            cout << "Match nul !" << endl;
            return;
        }
    }
}

int main()
{
    TicTacToeGame(grid, exampleGrid);
    return 0;
}
