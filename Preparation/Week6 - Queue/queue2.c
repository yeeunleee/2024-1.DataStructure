#include <stdio.h> 
#include <stdlib.h>
#include <string.h>
typedef struct Node {
    int elem;
    struct Node *prev;
    struct Node *next;
} NODE;
typedef struct Deque {
    NODE *f;
    NODE *r;
} DEQUE;
NODE *getNode() {
    NODE *new = (NODE *) malloc(sizeof(NODE));
    new->next = new->prev = NULL;
    return new;
}
void initDeque(DEQUE *deq) {
    deq->f = deq->r = NULL;
}
int isEmpty(DEQUE *deq) {
    return deq->f == NULL;
}
void add_front(DEQUE *deq, int x) {
    NODE *new = getNode();
    new->elem = x;
    if (isEmpty(deq)) {
        deq->f = deq->r = new;
    }
    else {
        new->next = deq->f;
        deq->f->prev = new;
        deq->f = new;
    }
}
void add_rear(DEQUE *deq, int x) {
    NODE *new = getNode();
    new->elem = x;
    if (isEmpty(deq)) {
        deq->f = deq->r = new;
    }
    else {
        new->prev = deq->r;
        deq->r->next = new;
        deq->r = new;
    }
}
int delete_front(DEQUE *deq) {
    if (isEmpty(deq)) {
        printf("underflow\n");
        return -1;
    }
    int e = deq->f->elem;
    NODE *p = deq->f;
    deq->f = deq->f->next;
    if (deq->f == NULL) {
        deq->r = NULL;
    }
    else {
        deq->f->prev = NULL;
    }
    free(p);
    return e;
}
int delete_rear(DEQUE *deq) {
    if (isEmpty(deq)) {
        printf("underflow\n");
        return -1;
    }
    int e = deq->r->elem;
    NODE *p = deq->r;
    deq->r = deq->r->prev;
    if (deq->r == NULL) {
        deq->f = NULL;
    }
    else {
        deq->r->next = NULL;
    }
    free(p);
    return e;
}
void print(DEQUE *deq) {
    for (NODE *p = deq->f; ; p = p->next) {
        printf(" %d", p->elem);
        if (p == deq->r) break;
    }
    printf("\n");
}
int main() {
    DEQUE deq;
    initDeque(&deq);
    int n, num;
    char op[3];
    scanf("%d", &n);
    getchar();
    for (int i = 0; i < n; i++) {
        scanf(" %s", op);
        if (!strcmp(op, "AF")) {
            scanf(" %d", &num);
            add_front(&deq, num);
        }
        else if (!strcmp(op, "AR")) {
            scanf(" %d", &num);
            add_rear(&deq, num);
        }
        else if (!strcmp(op, "DF")) {
            if (delete_front(&deq) == -1) break;
        }
        else if (!strcmp(op, "DR")) {
            if (delete_rear(&deq) == -1) break;
        }
        else if (!strcmp(op, "P")) {
            print(&deq);
        }
    }
    return 0;
}