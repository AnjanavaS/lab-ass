#include <stdio.h>

typedef struct {
    float real;
    float imag;
} Complex;

Complex add(Complex a, Complex b) {
    Complex result;
    result.real = a.real + b.real;
    result.imag = a.imag + b.imag;
    return result;
}

Complex subtract(Complex a, Complex b) {
    Complex result;
    result.real = a.real - b.real;
    result.imag = a.imag - b.imag;
    return result;
}

Complex multiply(Complex a, Complex b) {
    Complex result;
    result.real = a.real * b.real - a.imag * b.imag;
    result.imag = a.real * b.imag + a.imag * b.real;
    return result;
}

Complex divide(Complex a, Complex b) {
    Complex result;
    float denominator = b.real * b.real + b.imag * b.imag;
    if (denominator == 0) {
        printf("Error: Division by zero complex number.\n");
        result.real = 0;
        result.imag = 0;
        return result;
    }
    result.real = (a.real * b.real + a.imag * b.imag) / denominator;
    result.imag = (a.imag * b.real - a.real * b.imag) / denominator;
    return result;
}

void printComplex(Complex c) {
    if (c.imag >= 0)
        printf("%.2f + %.2fi\n", c.real, c.imag);
    else
        printf("%.2f - %.2fi\n", c.real, -c.imag);
}

int main() {
    Complex num1, num2, result;
    int choice;

    do {
        printf("\nMenu:\n");
        printf("1. Add\n");
        printf("2. Subtract\n");
        printf("3. Multiply\n");
        printf("4. Divide\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        if (choice >= 1 && choice <= 4) {
            printf("Enter real and imaginary parts of first complex number: ");
            scanf("%f %f", &num1.real, &num1.imag);
            printf("Enter real and imaginary parts of second complex number: ");
            scanf("%f %f", &num2.real, &num2.imag);
        }

        switch (choice) {
            case 1:
                result = add(num1, num2);
                printf("Sum = ");
                printComplex(result);
                break;
            case 2:
                result = subtract(num1, num2);
                printf("Difference = ");
                printComplex(result);
                break;
            case 3:
                result = multiply(num1, num2);
                printf("Product = ");
                printComplex(result);
                break;
            case 4:
                result = divide(num1, num2);
                printf("Quotient = ");
                printComplex(result);
                break;
            case 5:
                printf("Exiting program.\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 5);

    return 0;
}
