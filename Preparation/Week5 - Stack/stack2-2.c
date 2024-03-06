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
void push(STACK *s, int e) {
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
int pop(STACK *s) {
    if (isEmpty(s)) {
        printf("Stack Empty\n");
        return -1;
    }
    else {
        s->top -= 1;
        return s->array[s->top + 1];
    }
}
char endOfString(char *str, int i) {
    return str[i] == '\0';
}
int doOperator(char op, int x, int y) {
    if (op == '*') return x * y;
    else if (op == '/') return x / y;
    else if (op == '+') return x + y;
    else if (op == '-') return x - y;
}
int evaluate(char *postfix) {
    STACK stack;
    initStack(&stack, 101);
    int value, i = 0, a, b;
    char s;

    while(!endOfString(postfix, i)) {
        s = postfix[i];
        if ('0' <= s && s <= '9') {
            s = (int)(s - '0');
            //printf("%d: %d\n", i, s);
            push(&stack, s);
        }
        else {
            a = pop(&stack);
            b = pop(&stack);
            push(&stack, doOperator(s, b, a));
        }
        i++;
    }
    return pop(&stack);
}
int main() {
    char postfix[101];
    int n;
    scanf("%d", &n);
    getchar();
    for (int i = 0; i < n; i++) {
        scanf("%s", postfix);
        printf("%d\n", evaluate(postfix));
    }
    return 0;
}
