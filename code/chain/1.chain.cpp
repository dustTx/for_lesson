#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct LinkListNode {
    int data;
    struct LinkListNode *next;
} LinkListNode;

typedef struct LinkList {
    LinkListNode head;
    int length;
} LinkList;

LinkListNode *getNewNode(int val) {
    LinkListNode *p = (LinkListNode *)malloc(sizeof(LinkListNode));
    p->data = val;
    p->next = NULL;
    return p;
}   

LinkList *getNewList() {
    LinkList *l = (LinkList *)malloc(sizeof(LinkList));
    l->head.next = NULL;
    l->length = 0;
    return l;
}

int insert(LinkList *l, int ind, int val) {
    if (ind < 0 || ind > l->length) return 0;
    LinkListNode *p = &(l->head), *new_node = getNewNode(val);
    while (ind--) p = p->next;
    new_node->next = p->next;
    p->next = new_node;
    l->length += 1;
    return 1;
}

int search(LinkList *l, int val) {
    int ind = 0;
    LinkListNode *p = l->head.next;
    while (p && p->data != val) p = p->next, ind += 1;
    if (ind == l->length) return -1;
    return ind;
}



void clear(LinkList *l) {
    LinkListNode *p = l->head.next, *q;
    while (p) {
        q = p;
        p = p->next;
        free(q);
    }
    free(l);
    return ;
}

void output(LinkList *l) {
    printf("head -> ");
    LinkListNode *p = l->head.next;
    while (p) {
        printf(" %d ->", p->data);
        p = p->next;
    }
    printf(" NULL\n");
}

void output_search(LinkList *l, int ind) {
    char str[100] = {0};
    int offset = ind;
    LinkListNode *p = l->head.next;
    while (ind != -1) {
        offset += sprintf(str, " %d ->", p->data);
        ind -= 1;
        p = p->next;
    }
    printf("    ");
    for (int i = 0; i < offset; i++) printf(" ");
    printf("^\n    ");
    for (int i = 0; i < offset; i++) printf(" ");
    printf("|\n\n");
    return ;
}

int main() {
    LinkList *l = getNewList();
    int ind, val;
    while (~scanf("%d%d", &ind, &val)) {
        printf("insert %d to LinkList at %d = %d\n", val, ind, insert(l, ind, val));
        output(l);
        ind = search(l, val);
        output_search(l, ind);
    }
    
    return 0;
}
