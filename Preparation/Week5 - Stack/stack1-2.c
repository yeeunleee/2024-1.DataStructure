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
char endOfString(char *str, int i) {
    return str[i] == '\0';
}
char isCounterpart(char s, char t) {
    return (s == ')' && t == '(') ||
           (s == ']' && t == '[') ||
           (s == '}' && t == '{');
}
char isBalanced(char *str) {
    STACK stack;
    int len = strlen(str), i = 0;
    initStack(&stack, len);

    while(!endOfString(str, i)) {
        char s = str[i];
        if (s == '(' || s == '[' || s == '{') {
            push(&stack, s);
        }
        else if (s == ')' || s == ']' || s == '}') {
            if (isEmpty(&stack)) {
                return 0;
            }
            char t = pop(&stack);
            if (!isCounterpart(s, t)) {
                return 0;
            }
        }
        i++;
    }
    return isEmpty(&stack);
}
int bracket(char *str) {
    int count = 0;
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == '(' || str[i] == '[' || str[i] == '{' || 
        str[i] == ')' || str[i] == ']' || str[i] == '}') {
            count++;
        }
    }
    return count;
}
int main() {
    STACK stack;
    char str[1001], isOK[6] = "OK";

    fgets(str, 1001, stdin);

    int len = strlen(str);
    int count = bracket(str);
    if (!isBalanced(str)) strcpy(isOK, "Wrong");
    
    printf("%s_%d\n", isOK, count);
    return 0;
}
