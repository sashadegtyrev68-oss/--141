#include <stdio.h>
#include <math.h>
#include <stdbool.h>

/**
 * @brief вычисляет время нагревания проволоки по закону Джоуля-Ленца
 * @param R - сопротивление проволоки, Ом
 * @param I - сила тока, А
 * @param Q_kJ - количество теплоты, кДж
 * @return время нагревания в секундах
 */
double heatingTime(const double R, const double I, const double Q_kJ);

/**
 * @brief запрашивает у пользователя значение double
 * @param prompt - текст приглашения
 * @return введенное значение
 */
double getInputValue(const char* prompt);

/**
 * @brief проверяет корректность входных данных
 * @param R - сопротивление проволоки, Ом
 * @param I - сила тока, А
 * @param Q_kJ - количество теплоты, кДж
 * @return true, если данные корректны, иначе false
 */
bool validateInput(const double R, const double I, const double Q_kJ);

/**
 * @brief точка входа в программу
 * @return 0, если программа выполнена корректно, иначе не 0
 */
int main()
{
    double R = 0.0, I = 0.0, Q_kJ = 0.0;

    R = getInputValue("Введите сопротивление проволоки R (Ом): ");
    I = getInputValue("Введите силу тока I (А): ");
    Q_kJ = getInputValue("Введите количество теплоты Q (кДж): ");

    if (!validateInput(R, I, Q_kJ))
    {
        printf("Ошибка: некорректные входные данные.\n");
        return 1;
    }

    // Вычисление и вывод результата
    double t_sec = heatingTime(R, I, Q_kJ);
    double t_min = t_sec / 60.0;

    printf("Время нагревания: %.3f сек. (%.3f мин.)\n", t_sec, t_min);

    return 0;
}

/**
 * @brief Вычисление времени по закону Джоуля-Ленца
 */
double heatingTime(const double R, const double I, const double Q_kJ)
{
    const double Q_J = Q_kJ * 1000.0;      
    return Q_J / (pow(I, 2) * R);           
}

/**
 * @brief Ввод значения
 */
double getInputValue(const char* prompt)
{
    double value = 0.0;
    printf("%s", prompt);
    scanf("%lf", &value);
    return value;
}

/**
 * @brief Проверка входных данных
 */
bool validateInput(const double R, const double I, const double Q_kJ)
{
    return (R > 0 && I != 0 && Q_kJ >= 0);
}
