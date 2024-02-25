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
int getPriority(char c) {
    if (c == '!' || c == 'p' || c == 'm') return 6;
    else if (c == '*' || c == '/') return 5;
    else if (c == '+' || c == '-') return 4;
    else if (c == '>' || c == '<') return 3;
    else if (c == '&') return 2;
    else if (c == '|') return 1;
    else if (c == '(') return 0;
}
void print(STACK *s) {
    for (int i = s->top; i >= 0; i--) {
        printf("%c", s->array[i]);
    }
    printf("\n");
}
void convert(char *infix, char *postfix) {
    STACK stack;
    int i = 0, idx = 0;
    char before = '\0';
    initStack(&stack, 101);

    while(!endOfString(infix, i)) {
        char s = infix[i];
        char ss[3] = { '\0' };
        if ('A' <= s && s <= 'Z') {
            postfix[idx++] = s;
        }
        else if (s == '(') {
            push(&stack, s);
        }
        else if (s == ')') {
            while(stack.array[stack.top] != '(') {
                postfix[idx++] = pop(&stack);
            }
            pop(&stack);
        }
        else {
            if (s == '+' || s == '-') {
                if (i == 0) {
                    s = (s == '+') ? 'p' : 'm';
                }
                else if (infix[i - 1] != ')' && !('A' <= infix[i - 1] && infix[i - 1] <= 'Z')) {
                    s = (s == '+') ? 'p' : 'm';
                }
            }

            if ((s == '&' || s == '|') && s != before) {
                before = s;
            }
            else {
                while(!isEmpty(&stack) && (getPriority(s) <= getPriority(stack.array[stack.top]))) {
                    if (stack.array[stack.top] == '&' || stack.array[stack.top] == '|') {
                        postfix[idx++] = stack.array[stack.top];
                        postfix[idx++] = pop(&stack);
                    }
                    else if (stack.array[stack.top] == 'p') {
                        postfix[idx++] = '+';
                        pop(&stack);
                    }
                    else if (stack.array[stack.top] == 'm') {
                        postfix[idx++] = '-';
                        pop(&stack);
                    }
                    else {
                        postfix[idx++] = pop(&stack);
                    }
                }
                push(&stack, s);
                if (s == '&' || s == '|') before = '\0';
            }
        }
        i++;
    }
    while(!isEmpty(&stack)) {
        if (stack.array[stack.top] == '&' || stack.array[stack.top] == '|') {
            postfix[idx++] = stack.array[stack.top];
            postfix[idx++] = pop(&stack);
        }
        else if (stack.array[stack.top] == 'p') {
            postfix[idx++] = '+';
            pop(&stack);
        }
        else if (stack.array[stack.top] == 'm') {
            postfix[idx++] = '-';
            pop(&stack);
        }
        else {
            postfix[idx++] = pop(&stack);
        }
    }
    postfix[idx] = '\0';
}
int main() {
    char input[101];
    int n;
    scanf("%d", &n);
    getchar();
    for (int i = 0; i < n; i++) {
        scanf("%s", input);
        char postfix[101] = {'\0'};
        convert(input, postfix);
        printf("%s\n", postfix);
    }
    return 0;
}
