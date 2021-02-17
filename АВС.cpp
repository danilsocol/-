#include <iostream>
#include <cmath>
#include <string>

using namespace std;

double Input()
{
	setlocale(LC_ALL, "Russian");

	cout << "Число ";

	double a;
	cin >> a;
	return a;
}

void CalculateBig(char* num, int bytes)
{
	cout << "Big-Endian:";
	for (int i = bytes - 1; i >= 0; i--)
	{
		for (int j = 0; j < 8; j++)
		{
			cout << ((*(num + i) >> (7 - j)) & 1);
		}
	}
	cout << endl;
}

void CalculateLittle(char* num, int bytes)
{
	cout << "Little-Endian:";
	for (int i = 0; i < bytes; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			cout << ((*(num + i) >> (7 - j)) & 1);
		}
	}
	cout << endl;
}

int main()
{
	double num = Input();

	int numInt = (int)num;
	float numFloat = (float)num;

	cout << "int:" << endl;
	CalculateBig((char*)&numInt, 4);
	CalculateLittle((char*)&numInt, 4);

	cout << "float:" << endl;
	CalculateBig((char*)&numFloat, 4);
	CalculateLittle((char*)&numFloat, 4);

	cout << "double:" << endl;
	CalculateBig((char*)&num, 8);
	CalculateLittle((char*)&num, 8);
	
}