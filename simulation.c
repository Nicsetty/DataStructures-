#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_QUEUE_SIZE 100

typedef struct {
    int queue[MAX_QUEUE_SIZE];
    int front;
    int rear;
    int size;
} Queue;

void initQueue(Queue* q) {
    q->front = 0;
    q->rear = -1;
    q->size = 0;
}

bool isQueueEmpty(Queue* q) {
    return q->size == 0;
}

bool isQueueFull(Queue* q) {
    return q->size == MAX_QUEUE_SIZE;
}

void enqueue(Queue* q, int plane) {
    if (!isQueueFull(q)) {
        q->rear = (q->rear + 1) % MAX_QUEUE_SIZE;
        q->queue[q->rear] = plane;
        q->size++;
    }
}

int dequeue(Queue* q) {
    if (!isQueueEmpty(q)) {
        int plane = q->queue[q->front];
        q->front = (q->front + 1) % MAX_QUEUE_SIZE;
        q->size--;
        return plane;
    }
    return -1;
}

int main() {
    Queue landingQueue, takeoffQueue;
    initQueue(&landingQueue);
    initQueue(&takeoffQueue);

    int endTime, numLanding, numTakeoff, planeId = 1, currentTime;
    
    printf("Enter simulation end time: ");
    scanf("%d", &endTime);

    printf("Enter number of landing planes: ");
    scanf("%d", &numLanding);

    printf("Enter number of takeoff planes: ");
    scanf("%d", &numTakeoff);

    for (int i = 0; i < numLanding; i++) {
        enqueue(&landingQueue, planeId++);
    }

    for (int i = 0; i < numTakeoff; i++) {
        enqueue(&takeoffQueue, planeId++);
    }

    for (currentTime = 1; currentTime <= endTime; currentTime++) {
        printf("Time unit %d: ", currentTime);
        if (!isQueueEmpty(&landingQueue)) {
            int plane = dequeue(&landingQueue);
            printf("Plane %d landed.\n", plane);
        } else if (!isQueueEmpty(&takeoffQueue)) {
            int plane = dequeue(&takeoffQueue);
            printf("Plane %d took off.\n", plane);
        } else {
            printf("Runway idle.\n");
        }
    }

    return 0;
}
