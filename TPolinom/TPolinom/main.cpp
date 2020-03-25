#include <iostream>
#include "TPolinom.h"

using namespace std;

void main() {
	int m;
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
	TPolinom pol1(mas, size);
	cout << "Pol1 = " << pol1 << endl;

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
	TPolinom pol2(mas1, size);
	cout << "Pol2 = " << pol2 << endl;
	do {

		cout << "choose operation" << endl;
		cout << "1 - insert monom" << endl << "2 - multiply polynom by a constant" << endl
			<< "3 - multiply polynom by a monom" << endl << "4 - add polynoms" << endl;
		int wcase;
		cin >> wcase;
		switch (wcase) {
		case 1: {
			cout << "choose the polynom, 1 or 2";
			int w;
			cin >> w;
			int mas[1][2];
			cout << "Enter coeff" << endl;
			cin >> mas[0][0];
			cout << "Enter powers" << endl;
			cin >> mas[0][1];
			TMonom mon(mas);
			if (w == 1) {
				pol1.InsMonom(mon);
				cout << "Pol1 + mon = " << pol1 << endl;
			}
			else {
				pol2.InsMonom(mon);
				cout << "Pol2 + mon = " << pol2 << endl;
			}
		}
			break;

		case 2: {
			cout << "choose the polynom, 1 or 2";
			int k;
			cin >> k;
			int c;
			cout << "Enter const" << endl;
			cin >> c;
			if (k == 1) {
				pol1 *= c;
				cout << "pol1 * const = " << pol1;
			}
			else {
				pol2 *= c;
				cout << "pol2 * const = " << pol2;
			}
		}
			break;

		case 3: {
			cout << "choose the polynom, 1 or 2" << endl;
			int q;
			cin >> q;
			int mas1[1][2];
			cout << "Enter coeff" << endl;
			cin >> mas1[0][0];
			cout << "Enter powers" << endl;
			cin >> mas1[0][1];
			TMonom mon1(mas1);
			if (q == 1) {
				pol1 *= mon1;
				cout << "Pol1 * mon = " << pol1 << endl;
			}
			else {
				pol2 *= mon1;
				cout << "Pol2 * mon = " << pol2 << endl;
			}
		}
			break;

		case 4: {
			pol1 += pol2;
			cout << "Polynom1 + Polynom2 = " << pol1 << endl;
		}
			  break;
		}
		cout << "press 1 to continue" << endl;
		cin >> m;
	} while (m == 1);
}