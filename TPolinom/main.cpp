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
		cout << "Enter " << i+1 << " coeff" << endl;
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
		cout << "Enter " << i+1 << " coeff" << endl;
		cin >> mas1[i][0];
		cout << "Enter powers" << endl;
		cin >> mas1[i][1];
	}
	TPolinom pol2(mas1, size);
	cout << "Pol2 = " << pol2 << endl;

	int** mas2;
	mas2 = new int* [1];
	for (int i = 0; i < 1; i++)
		mas2[i] = new int[1];
	mas2[0][0] = 0;
	mas2[0][1] = 0;
	TPolinom pol3(mas2, 1);

	int** mas3;
	mas3 = new int* [1];
	for (int i = 0; i < 1; i++)
		mas3[i] = new int[1];
	mas3[0][0] = 0;
	mas3[0][1] = 0;
	TPolinom pol4(mas3, 1);

	do {

		cout << "choose operation" << endl;
		cout << "1 - insert monom" << endl << "2 - multiply polynom by a constant" << endl
			<< "3 - multiply polynom by a monom" << endl << "4 - add polynoms" << endl;
		int wcase;
		cin >> wcase;
		switch (wcase) {
		case 1: {
			cout << "choose the polynom, press 1 or 2" << endl;
			int k;
			cin >> k;
			cout << "izmenyaem ishodniy polinom da/net, press 3 or 4" << endl;
			int d;
			cin >> d;
			int mas[1][2];
			cout << "Enter coeff" << endl;
			cin >> mas[0][0];
			cout << "Enter powers" << endl;
			cin >> mas[0][1];
			TMonom mon(mas);
			cout << "Enter powers" << endl;
			if (k == 1) {
				if (d == 3) {
					pol1.InsMonom(mon);
					cout << "Pol1 + mon = " << pol1 << endl;
				}
				else {
					pol3 = pol1;
					pol3.InsMonom(mon);
					cout << "Pol1 + mon = " << pol3 << endl;
					pol4 = pol3;
					pol3 *= -1;
					pol4 += pol3;
					pol3 = pol4;
				}
			}
			else {
				if (d == 3) {
					pol2.InsMonom(mon);
					cout << "Pol2 + mon = " << pol2 << endl;
				}
				else {
					pol3 = pol2;
					pol3.InsMonom(mon);
					cout << "Pol2 + mon = " << pol3 << endl;
					pol4 = pol3;
					pol3 *= -1;
					pol4 += pol3;
					pol3 = pol4;
				}
			}
		}
			break;

		case 2: {
			cout << "choose the polynom, 1 or 2" << endl;
			int k;
			cin >> k;
			cout << "izmenyaem ishodniy polinom da/net, press 3 or 4" << endl;
			int d;
			cin >> d;
			int c;
			cout << "Enter const" << endl;
			cin >> c;
			if (k == 1) {
				if (d == 3) {
					pol1 *= c;
					cout << "pol1 * const = " << pol1;
				}
				else {
					pol3 = pol1;
					pol3 *= c;
					cout << "pol1 * const = " << pol3;
					pol4 = pol3;
					pol3 *= -1;
					pol4 += pol3;
					pol3 = pol4;
				}
			}
			else {
				if (d == 3) {
					pol2 *= c;
					cout << "pol2 * const = " << pol2;
				}
				else {
					pol3 = pol2;
					pol3 *= c;
					cout << "pol2 * const = " << pol3;
					pol4 = pol3;
					pol3 *= -1;
					pol4 += pol3;
					pol3 = pol4;
				}
			}
		}
			break;

		case 3: {
			cout << "choose the polynom, 1 or 2" << endl;
			int k;
			cin >> k;
			cout << "izmenyaem ishodniy polinom da/net, press 3 or 4" << endl;
			int d;
			cin >> d;
			int mas1[1][2];
			cout << "Enter coeff" << endl;
			cin >> mas1[0][0];
			cout << "Enter powers" << endl;
			cin >> mas1[0][1];
			TMonom mon1(mas1);
			if (k == 1) {
				if (d == 3) {
					pol1 *= mon1;
					cout << "Pol1 * mon = " << pol1 << endl;
				}
				else {
					pol3 = pol1;
					pol3 *= mon1;
					cout << "Pol1 * mon = " << pol3 << endl;
					pol4 = pol3;
					pol3 *= -1;
					pol4 += pol3;
					pol3 = pol4;
				}
			}
			else {
				if (d == 3) {
					pol2 *= mon1;
					cout << "Pol2 * mon = " << pol2 << endl;
				}
				else {
					pol3 = pol2;
					pol3 *= mon1;
					cout << "Pol2 * mon = " << pol3 << endl;
					pol4 = pol3;
					pol3 *= -1;
					pol4 += pol3;
					pol3 = pol4;
				}
			}
		}
			break;

		case 4: {
			cout << "izmenyaem ishodniy polinom da/net, press 3 or 4, esli da, to kakoy 1 or 2" << endl;
			int d;
			int k;
			cin >> d;
			cout << endl;
			cin >> k;
			if (d == 3) {
				if (k == 1) {
					pol1 += pol2;
					cout << "Polynom1 + Polynom2 = " << pol1 << endl;
				}
				else {
					pol2 += pol1;
					cout << "Polynom1 + Polynom2 = " << pol2 << endl;
				}
			}
			else {
				pol3 = pol1;
				pol3 += pol2;
				cout << "Polynom1 + Polynom2 = " << pol3 << endl;
				pol4 = pol3;
				pol3 *= -1;
				pol4 += pol3;
				pol3 = pol4;
			}
		}
			  break;
		}
		cout << "press 1 to continue" << endl;
		cin >> m;
	} while (m == 1);
}