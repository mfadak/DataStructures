#include "BST.hpp"

int main(){
	BST<int> *tree = new BST<int>();
	
	tree->add(50);
	tree->add(40);
	tree->add(60);
	tree->add(30);
	tree->add(45);
	tree->add(55);
	tree->add(90);
	tree->add(15);
	tree->add(35);
	tree->add(42);
	tree->add(48);
	tree->add(54);
	tree->add(56);
	tree->add(70);
	tree->add(100);
	
	cout<<"Height: "<<tree->Height()<<endl;
	
	if(tree->find(35)) cout<<"35 is exist"<<endl;
	if(tree->find(500)) cout<<"500 is exist"<<endl;
	else cout<<"500 is not exist"<<endl;
	
	tree->postorder();
	tree->Delete(50);
	cout<<endl;
	tree->inorder();
	delete tree;
	return 0; 
}
