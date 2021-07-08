// Implement a Stack using Arrays in C and develop functions to perform push and pop operations
#include<stdio.h>
#include<stdlib.h>
#include<limits.h> // for int_min

struct Stack{
    int *arr;
    int top;
    int size;
};

// For Checking Empty Stack
int isEmpty(struct Stack *stack){
    if (stack->top == -1){
        return 1;
    }
    return 0;
}
// For inserting element into the Stack
void push(struct Stack *stack, int element){
    if (stack->top == stack->size - 1){
        printf("Stack is FULL.\n");
    }
    else{
        stack->top++;
        stack->arr[stack->top] = element;
        printf("Element Inserted Sucessfully\n");
    }
}
// For removing elemnet out of the stack
int pop(struct Stack *stack){
    int top;
    if (isEmpty(stack)){
        return INT_MIN;
    }
    else{
        top = stack->arr[stack->top];
        stack->top--;
        return top;
    }
}
// To check top of the Stack
int topOfStack(struct Stack *stack){
    int topElement;
    if (isEmpty(stack)){
        return INT_MIN;
    }
    else{
        topElement = stack->arr[stack->top];
        return topElement;
    }
}

int main(){
    struct Stack stackA;
    int option, element, topElement;
    stackA.top = -1;
    stackA.arr = (int *)malloc(((stackA.size)*sizeof(int)));

    do{
        printf("Enter the Option: \n");
        printf("1. Push \n2. POP \n3. Top of Stack \n4. Exit\n");
        scanf("%d", &option);

        switch (option){
            case 1:
                printf("Enter the element you want to Push: \n");
                scanf("%d", &element);
                push(&stackA, element);
                break;
            case 2:
                if (pop(&stackA)!=INT_MIN){
                    printf("Top Element removed Sucessfully\n");
                }
                else{
                    printf("Stack is Empty!\n");
                }
                break;
            case 3:
                if (topOfStack(&stackA)!=INT_MIN){
                    topElement = topOfStack(&stackA);
                    printf("Element at top of a Stack is %d\n", topElement);
                }
                else{
                    printf("Stack is Empty!\n");
                }
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