#include <stdio.h>
#include <stdlib.h>
typedef struct Node {
    char elem;
    struct Node *prev;
    struct Node *next;
} NODE;
typedef struct DList {
    NODE *head;
    NODE *tail;
    int count;
} DLIST;
NODE *newNode();
void init(DLIST *list);
void add(DLIST *list, int r, char e);
void delete(DLIST *list, int r);
char get(DLIST *list, int r);
void print(DLIST *list);
int main() {
    DLIST list;
    int n, r;
    char op, elem;

    init(&list);
    scanf("%d", &n);
    getchar();
    for (int i = 0; i < n; i++) {
        scanf(" %c", &op);
        if (op == 'A') {
            scanf(" %d %c", &r, &elem);
            add(&list, r, elem);
        }
        else if (op == 'D') {
            scanf(" %d", &r);
            delete(&list, r);
        }
        else if (op == 'G') {
            scanf(" %d", &r);
            if (get(&list, r) != 0) printf("%c\n", get(&list, r));
        }
        else if (op == 'P') {
            print(&list);
        }
    }
    return 0;
}
NODE *newNode() {
    NODE *new = (NODE *) malloc(sizeof(NODE));
    new->prev = new->next = NULL;
    return new;
}
void init(DLIST *list) {
    list->head = newNode();
    list->tail = newNode();
    list->head->next = list->tail;
    list->tail->prev = list->head;
    list->count = 0;
}
void add(DLIST *list, int r, char e) {
    if (r != 1 && (r < 1 || r > list->count + 1)) {
        printf("invalid position\n");
        return;
    }
    NODE *current = list->head;
    NODE *new = newNode();
    new->elem = e;
    for (int i = 0; i < r; i++) {
        current = current->next;
    }
    new->prev = current->prev;
    new->next = current;
    (current->prev)->next = new;
    current->prev = new;
    list->count++;
}
void delete(DLIST *list, int r) {
    if (r < 1 || r > list->count) {
        printf("invalid position\n");
        return;
    }
    NODE *current = list->head;
    for (int i = 0; i < r; i++) {
        current = current->next;
    }
    (current->prev)->next = current->next;
    (current->next)->prev = current->prev;
    free(current);
    list->count--;
}
char get(DLIST *list, int r) {
    if (r < 1 || r > list->count) {
        printf("invalid position\n");
        return 0;
    }
    NODE *current = list->head;
    for (int i = 0; i < r; i++) {
        current = current->next;
    }
    return current->elem;
}
void print(DLIST *list) {
    NODE *current = list->head->next;
    while(1) {
        printf("%c", current->elem);
        if (current->next == list->tail) break;
        current = current->next;
    }
    printf("\n");
}