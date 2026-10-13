#include <stdio.h>
#include <math.h>

/**
 * @brief вычисляет время нагревания проволоки по закону Джоуля-Ленца
 * @param R - сопротивление проволоки, Ом
 * @param I - сила тока, А
 * @param Q_kJ - количество теплоты, кДж
 * @return время нагревания в секундах
 */
double heatingTime(const double R, const double I, const double Q_kJ);

/**
 * @brief точка входа в программу
 * @return 0, если программа выполнена корректно, иначе не 0
 */
int main()
{
    double R, I, Q_kJ;

    // Ввод данных пользователем
    printf("Введите сопротивление проволоки R (Ом): ");
    scanf("%lf", &R);

    printf("Введите силу тока I (А): ");
    scanf("%lf", &I);

    printf("Введите количество теплоты Q (кДж): ");
    scanf("%lf", &Q_kJ);

    // Проверка корректности входных данных (исключаем деление на ноль и отрицательные значения)
    if (R <= 0 || I == 0 || Q_kJ < 0) 
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
 * @brief реализация вычисления времени по закону Джоуля-Ленца
 */
double heatingTime(const double R, const double I, const double Q_kJ)
{
    const double Q_J = Q_kJ * 1000.0;      
    return Q_J / (pow(I, 2) * R);           
}
