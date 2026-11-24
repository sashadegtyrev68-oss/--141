#include <stdio.h>
#include <math.h>
#include <float.h> 

/**
 * @brief вычисляет значение функции y = x - 1/(3 + sin(3.6*x))
 * @param x - значение аргумента
 * @return значение функции y
 */
double computeY(const double x);

/**
 * @brief считывает значение с клавиатуры
 * @param prompt - сообщение для пользователя
 * @return введенное значение типа double
 */
double getValue(const char* prompt);

/**
 * @brief проверяет корректность шага табуляции
 * @return 1, если шаг положительный, иначе 0
 */
int isStepValid(const double step);

/**
 * @brief проверяет корректность границ интервала
 * @return 1, если начало не больше конца, иначе 0
 */
int isIntervalValid(const double x_start, const double x_end);

/**
 * @brief точка входа в программу
 * @return 0, если программа выполнена корректно
 */
int main(void)
{
    double x_start = getValue("Введите начало интервала (x_нач): ");
    double x_end   = getValue("Введите конец интервала (x_кон): ");
    double step    = getValue("Введите шаг табуляции (dx): ");

    if (!isStepValid(step))
    {
        printf("Ошибка: шаг должен быть положительным числом.\n");
        return 1;
    }

    if (!isIntervalValid(x_start, x_end))
    {
        printf("Ошибка: начало интервала не может быть больше конца.\n");
        return 1;
    }

    printf("\n      x            y\n");
    printf("--------------------\n");

    /* Число шагов считаем один раз, а x вычисляем умножением i*step */
    int steps_count = (int)round((x_end - x_start) / step);

    for (int i = 0; i <= steps_count; ++i)
    {
        double x = x_start + i * step;
        double denominator = 3.0 + sin(3.6 * x);

        /* Встроенная константа */
        if (fabs(denominator) < DBL_EPSILON)
        {
            printf("%10.4f   нет решения\n", x);
        }
        else
        {
            double y = computeY(x);
            printf("%10.4f   %10.4f\n", x, y);
        }
    }

    return 0;
}

/**
 * @brief вычисление y = x - 1/(3 + sin(3.6*x))
 */
double computeY(const double x)
{
    return x - 1.0 / (3.0 + sin(3.6 * x));
}

/**
 * @brief проверка шага
 */
int isStepValid(const double step)
{
    return step > 0.0;
}

/**
 * @brief проверка границ интервала
 */
int isIntervalValid(const double x_start, const double x_end)
{
    return x_start <= x_end;
}

/**
 * @brief считывание значения с клавиатуры 
 */
double getValue(const char* prompt)
{
    double value = 0.0;
    int scanned = 0;

    if (prompt == NULL)
    {
        printf("Ошибка: некорректное сообщение (NULL-указатель).\n");
        return 0.0;
    }

    printf("%s", prompt);

    
    scanned = scanf("%lf", &value);
    if (scanned != 1)
    {
        printf("Некорректный ввод, ожидалось число.\n");
    }

    return value;
}
