#include <iostream>

using namespace std;

int main()
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
