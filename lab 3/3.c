#include <stdio.h>
#define MAX 100

void readPolynomial(int poly[MAX], int *degree) {
    int terms, coeff, exp;
    printf("Enter number of terms in the polynomial: ");
    scanf("%d", &terms);

    *degree = 0;

  
    for (int i = 0; i < MAX; i++) {
        poly[i] = 0;
    }

    printf("Enter each term in format <coefficient exponent>:\n");
    for (int i = 0; i < terms; i++) {
        scanf("%d %d", &coeff, &exp);
        poly[exp] = coeff;

        if (exp > *degree) {
            *degree = exp;
        }
    }
}

void printPolynomial(int poly[MAX], int degree) {
    int printed = 0;
    for (int i = degree; i >= 0; i--) {
        if (poly[i] != 0) {
            if (printed && poly[i] > 0)
                printf(" + ");
            else if (poly[i] < 0)
                printf(" - ");
            else if (printed)
                printf(" ");

            if (i == 0 || abs(poly[i]) != 1)
                printf("%d", abs(poly[i]));
            else if (poly[i] == -1)
                printf("-");

            if (i > 0) {
                printf("x");
                if (i > 1)
                    printf("^%d", i);
            }

            printed = 1;
        }
    }

    if (!printed)
        printf("0");
    printf("\n");
}

void addPolynomials(int poly1[MAX], int poly2[MAX], int result[MAX], int degree1, int degree2, int *resDeg) {
    *resDeg = (degree1 > degree2) ? degree1 : degree2;

    for (int i = 0; i <= *resDeg; i++) {
        result[i] = poly1[i] + poly2[i];
    }
}

int main() {
    int poly1[MAX], poly2[MAX], sum[MAX];
    int deg1, deg2, sumDeg;

    printf("Enter first polynomial:\n");
    readPolynomial(poly1, &deg1);

    printf("Enter second polynomial:\n");
    readPolynomial(poly2, &deg2);

    printf("\nFirst Polynomial: ");
    printPolynomial(poly1, deg1);

    printf("Second Polynomial: ");
    printPolynomial(poly2, deg2);

    addPolynomials(poly1, poly2, sum, deg1, deg2, &sumDeg);

    printf("Sum Polynomial: ");
    printPolynomial(sum, sumDeg);

    return 0;
}
