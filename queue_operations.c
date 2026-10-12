#include <stdio.h>

#define MAX 5

int Queue[MAX];
int front = -1;
int rear = -1;


   //1) INSERT (Enqueue)
  
int enqueue(int x) {
    if (rear == MAX - 1) {
        printf("Q is FULL!! \n");
    }
    else {
        if (front == -1) front = 0;
        rear++;
        Queue[rear] = x;
        printf("%d has been queued \n", x);
    }
}


   //2) DELETE (Dequeue)

int dequeue() {
    if (front == -1 || front > rear) {
        printf("Q is EMPTY!! \n");
        return -1;
    }
    else {
        int val = Queue[front];
        printf("%d has been dequeued \n", val);
        front++;
        if (front > rear) {
            front = -1;
            rear = -1;
        }
        return val;
    }
}


   //3) TRAVERSING (Display all elements)
   
void traverse() {
    if (front == -1 || front > rear) {
        printf("Q is EMPTY!! Nothing to display \n");
    }
    else {
        printf("Queue elements: ");
        for (int i = front; i <= rear; i++) {
            printf("%d ", Queue[i]);
        }
        printf("\n");
    }
}


   //4) UPDATE (Change value at a given position)
  
void update(int position, int newValue) {
    if (front == -1 || front > rear) {
        printf("Q is EMPTY!! Nothing to update \n");
    }
    else if (position < 0 || position > (rear - front)) {
        printf("Invalid position! \n");
    }
    else {
        int index = front + position;
        int oldVal = Queue[index];
        Queue[index] = newValue;
        printf("Updated: %d -> %d at position %d \n", oldVal, newValue, position);
    }
}


   //MAIN FUNCTION
  
int main() {

    printf(" INSERT OPERATIONS \n");
    enqueue(10);
    enqueue(20);
    enqueue(30);
    enqueue(40);
    enqueue(50);

    printf("\n TRAVERSE (Display) \n");
    traverse();

    printf("\n UPDATE OPERATION \n");
    update(1, 99);   // Change position 1 (value 20) to 99
    traverse();

    printf("\n DELETE OPERATIONS \n");
    dequeue();
    dequeue();
    traverse();

    printf("\n INSERT AFTER DELETE \n");
    enqueue(60);
    traverse();

    return 0;
}