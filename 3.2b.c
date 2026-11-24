#include <stdio.h>
#include <math.h>

/**
 * @brief считывает значение с клавиатуры
 * @param prompt - сообщение для пользователя
 * @return введенное значение типа double
 */
double getValue(const char* prompt);

/**
 * @brief проверяет корректность точности
 * @return 1, если e положительное, иначе 0
 */
int isPrecisionValid(const double e);

/**
 * @brief точка входа в программу
 * @return 0, если программа выполнена корректно
 */
int main(void)
{
    double e = getValue("Введите точность e: ");

    if (!isPrecisionValid(e))
    {
        printf("Ошибка: e должно быть положительным числом.\n");
        return 1;
    }

    double sum = 0.0;
    double term = -1.0;  /* a_1 = (-1)^1 * 1/1! = -1; член a_0 = 0 сумму не меняет */
    int k = 1;
    int count = 0;


    while (fabs(term) >= e)
    {
        sum += term;
        count++;
        term = -term / k;
        k++;
    }

    printf("\n--- Результат ---\n");
    printf("Сумма членов, |a_k| >= %lf: %lf\n", e, sum);
    printf("Вычислено членов: %d\n", count);

    return 0;
}

/**
 * @brief проверка e
 */
int isPrecisionValid(const double e)
{
    return e > 0.0;
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
