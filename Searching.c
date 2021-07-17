#include<stdio.h>
#include <stdlib.h>
#include "TypeDef.h"


uint8_t binarysearch(uint32_t*arr,uint8_t size,uint32_t number);
uint8_t ArrayIsSort(uint32_t*arr,uint8_t size);
void bubbleSort(uint32_t*arr,uint8_t size);

void main(void)  
{
	uint8_t result ;
	uint32_t x[5]={5,15,7,88,90};
	result=binarysearch(x,5,8);
	if (result==255)     // -1 is not in the range of un signed char values
	{
		printf("Not found\n");
	}
	else
	{
		printf("value at index %d\n",result);
	}
}

uint8_t ArrayIsSort(uint32_t*arr,uint8_t size)
{
	for(int i=0;i<size-1;i++)
	{
		if(arr[i]>arr[i+1])
		{
			return 0;
		}
	}
	return 1;
}

void bubbleSort(uint32_t*arr,uint8_t size)
{
	uint32_t temp;
	
	for(int i=0;i<size-1;i++)
	{
		for(int j=0;j<size-i-1;j++)
		{
			if(arr[j]>arr[j+1])
			{
				temp=arr[j];
				arr[j]=arr[j+1];
				arr[j+1]=temp;
			}
		}
	}
}

uint8_t binarysearch(uint32_t*arr,uint8_t size,uint32_t number)
{
	uint8_t start=0;
	uint8_t end=(size-1);
	uint8_t mid;
	if(!(ArrayIsSort(arr,size)))
	{
		bubbleSort(arr,size);
	}
	while(start!=end)
	{
		mid=(start+end)/2;
		if(number==arr[mid])
		{
			return mid;
		}
		else if(number>arr[mid])
		{
			start=mid+1;
		}
		else if(number<arr[mid])
		{
			end=mid-1;
		}
		mid=(start+end)/2;
	}
	if(number==arr[start])
	{
		return start;
	}
	return 255; // -1 is not in the range of un signed char values
}
