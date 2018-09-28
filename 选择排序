#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

void Swap(int & a, int &b)
{
	int c = a;
	a = b;
	b = c;

}
void SelectSort(int arr[], int n)
{
	
	int Index_min = 0;
	for (int i = 0; i < n; i++)
	{
		Index_min = i;
		for (int j = i + 1; j < n; j++)
		{
			if (arr[j] < arr[Index_min])
			{
				
				Index_min = j;
			}
		}

       	Swap(arr[i], arr[Index_min]);
	}
}


int main05()
{
	int arr[] = { 12,1,34,54,78,53,89,23,8,63,79,29 };
	int len = sizeof(arr) / sizeof(arr[0]);
	for (int i = 0; i < len; i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");

	SelectSort(arr, len);
	for (int i = 0; i < len; i++)
	{
		printf("%d ", arr[i]);
	}



	printf("\nHello world!\n");
	getchar();
	return 0;
}
