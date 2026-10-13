#include <stdio.h>
#include <math.h>

/**
 * @brief вычисляет площадь прямоугольника по заданным сторонам
 * @param a - длина первой стороны
 * @param b - длина второй стороны
 * @return площадь прямоугольника
 */
double rectangleArea(const double a, const double b);

/**
 * @brief вычисляет площадь треугольника по трем сторонам (формула Герона)
 * @param a - длина первой стороны
 * @param b - длина второй стороны
 * @param c - длина третьей стороны
 * @return площадь треугольника
 */
double triangleArea(const double a, const double b, const double c);

/**
 * @brief точка входа в программу
 * @return 0, если программа выполнена корректно, иначе не 0
 */
int main()
{
    double a_rect, b_rect;
    double a_tri, b_tri, c_tri;

    // Ввод данных пользователем (согласно заданию)
    printf("Введите стороны прямоугольника (a и b): ");
    scanf("%lf %lf", &a_rect, &b_rect);

    printf("Введите стороны треугольника (a, b и c): ");
    scanf("%lf %lf %lf", &a_tri, &b_tri, &c_tri);

    // Проверка существования треугольника (неравенство треугольника)
    if (a_tri + b_tri <= c_tri || a_tri + c_tri <= b_tri || b_tri + c_tri <= a_tri) {
        printf("Ошибка: Треугольник с такими сторонами не существует.\n");
        return 1;
    }

    // Вызов функций и вывод результатов
    printf("Площадь прямоугольника = %lf\n", rectangleArea(a_rect, b_rect));
    printf("Площадь треугольника   = %lf\n", triangleArea(a_tri, b_tri, c_tri));

    return 0;
}

/**
 * @brief реализация вычисления площади прямоугольника
 */
double rectangleArea(const double a, const double b)
{
    return a * b;
}

/**
 * @brief реализация вычисления площади треугольника по формуле Герона
 */
double triangleArea(const double a, const double b, const double c)
{
    double p = (a + b + c) / 2.0; // Вычисляем полупериметр
    return sqrt(p * (p - a) * (p - b) * (p - c));
}
