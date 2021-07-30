// Implement a Stack using Arrays in C and develop functions to perform push and pop operations
#include<stdio.h> // standard header file (for printf and scanf)
#include<stdlib.h> // for dynamic memory allocation
#include<limits.h> // for INT_MIN

struct Stack{   //structure for stack
    int *arr;   //array
    int top;    //stack top
    int size;   //size of stack
};

// For Checking Empty Stack
int isEmpty(struct Stack *stack){  //function parameters
    if (stack->top == -1){         //condition (if stack top is -1 then its empty)
        return 1;                   // 1 = true
    }
    return 0;                       // 0 = false
}
// For Checking the Stack is Full or Not
int isFull(struct Stack *stack){        //function parameter
    if (stack->top == stack->size-1){   // if stack top = stack size -1 then stack is full eg 49
        return 1;                       // 1 = true
    }
    else{
        return 0;                       // 0 = false
    }
}
// For inserting element into the Stack
void push(struct Stack *stack, int element){  // void is used bcoz function will not return anything
    if (isFull(stack)==1){                    // calling isFull function
        printf("Stack is FULL.\n");            //if the stack is full
    }
    else{
        stack->top++;                           // if not full then stack will be incremented by 1
        stack->arr[stack->top] = element;       // it will insert the element on top of stack
        printf("Element %d Inserted Sucessfully\n", element); // element inserted succesfully
    }
}
// For removing elemnet out of the stack
int pop(struct Stack *stack){   // function parameters
    int top;                    // variable (for saving the element to be removed)
    if (isEmpty(stack)){         // checking the stack is empty or not
        return INT_MIN;         // if stack is empty then it will return minimum integer value (-2147483647 - 1)                                     
    }
    else{
        top = stack->arr[stack->top];  // it will store the top element before removing it                                                                                /
        stack->top--;                   // size decremented by 1
        return top;                     // returned the removed element 
    }
}
// To check top of the Stack
int topOfStack(struct Stack *stack){  //function parameters
    int topElement;                     // variable to store the element at top
    if (isEmpty(stack)){        //  if stack is empty then it will return minimum integer value (-2147483647 - 1)                                     
        return INT_MIN;
    }
    else{
        topElement = stack->arr[stack->top]; // if not empty then the current top element will be store here
        return topElement;                      // return the element at the top
    }
}

int main(){
    struct Stack stackA;                            // declaring a stackA
    int option, element, topElement, elementRemoved;   //options for switch case
    stackA.top = -1;                                    // initially stack top will be -1 means stack is empty
    stackA.size = 50;                                   //MaxSize
    stackA.arr = (int *)malloc(((stackA.size)*sizeof(int))); // for memory allocation

    do{
        printf("Enter the Option: \n");
        printf("1. Push \n2. POP \n3. Top of Stack \n4. Exit\n");
        scanf("%d", &option);

        switch (option){
            case 1:
                printf("Enter the element you want to Push: \n"); 
                scanf("%d", &element);
                push(&stackA, element); // calling function and passing parameters (element to be inserted)
                break;
            case 2:
                elementRemoved = stackA.arr[stackA.top];    //storing the topElement to be deleted
                if (pop(&stackA)!=INT_MIN){ // if stack is not empty (return will not be INT_MIN)
                    printf("Top Element %d removed Sucessfully\n", elementRemoved);
                }
                else{
                    printf("Stack is Empty!\n");
                }
                break;
            case 3:
                if (topOfStack(&stackA)!=INT_MIN){ // if stack is not empty
                    topElement = topOfStack(&stackA);           //storing the topElement 
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