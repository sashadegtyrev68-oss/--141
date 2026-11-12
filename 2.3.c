#include <stdio.h>

/**
 * @brief считывает значение с клавиатуры
 * @param prompt - сообщение для пользователя
 * @return введенное значение типа double
 */
double getValue(const char* prompt);

/**
 * @brief проверяет существование треугольника по неравенству треугольника
 * @param a - длина первой стороны
 * @param b - длина второй стороны
 * @param c - длина третьей стороны
 * @return 1 если треугольник существует, 0 иначе
 */
int isTriangleValid(const double a, const double b, const double c);

/**
 * @brief определяет, является ли треугольник прямоугольным
 * @param a - длина первой стороны
 * @param b - длина второй стороны
 * @param c - длина третьей стороны
 * @param hypotenuse - указатель на переменную для хранения длины гипотенузы
 * @return 1 если треугольник прямоугольный, 0 иначе
 */
int isRightTriangle(const double a, const double b, const double c, double* hypotenuse);

/**
 * @brief точка входа в программу
 * @return 0, если программа выполнена корректно
 */
int main()
{
    double a = 0.0, b = 0.0, c = 0.0;
    double hypotenuse = 0.0;

    // Ввод данных пользователем
    a = getValue("Введите сторону a: ");
    b = getValue("Введите сторону b: ");
    c = getValue("Введите сторону c: ");

    // Проверка, что все стороны положительные
    if (a <= 0.0 || b <= 0.0 || c <= 0.0) 
    {
        printf("Ошибка: все стороны должны быть положительными числами.\n");
        return 1;
    }

    // Проверка существования треугольника
    if (!isTriangleValid(a, b, c)) 
    {
        printf("Ошибка: треугольник с такими сторонами не существует.\n");
        return 1;
    }

    // Проверка на прямоугольность
    if (isRightTriangle(a, b, c, &hypotenuse)) 
    {
        printf("\n--- Результат ---\n");
        printf("Треугольник является прямоугольным.\n");
        printf("Гипотенуза равна: %lf\n", hypotenuse);
    } else 
    {
        printf("\n--- Результат ---\n");
        printf("Треугольник НЕ является прямоугольным.\n");
    }

    return 0;
}

/**
 * @brief считывание значения с клавиатуры
 */
double getValue(const char* prompt)
{
    double value = 0.0;
    printf("%s", prompt);
    scanf("%lf", &value);
    return value;
}

/**
 * @brief проверка существования треугольника по неравенству треугольника
 */
int isTriangleValid(const double a, const double b, const double c)
{
    if (a + b <= c || a + c <= b || b + c <= a) 
    {
        return 0;
    }
    return 1;
}

/**
 * @brief определение прямоугольности треугольника по теореме Пифагора
 */
int isRightTriangle(const double a, const double b, const double c, double* hypotenuse)
{
    /* Находим максимальную сторону (она будет гипотенузой) */
    double maxSide = a;
    if (b > maxSide) maxSide = b;
    if (c > maxSide) maxSide = c;

    /* Вычисляем сумму квадратов двух других сторон */
    double sumOfSquares = 0.0;
    if (a == maxSide) 
    {
        sumOfSquares = b * b + c * c;
    } else if (b == maxSide) 
    {
        sumOfSquares = a * a + c * c;
    } else 
    {
        sumOfSquares = a * a + b * b;
    }

    /* Прямое сравнение по теореме Пифагора */
    if (sumOfSquares == maxSide * maxSide) 
    {
        *hypotenuse = maxSide;
        return 1;
    }

    return 0;
}
