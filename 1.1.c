#include <stdio.h>
#include <math.h>

/*
* @brief рассчитывает функцию A по заданной формуле
* @param x - значение параметра x
* @param y - значение параметра y
* @param z - значение параметра z
* @return рассчитанное значение
*/
double GetA(const double x, const double y, const double z);

/*
* @brief рассчитывает функцию B по заданной формуле
* @param x - значение параметра x
* @param y - значение параметра y
* @param z - значение параметра z
* @return рассчитанное значение
*/
double GetB(const double x, const double y, const double z);

/*
* @brief точка входа в программу
* @return возвращает 0, если программа выполнена корректно
*/
int main()
{
	const double X = -4.8;
	const double Y = 17.5;
	const double Z = 3.2;
	printf("a = %lf\n", GetA(X, Y, Z));
	printf("b = %lf\n", GetB(X, Y, Z));
	return 0;
}

double GetA(const double x, const double y, const double z)
{
	return y * z * pow(x, 2) - z / pow(sin(x / z), 2);
}

double GetB(const double x, const double y, const double z)
{
	return z * exp(-sqrt(z)) * cos(y * x / z);
}
