#include <stdio.h>
#include <math.h>
#include <stdlib.h>

void input_array(double *arr, int size, const char *name) 
{
    printf("Введіть %d елементів масиву %s:\n", size, name);
    for (int i = 0; i < size; i += 1) 
    {
        printf("%s[%d] = ", name, i);
        scanf("%lf", &arr[i]);
    }
}

void calculate_sums(double *arr, int size, double *sum, double *sum_sin, double *sum_cos, double *sum_tan) 
{
    *sum = 0.0;
    *sum_sin = 0.0;
    *sum_cos = 0.0;
    *sum_tan = 0.0;
    
    for (int i = 0; i < size; i += 1) 
    {
        *sum += arr[i];
        *sum_sin += arr[i] * sin(arr[i]);
        *sum_cos += arr[i] * cos(arr[i]);
        *sum_tan += arr[i] * tan(arr[i]);
    }
}

double calculate_product_sin(double *arr, int size)
{
    double product = 1.0;
    for (int i = 0; i < size; i += 1) 
    {
        product *= arr[i] * sin(arr[i]);
    }
    return product;
}

double calculate_product_cos(double *arr, int size) 
{
    double product = 1.0;
    for (int i = 0; i < size; i += 1) 
    {
        product *= arr[i] * cos(arr[i]);
    }
    return product;
}

int main() 
{
    system("chcp 65001");
    int n, m;
    printf("Введіть кількість елементів масиву a (n): ");
    scanf("%d", &n);
    printf("Введіть кількість елементів масиву b (m): ");
    scanf("%d", &m);
    
    double *a = (double*)malloc(n * sizeof(double));
    double *b = (double*)malloc(m * sizeof(double));
    
    input_array(a, n, "a");
    input_array(b, m, "b");
    
    double s_a, sum_sin_a, sum_cos_a, sum_tan_a;
    calculate_sums(a, n, &s_a, &sum_sin_a, &sum_cos_a, &sum_tan_a);
    double A = s_a * sum_sin_a;
    double B = calculate_product_sin(a, n);
    double C = s_a * sum_cos_a;
    
    double s_b, sum_sin_b, sum_cos_b, sum_tan_b;
    calculate_sums(b, m, &s_b, &sum_sin_b, &sum_cos_b, &sum_tan_b);
    double D = s_b * sum_tan_b;
    double E = calculate_product_cos(b, m);
    double F = s_b * sum_sin_b;
    
    double delta = (A * sin(B) + C) / (D * cos(E) + F);
    
    printf("\nРезультати:\n");
    printf("A = %lf\n", A);
    printf("B = %lf\n", B);
    printf("C = %lf\n", C);
    printf("D = %lf\n", D);
    printf("E = %lf\n", E);
    printf("F = %lf\n", F);
    printf("\nФінальний результат: δ = %lf\n", delta);
    
    free(a);
    free(b);
    
    return 0;
}