#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct treeNode {
    int id;
    struct treeNode *left;
    struct treeNode *right;
} TREENODE;
TREENODE* getNode() {
    TREENODE *new = (TREENODE *) malloc(sizeof(TREENODE));
    new->id = '\0';
    new->left = NULL;
    new->right = NULL;
    return new;
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
TREENODE* treeBuild() {
    TREENODE *root = (TREENODE *) malloc(sizeof(TREENODE));
    root->left = NULL;
    root->right = NULL;

    int id, left_id, right_id, num, flag = 1;
    scanf("%d", &num);
    while (num--) {
        scanf("%d %d %d", &id, &left_id, &right_id);
        TREENODE *v;
        if (flag) {
            v = root;
            flag = 0;
        }
        else {
            v = findID(root, id);
        }
        v->id = id;
        if (left_id) {
            TREENODE *left = getNode();
            left->id = left_id;
            v->left = left;
        }
        if (right_id) {
            TREENODE *right = getNode();
            right->id = right_id;
            v->right = right;
        }
    }
    return root;
}
void search(TREENODE *root) {
    int num;
    char info[101];
    TREENODE *v = root;
    scanf("%d", &num);
    while (num--) {
        scanf("%s", info);
        v = root;
        printf(" %d", v->id);
        for (int i = 0; info[i] != '\0'; i++) {
            if      (info[i] == 'L') v = v->left;
            else if (info[i] == 'R') v = v->right;
            printf(" %d", v->id);
        }
        printf("\n");
    }
}
int main() {
    TREENODE *root = treeBuild();
    printf("check\n");
    search(root);
    return 0;
}