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
 * @brief проверяет существование треугольника по неравенству треугольника
 * @param a - длина первой стороны
 * @param b - длина второй стороны
 * @param c - длина третьей стороны
 * @return 1 если треугольник существует, 0 иначе
 */
int isTriangleValid(const double a, const double b, const double c);

/**
 * @brief считывает значение с клавиатуры
 * @return введенное значение типа double (0.0 при ошибке ввода)
 */
double getValue(void);

/**
 * @brief точка входа в программу
 * @return 0, если программа выполнена корректно, иначе не 0
 */
int main()
{
    double a_rect = 0.0, b_rect = 0.0;
    double a_tri = 0.0, b_tri = 0.0, c_tri = 0.0;

    // Ввод данных пользователем
    printf("Введите стороны прямоугольника (a и b): ");
    a_rect = getValue();
    b_rect = getValue();

    printf("Введите стороны треугольника (a, b и c): ");
    a_tri = getValue();
    b_tri = getValue();
    c_tri = getValue();

    // Проверка существования треугольника
    if (!isTriangleValid(a_tri, b_tri, c_tri)) {
        printf("Ошибка: Треугольник с такими сторонами не существует.\n");
        return 1;
    }

    // Вызов функций и вывод результатов
    printf("Площадь прямоугольника = %f\n", rectangleArea(a_rect, b_rect));
    printf("Площадь треугольника   = %f\n", triangleArea(a_tri, b_tri, c_tri));

    return 0;
}

/**
 * @brief вычисление площади прямоугольника
 */
double rectangleArea(const double a, const double b)
{
    return a * b;
}

/**
 * @brief вычисление площади треугольника по формуле Герона
 */
double triangleArea(const double a, const double b, const double c)
{
    double p = (a + b + c) / 2.0; // Вычисляем полупериметр
    return sqrt(p * (p - a) * (p - b) * (p - c));
}

/**
 * @brief проверка существования треугольника
 */
int isTriangleValid(const double a, const double b, const double c)
{
    // Проверка на положительные значения
    if (a <= 0.0 || b <= 0.0 || c <= 0.0) {
        return 0; 
    }
    // Классическое неравенство треугольника
    if (a + b <= c || a + c <= b || b + c <= a) {
        return 0; 
    }
    return 1; 
}

/**
 * @brief считывание значения с клавиатуры
 */
double getValue(void)
{
    double value = 0.0; 
    scanf("%lf", &value);
    return value;
}
