#include <iostream>
#include "TPolinom.h"

using namespace std;

void main() {

	//create first polinom
	int size;
	int column = 2;
	int** mas;
	cout << "Enter polinom1 size" << endl;
	cin >> size;
	mas = new int* [size];
	for (int i = 0; i < size; i++)
		mas[i] = new int[column];

	for (int i = 0; i < size; i++) {
		cout << "Enter " << i << " coeff" << endl;
		cin >> mas[i][0];
		cout << "Enter powers" << endl;
		cin >> mas[i][1];
	}
	TPolinom pol(mas, size);
	cout << "Pol1 = " << pol << endl;

	//create second polinom
	int** mas1;
	cout << "Enter polinom2 size" << endl;
	cin >> size;
	mas1 = new int* [size];
	for (int i = 0; i < size; i++)
		mas1[i] = new int[column];

	for (int i = 0; i < size; i++) {
		cout << "Enter " << i << " coeff" << endl;
		cin >> mas1[i][0];
		cout << "Enter powers" << endl;
		cin >> mas1[i][1];
	}
	TPolinom pol1(mas1, size);
	cout << "Pol2 = " << pol1 << endl;

	/*
	// Multiplication by a constant
	int c;
	cout << "Enter const" << endl;
	cin >> c;
	pol *= c;
	cout << "pol * const = " << pol;
	//Polinomial addition
	pol += pol1;
	cout << "Pokinom1 + Polinom2 = " << pol << endl;
	*/

	/* Multiplication

	int monomMas[1][2];
	cout << "Enter monom coeff" << endl;
	cin >> monomMas[0][0];
	cout << "Enter monom powers" << endl;
	cin >> monomMas[0][1];
	TMonom mon(monomMas);
	pol1 *= mon;
	cout << "Pol2 * monom = " << pol1 << endl;

*/
}