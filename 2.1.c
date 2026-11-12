#include <stdio.h>
#include <math.h>

/**Перечислимый тип для выбора формулы*/
typedef enum 
{
    CHOICE_ARITHMETIC = 1,
    CHOICE_GEOMETRIC = 2,
    CHOICE_BOTH = 3
} CalculationChoice;

/**
 * @brief вычисляет среднее арифметическое кубов двух чисел
 * @param a - первое число
 * @param b - второе число
 * @return среднее арифметическое кубов
 */
double getArithmeticMeanOfCubes(const double a, const double b);

/**
 * @brief вычисляет среднее геометрическое модулей двух чисел
 * @param a - первое число
 * @param b - второе число
 * @return среднее геометрическое модулей
 */
double getGeometricMeanOfAbs(const double a, const double b);

/**
 * @brief считывает значение с клавиатуры
 * @return введенное значение типа double
 */
double getValue(void);

/**
 * @brief точка входа в программу
 * @return 0, если программа выполнена корректно
 */
int main()
{
    double a = 0.0, b = 0.0;
    int choice = 0;

    // Ввод данных пользователем
    printf("Введите первое число (a): ");
    a = getValue();
    printf("Введите второе число (b): ");
    b = getValue();

    // Выбор формулы с использованием перечислимого типа
    printf("\nВыберите, что вычислить:\n");
    printf("1. Среднее арифметическое кубов\n");
    printf("2. Среднее геометрическое модулей\n");
    printf("3. Оба значения\n");
    printf("Ваш выбор (1-3): ");
    scanf("%d", &choice);

    // Проверка корректности выбора
    if (choice < CHOICE_ARITHMETIC || choice > CHOICE_BOTH)
    {
        printf("Ошибка: неверный выбор. Вычисляем оба значения.\n");
        choice = CHOICE_BOTH;
    }

    // Вызов функций и вывод результатов
    printf("\n--- Результаты ---\n");
    if (choice == CHOICE_ARITHMETIC || choice == CHOICE_BOTH) 
    {
        printf("Среднее арифметическое кубов = %lf\n", getArithmeticMeanOfCubes(a, b));
    }
    if (choice == CHOICE_GEOMETRIC || choice == CHOICE_BOTH) 
    {
        printf("Среднее геометрическое модулей = %lf\n", getGeometricMeanOfAbs(a, b));
    }

    return 0;
}

/**
 * @brief вычисление среднего арифметического кубов: (a^3 + b^3) / 2
 */
double getArithmeticMeanOfCubes(const double a, const double b)
{
    return (pow(a, 3) + pow(b, 3)) / 2.0;
}

/**
 * @brief вычисление среднего геометрического модулей: sqrt(|a| * |b|)
 */
double getGeometricMeanOfAbs(const double a, const double b)
{
    return sqrt(fabs(a) * fabs(b));
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
