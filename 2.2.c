#include <stdio.h>
#include <math.h>

/** ==================== Именованные константы ==================== */
#define PROMPT_X             "Введите значение x: "
#define MSG_INVALID_NUM      "Ошибка: ввод должен быть числом. Попробуйте снова.\n"
#define MSG_DIV_BY_ZERO      "Ошибка: при x < 4 деление на ноль невозможно.\n"
#define MSG_RESULT_HEADER    "\n--- Результат ---\n"
#define MSG_XA               "При x = %lf и a = %lf\n"
#define MSG_Y                "y = %lf\n"

/**
 * @brief вычисляет значение функции y по заданной формуле
 * @param x - значение аргумента
 * @param a - константа
 * @return значение функции y
 */
double computeY(const double x, const double a);

/**
 * @brief считывает значение с клавиатуры
 * @param prompt - сообщение для пользователя; допускается NULL
 *                 (тогда промпт не печатается)
 * @return введенное значение типа double
 */
double getValue(const char* prompt);

/**
 * @brief точка входа в программу
 * @return 0, если программа выполнена корректно
 */
int main(void)
{
    const double A = 2.1; 
    double x = 0.0;
    double y = 0.0;

    /* Ввод данных с проверкой */
    x = getValue(PROMPT_X);

    /* Проверка: при x < 4 нельзя делить на ноль */
    if (x < 4.0 && x == 0.0)
    {
        printf(MSG_DIV_BY_ZERO);
        return 1;
    }

    /* Вычисление y с ветвлением */
    y = computeY(x, A);

    /* Вывод результата */
    printf(MSG_RESULT_HEADER);
    printf(MSG_XA, x, A);
    printf(MSG_Y, y);

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
    }
    else
    {
        return a * x + pow(x, 3);
    }
}

/**
 * @brief считывание значения с клавиатуры
 *        - проверяет, что указатель prompt непустой;
 *        - проверяет корректность ввода через scanf
 */
double getValue(const char* prompt)
{
    double value = 0.0;
    int scanned = 0;
    int c;

    /* printf("%s", NULL) — UB, поэтому печатаем только если prompt != NULL. */
    if (prompt != NULL)
    {
        printf("%s", prompt);
    }

    do
    {
        scanned = scanf("%lf", &value);
        if (scanned != 1)
        {
            printf(MSG_INVALID_NUM);
            /* чистим буфер до конца строки, чтобы мусор не зациклил ввод */
            while ((c = getchar()) != '\n' && c != EOF)
            {
                /* пустое тело: читаем и выбрасываем */
            }
        }
    } while (scanned != 1);

    return value;
}
