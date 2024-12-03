#include <stdio.h>
#include <stdlib.h>

struct node {
    int coeff;
    int power;
    struct node *next;
};

struct node *head1 = NULL, *head2 = NULL, *head3 = NULL;

struct node *createPolynomial(struct node *head) {
    int n, i, c, p;
    struct node *newnode, *temp;
    printf("Enter number of terms: ");
    scanf("%d", &n);

    for(i=1; i<=n; i++) {
        newnode = (struct node *)malloc(sizeof(struct node));
        temp = head;

        printf("Enter the coefficient: "); scanf("%d", &c);
        printf("Enter the power: "); scanf("%d", &p);
        newnode -> coeff = c;
        newnode -> power = p;
        newnode -> next = NULL;

        if(head == NULL) {
            head = newnode;
        }
        else{
            while(temp -> next != NULL) {
                temp = temp -> next;
            }
            temp -> next = newnode;
        }
    }
    printf("==== done ====\n");
    return head;
}

void showPolynomial(struct node *head) {
    struct node *temp;
    temp = head;

    if(head == NULL) {
        printf("Polynomial has not inserted\n");
    }

    else{
        while(temp != NULL) {
            printf("%dx^%d ", temp -> coeff, temp -> power);
            temp = temp -> next;

            if(temp != NULL) {
                printf(" + ");
            }
        }
        printf(" = 0\n");
    }
}

void createAnswer(int c, int p) {
    struct node *newnode, *temp;

    newnode = (struct node *)malloc(sizeof(struct node));
    newnode -> coeff = c;
    newnode -> power = p;
    newnode -> next = NULL;

    if(head3 == NULL) {
        head3 = newnode;
    }
    else{
        temp = head3;
        while(temp -> next != NULL) {
            temp = temp -> next;
        }
        temp -> next = newnode;
    }
}

struct node *addPolynomial() {
    int c, p;
    struct node *temp1 = head1;
    struct node *temp2 = head2;

    while(temp1 != NULL && temp2 != NULL) {
        if(temp1 -> power > temp2 -> power) {
            c = temp1 -> coeff;
            p = temp1 -> power;
            temp1 = temp1 -> next;
        }
        else if(temp1 -> power < temp2 -> power) {
            c = temp2 -> coeff;
            p = temp2 -> power;
            temp2 = temp2 -> next;
        }
        else {
            c = (temp1 -> coeff) + (temp2 -> coeff);
            p = temp1 -> power;
            temp1 = temp1 -> next;
            temp2 = temp2 -> next;
        }
        createAnswer(c, p);
    }
    while(temp1 != NULL) {
        createAnswer(temp1 -> coeff, temp1 -> power);
        temp1 = temp1 -> next;
    }
    while(temp2 != NULL) {
        createAnswer(temp2 -> coeff, temp2 -> power);
        temp2 = temp2 -> next;
    }
}

void main() {
    printf("********************************************\n");
    printf("Enter values for First Polynomial Expression: \n");
    head1 = createPolynomial(head1);
    printf("____________________________________________\n");
    printf("Enter values for Second Polynomial Expression: \n");
    head2 = createPolynomial(head2);
    printf("____________________________________________\n");
    printf("Two Polynomials: \n");
    showPolynomial(head1);
    showPolynomial(head2);

    addPolynomial();

    printf("____________________________________________\n");
    printf("The addition of two polynomials: \n");
    showPolynomial(head3);
    printf("********************************************\n");
}