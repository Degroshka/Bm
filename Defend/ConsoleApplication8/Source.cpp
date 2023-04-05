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
	symb* s,* sf,*mo;
	num* n,*sn;
	s =sf=mo=new symb;
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
		cout << s->elem;
		s = s->next;
		s->elem = x;
	}
	s->next = NULL;
	fin.close();
	s = s->prev;
	cout << endl;
	while (s != sf) {
		while (isdigit(s->elem)) {
			b = s->elem - '0';
			n->elem += b * c;
			c = c * 10;
			s = s->prev;
		}
		c = 1;
		mo = s;
		s = s->prev;
		while (isdigit(s->elem)) {
			b = s->elem - '0';
			sn->elem =sn->elem+ b * c;
			c = c * 10;
			s = s->prev;
		}
		switch (mo->elem) {
			case '+':
				cout << n->elem << '+' << sn->elem << '=';
				n->elem += sn->elem;
				sn->elem = NULL;
				cout << n->elem << endl;
				break;
			case '-':
				cout << sn->elem << '-' << n->elem<<'=';
				n->elem = sn->elem - n->elem;
				sn->elem = NULL;
				cout << n->elem << endl;
				break;
			case '*':
				cout << n->elem << '*' << sn->elem<<'=';
				n->elem *= sn->elem;
				sn->elem = NULL;
				cout << n->elem << endl;
				break;
			case '/':
				cout << n->elem << '/' << sn->elem << '=';
				n->elem =n->elem/ sn->elem;
				sn->elem = NULL;
				cout << n->elem << endl;
				break;

		}
	}
}