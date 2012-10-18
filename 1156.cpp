// Accepted
#include <iostream>
#include <list>

using namespace std;

struct node{
	int ID;
	char c;
	int l;
	int r;
	int u;
};

void preorder(struct node* nodes, struct node n){
//	cout << "pre-order node NO." << n.ID << endl;
	
	cout << n.c;
	if (n.l != 0) {
		preorder(nodes, nodes[n.l]);
	}
	if (n.r != 0) {
		preorder(nodes, nodes[n.r]);
	}
};

int findRoot(struct node* nodes, struct node n){
//	cout << "looking for root of NO." << n.ID << endl;
	if (n.u != 0){
		return findRoot(nodes, nodes[n.u]);
	} else {
//		cout << "root is NO." << n.ID << endl;
		return n.ID;
	}
};

int main(int argc, char *argv[]) {
	int numNode;
	int ID;
	char c;
	int l;
	int r;
//	struct node* n;
	
	
	while (cin >> numNode) {
		
		struct node nodes[1001];
		for (int i = 0; i < 1001; i++) {
					nodes[i].ID = 0;
					nodes[i].c = 0;
					nodes[i].l = 0;
					nodes[i].r = 0;
					nodes[i].u = 0;
		}
		
		for (int i = 0; i < numNode; i++) {
			
			cin >> ID >> c >> l >> r;
//			n = &node();
			nodes[ID].ID = ID;
			nodes[ID].c = c;
			nodes[ID].l = l;
			nodes[ID].r = r;
			
			nodes[l].u = ID;
			nodes[r].u = ID;
		}
		
		int root = findRoot(nodes, nodes[ID]);
//		cout << "the int root is " << root << endl;
		preorder(nodes, nodes[root]);
//		cout << "-------------" << endl;
		cout << endl;
		
//		for (int i = 0; i < numNode; i++) {
//			cout << nodes[i].ID << "\t" << nodes[i].c << "\t" << nodes[i].l << "\t" << nodes[i].r << endl; 
//		}
		
	}
	
	return 0;
}