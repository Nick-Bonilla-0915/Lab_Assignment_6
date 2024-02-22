#include <stdio.h>

int search(int numbers[], int low, int high, int value) 
{
	//Making variables
	int mid, found = 0;

	//Making sure value is still between
	if(low <= high)
	{
		//Changing middle to be between current low and high
		mid = (low + high)/2;

		//Checking if the value is above or below mid
		if(value < numbers[mid] && found == 0)
		{
			//Recursion
			return search(numbers, low, mid-1, value);
		}

		//Checking if value is above mid
		else if(value > numbers[mid] && found == 0)
		{
			//Recursion
			return search(numbers, mid + 1, high, value);
		}

		//Checking if value found
		else if(value == numbers[mid] && found == 0)
		{
			found == 1;
			return mid;
		}
	}

	return -1;
}

//Pre-made function
void printArray(int numbers[], int sz)
{
	int i;
	printf("Number array : ");
	for (i = 0;i<sz;++i)
	{
		printf("%d ",numbers[i]);
	}
	printf("\n");
}

//Main function, didn't touch
int main(void)
{
	int i, numInputs;
	char* str;
	float average;
	int value;
	int index;
	int* numArray = NULL;
	int countOfNums;
	FILE* inFile = fopen("input.txt","r");

	fscanf(inFile, " %d\n", &numInputs);
	
	while (numInputs-- > 0)
	{
		fscanf(inFile, " %d\n", &countOfNums);
		numArray = (int *) malloc(countOfNums * sizeof(int));
		average = 0;
		for (i = 0; i < countOfNums; i++)
		{
			fscanf(inFile," %d", &value);
			numArray[i] = value;
			average += numArray[i];
		}

		printArray(numArray, countOfNums);
		value = average / countOfNums;
		index = search(numArray, 0, countOfNums - 1, value);
		if (index >= 0)
		{
			printf("Item %d exists in the number array at index %d!\n",value, index);
		}
		else
		{
			printf("Item %d does not exist in the number array!\n", value);
		}

		free(numArray);
	}

	fclose(inFile);
}