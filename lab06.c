// Implement a Queue using Array and develop functions to perform enqueue and dequeue operations.
#include<stdio.h>
#include<stdlib.h>
#include<limits.h>

struct Queue{
    int *arr;              //Array
    int front, rear;       //front and rear of the Queue
    int size;              //size of the Queue
};
//For checking No. of Items in a Queue
int noOfItems(struct Queue *queue){
    if (queue->rear == -1 && queue->front == -1){
        return 0;
    } 
    else if (queue->rear >= queue->front){
        return (queue->rear - queue->front)+1;
    }
    else{
        return (((queue->size - 1) - queue->front) + 1) + (queue->rear + 1);
    }
}
//For checking Queue is Full or not.
int isFull(struct Queue *queue){
    if (noOfItems(queue)==queue->size){
        return 1;
    }
    else{
        return 0;
    }
}
//For inserting an element into the queue
int enQueue(struct Queue *queue, int element){
    if (isFull(queue)==0){
        if(noOfItems(queue)==0){
            queue->front = 0;
        }
        queue->rear = (queue->rear+1)%(queue->size);        //Incrementing the rear (circularly)
        queue->arr[queue->rear] = element;                  //Adding element at the rear
        return 1;
    }
    else{
        return 0;
    }
}
//For deleteing an element from the queue
int deQueue(struct Queue *queue){
    if (noOfItems(queue) != 0){
        int element = queue->arr[queue->front];
        if (queue->front == queue->rear){
            queue->front = -1;
            queue->rear = -1;
        }
        else{
            queue->front = (queue->front+1)%(queue->size);  //Decrementing the front (Circularly)
        }
        return element;
    }
    else{
        return INT_MIN;
    }   
}
//For the printing the element of the Queue
void printQueue(struct Queue *queue){
	int i = queue->front;
	if (noOfItems(queue) != 0){
        printf("Elements in the Queue are: \n");
		do{
	        printf("arr[%d]= %d ", i, queue->arr[i]);
	        i = (i + 1) % (queue->size);
	    } while (i != (queue->rear + 1) % queue->size);
		printf("\n");
	}
    else{
        printf("Queue Underflow!\n");
    }
}


int main(){
    struct Queue queueA;
    int option, element, front, rear, delete;
    queueA.front = -1;
    queueA.rear = -1;
    queueA.arr = (int *)malloc(((queueA.size)*sizeof(int)));

    do{
        printf("Enter the Option: \n");
        printf("1. EnQueue \t2. DeQueue \n3. Front \t4. Rear \n5. Print Queue \t6. Exit \n");
        scanf("%d", &option);

        switch (option){
            case 1: //For Insertig an element
                printf("Enter the element you want to Insert: \n");
                scanf("%d", &element);
                if (enQueue(&queueA, element)==1){
                    printf("Element %d Inserted Sucessfully\n", element);
                }
                else{
                    printf("Queue is Full!\n");
                }
                break;
            case 2: //For Deleting an element
                delete=deQueue(&queueA);
                if (delete!=INT_MIN){ 
                    printf("Element %d removed Sucessfully\n", delete);
                }
                else{
                    printf("Queue Underflow!\n");
                }
                break;
            case 3: //For printing the front element of the Queue
                if (noOfItems(&queueA)==0){
                    printf("Queue Underflow!\n");
                }
                else{
                    front = (queueA.arr[queueA.front]);
                    printf("Element at Front is %d\n", front);
                }
                break;
            case 4:  //For printing the rear element of the Queue
                if (noOfItems(&queueA)==0){
                    printf("Queue Underflow!\n");  
                }
                else{
                    rear = (queueA.arr[queueA.rear]);
                    printf("Element at Rear is %d\n", rear);
                }
                break;
            case 5: //For printing a Queue
                printQueue(&queueA);
                break;
            case 6:
                exit(0);
            default:
                printf("Wrong Option!\n");
                break;
        }
    } while (1);
    return 0;
}