#include <iostream>

using std::cout;
using std::endl;
using std::cin;

// 1.����������� ������� �������� ����� �� ���������� ������� � ��������, ��������� ��������.
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
// 2.����������� ������� ���������� ����� [a] � ������� [b]: ����������
int exponentiation(uint16_t number, int degree) {
	if (degree == 0) return 1;
	if (degree == 1) return number;
	else
		return number * exponentiation(number, degree - 1);
}
// 3.����������, ��������� �������� �������� ������� (�� ����, ���� �������, � ������� ����� �������� �����, ������, ��������� ���������� � �������, � ���������� ������� �� ���, 
// � ���� ������� �������� - ��������� ���������� �� ���������, � ���������� ����������� �� �������)

// 4.����������� ���������� ���������� ��������� ���������� ������ � ������������� (��� ������� - ��� ������� �����������, � ���� - ��������� ��� ���� ������)


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