//Implement a Singly Linked List and develop functions to perform insertion, deletion and linear search operations
#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node *next;
} *head = NULL;
// Function to Insert an element into the list
void insert(int element){
    struct Node *ptr = head;
    if (ptr == NULL){
        ptr = (struct Node*)malloc(sizeof(struct Node));
        ptr->data = element;
        ptr->next = NULL;
        head = ptr;
    }
    else{
        while (ptr->next != NULL){
            ptr = ptr->next;
        }
        struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
        ptr->next = newNode;
        newNode->data = element;
        newNode->next = NULL;
    }
}
// Function to Search element in the list
int search(int element){
    struct Node *temp = head;
    int position = -1, i=0;
    while (temp != NULL){
        if (temp->data == element){
            position = i;
            break;
        }
        i++;
        temp = temp->next;
    }
    return position;
}
// Function to delete the element from the list
int delete(int item){
    struct Node *temp = head;
    if(temp != NULL){
        if (head->data == item){
            temp = head;
            head = head->next;
            free(temp);
            return 1;
        }
        else{
            struct Node *current = head;
            while (current->next != NULL){
                if (current->next->data == item){
                    temp = current->next;
                    current->next = current->next->next;
                    free(temp);
                    return 1;
                }
                else{
                    current = current->next;
                }
            } 
        }
    }
    else{
        return 0;
    }
}
// Function to print the list
void printList(){
    struct Node *ptr = head;
    if(ptr == NULL){
        printf("List is Empty!\n");
    }
    else{
        while (ptr != NULL){
            if (ptr->next != NULL){
                printf("%d --> ", ptr->data);  
            }
            else{
                printf("%d --> NULL", ptr->data);
            }
            ptr = ptr->next;
        }
        printf("\n");
    }
}
int main(){
    int element, option, item, ret, position, searchElement;

    do{
        printf("Enter the Option: \n");
        printf(" 1. Insert\n 2. Delete\n 3. Search\n 4. Print List\n 5. Exit\n");
        scanf("%d", &option);
        switch (option){
            case 1: // For Insertig an element
                printf("Enter the element you want to Insert: \n");
                scanf("%d", &element);
                insert(element);
                break;
            case 2: // For Deleting an element
                printf("Enter the element you want to delete: \n");
                scanf("%d", &item);
                ret = delete(item);
                if (ret != 1){
                     printf("No such element found in the list!\n");
                }
                else{
                    printf("%d Deleted sucessfully.\n", item);
                }
                break;
            case 3: // For Searching an element
                printf("Enter an element you want to search: \n");
                scanf("%d", &searchElement);
                position = search(searchElement);
                if (position != -1){
                    printf("Element found at index %d.\n", position);
                }
                else{
                    printf("Element Not found!\n");
                }
                break;
            case 4: // Function to print the List.
                printList();
                break;
            case 5:
                exit(0);
            default:
                printf("Wrong Option!\n");
                break;
        }
    } while (1);
    return 0;
}