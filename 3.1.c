#include <stdio.h>
#include <math.h>

#define EPS 1e-6

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
 * @brief точка входа в программу
 * @return 0, если программа выполнена корректно
 */
int main(void)
{
    // Ввод параметров табуляции
    double x_start = getValue("Введите начало интервала (x_нач): ");
    double x_end   = getValue("Введите конец интервала (x_кон): ");
    double step    = getValue("Введите шаг табуляции (dx): ");

    // Проверка корректности ввода
    if (step <= 0.0)
    {
        printf("Ошибка: шаг должен быть положительным числом.\n");
        return 1;
    }
    if (x_start > x_end)
    {
        printf("Ошибка: начало интервала не может быть больше конца.\n");
        return 1;
    }

    // Вывод заголовка таблицы
    printf("\n      x            y\n");
    printf("--------------------\n");

    // Цикл табуляции
    for (double x = x_start; x <= x_end; x += step)
    {
        double denominator = 3.0 + sin(3.6 * x);

        // Проверка знаменателя на ноль (по заданию)
        if (fabs(denominator) < EPS)
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
 * @brief считывание значения с клавиатуры с проверкой ввода
 */
double getValue(const char* prompt)
{
    // Проверка, что пришёл непустой указатель
    if (prompt == NULL)
    {
        printf("Ошибка: некорректное сообщение (NULL-указатель).\n");
        return 0.0;
    }

    double value = 0.0;
    printf("%s", prompt);

    // Проверка ввода: повторяем, пока не будет введено корректное число
    while (scanf("%lf", &value) != 1)
    {
        printf("Некорректный ввод, ожидалось число.\n");

        int ch;
        while ((ch = getchar()) != '\n' && ch != EOF)
        {
            /* очищаем буфер до конца строки */
        }

        printf("%s", prompt);
    }

    return value;
}
