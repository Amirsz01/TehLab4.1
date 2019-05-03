#include <iostream>
#include <random>
#include <ctime>
#include <string>

using namespace std;

template <typename T>
void show(T* ptr, int size) {
	for (int i = 0; i < size; i++) {
		cout << ptr[i] << ' ';
	}
	cout << endl;
}

template <typename T>
int razn(T* ptr, int size)
{
	cout << "Исходный массив: ";
	show(ptr, size);
	T min = *ptr, max = *ptr;
	for (int i = 0; i < size; i++)
	{
		if (*ptr > max)
			max = *ptr;
		if (*ptr < min)
			min = *ptr;
		ptr++;
	}
	cout << "Разница: " << max - min << endl;
	return max - min;
}

int main() {
	setlocale(LC_ALL, "Rus");

	srand(time(NULL));
	// Рандомизация размера массивов
	int size = rand() % 20 + 1;

	int* int_mass = new int[size];
	char* char_mass = new char[size];
	float* float_mass = new float[size];
	double* double_mass = new double[size];


	// Заполнение массивов
	for (int i = 0; i < size; i++) {
		int_mass[i] = rand() % 50 + 50;
		char_mass[i] = rand() % 127 + 33;
		float_mass[i] = float(rand() % 50 + 50) / float(rand() % 50 + 50);
		double_mass[i] = (double(rand() % 50) + 50) / (double(rand() % 50) + 50);
	}

	int callback;
	while (true) {
		system("cls");
		cout << "Меню выбора типа элементов массива:" << endl
		 << "1. int" << endl
		 << "2. char" << endl
		 << "3. float" << endl
		 << "4. double" << endl
		 << "0. Выход" << endl
		 << "Ваш выбор: ";
		cin >> callback;
		try
		{
			if (!(callback >= 0 && callback <= 4))
			{
				throw "Ошибка: Не верный выбор в меню";
			}
		}
		catch (const char *i)
		{
			cout << i << endl;
		}
		switch (callback) {
		case 1: 
			razn(int_mass, size); 
			break;
		case 2: 
			razn(char_mass, size); 
			break;
		case 3: 
			razn(float_mass, size); 
			break;
		case 4: 
			razn(double_mass, size); 
			break;
		case 0: 
			return 0;
		}
		system("pause");
	}
	delete[] int_mass;
	delete[] char_mass;
	delete[] float_mass;
	delete[] double_mass;
	return 0;
}