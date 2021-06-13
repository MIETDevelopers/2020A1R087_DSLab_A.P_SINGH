/* Implement a List using Array and develop functions to perform insertion, 
deletion and linear search operations.*/
#include<stdio.h>
#include<stdlib.h>
// Function to print Array
int printArray(int *array, int size){
    int i;
    for (i = 0; i < size; i++)
    {
        printf("arr[%d] = %d\n", i, *(array+i));
    }
    return (i+1);
}
// Function to for Insertion
int insertElement(int *list, int size, int location, int item){
    int newsizeOfList, i;
    list=realloc(list,((size+1)*sizeof(int)));
    for(i=size; i>=location; i--)
        list[i+1] = list[i];
    list[location] = item;                           
    newsizeOfList = ++size;                    
    return newsizeOfList;
}
// Function for Deletion
int deleteElement(int *list, int size, int index){
    int newSizeOfList, i;
    for(i = index; i < size-1; i++){
        list[i] = list[i+1]; 
    }                
    newSizeOfList = --size;                         
    return newSizeOfList;
}
// Function for Searching an element Using Linear Search.
int searchElement(int *list, int size, int element){
    int i;
    for(i=0; i < size; i++){
        if(list[i]==element){
            printf("%d is present at location %d.\n", element, i);
            return i;
        }
        else{
            printf("Element Not Found!\n");
            return -1;
        }
    }
    return -1;
}

int main(){
    int *listA;
    int i , sizeOflistA, element, index, location, item, option;

    printf("Enter the number of elements: \n");
    scanf("%d", &sizeOflistA);
    listA = (int*)malloc(sizeOflistA*sizeof(int));

    printf("Enter the elements: \n");
    for (i = 0; i < sizeOflistA; i++){
        printf("arr[%d] \n", i);
        scanf("%d", (listA+i));
    }
    printf("Elements of Array are: \n");
    for (i = 0; i < sizeOflistA; i++){
        printf("arr[%d] = %d \n", i, *(listA+i));
    }

    do{
    printf("Enter the Option..\n");
    printf("1. Insertion \n2. Deletion \n3. Search \n4. Exit \n");
    scanf("%d", &option);
    switch (option){
    // // For Insertion
    case 1:
        printf("Enter the location of item to be inserted in: \n");
        scanf("%d", &location);
        printf("Enter the item you wnat to insert: \n");
        scanf("%d", &item);
       sizeOflistA = insertElement(listA, sizeOflistA, location, item);
        printArray(listA, sizeOflistA);
        printf("Item inserted Sucessfully. \n");
        break;
    // For Deletion
    case 2:
        printf("Enter the index of element to be deleted: \n");
        scanf("%d", &index);
        sizeOflistA = deleteElement(listA, sizeOflistA, index);
        printArray(listA, sizeOflistA);
        printf("Item deleted Sucessfully. \n");
        break;
    // For Search
    case 3:
        printf("Enter an element to search: \n");
        scanf("%d", &element);
        searchElement(listA, sizeOflistA, element);
        break;
    // For Exiting the Program
    case 4:
        exit(0);
        break;

    default:
        printf("Incorrect Option!\n");
        break;
    }
    } while (1);
    return 0;
}