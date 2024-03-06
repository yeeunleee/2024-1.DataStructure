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
int member(SLIST *, int);
int subset(SLIST *, SLIST *);
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
    printf("%d\n", subset(&setA, &setB));
    return 0;
}
NODE *getNode() {
    NODE *new = (NODE *) malloc(sizeof(NODE));
    new->next = NULL;
    return new;
}
void init(SLIST *A) {
    A->head = NULL;
    A->count = 0;
}
void insert(SLIST *X, int num) {
    NODE *new = getNode();
    new->elem = num;
    if (X->head == NULL) {
        X->head = new;
    }
    else {
        NODE *p = X->head;
        while (p->next != NULL) {
            p = p->next;
        }
        p->next = new;
    }
}
int member(SLIST *X, int e) {
    if (X->head == NULL) {
        return 0;
    }
    NODE *p = X->head;
    while (1) {
        int a = p->elem;
        if (a < e) {
            if (p->next == NULL) return 0;
            else p = p->next;
        }
        else if (a > e) return 0;
        else return 1;
    }
    return 0;
}
int subset(SLIST *A, SLIST *B) {
    int flag = 1;
    if (A->head == NULL) {
        return 0;
    }
    NODE *p = A->head;
    while (1) {
        if (member(B, p->elem)) {
            if (p->next == NULL) return 0;
            else p = p->next;
        }
        else {
            flag = 0;
            break;
        }
    }
    if (!flag) {
        p = A->head;
        while (1) {
            if (member(B, p->elem)) {
                p = p->next;
            }
            else {
                return p->elem;
                break;
            }
        }
    }
    return 0;
}