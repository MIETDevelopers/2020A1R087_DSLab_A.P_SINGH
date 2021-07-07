//C program to check if a given expression is correctly parenthesized using Stacks.
#include<stdio.h>
#include<stdlib.h>
#include<string.h>    //string as input  

struct Stack{
    char *arr;      //Array for Stack
    int top;        //Top of the Stack
    int size;       //size of Stack
};

// For Checking Empty Stack
int isEmpty(struct Stack *stack){ // function parameters
    if (stack->top == -1){        // if stack top is equal to -1 then stack is empty
        return 1;                  // true
    }
    return 0;                       //false
}
// For inserting element into the Stack
void push(struct Stack *stack, char element){
    if(stack->top == stack->size - 1){      //if stack top is equal to stack size 
        printf("Stack is FULL.\n");         // if stack size is full
    }
    else{
        stack->top++;                       //if stack is not full then increment by one
        stack->arr[stack->top] = element;   // element is inserted on top of stack
    }
}
// For removing elemnet out of the stack
char pop(struct Stack *stack){
    char top;                   //the item poped is a character type
    if (isEmpty(stack)){      
        return '\0';        //null character
    }
    else{
        top = stack->arr[stack->top];   //accessing the top element
        stack->top--;                 //decrement by one (to remove an element)        
        return top;
    }
}
// For checking the Expression is Balanced or Not. (Opening brackets = Closing brackets)
int isBalanced(struct Stack *stack, char *expression){
    for (int i = 0; expression[i] != '\0'; i++){    // for loop will run till the end of the string
        if (expression[i] == '('){                  // if open parenthesis then it will push in the stack
            push(stack, '(');  
        }
        else if (expression[i] == ')'){             // closing parenthesis check (pop)
            if (isEmpty(stack)){                    // is stack empty
                return 0;
            }
            pop(stack);                            // when stack is not empty
        }

        if (expression[i] == '['){                  // for square brackets
            push(stack, '[');  
        }
        else if (expression[i] == ']'){
            if (isEmpty(stack)){
                return 0;
            }
            pop(stack);  
        }

        if (expression[i] == '{'){                  // for curly brackets
            push(stack, '{');  
        }
        else if (expression[i] == '}'){
            if (isEmpty(stack)){
                return 0;
            }
            pop(stack);  
        }
    }

    if (isEmpty(stack)){                        //to check stack is empty(balanced) or not
        return 1;                                       
    }
    else{
        return 0;
    }
}


int main(){
    struct Stack stackA;
    char expression[50];           //for expression
    stackA.top=-1;                 // stack will be empty at starting
    stackA.arr = (char *)malloc(((stackA.size)*sizeof(char))); // allocating the memory for stack

    printf("Enter the Expression:\n"); 
    scanf("%s", expression);                        //%s is for string
    if(isBalanced(&stackA, expression)){        //calling the above function
        printf("Expression is Balanced.\n");
    }
    else{
        printf("Expression is Not Balanced.\n");
    }
    free(stackA.arr); // free the memory
    return 0;
}