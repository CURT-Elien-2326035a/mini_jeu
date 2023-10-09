#include <iostream>
#include <vector>
using namespace std;

int caseCheck ()
{
    int cases = 8;
    int caseCheck = 1;
    int inVar;
    cout<< "entrer valeur de la case (8)";
    cin >> inVar;
    if(inVar==cases && caseCheck == 0){
        cout<< "case full";
    }
    if(inVar==cases && caseCheck == 1){
        cout<< "case empty";
        caseCheck = 0;
    }
}

int main() {
    while (true)
    {
        caseCheck();
    }
}

