#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct treeNode {
    struct treeNode *left;
    int id;
    int data;
    struct treeNode *right;
} TREENODE;
TREENODE* insertNode(int id, int d, TREENODE *l, TREENODE *r) {
    TREENODE *new = (TREENODE *) malloc(sizeof(TREENODE));
    new->data = d;
    new->id = id;
    new->left = l;
    new->right = r;
    return new;
}
TREENODE* treeBuild() {
    TREENODE *f7 = insertNode(7, 130, NULL, NULL);
    TREENODE *f8 = insertNode(8, 80, NULL, NULL);

    TREENODE *f4 = insertNode(4, 70, NULL, NULL);
    TREENODE *f5 = insertNode(5, 90, NULL, NULL);
    TREENODE *f6 = insertNode(6, 120, f7, f8);

    TREENODE *f2 = insertNode(2, 30, f4, f5);
    TREENODE *f3 = insertNode(3, 50, NULL, f6);

    TREENODE *f1 = insertNode(1, 20, f2, f3);
    return f1;
} 
int isInternal(TREENODE *v) {
    return v->left != NULL || v->right != NULL;
}
void totalCapacity(TREENODE *v, int *sum) {
    if (v != NULL) {
        *sum += v->data;
        totalCapacity(v->left, sum);
        totalCapacity(v->right, sum);
    }
}
TREENODE* findID(TREENODE *v, int id) {
    if (v != NULL) {
        if (v->id == id) return v;
        
        TREENODE *p = NULL;
        p = findID(v->left, id);
        if (p != NULL) return p;
        p = findID(v->right, id);
        if (p != NULL) return p;
    }
    return NULL;
}
int main() {
    TREENODE *root = treeBuild(), *node;
    int nodeID, sum = 0;
    scanf("%d", &nodeID);

    node = findID(root, nodeID);
    if (node == NULL) {
        printf("-1\n");
        return -1;
    }
    totalCapacity(node, &sum);
    printf("%d\n", sum);
    return 0;
}