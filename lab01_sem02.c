//Implement a List using Array and develop functions to perform insertion, deletion and linear search operations.
#include<stdio.h>
#include<stdlib.h>  // For using the exit() function
#include<conio.h>  // For using the getch() function
// Function for Insertion
int insert_element(int *arr, int n, int element){
    arr[n] = element;
    n++;
    return n;
}
// Fucntion for Linear Search
int Lsearch(int *arr, int n, int element){
    int i, index= -1;
    for(i=0; i<n; i++){
        if(arr[i]== element){
            index = i;
            break;
        }
    }    
    return index;    
}
// Function for Deletion 
int delete_element(int *arr, int n, int element){
    int i, index;
    // Using Linear search function to check if the element is present 
    index = Lsearch(arr, n, element); 
    if(index == -1){
        return -1;
    }
    else{
        // deleting the element
        for(i = index; i<n; i++){
            arr[i] = arr[i+1];
        }
        n = n-1;
        return n;
    }
}    
// Display function
void display(int *arr, int n){
    int i;
    for(i=0; i<n; i++){
        printf("%d ", arr[i]);
    }
}
int main()
{
    int arr[20], option, element, n=0, del, index;
    printf("\t\t LIST IMPLEMENTATION \n");
    do{
        printf("\t OPERATIONS \n");
        printf("1. Insertion \n");
        printf("2. Deletion \n");
        printf("3. Linear Seach \n");
        printf("4. Exit \n \n ");
        printf("Enter your choice : ");
        scanf("%d", &option);
        switch(option){
            case 1: printf("Insertion \n");
                    printf("Enter the element you want to insert : ");
                    scanf("%d", &element);
                    n = insert_element(arr, n, element);
                    printf("Element inserted at index : %d \n" ,(n-1));
                    printf("Array after updation : \n");
                    display(arr, n); 
                    break;
            case 2: printf("Deletion \n");
                    printf("Enter the element you want to delete : ");
                    scanf("%d", &element);
                    del = delete_element(arr,n, element);
                    if (del == -1 || n == 0){
                        // (n == 0) is used to check if the array is empty
                    printf("Element not found or array is empty!");
                    break;
                    }else{
                     n = del;
                     printf("Element is deleted!!! \n");
                    }
                    printf("Array after updation : \n");
                    display(arr, n);
                    break;
            case 3: printf("Linear Search \n");
                    printf("Enter the element you want to search : ");
                    scanf("%d", &element);
                    index = Lsearch(arr, n, element);
                    if( index == -1 || n == 0){
                        // (n == 0) is used to check if the array is empty
                        printf("Element couldn't be found !! \n");
                    }else
                     printf("Element found at index : %d", index);
                    break;
            case 4: exit(0);
            default: printf("Please enter the correct choice !! \n");
                     break;
        }
        printf("\n Press any key to continue \n");
        getch();
    }while(1);
    return 0;
}