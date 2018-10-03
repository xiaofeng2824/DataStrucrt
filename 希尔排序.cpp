#define _CRT_SECURE_NO_WARNINGS

#include<iostream>
#include<stdio.h>
#include<stdlib.h>

//初始版本
void shellsort1(int arr[],int n)
{
	int i, j, gap;
	for (gap = n / 2; gap > 0; gap = gap / 2) //分组
	{
		for (int i = 0; i < gap; i++)  //一组一组的排序
	   	{

			for (j = i+gap; j  < n; j = j + gap)  //组间排序
			{
				if (arr[j] < arr[j - gap])
				{
					
					int temp = arr[j];
					int k = j - gap;
					while (  k>=0 && arr[k] > temp)  // 每次保证前面的元素都有序
					{
						arr[k + gap] = arr[k];   //这部分是插入排序  大的元素往后移
						k -= gap;
					}
					arr[k + gap] = temp;  //插入元素
				}
			}
		}
		
	}

}

//优化版本1

void shellsort2(int arr[], int n)
{
	int j,  gap;

	for (gap = n / 2; gap > 0; gap /= 2)  //分组
	{
		for ( j = gap; j < n; j++)   //组间排序
		{
			if (arr[j] < arr[j - gap])
			{
				int temp = arr[j];
				int k = j - gap;
				while (k >= 0 && arr[k] > temp)  //组间排序为插入排序
				{
					arr[k + gap] = arr[k];
					k -= gap;
				}

				arr[k + gap] = temp;
			}
		}
	}

}

int main02()
{
	int arr[] = {12,1,34,54,78,53,89,23,8,63,79,29};
	int len = sizeof(arr) / sizeof(arr[0]);
	for (int i = 0; i < len; i++)
	{
		printf("%d ", arr[i]);
	}

	shellsort2(arr, len);
	printf("\nlen = %d\n", len);

	for (int i = 0; i < len; i++)
	{
		printf("%d ", arr[i]);
	}


	//system("pause");
	getchar();
	//cin.get();
	return 0;
}
