#include <stdio.h>

/**
 * @brief считывает значение с клавиатуры
 * @param prompt - сообщение для пользователя
 * @return введенное значение типа double
 */
double getValue(const char* prompt);

/**
 * @brief проверяет, что все стороны положительны
 * @return 1, если все стороны > 0, иначе 0
 */
int isSidesPositive(const double a, const double b, const double c);

/**
 * @brief проверяет существование треугольника по неравенству треугольника
 * @return 1 если треугольник существует, 0 иначе
 */
int isTriangleInvalid(const double a, const double b, const double c);

/**
 * @brief определяет, является ли треугольник прямоугольным
 * @return длина гипотенузы, если треугольник прямоугольный, иначе 0.0
 */
double isRightTriangle(const double a, const double b, const double c);

/**
 * @brief точка входа в программу
 */
int main(void)
{
    double a = getValue("Введите сторону a: ");
    double b = getValue("Введите сторону b: ");
    double c = getValue("Введите сторону c: ");

    if (!isSidesPositive(a, b, c))
    {
        printf("Ошибка: все стороны должны быть положительными числами.\n");
        return 1;
    }

    if (isTriangleInvalid(a, b, c))
    {
        printf("Ошибка: треугольник с такими сторонами не существует.\n");
        return 1;
    }

    double hypotenuse = isRightTriangle(a, b, c);

    if (hypotenuse > 0.0)
    {
        printf("\n--- Результат ---\n");
        printf("Треугольник является прямоугольным.\n");
        printf("Гипотенуза равна: %lf\n", hypotenuse);
    }
    else
    {
        printf("\n--- Результат ---\n");
        printf("Треугольник НЕ является прямоугольным.\n");
    }

    return 0;
}

/**
 * @brief считывание значения с клавиатуры (без циклов)
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

int isSidesPositive(const double a, const double b, const double c)
{
    return a > 0.0 && b > 0.0 && c > 0.0;
}


int isTriangleInvalid(const double a, const double b, const double c)
{
    return a + b <= c || a + c <= b || b + c <= a;
}

/**
 * @brief определение прямоугольности треугольника по теореме Пифагора
 */
double isRightTriangle(const double a, const double b, const double c)
{
    double hyp = a;
    double leg1 = b;
    double leg2 = c;

    if (b >= a && b >= c)
    {
        hyp = b;
        leg1 = a;
        leg2 = c;
    }
    else if (c >= a && c >= b)
    {
        hyp = c;
        leg1 = a;
        leg2 = b;
    }

    if (leg1 * leg1 + leg2 * leg2 == hyp * hyp)
    {
        return hyp;
    }

    return 0.0;
}
