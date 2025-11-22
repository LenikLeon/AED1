#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

typedef struct {
    Node* front;
    Node* rear;
} Queue;

Queue* createQueue() {
    Queue* q = (Queue*)malloc(sizeof(Queue));
    q->front = q->rear = NULL;
    return q;
}

void enqueue(Queue* q, int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    if (q->rear == NULL) {
        q->front = q->rear = newNode;
        return;
    }
    q->rear->next = newNode;
    q->rear = newNode;
}

int dequeue(Queue* q) {
    if (q->front == NULL) return -1;
    Node* temp = q->front;
    int data = temp->data;
    q->front = q->front->next;
    if (q->front == NULL) q->rear = NULL;
    free(temp);
    return data;
}

int isEmpty(Queue* q) {
    return q->front == NULL;
}

int main() {
    int n;
    while (1) {
        scanf("%d", &n);
        if (n == 0) break;
        
        Queue* q = createQueue();
        for (int i = 1; i <= n; i++) {
            enqueue(q, i);
        }
        
        printf("Discarded cards:");
        int first = 1;
        while (1) {
            int discarded = dequeue(q);
            if (isEmpty(q)) {
                printf("\nRemaining card: %d\n", discarded);
                break;
            }
            if (first) {
                printf(" %d", discarded);
                first = 0;
            } else {
                printf(", %d", discarded);
            }
            int moved = dequeue(q);
            enqueue(q, moved);
        }
        free(q);
    }
    return 0;
}