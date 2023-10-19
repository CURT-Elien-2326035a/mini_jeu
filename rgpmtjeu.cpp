#include <iostream>
#include <stdlib.h>
#include <fstream>
#include <vector>
using namespace std;


void playerChoice(){
    ifstream myFile;
    myFile.open("nom joueur");
    if ( myFile.is_open() ) {
        char mychar;
        while ( myFile ) {
            mychar = myFile.get();
            cout << mychar;
        }
    }
}

void pileOuFace(){
    bool piece;
    string player1;
    string player2;
    string player1status;
    cout << "rentrer no du joueur 1: ";
    cin >> player1;
    cout << "rentrer nom du joueur 2: ";
    cin >> player2;
    cout << "joeur 1 rentrer face de la pièce: pile ou face: ";
            cin >> player1status;
    if (player1status == "pile"){
        piece=true;
    }
    else{
        piece=false;
    }
    if(piece=true){
        cout << player1 << " gagne!";

    }
    else{
        cout << player2 << " gagne!";
    }
}

void shifoumi(string player1, string player2, string player1status, string player2status){
    int rock;
    int paper;
    int cisor;
    int rock2;
    int paper2;
    int cisor2;
    
/*
    cout << "rentrer no du joueur 1: ";
    cin >> player1;
    cout << "rentrer nom du joueur 2: ";
    cin >> player2;
    cout << "joeur 1 rentrer face de la pièce: pierre, feuille ou ciseaux: ";
            cin >> player1status;
    system("clear");
    cout << "joeur 2 rentrer face de la pièce: pierre, feuille ou ciseaux: ";
            cin >> player2status;
*/
    if(player1status == "pierre"){
        rock = true;
        paper = false;
        cisor = false;
    }
    if(player1status == "feuille"){
        rock = false;
        paper = true;
        cisor = false;
    }
    if(player1status == "ciseaux"){
        rock = false;
        paper = false;
        cisor = true;
    }
    if(player2status == "pierre"){
        rock2 = true;
        paper2 = false;
        cisor2 = false;
    }
    if(player2status == "feuille"){
        rock2 = false;
        paper2 = true;
        cisor2 = false;
    }
    if(player2status == "ciseaux"){
        rock2 = false;
        paper2 = false;
        cisor2 = true;
    }
    cout << endl<< endl;
    //1V1
    if(rock==true && rock2==true)
    {
        cout<< "pair";
    }
    if (rock==true && cisor2==true){
        cout << player1 << " gagne";
    }
    if (rock==true && paper2==true){
        cout << player2 <<" gagne";
    }

    if(paper==true && rock2==true)
    {
        cout<< player1 << " gagne";
    }
    if (paper==true && cisor2==true){
        cout <<player2<<" gagne";
    }
    if (paper==true && paper2==true){
        cout << "pair";
    }
    if(cisor==true && rock2==true)
    {
        cout<< player2<<" gagne";
    }
    if (cisor==true && cisor2==true){
        cout << "pair";
    }
    if (cisor==true && paper2==true){
        cout<< player1 << " gagne";
    }
}

int justeprix(int prix)
{
    int score = 100;
    unsigned tentative = 0;
    cout << "Le prix est entre 0 et 100. Devinez le prix : ";
    while (true)
    {
        unsigned x;
        cin >> x;
        tentative += 1;
        if (x < prix) cout << "Le prix est plus haut : ";
        if (x > prix) cout << "Le prix est plus bas : ";
        if (x == prix)
        {
            cout << "Vous avez gagne. Bravo, votre score est de : " << score / tentative << endl;
            cout << "Votre total de tentatives est de : " << tentative << endl;
            break;
        }
    }
    cout << "Partie terminée" << endl;
    return 0;
}


vector<vector<string>> grid{{" ", " ", " "},{" ", " ", " "},{" ", " ", " "}};
vector<vector<string>> exampleGrid{{"0", "1", "2"},{"3", "4", "5"},{"6", "7", "8"}};

struct player{
    string name;
    vector<int> move;
};

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
    system("clear");
}

//Main Game
void TicTacToeGame(vector<vector<string>> grid, vector<vector<string>> exampleGrid, vector<player> pls){
    int count = 0;
    int round = -1;
    int selection = 0;
    int line = 0;
    int column = 0;
    string form;
    while(true){
        if(count%2 == 0){
            form = "X";
            round += 1;
        }else{
            form = "O";
        }
        showGrid(exampleGrid);
        showGrid(grid);
        //cout << "Joueur " << form << " c'est a vous de jouez : ";
        //cin >> selection;
        selection = pls[count%2].move[round];
        line = select_emp(selection)[0];
        column = select_emp(selection)[1];
        if(isPlayable(line, column, grid)){
            count += 1;
            grid[line][column] = form;
            //clearConsole();
        }else{
            //clearConsole();
        }
        if(isWinner(form, grid)){
            //clearConsole();
            cout << "Le joueur " << pls[count%2].name << " à gagné !" << endl;
            return;
        }
        if(count == 9){
            //clearConsole();
            cout << "Match nul !" << endl;
            return;
        }
    }
}

string Stoneplay (const vector<string> & player1, const vector<string> & player2) {
    int count (0) ;
    int result1 (3) ;
    int result2 (3) ;
    string winner ("Le gagnant est ") ;
    while (true)
    {
        if (count % 2 == 0)
        {
            cout << player1[0] << " cache " << player1[count+1] <<" cailloux et " << player2[0] << " pense qu'elle en a cache " << player2[count+1] << endl ;
        }
        else
        {
            cout << player2[0] << " cache " << player2[count+1] <<" cailloux et " << player1[0] << " pense qu'elle en a cache " << player1[count+1] << endl ;
        }
        if ((player1[count+1] == player2[count+1] && (count % 2) == 0) ) // 2 doit deviner, a raison, donc prend le nombre que 1 a caché
        {
            result2 += std::stoi(player1[count+1]) ;
            result1 -= std::stoi(player1[count+1]) ;
            cout << player2[0] << " gagne la manche" << endl ;
            cout << result1 << endl << result2 << endl << endl ;
            count += 1 ;
        }
        else if(player1[count+1] != player2[count+1] && (count % 2) == 1) // 1 doit deviner, a tord, donc 2 prend le nombre que 2 a caché
        {
            result2 += std::stoi(player2[count+1]) ;
            result1 -= std::stoi(player2[count+1]) ;
            cout << player2[0] << " gagne la manche" << endl ;
            cout << result1 << endl << result2 << endl << endl ;
            count += 1 ;
        }
        else if ((player1[count+1] == player2[count+1] && (count % 2) == 1) ) // 1 doit deviner, a raison, donc prend le nombre que 2 a caché
        {
            result2 -= std::stoi(player2[count+1]) ;
            result1 += std::stoi(player2[count+1]) ;
            cout << player1[0] << " gagne la manche" << endl ;
            cout << result1 << endl << result2 << endl << endl ;
            count += 1 ;
        }
        else // 2 doit deviner, a tord,  1 donc prend le nombre que 1 a caché
        {
            result2 -= std::stoi(player1[count+1]) ;
            result1 += std::stoi(player1[count+1]) ;
            count += 1 ;
            cout << player1[0] << " gagne la manche" << endl ;
            cout << result1 << endl << result2 << endl << endl ;
        }
        if (result1 < 1 )
        {
            winner += player2[0] ;
            return winner ;
        }
        else if (result2 < 1)
        {
            winner += player1[0] ;
            return winner ;
        }
    }
    return winner ;
}


void menu(){
    int choixJeu;
    cout << "choisir le jeu:" << endl << "1.shifoumi" << endl << "2.pile ou face:"<< endl << "3.Juste Prix:" << endl << "4. tictactoe: "<< endl << "5. stoneplay:"<< endl;
    cin >> choixJeu;
    if (choixJeu == 1){
        shifoumi("elien", "hugo", "ciseaux", "pierre");
    } 
    if (choixJeu == 2){
        pileOuFace();
    }
    if (choixJeu == 3){
        justeprix(56);
    }
    if (choixJeu == 4){
        player joueur1;
    player joueur2;

    joueur1.name = "Baptiste";
    joueur2.name = "Hugo";

    joueur1.move = {0,2,8,3,6};
    joueur2.move = {4,1,7,5};

    vector<player> pls{joueur1, joueur2};

    TicTacToeGame(grid, exampleGrid, pls);
    }
    if (choixJeu == 5){
            cout << Stoneplay ({"Coline", "1", "3", "2", "1"}, {"Baba", "2", "1","2", "2"})  << endl ;
    }
}
int main()
{
    menu();
}
