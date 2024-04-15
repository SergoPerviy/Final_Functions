#include <iostream>
#include <cstdlib>
#include <ctime>

//Функция заполнения массива случайными числами.
template<typename T>
void fill_arr(T arr[], const int lenght, int left, int right) {
	srand(time(NULL));
	for (int i = 0; i < lenght; i++)
		arr[i] = rand() % (right - left) + left;
}

//Функция вывода массива в консоль.
template <typename T>
void print_arr(T arr[], const int length) {
	std::cout << "{ ";
	for (int i = 0; i < length; i++)
		std::cout << arr[i] << ", ";
	std::cout << "\b\b }\n";
}

void type_of(int num) { std::cout << "INT\n"; }
void type_of(double num) { std::cout << "DOUBLE\n"; }
void type_of(float num) { std::cout << "FLOAT\n"; }

int range_sum(int left, int right);  //Прототип функции - объявление функции без определения ее тела с целью 
									 //предоставления компилятору основной информации о ее существовании.

template <typename T>
void middle_sort(T arr[], const int lenght);

template <typename T>
void move_arr(T arr[], const int lenght, int steps);

int main() {
	setlocale(LC_ALL, "Russian");

	int n{}, m{};

	//Задача 1. Создайте функцию, которая принимает число и выводит его тип данных.
	std::cout << "Задача 1. \n";
	std::cout << "5    - "; type_of(5);
	std::cout << "5.0  - "; type_of(5.0);
	std::cout << "5.0f - "; type_of(5.0f);
	std::cout << std::endl;

	//Задача 2. Рекурсивная функцию, которая вычислит сумму всех чисел в диапазоне от А до Б включительно.
	std::cout << "Введите начало диапазона -> ";
	std::cin >> n;
	std::cout << "Введите конец диапазона -> ";
	std::cin >> m;
	std::cout << "Сумма чисел из диапазона равна " <<
		range_sum(n, m) << "\n\n";

	//Задача 3. Сортировка значений массива от крайне правого до крайне левого отрицательных значений.
	std::cout << "Задача 3.\nИзначальный массив:\n";
	const int size3 = 10;
	int arr3[size3];
	fill_arr(arr3, size3, -20, 21);
	print_arr(arr3, size3);

	middle_sort(arr3, size3);
	std::cout << "Итоговый массив:\n";
	print_arr(arr3, size3);

	//Задача 4. Сдвиг массива по кругу.
	std::cout << "Задача 4.\nИзначальный массив:\n";
	const int size4 = 10;
	int arr4[size4]{ 1,2,3,4,5,6,7,8,9,10 };
	print_arr(arr4, size4);
	std::cout << "Введите количество сдвигов -> ";
	std::cin >> n;

	move_arr(arr4, size4, n);
	std::cout << "Итоговый массив:\n";
	print_arr(arr4, size4);

	return 0;
}

template <typename T>
void move_arr(T arr[], const int lenght, int steps) {
	for (int j = 0; j < steps; j++) {
		T tmp = arr[lenght - 1];
		for (int i = lenght - 1; i > 0; i--) {
			arr[i] = arr[i - 1];
		}
		arr[0] = tmp;
	}
}
template <typename T>
void middle_sort(T arr[], const int lenght) {
	int first_negative = -1, last_negative = -1;
	//Линейный поиск позиции певрого отрицательного элимента.
	for (int i = 0; i < lenght; i++) {
		if (arr[i] < 0) {
			first_negative = i;
			break;
		}
	}
	//Линейный поиск позиции последнего отрицательного элимента.
	for (int i = lenght - 1; i >= 0; i--) {
		if (arr[i] < 0) {
			last_negative = i;
			break;
		}
	}
	//Сортировка.
	for (int i = last_negative - 1; i > first_negative + 1; i--)
		for (int j = first_negative + 1; j < i; j++)
			if (arr[j] > arr[j + 1])
				std::swap(arr[j], arr[j + 1]);
}

int range_sum(int left, int right) {
		if (left > right)
			std::swap(left, right); //Функция swap меняет значения местами.
		if (left == right)
			return left;
		return range_sum(left, right - 1) + right;
	}