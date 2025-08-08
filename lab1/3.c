#include <stdio.h>

struct Employee {
    int emp_id;
    char name[50];
    char designation[50];
    float basic_salary;
    float hra_percent;
    float da_percent;
};

float calculateGrossSalary(struct Employee emp) {
    return emp.basic_salary + (emp.hra_percent / 100.0f) * emp.basic_salary + (emp.da_percent / 100.0f) * emp.basic_salary;
}

int main() {
    int n;
    printf("Enter the number of employees: ");
    scanf("%d", &n);

    struct Employee employees[n];

    for (int i = 0; i < n; i++) {
        printf("\nEnter details for employee %d\n", i + 1);
        printf("Emp-id: ");
        scanf("%d", &employees[i].emp_id);
        printf("Name: ");
        scanf(" %[^\n]", employees[i].name);
        printf("Designation: ");
        scanf(" %[^\n]", employees[i].designation);
        printf("Basic Salary: ");
        scanf("%f", &employees[i].basic_salary);
        printf("HRA%%: ");
        scanf("%f", &employees[i].hra_percent);
        printf("DA%%: ");
        scanf("%f", &employees[i].da_percent);
    }

    printf("\nEmployee Information with Gross Salary:\n");
    printf("Emp-id\tName\tDesignation\tBasic Salary\tHRA%%\tDA%%\tGross Salary\n");
    for (int i = 0; i < n; i++) {
        float gross_salary = calculateGrossSalary(employees[i]);
        printf("%d\t%s\t%s\t%.2f\t\t%.2f\t%.2f\t%.2f\n",
               employees[i].emp_id,
               employees[i].name,
               employees[i].designation,
               employees[i].basic_salary,
               employees[i].hra_percent,
               employees[i].da_percent,
               gross_salary);
    }

    return 0;
}
