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
int main()
{
                    pileOuFace();
}
