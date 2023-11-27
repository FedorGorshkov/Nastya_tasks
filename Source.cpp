#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

struct Student {
	string surname, group, number_phone;
	Student(string s, string g, string p) {
		this->surname = s;
		this->group = g;
		this->number_phone = p;
	}
};

class Students {
	int n_students = 0;
	vector<Student*> students;
public:
	void add_student(string s, string g, string p) {
		students.push_back(new Student(s, g, p));
		n_students++;
	}

	vector<Student*> get_sorted_students_from_group(string g) {
		vector<Student*> res;
		for (int i = 0; i < n_students; i++)
			if (students[i]->group == g)
				res.push_back(students[i]);
		sort(res.begin(), res.end(), cmp);
		return res;
	}

	bool cmp(Student* f, Student* s) {
		// —читаем, что номера типа 89826397956, не с +7 (иначе удалить первый элемент)
		return stoi(f->number_phone) < stoi(s->number_phone);
	}
};

int main() {
	ifstream in("students.txt");
	Students* students = new Students();
	string buffer; in >> buffer;
	// ѕерва€ строка - количество записей
	int n = stoi(buffer);
	for (int i = 0; i < n; i++) {
		string s, g, p;
		in >> s; in >> g; in >> p;
		students->add_student(s, g, p);
	}
	in.close();
	// Target group
	string group; in >> group;
	vector<Student*> res = students->get_sorted_students_from_group(group);
	ofstream out("out.txt");
	int n_res = res.size();
	for (int i = 0; i < n_res; i++) {
		out << res[i]->surname << "\n" << res[i]->number_phone << "\n";
	}
	out.close();
	return 0;
}