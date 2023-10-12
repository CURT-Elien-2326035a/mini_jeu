#include <iostream>
#include <vector>

using namespace std;

vector<vector<string>> board{{"*","*","*"}, {"*","6","*"}, {"*","*","*"}};
vector<vector<string>> exampleBoard{{"0","1","2"}, {"3","4","5"}, {"6","7","8"}};

struct playerType{
    string name;
    char playerform;
};

vector<playerType> playerList;

void initPlayer(){
    playerType playerOne;
    playerType playerTwo;

    playerOne.name = "Joueur1";
    playerTwo.name = "Joueur2";
}


void start(){
    //Boucle du jeu.
    while(true){

    }
}

string showLine(vector<string> line){
    return line[0] + "|" + line[1] + "|" + line[2];
}

void showBoard(vector<vector<string>> bo, string title){
    cout << endl;
    cout << title << endl;
    cout << endl;
    int boardSize = size(bo);
    for(int i = 0; i < boardSize; i += 1){
        cout << showLine(bo[i]) << endl;
    }
    cout << endl;
}

bool isEmpty(string bo){
    if(bo != ""){
        return true;
    }
    return false;
}

string select_emp(const int & num, const vector<vector<string>> & bo){
    int size_tab = size(bo);
    int count = 0;
    for(int i = 0; i < size_tab; i += 1){
        for(int j = 0; j < 3; j += 1){
            if(count == num){
                if(isEmpty(bo[i][j])){
                    //Place la pièce
                }else{
                    //Erreur, rejoue.
                }
            }
            count += 1;
        }
    }
    return "erreur";
}

void playerPlaceForm(const vector<vector<string>> & bo){
    int typing;
    cout << "Choisissez un emplacement : ";
    cin >> typing;
    cout << endl;
    cout << select_emp(typing, bo) << endl;
}

int main(){
    //cout << board[0][0] << endl;
    //showBoard(exampleBoard, "Exemple des Emplacements");
    //showBoard(board, "board test");
    //playerPlaceForm(board);
    return 0;
}

