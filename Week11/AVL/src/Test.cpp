#include "AVL.hpp"

int main(){
	AVL<int> *avl = new AVL<int>();
	avl->Add(105);
	avl->Add(67);
	avl->Add(223);
	avl->Add(197);
	avl->Add(54);
	avl->Add(47);
	avl->Add(90);
	avl->Add(546);
	avl->Add(571);
	avl->Add(320);
	avl->postorder();
	cout<<endl<<"Height: "<<avl->Height()<<endl;
	if(avl->Search(95)) cout<<"Item found"<<endl;
	else cout<<"Not found"<<endl;
	avl->preorder();
	delete avl;
	return 0;
}
