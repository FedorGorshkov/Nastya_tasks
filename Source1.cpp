#include <iostream>
#include <string>
#include <fstream>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;

struct Word_stat {
	string word;
	int amount;
	Word_stat(string s, int n) {
		this->word = s; this->amount = n;
	}
};

class Words {
	map<string, int> amounts;
	vector<string> words;
public:
	void add_word(string word) {
		this->words.push_back(word);
		this->amounts[word] = 0;
	}
	void parse_and_find(string str) {
		int n = words.size();
		vector<string> str_words; string word = "";
		int current = 0, len_str = str.length();
		while (current != len_str - 1) {
			if (str[current] == ' ' || str[current] == ',' || str[current] == '.' ||
				str[current] == ':' || str[current] == '!' || str[current] == '?') {
				if (word != "") {
					str_words.push_back(word);
					word = "";
				}
			}
			else
				word += str[current];
			current++;
		}
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < str_words.size(); j++) {
				if (str_words[j] == this->words[i])
					this->amounts[words[i]]++;
			}
		}
	}
	Word_stat** get_sorted(int* len_res) {
		*len_res = this->words.size();
		Word_stat** res = new Word_stat*[*len_res];
		for (int i = 0; i < *len_res; i++)
			res[i] = new Word_stat(words[i], amounts[words[i]]);
		sort(res, res + sizeof(Word_stat*) * (*len_res), cmp);
		return res;
	}

	bool cmp(Word_stat* f, Word_stat* s) {
		return f->amount < s->amount;
	}
};

int main() {
	ifstream in("reserved_words.txt");
	string buffer; in >> buffer;
	// Первая строка файла - количество слов
	int n = stoi(buffer);
	Words* words = new Words();
	for (int i = 0; i < n; i++) {
		in >> buffer;
		words->add_word(buffer);
	}
	in.close();
	// Первая строка - количество строк в тексте
	in.open("text.txt");
	in >> buffer; n = stoi(buffer);
	for (int i = 0; i < n; i++) {
		in >> buffer;
		words->parse_and_find(buffer);
	}
	in.close();
	int* len_res = 0;
	Word_stat** res = words->get_sorted(len_res);
	ofstream out("out.txt");
	for (int i = 0; i < *len_res; i++) {
		out << res[i]->word << ": " << res[i]->amount << "\n";
	}
	out.close();
	return 0;
}