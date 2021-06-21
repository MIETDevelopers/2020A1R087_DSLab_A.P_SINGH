// Implement a Stack using Arrays in C and develop functions to perform push and pop operations
#include<stdio.h>
#include<stdlib.h>

struct stack{     //structure for stack
    int *data;    //pointer variable for stack
    int size;     //size of stack
};
// For Push(to insert an element) Operation
int push(struct stack *stack, int value){ //for stack, user input for push
    if (stack->size == 0){                //checking stack is it empty or not      
        stack->data = (int *)malloc((((stack->size)+1)*sizeof(int)));  //if stack is empty
     }
    else{
        stack->data = (int *)realloc(stack->data, (((stack->size)+1)*sizeof(int)));//if stack is not empty then memory will be rellocated
    }
    (stack->size)++; //increasing stack size
    *((stack->data) + ((stack->size)-1)) = value; //insert user value at top 
    return stack->size;
}
// To check top of the Stack
int topOfStack(struct stack *stack){
    int topElement;
    if (stack->size == 0){             
        printf("Stack is Empty!\n");
        return 0;
    }
    else{
        topElement = *((stack->data) + ((stack->size)-1));
        printf("Element at top of a Stack is %d\n", topElement); 
        return topElement;
    }
}
// For POP(to remove top element) Operation
int pop(struct stack *stack){          //for comparing stack size
    int top;
    if(stack->size == 0){
        printf("Stack is Empty. \n");
        return 0;                             
    }
    else{
        top = topOfStack(stack);
        (stack->size)--;               //decrease size of the stack
        printf("Top element %d removed sucessfuly.\n", top);
        return top;
    }
}

int main(){                                        
    struct stack stackA;
    int option, element;
    stackA.size = 0;          //initial size of the stack is zero

    do{
        printf("Enter the Option: \n");
        printf("1. Push \n2. POP \n3. Top of Stack \n4. Exit\n");
        scanf("%d", &option);

        switch (option){
            case 1:
                printf("Enter the element you want to Push: \n");
                scanf("%d", &element);
                push(&stackA, element);
                printf("Element Inserted Sucessfully\n");
                break;
            case 2:
                pop(&stackA);
                break;
            case 3:
                topOfStack(&stackA);
                break;
            case 4:
                exit(0);
                break;
            default:
                printf("Wrong Option!\n");
                break;
        }
    } while (1);
    return 0;
}