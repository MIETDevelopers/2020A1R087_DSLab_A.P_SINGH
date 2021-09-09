/*Write a C program to compare the running times (in milliseconds) of Bubble Sort and Merge Sort for the following array:
{1,3,42,2,41,66,66,33,98,0}*/
#include<stdio.h>
#include<time.h>
void inputElements(int *arr , int size){
    int i;
    printf("Enter array elements... \n");
    for(i=0; i<size; i++){
        printf("Enter element at arr[%d] : ", i);
        scanf("%d", (arr + i));
    }
}
void swap(int *x, int *y){ //pass the address of the variables to swap
	int temp;
	temp=*x;
	*x=*y;
	*y=temp;
}
void bubbleSort(int *arr, int size){
    int i, j;
	for (i = 0; i < (size-1); i++)
	{
		for (j = 0; j < (size-(i+1)); ++j)
		{
			if (arr[j]>arr[j+1])
			{
				swap(&arr[j], &arr[j+1]);
			}
		}
	}
}
void merge(int *arr, int l, int m, int r){
	int n1 = m-l+1;
	int n2 = r-m;
	int L[n1], R[n2];
	int i,j,k;
	/* Copy data to temp arrays L[] and R[] */
    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[(m + 1) + j];
	i = 0; // Initial index for first or left subarray
    j = 0; // Initial index for second or right subarray
    k = l; // Initial index for merged subarray
    while(i<n1 && j<n2){
    	if (L[i]<=R[j])
    	{
    		arr[k] = L[i];
    		i++;
    	} else{
    		arr[k] = R[j];
    		j++;
    	}
    	k++;
    }
    while (i < n1) { // right is empty
        arr[k] = L[i];
        i++;
        k++;
    }
    while (j < n2) { // left is empty
        arr[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort(int *arr, int l, int r){//recursive function
	int mid;
	/* l is for left index and r is right index of the sub-array of arr to be sorted */
	if (l < r)
	{
		mid = (l+r)/2;
		// call mergeSort() for left subarray
		mergeSort(arr, l, mid);
		// call mergeSort() for right subarray
		mergeSort(arr, mid+1, r);
		// merge the left and right subarrays
		merge(arr, l, mid, r);
	}
}
void printArray(int *arr, int size){
    int i;
	for (i = 0; i < size; i++)
	{
		printf("\n arr[%d] = %d", i, *(arr+i));
	}
}
int main(){
     clock_t start, stop;
    int arr[10]; 
    float ms;
    printf("\t\t COMPARISON OF BUBBLE SORT AND MERGE SORT \n");
    inputElements(arr, 10);         
    printf("\t SORTING USING BUBBLE SORT \n");
    start = clock();                    // for starting the time calculation for bubble sort 
    bubbleSort(arr, 10);            
    printf("Array after sorting... \n");
    printArray(arr, 10);
    stop = clock();                     // for stoping the time calculation for bubble sort
    // To get the number of seconds used by the CPU, divide (stop - start) by CLOCKS_PER_SEC.
    ms = ((double)(stop - start) / CLOCKS_PER_SEC)*1000; // converting to milliseconds.
    printf(" \n\n Time taken in sorting the array : %.2f milliseconds", ms);
    printf("\n\n");
    printf("\t SORTING USING MERGE SORT \n");
    start = clock();                // for starting the time calculation for merge sort
    mergeSort(arr, 0, 9);             
    printf("Array after sorting ... \n");
    printArray(arr, 10);
    stop = clock();                 // for stoping the time calculation for merge sort
    // To get the number of seconds used by the CPU, divide (stop - start) by CLOCKS_PER_SEC.
     ms = ((double)(stop - start) / CLOCKS_PER_SEC)*1000;
    printf(" \n\n Time taken in sorting the array : %.2f milliseconds",ms);
    printf("\n\n");
    return 0;
}