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
 * @return длина гипотенузы, если треугольник прямоугольный, иначе 0.0
 */
double isRightTriangle(const double a, const double b, const double c);

/**
 * @brief точка входа в программу
 * @return 0, если программа выполнена корректно
 */
int main(void)
{
    double a = 0.0, b = 0.0, c = 0.0;

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

    // Проверка на прямоугольность: функция возвращает гипотенузу напрямую
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
 * @brief считывание значения с клавиатуры с проверкой ввода
 */
double getValue(const char* prompt)
{
    // Проверка, что пришёл непустой указатель
    if (prompt == NULL) 
    {
        printf("Ошибка: некорректное сообщение (NULL-указатель).\n");
        return 0.0;
    }

    double value = 0.0;
    printf("%s", prompt);

    // Проверка ввода: повторяем, пока не будет введено корректное число
    while (scanf("%lf", &value) != 1) 
    {
        printf("Некорректный ввод, ожидалось число.\n");
        
        // Очистка буфера ввода
        int ch;
        while ((ch = getchar()) != '\n' && ch != EOF) 
        {
            /* пусто */
        }
        
        printf("%s", prompt);
    }

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
double isRightTriangle(const double a, const double b, const double c)
{
    /* Находим максимальную сторону (она будет гипотенузой) */
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

    /* Прямое сравнение по теореме Пифагора */
    if (leg1 * leg1 + leg2 * leg2 == hyp * hyp) 
    {
        return hyp;
    }

    return 0.0;
}
