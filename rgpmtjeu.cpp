#include <iostream>
using namespace std;

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

void shifoumi(){
    int rock;
    int paper;
    int cisor;
    int rock2;
    int paper2;
    int cisor2;
    string player1;
    string player2;
    string player1status;
    string player2status;

    cout << "rentrer no du joueur 1: ";
    cin >> player1;
    cout << "rentrer nom du joueur 2: ";
    cin >> player2;
    cout << "joeur 1 rentrer face de la pièce: pierre, feuille ou ciseaux: ";
            cin >> player1status;
    cout << "joeur 2 rentrer face de la pièce: pierre, feuille ou ciseaux: ";
            cin >> player2status;
    //1V1
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

void justeprix()
{
    int prix = 67;
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
    cout << "Partie terminer" << endl;
}


void menu(){
    int choixJeu;
    cout << "choisir le jeu:" << endl << "1.shifoumi" << endl << "2.pile ou face:"<< endl << "3.Juste Prix:" << endl;
    cin >> choixJeu;
    if (choixJeu == 1){
        shifoumi();
    }
    if (choixJeu == 2){
        pileOuFace();
    }
    if (choixJeu == 3){
        justeprix();
    }


}
int main()
{
    menu();
}
