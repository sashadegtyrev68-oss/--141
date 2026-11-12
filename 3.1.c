#include <stdio.h>
#include <math.h>

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
int main()
{
    double x_start = 0.0, x_end = 0.0, step = 0.0;
    double x = 0.0, y = 0.0;
    double denominator = 0.0;

    // Ввод параметров табуляции
    x_start = getValue("Введите начало интервала (x_нач): ");
    x_end   = getValue("Введите конец интервала (x_кон): ");
    step    = getValue("Введите шаг табуляции (dx): ");

    // Проверка корректности ввода
    if (step <= 0.0) {
        printf("Ошибка: шаг должен быть положительным числом.\n");
        return 1;
    }
    if (x_start > x_end) {
        printf("Ошибка: начало интервала не может быть больше конца.\n");
        return 1;
    }

    // Вывод заголовка таблицы
    printf("\n      x            y\n");
    printf("--------------------\n");

    // Цикл табуляции
    x = x_start;
    while (x <= x_end) {
        denominator = 3.0 + sin(3.6 * x);

        // Проверка знаменателя на ноль (по заданию)
        if (denominator == 0.0) {
            printf("%10.4f   нет решения\n", x);
        } else {
            y = computeY(x);
            printf("%10.4f   %10.4f\n", x, y);
        }

        x = x + step;
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
 * @brief считывание значения с клавиатуры
 */
double getValue(const char* prompt)
{
    double value = 0.0;
    printf("%s", prompt);
    scanf("%lf", &value);
    return value;
}
