#include "BST.hpp"

int main(){
	BST<int> *bst = new BST<int>();
	bst->Add(105);
	bst->Add(67);
	bst->Add(223);
	bst->Add(197);
	bst->Add(54);
	bst->Add(47);
	bst->Add(90);
	bst->Add(546);
	bst->Add(571);
	bst->Add(320);
	bst->postorder();
	cout<<endl<<"Height: "<<bst->Height()<<endl;
	if(bst->Search(95)) cout<<"Item found"<<endl;
	else cout<<"Not found"<<endl;
	delete bst;
	return 0;
}
