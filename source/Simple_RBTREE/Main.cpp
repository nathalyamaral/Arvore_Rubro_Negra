#include "RBTree.h"

int main(){
	
	RBTree* tree = new RBTree();

	tree->insert(12);
	tree->insert(13);
	tree->insert(14);

    tree->print();
	return 0;
}
