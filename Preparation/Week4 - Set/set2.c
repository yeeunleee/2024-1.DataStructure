#include <stdio.h> 
#include <stdlib.h>
typedef struct Node {
    int elem;
    struct Node *next;
} NODE;
typedef struct SList {
    NODE *head;
    int count;
} SLIST;
NODE *getNode();
void init(SLIST *);
void insert(SLIST *, int);
NODE *uunion(NODE *, NODE *);
NODE *intersect(NODE *, NODE *);
void print(NODE *);
int main() {
    SLIST setA, setB;
    init(&setA);
    init(&setB);
    int n, num;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &num);
        insert(&setA, num);
    }
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &num);
        insert(&setB, num);
    }
    NODE *uni = uunion(setA.head->next, setB.head->next), *inter = intersect(setA.head->next, setB.head->next);
    print(uni);
    print(inter);
    return 0;
}
NODE *getNode() {
    NODE *new = (NODE *)malloc(sizeof(NODE));
    new->next = NULL;
    return new;
}
void init(SLIST *list) {
    list->head = getNode();
    list->count = 0;
}
void insert(SLIST *list, int num) {
    NODE *new = getNode();
    new->elem = num;
    NODE *p = list->head;
    while (p->next != NULL) {
        p = p->next;
    }
    p->next = new;
}
NODE *uunion(NODE *A, NODE *B) {
    if (A == NULL && B == NULL) {
        return NULL;
    }
    NODE *p = getNode();
    if (A == NULL) {
        p->elem = B->elem;
        p->next = uunion(A, B->next);
    }
    else if (B == NULL) {
        p->elem = A->elem;
        p->next = uunion(A->next, B);
    }
    else {
        if (A->elem < B->elem) {
            p->elem = A->elem;
            p->next = uunion(A->next, B);
        }
        else if (A->elem > B->elem) {
            p->elem = B->elem;
            p->next = uunion(A, B->next);
        }
        else {
            p->elem = A->elem;
            p->next = uunion(A->next, B->next);
        }
    }
    return p;
}
NODE *intersect(NODE *A, NODE *B) {
    if (A == NULL || B == NULL) {
        return NULL;
    }
    if (A->elem < B->elem) {
        return intersect(A->next, B);
    }
    else if (A->elem > B->elem) {
        return intersect(A, B->next);
    }
    else {
        NODE *p = getNode();
        p->elem = A->elem;
        p->next = intersect(A->next, B->next);
        return p;
    }
}
void print(NODE *A) {
    int flag = 0;
    NODE *p = A;
    while (p != NULL) {
        printf(" %d", p->elem);
        p = p->next;
        flag = 1;
    }
    if (!flag) printf("0");
    printf("\n");
}