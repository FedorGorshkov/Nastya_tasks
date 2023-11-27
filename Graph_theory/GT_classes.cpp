#include "Graph_theory.h"


// Конструктор класса
Matrix_incidence::Matrix_incidence(int n, int m) {
		// Записываем размерность матрицы
		this->amount_vertices = n;
		this->amount_edges = m;
		// Теперь выделяем память под саму матрицу, сначала кол-во строк, затем столбцов.
		this->matrix = new int* [amount_vertices];
		for (int i = 0; i < m; i++)
			this->matrix[i] = new int[amount_edges];
}
// Функция, которая заполняет строку матрицы для вершины
void Matrix_incidence::set_row(int vertex, int* row) {
	/* Просто циклом идём по строке (массиву, соответствующему данной вершине)
		и тупо приравниваем элемент к элементу */
	for (int i = 0; i < amount_edges; i++)
		this->matrix[vertex][i] = row[i];
}
// Функция, которая заполняет столбец для ребра (вряд ли пригодится)
void Matrix_incidence::set_column(int edge, int* column) {
	for (int i = 0; i < amount_vertices; i++)
		this->matrix[i][edge] = column[i];
}

// Конструктор класса
List_adjacency::List_adjacency(int amount_vertices) {
	// Записываем число вершин во внутреннее поле
	this->amount_vertices = amount_vertices;
	// Добавляем соотв. кол-во пустых векторов (заполнение в методе add_list)
	this->list = vector<vector<int>>(amount_vertices, vector<int>());
}
// Функция, добавляющая очередной список 
void List_adjacency::add_list(int vertex, int len_row, int* row) {
	for (int i = 0; i < len_row; i++)
		list[vertex].push_back(row[i]);
}
// Функция, переводящая список (списков) смежности в массив рёбер
vector<vector<int>> List_adjacency::to_edges_array() {
	// Двумерный вектор из нуля элементов длиной 2 (2 вершины в ребре, пока ребёр известно 0)
	vector<vector<int>> res(0, vector<int>(2));
	// Цикл по всем вершинам
	for (int i = 0; i < amount_vertices; i++) {
		// Чтобы не вычислять на каждом шаге цикла
		int len = list[i].size();
		// Цикл по всем вершинам, смежным к текущей (i-той)
;			for (int j = 0; j < len; j++) {
			/* Перед тем, как добавить ребро, нужно убедиться, что такого 
				ребра у нас ещё нет (т. к. рёбра [2, 5] и [5, 2] одинаковы)
				Для этого идём циклом по уже заполненным рёбрам и ищем такое же
				(где оба элемента одинаковы, вне зависимости от порядка), если 
				нашли - ставим flag в false и не добавляем ребро.*/
			bool flag = true;
			for (int k = 0; k < res.size(); k++) {
				if ((res[k][0] == i || res[k][0] == list[i][j]) &&
					(res[k][1] == i || res[k][1] == list[i][j]))
					flag = false;
			}
			if (flag)
				res.push_back(vector<int>{i, list[i][j]});
		}
	}
	return res;
}
