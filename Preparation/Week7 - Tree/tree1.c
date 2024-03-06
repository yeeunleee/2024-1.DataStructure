#include <stdio.h> 
#include <stdlib.h>
#include <string.h>
typedef struct treeNode {
    struct treeNode *left;
    int data;
    struct treeNode *right;
} TREENODE;
TREENODE* insertNode(int d, TREENODE* l, TREENODE* r) {
    TREENODE *new = (TREENODE *) malloc(sizeof(TREENODE));
    new->data = d;
    new->left = l;
    new->right = r;
    return new;
}
TREENODE* treeBuild() {
    TREENODE* f4 = insertNode(70, NULL, NULL);
    TREENODE* f5 = insertNode(90, NULL, NULL);
    TREENODE* f2 = insertNode(30, f4, f5);

    TREENODE* f7 = insertNode(130, NULL, NULL);
    TREENODE* f8 = insertNode(80, NULL, NULL);
    TREENODE* f6 = insertNode(120, f7, f8);
    TREENODE* f3 = insertNode(50, f6, NULL);

    TREENODE* f1 = insertNode(20, f2, f3);
    return f1;
}
TREENODE *leftChild(TREENODE *v) {
    return v->left;
}
TREENODE *rightChild(TREENODE *v) {
    return v->right;
}
int isInternal(TREENODE *v) {
    return (v->left != NULL || v->right != NULL);
}
void visit(TREENODE *v) {
    printf("%d ", v->data);
}


typedef struct queueNode {
    TREENODE *elem;
    struct queueNode *next;
} QUEUENODE;
typedef struct queue {
    QUEUENODE *f;
    QUEUENODE *r;
} QUEUE;
QUEUENODE *QinsertNode() {
    QUEUENODE *new = (QUEUENODE *)malloc(sizeof(QUEUENODE));
    new->next = NULL;
    return new;
}
void initQueue(QUEUE *q) {
    q->f = q->r = NULL;
}
int isEmpty(QUEUE *q) {
    return (q->f == NULL);
}
void enqueue(QUEUE *q, TREENODE *elem) {
    QUEUENODE *new = QinsertNode();
    new->elem = elem;
    if (isEmpty(q)) {
        q->f = q->r = new;
    }
    else {
        q->r->next = new;
        q->r = new;
    }
}
TREENODE* dequeue(QUEUE *q) {
    if(isEmpty(q)) {
        printf("underflow\n");
        return NULL;
    }
    TREENODE *v = q->f->elem;
    QUEUENODE *p = q->f;
    q->f = q->f->next;
    if (q->f == NULL) {
        q->r = NULL;
    }
    free(p);
    return v;
}
TREENODE* findNode(TREENODE *root, int num) {
    QUEUE q;
    TREENODE *v;
    int i = 1;
    initQueue(&q);
    enqueue(&q, root);

    while (!isEmpty(&q)) {
        v = dequeue(&q);
        //printf("%d ", v->data);
        if (i == num) {
            return v;
        }
        if (leftChild(v) != NULL) {
            enqueue(&q, leftChild(v));
        }
        if (rightChild(v) != NULL) {
            enqueue(&q, rightChild(v));
        }
        i++;
    }
    return NULL;
}
void print(TREENODE *v) {
    if (v == NULL) {
        printf("-1\n");
        return;
    }
    printf("%d ", v->data);
    if (leftChild(v) != NULL) {
        printf("%d ", leftChild(v)->data);
    }
    if (rightChild(v) != NULL) {
        printf("%d ", rightChild(v)->data);
    }
}
int main() {
    TREENODE *root = treeBuild();
    int num;
    scanf("%d", &num);
    print(findNode(root, num));
    return 0;
}