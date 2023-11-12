#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <iostream>
#include <ostream>
#include <tuple>
#include <algorithm>
#include <cstdlib>
#include <ctime>



using namespace std;


// -----------------------------------------------------------------------------
// ----------------------- Récupération des donneés -----------------------
// -----------------------------------------------------------------------------

struct joueur {
    string nom;
    string prenom;
    unsigned numEquipe;
    unsigned points ;
};

vector<vector<joueur>> saisirEquipe (const string & chemin){
    // Recupere les joueurs de chaques equipes a partir d'un fichier passe en parametre
    ifstream ifs (chemin);
    string nom;
    string prenom;
    string numEquipeStr;
    unsigned point = 0;
    vector<vector<joueur>> equipes (19);
    cout << "Recuperation des equipes." << endl;
    for(int i = 0; i < 114; ++i){
        getline (ifs, nom);
        //cout << nom << endl;
        getline (ifs, prenom);
        //cout << prenom << endl;
        getline(ifs, numEquipeStr);
        //cout << numEquipeStr << endl;
        unsigned numEquipe = stoi(numEquipeStr);
        equipes[numEquipe-1].push_back(joueur {nom, prenom, numEquipe, point});
    }
    return equipes;
}

int recuperationGraine (const string & chemin){
    ifstream ifs (chemin);
    string vent;
    string graine ;
    for(int i = 0; i < 114; ++i){
        getline (ifs, vent);
        getline (ifs, vent);
        getline(ifs, vent);
    }
    getline(ifs, graine);
    cout << "la graine est : " << graine <<endl ;
    int graine2 = stoi(graine);
    cout << "---------------------" << endl;
    return graine2;
}


// -----------------------------------------------------------------------------
// ----------------------- Jeux -----------------------
// -----------------------------------------------------------------------------


// ------------ pileOuFace -----------
unsigned pileOuFace(const unsigned & j1, const unsigned j2) {
    //Affronte deux equipes au pile ou face
    int resultat = rand() % 2;
    if (resultat == 0) {
        cout << "Le gagant de la manche est l'equipe " << j1 << endl;
        return j1;
    }
    cout << "Le gagant de la manche est l'equipe " << j2 << endl;
    return j2;
}


// ------------ shifumi -----------
unsigned shifumi(const unsigned & j1, const unsigned j2) {
    //Affronte deux equipes au shifumi
    //0 pour Pierre, 1 pour Papier, 2 pour Ciseaux
    string coupj1 = to_string(rand() % 2);
    string coupj2 = "2";
    while (true){
        if ((coupj1 == "0" && coupj2 == "2") || (coupj1 == "1" && coupj2 == "0") || (coupj1 == "2" && coupj2 == "1")) {
            cout << "Le gagant de la manche est l'equipe " << j1 << endl;
            return j1;
        }
        else {
            cout << "Le gagant de la manche est l'equipe " << j2 << endl;
            return j2;
        }
    }
}

// ------------ justePrix -----------
unsigned justePrix(const unsigned & j1, const unsigned & j2){
    int nbSecret = rand() % 10;
    cout << "Le nombre secret est " << nbSecret << endl;
    bool j1Turn = true;
    int limiteMin = 0;
    int limiteMax = 10;
    int coupJ;
    while(true){
        coupJ = rand() % (limiteMax - limiteMin) + limiteMin;
        if(j1Turn){
            cout << "L'equipe 1 pense au nombre "<< coupJ << endl;
            if(coupJ == nbSecret){
                cout << "Le gagant de la manche est l'equipe " << j1 << endl;
                return j1;
            }else if(coupJ > nbSecret){
                //cout << coupJ << " trop grand j1" << endl;
                limiteMax = coupJ - 1;
            }else{
                limiteMin = coupJ + 1;
                //cout << coupJ << " trop petit j1" << endl;
            }
            j1Turn = false;
        }else{
            cout << "L'equipe 2 pense au nombre "<< coupJ << endl;
            if(coupJ == nbSecret){
                cout << "Le gagant de la manche est l'equipe " << j2 << endl;
                return j2;
            }else if(coupJ > nbSecret){
                // << coupJ << " trop grand j2" << endl;
                limiteMax = coupJ - 1;
            }else{
                limiteMin = coupJ + 1;
                //cout << coupJ << " trop petit j2" << endl;
            }
            j1Turn = true;
        }
    }
}

string jeuDuCailloux (const vector<string> & player1, const vector<string> & player2){
    //Affronte deux equipes au jeu du cailloux
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
            result2 += stoi(player1[count+1]) ;
            result1 -= stoi(player1[count+1]) ;
            cout << player2[0] << " gagne la manche" << endl ;
            cout << result1 << endl << result2 << endl << endl ;
            count += 1 ;
        }
        else if(player1[count+1] != player2[count+1] && (count % 2) == 1) // 1 doit deviner, a tord, donc 2 prend le nombre que 2 a caché
        {
            result2 += stoi(player2[count+1]) ;
            result1 -= stoi(player2[count+1]) ;
            cout << player2[0] << " gagne la manche" << endl ;
            cout << result1 << endl << result2 << endl << endl ;
            count += 1 ;
        }
        else if ((player1[count+1] == player2[count+1] && (count % 2) == 1) ) // 1 doit deviner, a raison, donc prend le nombre que 2 a caché
        {
            result2 -= stoi(player2[count+1]) ;
            result1 += stoi(player2[count+1]) ;
            cout << player1[0] << " gagne la manche" << endl ;
            cout << result1 << endl << result2 << endl << endl ;
            count += 1 ;
        }
        else // 2 doit deviner, a tord,  1 donc prend le nombre que 1 a caché
        {
            result2 -= stoi(player1[count+1]) ;
            result1 += stoi(player1[count+1]) ;
            count += 1 ;
            cout << player1[0] << " gagne la manche" << endl ;
            cout << result1 << endl << result2 << endl << endl ;
        }
        if (result1 < 1 || result2 < 1)
        {
            winner += player1[0] ;
            return winner ;
        }
    }
    return winner ;
}


// -----------------------------------------------------------------------------
// ----------------------- Tournoi -----------------------
// -----------------------------------------------------------------------------


void affichTabJoueur (const vector<vector<joueur>> & vJ){
    //    for (const auto & equipe  : vector<vector<joueur>>){
    for (size_t i (0); i < vJ.size(); ++i) {
        cout << "numero equipe : " << i+1 << endl;
        for (const auto & _joueur  : vJ[i])
            cout << _joueur.nom << " " << _joueur.prenom << endl;
    }
}


size_t equipeGagnante(const vector<vector<joueur>> & vJoueur, const size_t & posEquipe1, const size_t & posEquipe2) {
    return posEquipe2; //(vJoueur[posEquipe1][0].points > vJoueur[posEquipe2][0].points) ? posEquipe1 : posEquipe2;
}




// ------------ tournoiSansLoserBracket -----------
size_t tournoiSansLoserBracket (vector<vector<joueur>> & vJoueur, int & graine){
    if (vJoueur.size() > 16) vJoueur.resize(16);
    cout << endl << "Les equipes vont s'affronter dans un tournoi sans loser bracket." << endl << endl ;
    while (vJoueur.size()> 1){
        cout << "Debut du round "  << endl;
        cout << "Il y a " << vJoueur.size() << " participants" << endl;
        vector<vector<joueur>> prochainRoundVJouer;

        for (size_t i (0); i < vJoueur.size(); i += 2) {
            cout << "Les equipes " <<  vJoueur[i][0].numEquipe << " et " << vJoueur[i+1][0].numEquipe << " s'affrontent sur le pile ou face." << endl;
            unsigned gagnant = pileOuFace(vJoueur[i][0].numEquipe,vJoueur[i+1][0].numEquipe);
            size_t equipeGagnanteIndex = (gagnant == vJoueur[i][0].numEquipe) ? i : i + 1;
            prochainRoundVJouer.push_back(vJoueur[equipeGagnanteIndex]);
        }
        vJoueur = prochainRoundVJouer;
    }
    cout << endl << "c'est l'equipe " << vJoueur[0][0].numEquipe << " qui a gagne." << endl;
    return size_t(vJoueur[0][0].numEquipe);
}


// ------------ tournoiAvecLoserBracket -----------
size_t tournoiAvecLoserBracket(vector<vector<joueur>> & vJoueur) {
    if (vJoueur.size() > 16) vJoueur.resize(16);
    vector<vector<joueur>> loserBracket;
    while (vJoueur.size() > 1 || loserBracket.size() > 1) {
        vector<vector<joueur>> prochainRoundVJouer;
        for (size_t i(0); i < vJoueur.size(); i += 2) {
            size_t equipeGagnanteIndex = equipeGagnante(vJoueur, i, i + 1);
            vJoueur[equipeGagnanteIndex][0].points++;
            prochainRoundVJouer.push_back(vJoueur[equipeGagnanteIndex]);
        }
        vJoueur = prochainRoundVJouer;
        for (size_t i(0); i < loserBracket.size(); i += 2) {
            size_t equipeGagnanteIndex = equipeGagnante(loserBracket, i, i + 1);
            loserBracket[equipeGagnanteIndex][0].points++;
            prochainRoundVJouer.push_back(loserBracket[equipeGagnanteIndex]);
        }
        loserBracket = prochainRoundVJouer;
    }
    vector<vector<joueur>> final;
    final.push_back(vJoueur[0]);
    final.push_back(loserBracket[0]);
    size_t equipeGagnanteIndex = equipeGagnante(final, 0, 1);
    final[equipeGagnanteIndex][0].points++;
    cout << "c'est l'equipe " << final[0][0].numEquipe << " qui a gagne avec " << final[0][0].points << " points." << endl;
    return size_t(final[0][0].numEquipe);
}

// ------------ tournoiSuisse -----------
size_t tournoiSuisse(vector<vector<joueur>> & vJoueur) {
    if (vJoueur.size() > 16) vJoueur.resize(16);
    
    size_t nombreRounds = 4; // Utilisez log2 pour déterminer le nombre de rondes
    
    for (size_t ronde = 1; ronde <= nombreRounds; ++ronde) {
        cout << "Ronde " << ronde << endl;
        vector<vector<joueur>> prochainRoundVJouer;
        
        // Triez les équipes en fonction des points avant chaque ronde
        sort(vJoueur.begin(), vJoueur.end(), [](const auto &a, const auto &b) {
            return a[0].points > b[0].points;
        });

        for (size_t i = 0; i < vJoueur.size(); i += 2) {
            cout << "Les équipes " << vJoueur[i][0].numEquipe << " et " << vJoueur[i+1][0].numEquipe << " s'affrontent." << endl;
            unsigned gagnantPOF = pileOuFace(vJoueur[i][0].numEquipe, vJoueur[i+1][0].numEquipe);
            unsigned gagnantJP = justePrix(vJoueur[i][0].numEquipe, vJoueur[i+1][0].numEquipe);
            unsigned gagnantSFM = shifumi(vJoueur[i][0].numEquipe, vJoueur[i+1][0].numEquipe);
            size_t equipeGagnanteIndex = (gagnantPOF == vJoueur[i][0].numEquipe) ? i : i + 1;
            equipeGagnanteIndex = (gagnantJP == vJoueur[i][0].numEquipe) ? i : i + 1;
            equipeGagnanteIndex = (gagnantSFM == vJoueur[i][0].numEquipe) ? i : i + 1;

            vJoueur[equipeGagnanteIndex][0].points++;
            prochainRoundVJouer.push_back(vJoueur[equipeGagnanteIndex]);
        }   
        
        vJoueur = prochainRoundVJouer;
    }

    // Trouvez et imprimez l'équipe gagnante du tournoi suisse
    size_t equipeGagnanteIndex = 0;
    unsigned maxPoints = 0;
    for (size_t i = 0; i < vJoueur.size(); ++i) {
        if (vJoueur[i][0].points > maxPoints) {
            maxPoints = vJoueur[i][0].points;
            equipeGagnanteIndex = i;
        }
    }

    cout << endl << "C'est l'équipe " << vJoueur[equipeGagnanteIndex][0].numEquipe
         << " qui a gagné le tournoi suisse avec " << vJoueur[equipeGagnanteIndex][0].points << " points." << endl;

    return size_t(vJoueur[equipeGagnanteIndex][0].numEquipe);
}

// ------------ tournoiLigue1 -----------
size_t tournoiLigue1(vector<vector<joueur>> & vJoueur) {
    if (vJoueur.size() > 16) vJoueur.resize(16);
    //Manche pile ou face
    for (size_t i = 0; i < vJoueur.size(); i=i+1) {
        for (size_t j = i+1; j < vJoueur.size(); j=j+1) {
            cout << "Les equipes " <<  vJoueur[i][0].numEquipe << " et " << vJoueur[i+1][0].numEquipe << " s'affrontent sur le pile ou face." << endl;
            unsigned gagnant = pileOuFace(vJoueur[i][0].numEquipe,vJoueur[j][0].numEquipe);
            size_t equipeGagnanteIndex = (gagnant == vJoueur[i][0].numEquipe) ? i : j;
            vJoueur[equipeGagnanteIndex][0].points++;
        }
    }
    /*
    //Manche shifumi
    for (size_t i = 5; i < 10; i=i+1) {
        for (size_t j = i+1; j < vJoueur.size(); j=j+1) {
            string gagnant = pileOuFace();
            size_t equipeGagnanteIndex = (gagnant == "1") ? i : j;
            vJoueur[equipeGagnanteIndex][0].points++;
        }
    }*/
/*
    for (size_t i = 0; i < vJoueur.size(); i=i+1) {
        for (size_t j = 0; j < vJoueur.size(); j=j+1) {
            string gagnant = pileOuFace();
            size_t equipeGagnanteIndex = (gagnant == "1") ? j : j+1;
            vJoueur[equipeGagnanteIndex][0].points++;
        }
    }
*/
    size_t equipeGagnanteIndex = 0;
    unsigned maxPoints = 0;
    for (size_t i = 0; i < vJoueur.size(); ++i) {
        if (vJoueur[i][0].points > maxPoints) {
            maxPoints = vJoueur[i][0].points;
            equipeGagnanteIndex = i;
        }
    }

    for (size_t i = 0; i < vJoueur.size(); i=i+1) {
        cout << "C'est l'equipe " << vJoueur[i][0].numEquipe << " qui a gagne avec " << vJoueur[i][0].points << " points." << endl;}
    cout << endl << "C'est l'equipe " << vJoueur[equipeGagnanteIndex][0].numEquipe << " qui a gagne avec " << vJoueur[equipeGagnanteIndex][0].points << " points." << endl;

    return size_t(vJoueur[equipeGagnanteIndex][0].numEquipe);
}




int main(){
    string chemin = "players.txt";
    vector<vector<joueur>> equipes = saisirEquipe(chemin);
    int graine = recuperationGraine(chemin);
    srand(graine);

    tournoiSuisse(equipes); // Appel à la fonction de tournoi suisse

    return 0;
}