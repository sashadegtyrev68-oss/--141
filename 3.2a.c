#include <stdio.h>

/**
 * @brief считывает значение с клавиатуры
 * @param prompt - сообщение для пользователя
 * @return введенное значение типа double
 */
double getValue(const char* prompt);

/**
 * @brief проверяет корректность количества членов
 * @return 1, если n неотрицательное, иначе 0
 */
int isCountValid(const int n);

/**
 * @brief точка входа в программу
 * @return 0, если программа выполнена корректно
 */
int main(void)
{
    int n = (int)getValue("Введите количество членов n: ");

    if (!isCountValid(n))
    {
        printf("Ошибка: n должно быть неотрицательным.\n");
        return 1;
    }

    double sum = 0.0;
    double term = -1.0;  /* a_1 = (-1)^1 * 1/1! = -1; член a_0 = 0 сумму не меняет */

    /* Рекуррентность: a_{k+1} = -a_k / k */
    for (int k = 1; k <= n; ++k)
    {
        sum += term;
        term = -term / k;
    }

    printf("\n--- Результат ---\n");
    printf("Сумма первых %d членов: %lf\n", n, sum);

    return 0;
}

/**
 * @brief проверка n
 */
int isCountValid(const int n)
{
    return n >= 0;
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
