#include <stdio.h>
#include <stdlib.h>

typedef int Data;

typedef struct Node Node;
struct Node {
    Data data;
    Node * next;
};

int size(Node * list) {
    int n = 0;
    for (Node * p = list; p != NULL; p = p->next)
        n++;
    return n;
}

int is_empty(Node * list) {
    return list == NULL;
}

void print(Node * list) {
    for (Node * p = list; p != NULL; p = p->next) {
        printf("%d ", p->data);
    }
    printf("\n");
}

void push(Node ** plist, Data d) {
    Node * p = malloc(sizeof(Node));
    p->data = d;
    p->next = *plist;
    *plist = p;
}

Data pop(Node ** plist) {
    Node * p = *plist;
    Data res = p->data;
    *plist = p->next;
    free(p);
    return res;
}

int main() {
    Data test[] = {10, 3, 17, 21};

    Node * list = NULL;
    print(list);
    printf("size=%d : \n", size(list));                     // size = 0
    printf("Empty: %s\n", is_empty(list) ? "YES" : "NO");   // Empty: YES

    for(int i = sizeof(test)/sizeof(test[0]) - 1; i >= 0; i--) {
        push(&list, test[i]);
        printf("push %d  size=%d : ", test[i], size(list));
        print(list);
    }

    printf("size=%d : \n", size(list));                     // size = 4
    printf("Empty: %s\n", is_empty(list) ? "YES" : "NO");   // Empty: NO

    while( ! is_empty(list)) {
        Data d = pop(&list);
        printf("pop %d : ", d);
        print(list);
    }

    printf("size=%d : \n", size(list));                     // size = 0
    printf("Empty: %s\n", is_empty(list) ? "YES" : "NO");   // Empty: YES

    return 0;
}
