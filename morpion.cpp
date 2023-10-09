#include <iostream>
#include <vector>

using namespace std;

bool end () 
{
    if (victory_line)
    {
        return true ;
    }
    else if (victory_column)
    {
        return true ;
    }
    else if (victory_diagonal)
    {
        return true ;
    }
    else if (egality)
    {
        return true ;
    }
    else 
    {
        return false ;
    }
}

void start ()
{
    vector <vector<string>> morpion {{"","",""}, {"","",""}, {"","",""}} ;
    int count (0) ;
    while (true)
    {
        count += 1 ;
        place_form(count); //place form vérifie que la case est vide    
    }
    
    char yesno ('y');
    cout << "Si vous voulez rejouer, taper 'y', sinon tapez 'n'" << endl ;
    if (yesno == 'y') 
    {
        start();
    }
}



int main()
{
    start ();
}

