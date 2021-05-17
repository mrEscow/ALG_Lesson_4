#include <iostream>

using std::cout;
using std::endl;
using std::cin;

// 1.
void Dex_to_Bin(uint16_t number) {
	if (number > 0)
	{
		Dex_to_Bin(number / 2);
		if (number % 2 != 0) 
			cout << "1";
		else
			cout << "0";
	}
}
// 2.
int exponentiation(uint16_t number, int degree) {
	if (degree == 0) return 1;
	if (degree == 1) return number;
	else
		return number * exponentiation(number, degree - 1);
}
// 3.
int bin_pow(int number, int degree) {
	if (degree == 0) return 1;
	if (degree & 1) {
		return bin_pow(exponentiation(number,2), degree / 2);		 
	}
	else {
		return bin_pow(number, degree - 1) * number;
	}
}
// 4.
// S(m,n) = S(m-1,n) + S(m,n-1);
// S(m,n) = 1; если одна из координат равна нулю
// S(m,n) = 0; если m и n это стартовые координаты

// S(m,n) = S(m-1,n) + S(m,n-1); если map[y][x] = 0;
// S(m, n) = 0; если map[y][x] = 1;

const int sizeX = 5;
const int sizeY = 5;

int routes2(int x, int y, int map[sizeY][sizeX]) {
	if (map[y][x] == 1) return 0;
	if (x == 0 && y == 0) return 0;
	else if (x == 0 || y == 0 ) return 1;
	else return routes2(x, y - 1,map) + routes2(x - 1, y,map);
}

int main() {

	uint16_t number;
	int degree;

	do {
		cout << "\nTask_1\nInput 0 for exit.\nInput number :  ";
		cin >> number;
		if (number == 0) break;
		cout << "Bin number :  ";
		Dex_to_Bin(number);
		cout << endl;
	} while (number != 0);

	do {
		cout << "\nTask_2\nInput 0 for exit.\nInput number :  ";
		cin >> number;
		cout << "Input degree :  ";
		cin >> degree;
		if (number == 0) break;
		cout << "Exponentiation :  "<< exponentiation(number, degree);
		cout << endl;
	} while (number != 0);

	do {
		cout << "\nTask_3\nInput 0 for exit.\nInput number :  ";
		cin >> number;
		cout << "Input degree :  ";
		cin >> degree;
		if (number == 0) break;
		cout << "Binary exponentiation :  " << bin_pow(number, degree);
		cout << endl;
	} while (number != 0);

	int map[sizeY][sizeX] = {
		{0,0,0,1,0},
		{0,1,0,0,0},
		{0,0,0,0,0},
		{0,0,0,0,0},
		{0,0,0,0,0}
	};

	for (int y = 0; y < sizeY; y++) {
		for (int x = 0; x < sizeX; x++)
		{
			cout << "\t" << map[y][x];
		}
		cout << endl;
	}
	cout << endl;

	for (int y = 0; y < sizeY; y++) {
		for (int x = 0; x < sizeX; x++)
		{
			cout << "\t" << routes2(x, y, map);
		}
		cout << endl;
	}

	system("pause");
	return 0;
}