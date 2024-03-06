#include <stdio.h> 
#include <stdlib.h>
typedef struct Node {
    int coef;
    int exp;
    struct Node *next;
} NODE;
typedef struct list {
    NODE *head;
} POLY;
NODE *new_node();
void init(POLY *poly);
void appendTerm(NODE *head, int coef, int exp);
POLY addPoly(POLY *x, POLY *y);
void print(POLY *poly);
int main() {
    POLY x, y, result;
    int n, coef, exp;
    init(&x);
    init(&y);
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &coef, &exp);
        appendTerm(x.head, coef, exp);
    }
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &coef, &exp);
        appendTerm(y.head, coef, exp);
    }
    result = addPoly(&x, &y);
    print(&result);
}
NODE *new_node() {
    NODE *new = (NODE *) malloc(sizeof(NODE));
    new->next = NULL;
    return new;
}
void init(POLY *poly) {
    poly->head = new_node();
}
void appendTerm(NODE *head, int coef, int exp) {
    NODE *new = new_node();
    new->coef = coef;
    new->exp = exp;

    while (head->next != NULL) {
        head = head->next;
    }
    head->next = new;
}
POLY addPoly(POLY *x, POLY *y) {
    POLY result;
    init(&result);
    NODE *i, *j;
    i = x->head->next;
    j = y->head->next;
    while (i != NULL && j != NULL) {
        if (i->exp > j->exp) {
            appendTerm(result.head, i->coef, i->exp);
            i = i->next;
        }
        else if (j->exp > i->exp) {
            appendTerm(result.head, j->coef, j->exp);
            j = j->next;
        }
        else {
            int sum = i->coef + j->coef;
            if (sum != 0) {
                appendTerm(result.head, sum, i->exp);
            }
            i = i->next;
            j = j->next;
        }
    }
    while (i != NULL) {
        appendTerm(result.head, i->coef, i->exp);
        i = i->next;
    }
    while (j != NULL) {
        appendTerm(result.head, j->coef, j->exp);
            j = j->next;
    }
    return result;
}
void print(POLY *poly) {
    NODE *current = poly->head->next;
    while (current != NULL) {
        printf(" %d %d", current->coef, current->exp);
        current = current->next;
    }
}