#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct ArrayStack {
    int *array;
    int n;
    int top;
} STACK;
void initStack(STACK *s, int n) {
    s->array = (int *) malloc(sizeof(int) * n);
    s->n = n;
    s->top = -1; 
    return;
}
int isFull(STACK *s) {
    return s->top == s->n - 1;
}
void push(STACK *s, char e) {
    if (isFull(s)) {
        printf("Stack FULL\n");
    }
    else {
        s->top += 1;
        s->array[s->top] = e;
    }
    return;
}
int isEmpty(STACK *s) {
    return s->top == -1;
}
char pop(STACK *s) {
    if (isEmpty(s)) {
        printf("Stack Empty\n");
        return -1;
    }
    else {
        s->top -= 1;
        return s->array[s->top + 1];
    }
}
void peek(STACK *s) {
    if (isEmpty(s)) {
        printf("Stack Empty\n");
    }
    else {
        printf("%c\n", s->array[s->top]);
    }
}
void duplicate(STACK *s) {
    if (isFull(s)) {
        printf("Stack FULL\n");
    }
    else if (isEmpty(s)) {
        printf("Stack Empty\n");
    }
    else {
        char e = pop(s);
        push(s, e);
        push(s, e);
    }
}
void upRotate(STACK *s, int num) {
    if (num > s->top + 1) return;
    char tmp = s->array[s->top];
    for (int i = 0; i < num - 1; i++) {
        s->array[s->top - i] = s->array[s->top - i - 1];
    }
    s->array[s->top - num + 1] = tmp;
}
void downRotate(STACK *s, int num) {
    if (num > s->top + 1) return;
    char tmp = s->array[s->top - num + 1];
    for (int i = 0; i < num - 1; i++) {
        s->array[s->top - num + i + 1] = s->array[s->top - num + i + 2];
    }
    s->array[s->top] = tmp;
}
void print(STACK *s) {
    for (int i = s->top; i >= 0; i--) {
        printf("%c", s->array[i]);
    }
    printf("\n");
}
int main() {
    STACK stack;
    int n, m, num;
    char op[6], elem;
    scanf("%d %d", &n, &m);

    initStack(&stack, n);

    for (int i = 0; i < m; i++) {
        scanf("%s", op);
        if (strcmp(op, "PUSH") == 0) {
            scanf(" %c", &elem);
            push(&stack, elem);
        }
        else if (strcmp(op, "POP") == 0) {
            pop(&stack);
        }
        else if (strcmp(op, "PEEK") == 0) {
            peek(&stack);
        }
        else if (strcmp(op, "DUP") == 0) {
            duplicate(&stack);
        }
        else if (strcmp(op, "UpR") == 0) {
            scanf(" %d", &num);
            upRotate(&stack, num);
        }
        else if (strcmp(op, "DownR") == 0) {
            scanf(" %d", &num);
            downRotate(&stack, num);
        }
        else if (strcmp(op, "PRINT") == 0) {
            print(&stack);
        }
    }
    return 0;
}
