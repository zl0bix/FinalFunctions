#include<iostream>
#include<cstdlib>
#include<ctime>
#include<algorithm>//для быстрой сортировки

//Ex1
void type_of(int num)    { std::cout << "INT\n";    }
void type_of(char num)   { std::cout << "CHAR\n";   }
void type_of(float num)  { std::cout << "FLOAT\n";  }
void type_of(double num) { std::cout << "DOUBLE\n"; }

//Ex2
int sum_ab(int a, int b) {
	if (a > b) {
		std::swap(a, b); std::cout << "Ты дурачок!\n";
	}
	if (a == b) return a;
	return sum_ab(a, b - 1) + b;
}
//Ex3
template <typename T>
void midle_sort(T arr[], const int length) {
	int first_index=0, last_index=0;
	for (int i = 0; i < length; i++)
		if (arr[i] < 0) {
			first_index = i;
			break;
		}
	for (int i = length-1; i >= 0; i--)
		if (arr[i] < 0) {
			last_index = i;
			break;
		}
	//Быстрая сортировка
	/*if (first_index != last_index)
	std::sort(arr+first_index+1, arr + last_index);
	*/

	//Пузырьковая сортировка
	for (int i = last_index-1 ; i > first_index + 1; i--)
		for (int j = first_index+1; j < i; j++)
			if (arr[j] > arr[j + 1])
				std::swap(arr[j], arr[j + 1]);
}

//Ex4
template <typename T>
void move_arr(T arr[], const int length,int num) {
	
	if (num >= 0) {
		for (int i = 0; i < num; i++)
			for (int i = length - 1; i > 0; i--)
				std::swap(arr[i], arr[i - 1]);
	}
	else {
		//for (int i = num; i < 0; i++)
			//for (int i = 0; i <length-1 ; i++)
				//std::swap(arr[i], arr[i + 1]);
		num *= -1;
		
		for (int i = 0; i < num; i++) {
			int tmp = arr[length - 1];
			for (int i = 0; i < length - 1; i++)
				arr[i ] = arr[i+1];
			arr[length-1] = tmp;
		}
	}

}



template <typename T>
void print_arr(T arr[], const int length) {
	std::cout << '[';
	for (int i = 0; i < length; i++)
		std::cout << arr[i] << ", ";
	std::cout << "\b\b]\n";

}

template <typename T>
void fill_arr(T arr[], const int length, int left, int right) {
	srand(time(NULL));
	for (int i = 0; i < length; i++)
		arr[i] = rand() % (right - left) + left;

}








int main() {
	setlocale(LC_ALL, "rus");
	int n,m;

	//Задача 1
	// Типы данных
	/*std::cout << "\n\n\t\tЗадача 1\n\n";// Типы данных
	std::cout << "105 - ";  type_of(105);
	std::cout << "\'A\'- "; type_of('A');
	std::cout << "7.7F - "; type_of((float)7.7);// or 7.7F
	std::cout << "0.1 - ";  type_of(0.1);
	*/

	//Задача 2
	// Рекурсивная сумма
	/*
	std::cout << "\n\n\t\tЗадача 2\n\n";
	std::cout << "Введите 1-е число -> ";
	std::cin >> n;
	std::cout << "Введите 2-е число -> ";
	std::cin >> m;
	std::cout << "Сумма чисел от А "<<n<< " до Б = "<<m << ' ' << sum_ab(n, m);
	*/

	//Задача 3
	// Сортировка серидины
	/*
	std::cout << "\n\n\t\tЗадача 3\n\n Изначальный массив\n\n";
	const int size3 = 10;
		int arr3[size3];
		fill_arr(arr3, size3, -20, 21);//[-20..20]
		print_arr(arr3, size3);

		midle_sort(arr3, size3);   //быстрая сортировка
		std::cout << "Итоговый массив\n";
		print_arr(arr3, size3);
    */

	std::cout << "\n\n\t\tЗадача 4\n\n";// Сдвиг массива
	const int size4 = 4;
	int arr4[size4]{ 1,2,3,4 };
	std::cout << "Изночальный массив\n\n";
	print_arr(arr4, size4);
	std::cin >> n;
	
    move_arr(arr4, size4, n);
		
	
	print_arr(arr4, size4);

	std::cout << std::endl;




	return 0;
}