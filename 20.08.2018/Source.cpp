#include "stdafx.h"
#include <iostream>
#include <iomanip>
#include <math.h>
#include<ctime>
#include<cstdlib>
#include<stdio.h>
//#include <algorythm>

using namespace std;

//case 3
int f(int n) {// факториал через рекурсию
	if (n == 1) return 1;
	return n * f(n - 1);
}
// 46.	*Написать рекурсивную функцию, которая вычисляет x в степени y с помощью умножения.
template<typename type>
type power(type x, type y) {
	if (y == 0) return 1;
	return x * power(x, y-1);
}
// 47.	*Написать рекурсивную функцию, которая вычисляет x*y с помощью сложения.
int p(int x, int y) {
	if (y == 0) return 0;
	return x + p(x, y - 1);
}
// 48. *Написать рекурсивную функцию, которая выводит N звезд в ряд, число N задает пользователь. Проиллюстрируйте работу функции примером.
void print(int n) {
	if (n == 0)
	{
		cout << endl;
		return; // когда функция void она все равно ничего не возвращает,
		//но можно использовать return просто для выхода в нужной точке
	}
	cout << "*";
	print(n - 1);
}
// case 9. сумма элементов массива через рекурсию без цикла
int sum_arr(int arr[], int left, int right) {
	int middle = (left + right) / 2;
	if (left == right) return arr[left];
	return (sum_arr(arr, left, middle)+sum_arr(arr, middle+1, right));
}
// case 10. find max element of an array
int max_arr(int arr[], int left, int right) {
	int mid = (right + left) / 2;
	if (left == right) return arr[right];
	
	int leftSide = max_arr(arr, left, mid);
	int rightSide = max_arr(arr, mid + 1, right);

	return(leftSide > rightSide ? leftSide : rightSide);
}
// the same task, case 11 // без поэлементной раскладки массива
int max_arr2(int arr[], int size, int max) {
	if (size == 0) return max;
	if (max_arr2(arr, size - 1, max)<arr[size]) max=arr[size];
	return max_arr2(arr, size - 1, max);
}

// 51.	**Напишите рекурсивную функцию, которая принимает одномерный массив из 100 целых чисел
// заполненных случайным образом и находит позицию,
// с которой начинается последовательность из 10 чисел, сумма которых минимальна.
// (!!! поменяем условия для наглядности на 10 вместо 100 и на 4 вместо 10)
  int pos(int arr[], int size) {
	
	for (int i = 0; i < 10; i++)
	 {
		arr[i] = rand() % 10;
		cout << arr[i] << " ";
	 }
	cout << endl << endl;

	int sum = 0;
	int min_sum = INT_MAX;
	int index = 0;
	
	for (int i = 0; i < 10; i++)
	{
		sum = 0;
		for (int j = i; j < i + 4; j++)
		{
			if ((i + 3) >= size) return index;
			sum += arr[j];
		}
		if (sum < min_sum)
		{
			min_sum = sum;
			index = i;
		}
	}
	return index;
	/*int p = 0;

	right = left + 9;
	int middle = (left + right) / 2;
	if (left == right) return arr[left];
	return (pos(arr, left, middle) + pos(arr, middle + 1, right));*/
}
  int position(int arr[], int pos, int size, int &min, int &index) {
	  
	  if (pos == size - 3) return index;

	  int sum = 0;
	  for (int i = pos; i < pos + 4; i++)
	  { 
		  sum += arr[i];
	  }
	  if (sum < min)
	  {
		  min = sum;
		  index = pos;
	  }
	  pos++;
	 
	  return position(arr, pos, size, min, index);
  }




int main()
{
	srand(time(NULL));

	setlocale(LC_ALL, "Rus");

	int tn = 0;

	while (true)
	{
		cout << "Задача № ";
		cin >> tn;

		switch (tn)
		{
		case 51:
		{
			int arr[10];
			
			cout << pos(arr, 10) << endl << endl;

			int min = INT_MAX;
			int index = 0;
			int pos = 0;
			cout << position(arr, pos, 10, min, index) << endl << endl;
		}
		break;
		case 3:
		{
			int n = 5;
			cout << f(n) << endl << endl;
		}
		break;
		case 46:
		{
			int x = 2, y = 6;
			cout << power(x, y) << endl << endl;
		}
		break;
		case 47:
		{
			int x = 6, y = 7;
			cout << p(x, y) << endl << endl;
		}
		break;
		case 48:
		{
			int x;
			cin >> x;
			print(x);
		}
		break;
		case 9:
		{
			int a[] = { 3,4,2,0,6,5,1 };

			cout << sum_arr(a, 0, 6) << endl << endl;
		}
		break;
		case 10:
		{
			int a[] = { 3,4,2,0,8,5,1 };

			cout << max_arr(a, 0, 6) << endl << endl;
		}
		break;
		case 11:
		{
			int a[] = { -3,-4,-2,-1,-8,-5,-1 };

			int max = INT_MIN;
			cout << max_arr2(a, 6, max) << endl << endl;
		}
		break;
		case 12:
		{
			
		}
		break;
		case 13:
		{

		}
		break;
		case 14:
		{

		}
		break;
		default:
			cout << "нет такой задачи" << endl << endl;
		}
	}
	system("pause");
	return 0;
}