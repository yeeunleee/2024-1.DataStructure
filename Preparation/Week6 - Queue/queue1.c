#include <stdio.h> 
#include <stdlib.h>
typedef struct Queue {
    int f;
    int r;
    int *Q;
} QUEUE;
int isEmpty(QUEUE *q, int n) {
    return ((q->r + 1) % n == q->f);
}
int isFull(QUEUE *q, int n) {
    return ((q->r + 2) % n == q->f);
}
void initQueue(QUEUE *q, int n) {
    q->Q = (int *) malloc(sizeof(int) * n);
    q->f = 1;
    q->r = 0;
}
void print(QUEUE *q, int n) {
    for (int i = 0; i < n; i++) {
        printf(" %d", q->Q[i]);
    }
    printf("\n");
}
int enqueue(QUEUE *q, int n, int e) {
    if (isFull(q, n)) {
        printf("overflow");
        print(q, n);
        return -1;
    }
    q->r = (q->r + 1) % n;
    q->Q[q->r] = e;
    return 0;
}
int dequeue(QUEUE *q, int n) {
    if (isEmpty(q, n)) {
        printf("underflow\n");
        return -1;
    }
    int e = q->Q[q->f];
    q->Q[q->f] = 0;
    q->f = (q->f + 1) % n;
    return e;
}
int main() {
    QUEUE q;
    int size, n, e;
    char op;

    scanf("%d %d", &size, &n);
    initQueue(&q, size);

    for (int i = 0; i < n; i++) {
        scanf(" %c", &op);
        if (op == 'I') {
            scanf(" %d", &e);
            if (enqueue(&q, size, e) == -1) break;
        }
        else if (op == 'D') {
            if (dequeue(&q, size) == -1) break;
        }
        else if (op == 'P') {
            print(&q, size);
        }
    }
    return 0;
}