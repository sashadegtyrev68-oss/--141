#include <stdio.h>

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
    int n = 0;
    double sum = 0.0;
    double factorial = 1.0; // 0! = 1
    double sign = 1.0;      // (-1)^0 = 1

    n = (int)getValue("Введите количество членов n: ");

    if (n < 0)
    {
        printf("Ошибка: n должно быть неотрицательным.\n");
        return 1;
    }

    for (int k = 0; k <= n; k++)
    {
        double term = (sign / factorial) * k;
        sum += term;

        // Рекуррентное выражение: (k+1)! = k! * (k+1)
        factorial *= (k + 1);
        sign *= -1.0; // (-1)^(k+1) = (-1)^k * (-1)
    }

    printf("\n--- Результат ---\n");
    printf("Сумма первых %d членов: %lf\n", n, sum);

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
