#include "stdafx.h"
#include <iostream>
#include <iomanip>
#include <math.h>
#include<ctime>
#include<cstdlib>
#include<stdio.h>
//#include <algorythm>

using namespace std;

double round_num(double x, int k, int n) {
	/*int k = 0;*/

	//while (x / 10 != 0)
	//{
	//	x *= 10; // 1234.56999999
	//	k++;
	//}
	//int a = int(x / 10);
	//k--;

	int a = x * pow(10, k);

	int i = n;
	while (i != 0)
	{
		if (i == 1)
		{
			if (a % 10 >= 5) a = (a / 10 + 1)*pow(10, n);
			else a = a / 10 * pow(10, n);
		}
		else a /= 10;
		i--;
	}
	x = double(a / pow(10, k));

	return x;
}
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
//case 8. print *
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
	if (left == right) return arr[right];
	int mid = (right + left) / 2;
	int leftSide = max_arr(arr, left, mid);
	int rightSide = max_arr(arr, mid + 1, right);

	return(leftSide > rightSide ? leftSide : rightSide);
}
// the same task case 11
int max_arr2(int arr[], int size, int max) {
	if (size == 0) return max;
	if (max_arr2(arr, size - 1, max)) max=arr[size];
	return max_arr2(arr, size - 1, max);
}


//int max1(int arr[], int left, right) {
//	int max_el = INT_MIN;
//	if (max_el > arr[size - 1]) return max(arr, size);
//	else {
//		return max(arr, size - 1);
//	}
//	if (size == 0) return arr[0];
//}
// 51.	**Напишите рекурсивную функцию, которая принимает одномерный массив из 100 целых чисел
// заполненных случайным образом и находит позицию,
// с которой начинается последовательность из 10 чисел, сумма которых минимальна.
  int pos(int arr[], int size=10) {
	//
	int sum = 0;
	int min_sum = INT_MAX;
	int index = 0;
	
	for (int i = 0; i < 10; i++)
	{
		sum = 0;
		for (int j = i; j < i + 3; j++)
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
  int position(int arr[], int pos, int size, int max) {
	  if (pos == size - 4) return max;
	  int sum = 0;
	  for (int i = 0; i < 4; i++)
	  {
		  sum += arr[pos + i];
	  }
	  if (sum > max)
		  max = sum;
	  pos++;

	  return position(arr, pos, size, max);
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
			for (int i = 0; i < 10; i++) {
				arr[i] = rand() % 10;
				cout << arr[i] << " ";
			}
			cout << endl << endl;

			cout << pos << endl << endl;
		}
		break;
		case 1:
		{
			/*double x = 123.456;
			int n = 4;
			cout << round_num(x, n) << endl << endl;*/
		}
		break;
		case 2:
		{
			double x;
			int n, k;
			cin >> x >> k >> n;

			cout << round_num(x, k, n) << endl << endl;
		}
		break;
		case 3:
		{
			int n = 5;
			cout << f(n) << endl << endl;
		}
		break;
		case 4:
		{
			int a[] = { 2, 5, 3, 4, 1, 9, 3, 8, 0 };

			
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
		case 8:
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
			int a[] = { 3,4,2,0,8,5,1 };

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