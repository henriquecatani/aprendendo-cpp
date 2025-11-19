#include <iostream>
#include <cassert>
#include "list.cpp"

using namespace std;

int main()
{
    UPF::list l;

	l.insere_apos("a", "x");
	assert(l.first!=nullptr);
	assert(l.last!=nullptr);
	assert(l.first==l.last);
	assert(l.first->value=="a");
	assert(l.last->value=="a");
	assert(l.first->next==nullptr);
	assert(l.size()==1);
	cout << "size: " << l.size() << endl; 
	l.print();

	l.insere_apos("b", "a");
	assert(l.first!=nullptr);
	assert(l.last!=nullptr);
	assert(l.first!=l.last);
    assert(l.first->value=="a");
	assert(l.first->next!=nullptr);
	assert(l.first->next->value=="b");
	assert(l.last->value=="b");
	assert(l.first->next->next==nullptr);
	assert(l.size()==2);
	cout << "size: " << l.size() << endl; 
	l.print();

    l.insere_apos("c", "a");
	assert(l.first!=nullptr);
	assert(l.last!=nullptr);
	assert(l.first!=l.last);
    assert(l.first->value=="a");
	assert(l.first->next!=nullptr);
	assert(l.first->next->value=="c");
	assert(l.first->next->next!=nullptr);
	assert(l.first->next->next->value=="b");
	assert(l.last->value=="b");
	assert(l.first->next->next->next==nullptr);
	assert(l.size()==3);
    cout << "size: " << l.size() << endl; l.print();

    l.insere_apos("d", "c");
	assert(l.first!=nullptr);
	assert(l.last!=nullptr);
	assert(l.first!=l.last);
    assert(l.first->value=="a");
	assert(l.first->next!=nullptr);
	assert(l.first->next->value=="c");
	assert(l.first->next->next!=nullptr);
	assert(l.first->next->next->value=="d");
	assert(l.first->next->next->next!=nullptr);
    assert(l.first->next->next->next->value=="b");
	assert(l.first->next->next->next->next==nullptr);
	assert(l.last->value=="b");
	assert(l.size()==4);
    cout << "size: " << l.size() << endl; l.print();

    l.insere_apos("e", "b");
	assert(l.first!=nullptr);
	assert(l.last!=nullptr);
	assert(l.first!=l.last);
    assert(l.first->value=="a");
	assert(l.first->next!=nullptr);
	assert(l.first->next->value=="c");
	assert(l.first->next->next!=nullptr);
	assert(l.first->next->next->value=="d");
	assert(l.first->next->next->next!=nullptr);
    assert(l.first->next->next->next->value=="b");
	assert(l.first->next->next->next->next!=nullptr);
    assert(l.first->next->next->next->next->value=="e");
	assert(l.first->next->next->next->next->next==nullptr);
	assert(l.last->value=="e");
	assert(l.size()==5);
    cout << "size: " << l.size() << endl; l.print();

    cout << "\nThats all, folks! (Tudo ok!)!\n";
    return 0;
}
