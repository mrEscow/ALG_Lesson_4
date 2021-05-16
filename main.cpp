#include <iostream>

using std::cout;
using std::endl;
using std::cin;

// 1.–еализовать функцию перевода чисел из дес€тичной системы в двоичную, использу€ рекурсию.
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
// 2.–еализовать функцию возведени€ числа [a] в степень [b]: рекурсивно
int exponentiation(uint16_t number, int degree) {
	if (degree == 0) return 1;
	if (degree == 1) return number;
	else
		return number * exponentiation(number, degree - 1);
}
// 3.–екурсивно, использу€ свойство чЄтности степени (то есть, если степень, в которую нужно возвести число, чЄтна€, основание возводитс€ в квадрат, а показатель делитс€ на два, 
// а если степень нечЄтна€ - результат умножаетс€ на основание, а показатель уменьшаетс€ на единицу)

// 4.–еализовать нахождение количества маршрутов шахматного корол€ с преп€тстви€ми (где единица - это наличие преп€тстви€, а ноль - свободна€ дл€ хода клетка)


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
	system("pause");
	return 0;
}