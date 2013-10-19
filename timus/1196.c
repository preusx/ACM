#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int number, count;
    struct Node *children[10];
} Node;


Node *create(int number, int count) {
    Node *tmp;
    int i;

    tmp = (Node *)malloc(sizeof(Node));
    tmp->number = number;
    tmp->count = count;

    for(i = 0; i < 10; i++) {
        tmp->children[i] = 0;
    }

    return tmp;
}

Node *add(Node *root, int number) {
    int ch, i;
    char hb = 0;
    Node *current = root;

    for(i = 1000000000; i != 0; i /= 10) {
        if((ch = number/i) > 0 || hb) {
            if(!current->children[ch]) {
                current->children[ch] = create(ch, 0);
            }

            number %= i;
            current = current->children[ch];
            hb = 1;
        }
    }
    
    current->count++;

    return current;
}

Node *find(Node *root, int number) {
    int ch, i;
    char hb = 0;
    Node *current = root;

    for(i = 1000000000; i != 0; i /= 10) {
        if((ch = number/i) > 0 || hb) {
            if(!current->children[ch]) {
                return 0;
            }

            number %= i;
            current = current->children[ch];
            hb = 1;
        }
    }

    return current;
}

int main() {
    int n, b, i, count = 0;
    Node *root = create(0, 0), *nb;

    scanf("%d", &n);
    for(i=0; i<n; i++) {
        scanf("%d", &b);
        add(root, b);
    }

    scanf("%d", &n);
    for(i=0; i<n; i++) {
        scanf("%d", &b);
        nb = find(root, b);

        if(nb) {
            if(nb->count > 0) {
                count++;
                // nb->count = 0;
            }
            // printf("%d ", nb->number);
        }
    }

    printf("%d\n", count);

    return 0;
}

