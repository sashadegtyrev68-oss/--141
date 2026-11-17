#include <stdio.h>
#include <math.h>

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
    double e = 0.0;
    double sum = 0.0;
    double factorial = 1.0;
    double sign = 1.0;
    int k = 0;
    int count = 0;

    e = getValue("Введите точность e: ");

    if (e <= 0.0)
    {
        printf("Ошибка: e должно быть положительным числом.\n");
        return 1;
    }

    while (1)
    {
        double term = (sign / factorial) * k;

        // Первый член (k=0) всегда добавляем, дальше проверяем условие
        if (count > 0 && fabs(term) < e)
        {
            break;
        }

        sum += term;
        count++;

        // Рекуррентное выражение для факториала
        factorial *= (k + 1);
        sign *= -1.0;
        k++;
    }

    printf("\n--- Результат ---\n");
    printf("Сумма членов, |a_k| >= %lf: %lf\n", e, sum);
    printf("Вычислено членов: %d\n", count);

    return 0;
}

/**
 * @brief считывание значения с клавиатуры с проверкой ввода
 */
double getValue(const char* prompt)
{
    if (prompt == NULL)
    {
        printf("Ошибка: некорректное сообщение (NULL-указатель).\n");
        return 0.0;
    }

    double value = 0.0;
    printf("%s", prompt);

    while (scanf("%lf", &value) != 1)
    {
        printf("Некорректный ввод, ожидалось число.\n");
        int ch;
        while ((ch = getchar()) != '\n' && ch != EOF) {}
        printf("%s", prompt);
    }

    return value;
}
