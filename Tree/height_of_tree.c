#include <stdio.h>

struct node{
    int data;
    struct node *left;
    struct node *right;
};

struct node *root;

int findHeight(struct node *temp) {
    
    //  base condition
    if(temp == NULL) {
        return 0;
    }

    int left = findHeight(temp -> left);
    int right = findHeight(temp -> right);

    return (left > right ? left : right) + 1;
}

void main() {

    //  Assume that tree is already been created

    int height = findHeight(root);

}