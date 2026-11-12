#include <stdio.h>
#include <math.h>

/**
 * @brief вычисляет значение функции y по заданной формуле
 * @param x - значение аргумента
 * @param a - константа
 * @return значение функции y
 */
double computeY(const double x, const double a);

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
    const double A = 2.1;  // Константа из задания
    double x = 0.0;
    double y = 0.0;

    // Ввод данных пользователем с проверкой
    x = getValue("Введите значение x: ");

    // Проверка: при x < 4 нельзя делить на ноль
    if (x < 4.0 && x == 0.0) 
    {
        printf("Ошибка: при x < 4 деление на ноль невозможно.\n");
        return 1;
    }

    // Вычисление y с ветвлением
    y = computeY(x, A);

    // Вывод результата
    printf("\n--- Результат ---\n");
    printf("При x = %lf и a = %lf\n", x, A);
    printf("y = %lf\n", y);

    return 0;
}

/**
 * @brief вычисление y по формуле с ветвлением
 *        y = a/x + x², если x < 4
 *        y = ax + x³, если x >= 4
 */
double computeY(const double x, const double a)
{
    if (x < 4.0) 
    {
        return a / x + pow(x, 2);
    } else 
    {
        return a * x + pow(x, 3);
    }
}

/**
 * @brief считывание значения с клавиатуры с проверкой корректности ввода
 */
double getValue(const char* prompt)
{
    double value = 0.0;
    printf("%s", prompt);
    scanf("%lf", &value);
    return value;
}
