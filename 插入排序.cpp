#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<stdlib.h>
#include<stdio.h>

//   实现插入排序  从小到大的顺序  初始版本 思路比较清晰
/*
具体思路：
 首先保证前一部分有序，后一部分无序
 将后续无序的部分逐个插入到有序的部分
 1.首先将数组的第一个元素视为第一部分，将其他的视为无序部分
 2.逐个查询，找到要虚入的位置  
 3.将数组元素逐个向后移直到要插入的位置
 4.将无序的元素插入到要插入的位置上
*/
void InsertSort(int arr[],int n)
{
	for (int i = 1; i < n; i++)
	{
		int j;
		int temp = arr[i];
		for (j = i-1; j >=0; j--)
		{
			if (arr[j] < temp )
			{
				break;
			}
		}

		if (j != i - 1)
		{
			int k;
			for (k = i - 1; k > j; k--)
			{
				arr[k + 1] = arr[k];
			}
			arr[k + 1] = temp;
		}
	}

}

//优化版本1
//优化部分： 将查询的部分 与向后移的部分  合并  检测某个元素仍然大于要插入的元素
//那么这个元素就向后移一位

void InsertSort2(int arr[], int n)
{
	int i, j;
	for ( i = 1; i < n; i++)
	{
		if (arr[i] < arr[i - 1])
		{
			int temp = arr[i];
			for (j = i - 1; j >= 0 && arr[j] > temp; j--)
				arr[j + 1] = arr[j];
			arr[j + 1] = temp;
		}
	}
}

//优化版本三
//优化部分： 将要插入的元素  改为向前移
//  如果要插入到前面的元素，满足移动的条件，就与前面的元素交换，直到不能满足条件，不交换为止。

void InsertSort3(int arr[], int n)
{
	for (int i = 1; i < n; i++)
	{
	
		for (int j = i ; j >= 0; j--)
		{
			if (arr[j] < arr[j - 1])
			{
				int temp = arr[j];
				arr[j] = arr[j - 1];
				arr[j - 1] = temp;
			}
		}
	}
}
int main03()
{

	int arr[] = { 12,1,34,54,78,53,89,23,8,63,79,29 };
	int len = sizeof(arr) / sizeof(arr[0]);
	for (int i = 0; i < len; i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\nlen = %d\n", len);
	InsertSort3(arr, len);
	for (int i = 0; i < len; i++)
	{
		printf("%d ", arr[i]);
	}



	printf("Hello world\n");
	getchar();
	
	return 0;
}
