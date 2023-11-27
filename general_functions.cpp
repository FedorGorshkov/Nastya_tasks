#include "Graph_theory/Graph_theory.h"

/* Функция, считающая количество вхождений символа в строку
   (есть аналогичная в <algorithm>, но мы же учимся) */
int count(char symbol, string str) {
	// Выделяем в переменную чтобы на каждом шаге цикла не вычислять str.length()
	int len = str.length(), res = 0;
	// Теперь собственно идём по строке, если находим совпадающий символ - инкрементируем res
	for (int i = 0; i < len; i++)
		if (str[i] == symbol)
			res++;
	return res;
}
