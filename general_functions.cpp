#include "Graph_theory/Graph_theory.h"

/* �������, ��������� ���������� ��������� ������� � ������
   (���� ����������� � <algorithm>, �� �� �� ������) */
int count(char symbol, string str) {
	// �������� � ���������� ����� �� ������ ���� ����� �� ��������� str.length()
	int len = str.length(), res = 0;
	// ������ ���������� ��� �� ������, ���� ������� ����������� ������ - �������������� res
	for (int i = 0; i < len; i++)
		if (str[i] == symbol)
			res++;
	return res;
}
