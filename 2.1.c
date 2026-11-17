#include <stdio.h>
#include <math.h>

/** ==================== Именованные константы ==================== */
#define PROMPT_FIRST_NUM     "Введите первое число (a): "
#define PROMPT_SECOND_NUM    "Введите второе число (b): "
#define MENU_TITLE           "\nВыберите, что вычислить:\n"
#define MENU_TEXT_ARITH      "Среднее арифметическое кубов"
#define MENU_TEXT_GEOM       "Среднее геометрическое модулей"
#define MENU_TEXT_BOTH       "Оба значения"
#define MENU_PROMPT          "Ваш выбор: "
#define MSG_INVALID_NUM      "Ошибка: ввод должен быть числом. Попробуйте снова.\n"
#define MSG_INVALID_CHOICE   "Ошибка: нужно выбрать 1, 2 или 3. Попробуйте снова.\n"
#define MSG_RESULT_HEADER    "\n--- Результаты ---\n"
#define MSG_ARITH_RESULT     "Среднее арифметическое кубов = %lf\n"
#define MSG_GEOM_RESULT      "Среднее геометрическое модулей = %lf\n"

/** Перечислимый тип для выбора формулы (номера пунктов берутся отсюда) */
typedef enum
{
    CHOICE_ARITHMETIC = 1,
    CHOICE_GEOMETRIC  = 2,
    CHOICE_BOTH       = 3
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
 * @brief считывает число с клавиатуры с проверкой ввода
 * @return введенное значение типа double
 */
double getValue(void);

/**
 * @brief считывает выбор пользователя с проверкой ввода
 * @return корректный выбор (1, 2 или 3)
 */
int getChoice(void);

/**
 * @brief очищает буфер ввода до конца строки
 */
void clearInputBuffer(void);

/**
 * @brief точка входа в программу
 * @return 0, если программа выполнена корректно
 */
int main(void)
{
    double a = 0.0, b = 0.0;
    int choice = 0;

    /* Ввод чисел с проверкой */
    printf(PROMPT_FIRST_NUM);
    a = getValue();
    printf(PROMPT_SECOND_NUM);
    b = getValue();

    /* Вывод меню: номер из enum, текст из константы */
    printf(MENU_TITLE);
    printf("%d. %s\n", CHOICE_ARITHMETIC, MENU_TEXT_ARITH);
    printf("%d. %s\n", CHOICE_GEOMETRIC,  MENU_TEXT_GEOM);
    printf("%d. %s\n", CHOICE_BOTH,       MENU_TEXT_BOTH);
    printf(MENU_PROMPT);

    /* Выбор формулы с проверкой */
    choice = getChoice();

    /* Вызов функций и вывод результатов */
    printf(MSG_RESULT_HEADER);
    if (choice == CHOICE_ARITHMETIC || choice == CHOICE_BOTH)
    {
        printf(MSG_ARITH_RESULT, getArithmeticMeanOfCubes(a, b));
    }
    if (choice == CHOICE_GEOMETRIC || choice == CHOICE_BOTH)
    {
        printf(MSG_GEOM_RESULT, getGeometricMeanOfAbs(a, b));
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
 * @brief считывание числа с проверкой
 */
double getValue(void)
{
    double value = 0.0;
    int scanned = 0;

    do
    {
        scanned = scanf("%lf", &value);
        if (scanned != 1)
        {
            printf(MSG_INVALID_NUM);
            clearInputBuffer();
        }
    } while (scanned != 1);

    return value;
}

/**
 * @brief считывание выбора с проверкой
 */
int getChoice(void)
{
    int choice = 0;
    int scanned = 0;

    do
    {
        scanned = scanf("%d", &choice);
        if (scanned != 1 || choice < CHOICE_ARITHMETIC || choice > CHOICE_BOTH)
        {
            printf(MSG_INVALID_CHOICE);
            clearInputBuffer();
        }
    } while (scanned != 1 || choice < CHOICE_ARITHMETIC || choice > CHOICE_BOTH);

    return choice;
}

/**
 * @brief выбрасывает из буфера ввода всё до конца строки
 */
void clearInputBuffer(void)
{
    int c;
    while ((c = getchar()) != '\n' && c != EOF)
    {
  
    }
}
