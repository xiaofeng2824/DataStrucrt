#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

//归并排序
//先通过分解数列 递归分割成一个元素 一个元素的序列  一个元素即有序
// 然后再将 序列合并起来   所有的就都是有序的了
//合并即  将两个有序数列合并成一个有序数列

//方法的声明
bool MergeSort(int a[], int n);
void mergesort(int a[], int first, int last, int temp[]);
void mergearray(int a[], int first, int mid, int last, int temp[]);

bool MergeSort(int a[],int n)
{
	int *pTempArray = new int[n];
	if (pTempArray == NULL)
		return false;

	mergesort(a, 0, n - 1, pTempArray);
		free(pTempArray);

	
	return true;
}

void mergesort(int a[],int first,int last,int temp[])
{
	if (first < last)
	{
		int mid =  (last+first) / 2;
		mergesort(a, first, mid, temp);  //递归分解左边有序
		mergesort(a, mid+1, last, temp); // 递归分解右边有序
		mergearray(a, first, mid, last, temp); // 将两边合并
	}
}


//将两个有序数列合并成一个有序数列
void mergearray(int a[], int first, int mid, int last, int temp[])
{
	int i = first;
	int j = mid + 1;
	int m = mid;
	int n = last;
	int k = 0;

	while (i <= m && j <= n)
	{
		if (a[i] < a[j])
			temp[k++] = a[i++];
		else
			temp[k++] = a[j++];
	}

	while (i <= m)
	{
		temp[k++] = a[i++];
	}
	while (j <= n)
	{
		temp[k++] = a[j++];
	}
	for (int i = 0; i < k; i++)
		a[first + i] = temp[i];
}
int main()
{
	int arr[] = { 12,1,34,54,78,53,89,23,8,63,79,29 };
	int len = sizeof(arr) / sizeof(arr[0]);
	for (int i = 0; i < len; i++)
	{
		printf("%d ", arr[i]);
	}

	MergeSort(arr, len);

	printf("\n");
	for (int i = 0; i < len; i++)
	{
		printf("%d ", arr[i]);
	}

	printf("\nHello world\n");
	getchar();
}
