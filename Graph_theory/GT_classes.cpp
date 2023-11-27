#include "Graph_theory.h"


// ����������� ������
Matrix_incidence::Matrix_incidence(int n, int m) {
		// ���������� ����������� �������
		this->amount_vertices = n;
		this->amount_edges = m;
		// ������ �������� ������ ��� ���� �������, ������� ���-�� �����, ����� ��������.
		this->matrix = new int* [amount_vertices];
		for (int i = 0; i < m; i++)
			this->matrix[i] = new int[amount_edges];
}
// �������, ������� ��������� ������ ������� ��� �������
void Matrix_incidence::set_row(int vertex, int* row) {
	/* ������ ������ ��� �� ������ (�������, ���������������� ������ �������)
		� ���� ������������ ������� � �������� */
	for (int i = 0; i < amount_edges; i++)
		this->matrix[vertex][i] = row[i];
}
// �������, ������� ��������� ������� ��� ����� (���� �� ����������)
void Matrix_incidence::set_column(int edge, int* column) {
	for (int i = 0; i < amount_vertices; i++)
		this->matrix[i][edge] = column[i];
}

// ����������� ������
List_adjacency::List_adjacency(int amount_vertices) {
	// ���������� ����� ������ �� ���������� ����
	this->amount_vertices = amount_vertices;
	// ��������� �����. ���-�� ������ �������� (���������� � ������ add_list)
	this->list = vector<vector<int>>(amount_vertices, vector<int>());
}
// �������, ����������� ��������� ������ 
void List_adjacency::add_list(int vertex, int len_row, int* row) {
	for (int i = 0; i < len_row; i++)
		list[vertex].push_back(row[i]);
}
// �������, ����������� ������ (�������) ��������� � ������ ����
vector<vector<int>> List_adjacency::to_edges_array() {
	// ��������� ������ �� ���� ��������� ������ 2 (2 ������� � �����, ���� ���� �������� 0)
	vector<vector<int>> res(0, vector<int>(2));
	// ���� �� ���� ��������
	for (int i = 0; i < amount_vertices; i++) {
		// ����� �� ��������� �� ������ ���� �����
		int len = list[i].size();
		// ���� �� ���� ��������, ������� � ������� (i-���)
;			for (int j = 0; j < len; j++) {
			/* ����� ���, ��� �������� �����, ����� ���������, ��� ������ 
				����� � ��� ��� ��� (�. �. ���� [2, 5] � [5, 2] ���������)
				��� ����� ��� ������ �� ��� ����������� ����� � ���� ����� ��
				(��� ��� �������� ���������, ��� ����������� �� �������), ���� 
				����� - ������ flag � false � �� ��������� �����.*/
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
