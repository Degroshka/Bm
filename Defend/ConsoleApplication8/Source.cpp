#include <iostream> 
#include<fstream>
using namespace std;

struct symb {
	char elem;
	symb* next, * prev;
};
struct num {
	int elem;
	num* next, * prev;
};


int main() {
	setlocale(LC_ALL, "Ru");
	char x;
	int  b, c = 1;
	symb* s,* sf,*mo,*sr;
	num* n,*sn;
	s =sf=mo=sr=new symb;
	s->elem = NULL;
	n=sn= new num;
	n->next = new num;
	n->next->prev = n;
	sn = n->next;
	n->elem = 0;
	sn->elem = 0;
	ifstream fin("txt1.txt"); //Открытие файла для чтения
	fin.unsetf(ios::skipws);
	if (!fin) { cout << "Warning"; return 0; }
	while (!fin.eof()) {
		fin >> x;
		s->next = new symb;
		s->next->prev = s;
		s = s->next;
		cout << s->prev->elem;
		s->elem = x;
	}
	s->next = NULL;
	s = s->next;
	fin.close();
	cout << endl;
	sf = sf->next;
	while (sf->next != s) {
		while (isdigit(sf->elem)) {
			sf = sf->next;
			sr = sf->prev;
		}
		while (isdigit(sr->elem)) {
			b = sr->elem - '0';
			n->elem +=b * c;
			c = c * 10;
			sr = sr->prev;
		}
		c = 1;
		mo = sf;
		sf = sf->next;
		while (isdigit(sf->elem)  and sf->next!=s) {
			sf = sf->next;
			sr = sf->prev;
		}sr = sf->prev;
		while (isdigit(sr->elem)) {
			b = sr->elem - '0';
			sn->elem +=b * c;
			c = c * 10;
			sr = sr->prev;

		}
		switch (mo->elem) {
			case '+':
				cout << n->elem << '+' << sn->elem << '=';
				n->elem += sn->elem;
				sn->elem = 0;
				cout << n->elem << endl;
				break;
			case '-':
				cout << n->elem << '-' << sn->elem<<'=';
				n->elem = n->elem - sn->elem;
				sn->elem = 0;
				cout << n->elem << endl;
				break;
			case '*':
				cout << n->elem << '*' << sn->elem<<'=';
				n->elem *= sn->elem;
				sn->elem = 0;
				cout << n->elem << endl;
				break;
			case '/':
				cout << n->elem << '/' << sn->elem << '=';
				n->elem =n->elem/ sn->elem;
				sn->elem = 0;
				cout << n->elem << endl;
				break;
		}
	}
}