// quickSort.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include "stdlib.h"
#include<cstdlib>
#include<time.h>
#include<Windows.h>
using namespace std;
#define ARRAYSIZE 10000
void mergeSort(int *arr, int num);
void mergeSortC(int *arr, int p, int r);
void merge(int *arr, int a, int b);
void quickSort(int *arr, int size);
void patition(int *arr, int p, int r);
int main()
{
	srand((unsigned)time(NULL));
	int arr[ARRAYSIZE] = { 0 };
	int arr1[ARRAYSIZE] = { 0 };
	for (int i = 0; i < ARRAYSIZE; i++) {
		arr1[i] = arr[i] = rand();
	}
	clock_t start_time1 = clock();
	mergeSort(arr, ARRAYSIZE);
	clock_t end_time1 = clock();
	cout << "time is " << static_cast<double>(end_time1 - start_time1) / CLOCKS_PER_SEC * 1000 << endl;
	clock_t start_time2 = clock();
	quickSort(arr1, ARRAYSIZE);
	clock_t end_time2 = clock();
	cout << "time is " << static_cast<double>(end_time2 - start_time2) / CLOCKS_PER_SEC * 1000 << endl;
	/*int arr[7] = { 11,8,3,9,7,1,2 };
	int arr1[7] = { 11,8,3,9,7,1,2 };*/
	//int arr[8] = {8,7,6,5,4,3,2,1 };
	/*clock_t start_time1 = clock();
	mergeSort(arr, 7);
	clock_t end_time1 = clock();
	cout << "time is " << static_cast<double>(end_time1 - start_time1) / CLOCKS_PER_SEC  << endl;
	clock_t start_time2 = clock();
	quickSort(arr1,7);
	clock_t end_time2 = clock();
	cout << "time is " << static_cast<double>(end_time2 - start_time2) / CLOCKS_PER_SEC  << endl; */
	////quickSort(arr, 7);
	//for (int i = 0; i < 7; i++)
	//{
	//	cout << arr[i] << endl;
	//	cout << arr1[i] << endl;
	//}
	system("pause");
    return 0;
}
void mergeSort(int *arr, int num)

{
	mergeSortC(arr, 0, num - 1);
}
void mergeSortC(int *arr, int p, int r)
{

	int q = (p + r) / 2;
	if (q == r)
		return;
	else
	{
		mergeSortC(arr, p, q);
		mergeSortC(arr, q + 1, r);
		merge(arr, p, r);
		return;
	}
}
void merge(int *arr, int a, int b)
{
	int temp = b - a + 1;
	int *arrayone = new int[temp];
	int i = a;
	int j = (a + b) / 2 + 1;
	for (int k = 0; k < temp; k++)
	{

		if (i >(a + b) / 2)
		{
			arrayone[k] = arr[j];
			j++;
		}
		if (j>b)
		{
			arrayone[k] = arr[i];
			i++;
		}
		else
		{
			if (arr[i]>arr[j])
			{
				arrayone[k] = arr[j];
				j++;
			}
			else
			{
				arrayone[k] = arr[i];
				i++;
			}
		}
	}
	for (int k = 0; k < temp; k++)
	{
		arr[k + a] = arrayone[k];
	}
	delete[]arrayone;

}
void quickSort(int *arr, int size)
{
	patition(arr,0,size-1);
}
void patition(int *arr, int p,int r)
{
	if (r<=p)
	{
		return;
	}
	int temp = arr[r];
	int k = p;
	for (int i = p; i < r; i++)
	{
		if (arr[i] < temp) {
			if (i != k)
			{
				int t1 = arr[k];
				arr[k] = arr[i];
				arr[i] = t1;
			}
			k++;
		}
	}
	int t2= arr[k];
	arr[k] = temp;
	arr[r] = t2;
	patition(arr,p, k-1);
	patition(arr, k+1, r);
	return;
}