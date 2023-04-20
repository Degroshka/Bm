
#include <iostream>
using namespace std;
struct Fdol {
	char elem;
	Fdol* next, * prev;
};
struct Sdol {
	char elem;
	Sdol* next, * prev;
};


int main() {
	setlocale(LC_ALL, "Russian");
	Fdol* f, *ff;
	Sdol* s, *ss;
	f=ff = new Fdol;
	s=ss = new Sdol;
	char fch, sch;
	cout << "Введите номера вершин между которыми есть связи"<<endl;
	cout << "Вершина x связана с вершиной y " << endl;
	for(;;){
		cout << "x=";
		cin >> fch;
		if (fch == '.') {
			break;
		}
		cout << "y=";
		cin >> sch;
		if (sch == '.') {
			break;
		}
		if (fch != sch) {
			f->elem = fch;
			s->elem = sch;
			f->next = new Fdol;
			f->next->prev = f;
			s->next = new Sdol;
			s->next->prev = s;
			f = f->next;
			s = s->next;
		}
	}
	f->next = new Fdol;
	f->next = NULL;
	s->next = new Sdol;
	s->next = NULL;
	s = ss;
	f = ff;
	while (f->next != NULL) {
		while (s->next != NULL) {
			cout << f->elem << " and " << s->elem<<endl;
			if (f->elem == s->elem) {
				cout << " Не двудольынй";
				return 0;
			}
			s = s->next;
		}
		s = ss;
		f = f->next;
	}
	if(!isdigit(f->elem) and isdigit(f->prev->elem)) {
		cout << " Двудольный";
	}
	else{
		cout << " Недостаточно информации";
	}
}