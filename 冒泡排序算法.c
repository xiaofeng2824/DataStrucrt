#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdbool.h>


// 冒泡排序   从小到大
// 每一次 相邻的两个元素进行比较。如果前面的元素大于后面的元素 则进行交换
void BubbleSort(int arr[], int n)
{
	for (int i = 0; i < n-1; i++)
	{
		
		for (int j = 0; j < n - 1 - i ; j++)
		{
			if (arr[j] > arr[j + 1])
			{
				int temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
				
			}
		}
	}
}

//优化版本
// 优化思路 ：  每一次进行比较 如果没有进行交换则数组就有序了，下面的比较则无需进行
//根据这个思路，可以设置一个标志flag 来判断是否 进行了比较，如果没有则排序完成了。

void BubbleSort2(int arr[], int n)
{
	bool flag = true;
	for (int i = 0; i < n - 1 && flag; i++)
	{
		
		for (int j = 0; j < n - 1 - i ; j++)
		{
			flag = false;
			if (arr[j] > arr[j + 1])
			{
				int temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
				flag = true;

			}

		}
	}
}
int main04()
{
	int arr[] = { 12,1,34,54,78,53,89,23,8,63,79,29 };
	int len = sizeof(arr) / sizeof(arr[0]);
	for (int i = 0; i < len; i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");
	BubbleSort2(arr, len);

	for (int i = 0; i < len; i++)
	{
		printf("%d ", arr[i]);
	}

	printf("\n Hello worldln");
	getchar();
	return 0;
}
