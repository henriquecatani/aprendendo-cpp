#include <iostream>
#include <fstream>
#include <iostream>
#include <set>
#include <tuple>
#include <list>
#include <vector>
using namespace std;
struct node {
	int val;
	pair<node*, int> link; // this only allows one link, the shortest weight on insert
};

vector<node> nodos;

node* find(int node_value) {
	for (node &n : nodos) {
		if (n.val == node_value) return &n;
	}
	return nullptr;
}

// verifies if to is already linked by from, or inverse, if yes, insert, if not, compare and insert the shortest weight link
void insert_link(node* from, node* to, int weight) {
	
	if (from->link.first == to) {
		if (from->link.second > weight) {
			from->link = {to, weight};
		}
	} else if (to->link.first == from) {
		if (to->link.second > weight) {
			to->link = {from, weight};
		}
	} else {
		from->link = {to, weight};
	}
}
node* insert_node(int value) {
	node* n = find(value);
	if (n) return n;

	nodos.push_back({value, {nullptr, 0}});
	return &nodos.back();
}

int main ()
{
	int R, C;
	int V, W, P;

	cin >> R >> C;
	
	for(int i = 0; i < C; i++)
	{
		cin >> V >> W >> P;
		node* first = insert_node(V);
		node* second = insert_node(W);
		insert_link(first, second, P);
	}

	// loop to sum links weights
	int sum = 0;
	for (node &n : nodos) {
		sum += n.link.second;
	}
	cout << sum << endl;
	return 0;
}
