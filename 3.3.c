#include <stdio.h>
#include <math.h>

/* Параметры табуляции и точность (по заданию — в константах) */
#define A   0.1
#define B   1.0
#define H   0.1
#define EPS 3e-4   /* требуемая точность: |y - S| < EPS */

/**
 * @brief вычисляет точное значение функции y = (x^2/4 + x/2 + 1) * e^(x/2)
 * @param x - значение аргумента
 * @return значение функции y
 */
double computeY(const double x)
{
    return (x * x / 4.0 + x / 2.0 + 1.0) * exp(x / 2.0);
}

/**
 * @brief вычисляет сумму ряда до достижения заданной точности
 *        a_n = a_{n-1} * (n^2+1)/((n-1)^2+1) * (x/(2n)),  a_0 = 1
 * @param x - значение аргумента
 * @param exact - точное значение функции (для контроля точности)
 * @param eps - требуемая точность
 * @return сумма ряда
 */
double computeSeries(const double x, const double exact, const double eps)
{
    double sum = 1.0;   /* a_0 = 1 */
    double term = 1.0;  /* текущий член ряда */
    int n = 1;

    /* Условие по заданию: разница точного и приближенного значений */
    while (fabs(exact - sum) >= eps)
    {
        term = term * ((n * n + 1.0) / ((n - 1.0) * (n - 1.0) + 1.0))
                    * (x / (2.0 * n));
        sum += term;
        n++;
    }

    return sum;
}

/**
 * @brief точка входа в программу
 * @return 0, если программа выполнена корректно
 */
int main(void)
{
    printf("Табулирование функции и суммы её разложения в ряд\n");
    printf("Интервал: [%.2f, %.2f], шаг: %.2f, точность: %e\n\n", A, B, H, EPS);
    printf("      x            y(x)          S(x)        |y - S|\n");
    printf("-----------------------------------------------------------\n");

    /* Целочисленный счётчик вместо x += H: ошибка не накапливается,
       конечная точка гарантированно попадает в таблицу */
    int steps = (int)round((B - A) / H);

    for (int i = 0; i <= steps; ++i)
    {
        double x = A + i * H;
        double y = computeY(x);
        double s = computeSeries(x, y, EPS);
        printf("%10.4f   %12.6f   %12.6f   %10.2e\n", x, y, s, fabs(y - s));
    }

    return 0;
}
