#include "Huffman.hpp"

Node* Huffman::CreateTree(int freq[]){
	Node *nodes[symbols];
	for(int i=0;i<symbols;i++){
		if(freq[i]>0){
			nodes[i] = new Node((char)i,freq[i]);
		}
		else{
			nodes[i] = NULL;
		}
	}
	
	while(true){
		int firstIndex = MinNodeIndex(nodes);
		Node* min1 = nodes[firstIndex];
		nodes[firstIndex] = NULL;
		int secondIndex = MinNodeIndex(nodes);
		if(secondIndex == -1) return min1;
		Node *min2 = nodes[secondIndex];
		nodes[secondIndex] = NULL;
		nodes[firstIndex] = new Node(0,min1->freq+min2->freq,min1,min2);
	}	
}
void Huffman::AssignCodes(Node* subNode,string code){
	if(!subNode->isLeaf()){
		AssignCodes(subNode->left,code+"0");
		AssignCodes(subNode->right,code+"1");
	}
	else{
		subNode->code = code;
	}
}
int Huffman::MinNodeIndex(Node* trees[]){
	Node *min;
	int minIndex = -1;
	
	for(int i=0;i<symbols;i++){
		if(trees[i] != NULL){
			min = trees[i];
			minIndex = i;
			break;
		}
	}
	
	for(int i=0;i<symbols;i++){
		if(trees[i] == NULL) continue;
		
		if(*min > *trees[i]){
			min = trees[i];
			minIndex = i;
		}
	}
	return minIndex;
}
void Huffman::ReadFile(string path){
	string line;
	ifstream file(path.c_str());
	while(getline(file,line)){
		input += line;
		input += "\n";
	}
	file.close();
}
void Huffman::inorder(Node* subNode){
	if(subNode != NULL){
		inorder(subNode->left);
		if(subNode->isLeaf()) cout<<subNode->chracter<<":"<<subNode->code<<endl;
		inorder(subNode->right);
	}
}
void Huffman::RemoveNode(Node*& subNode){
	if(subNode != NULL){
		RemoveNode(subNode->left);
		RemoveNode(subNode->right);
		delete subNode;
		subNode = NULL;
	}
}
Huffman::Huffman(string path){
	symbols = 256;
	ReadFile(path);
	root = NULL;
}
void Huffman::Encode(){
	char chars[input.size()-1];
	strcpy(chars,input.c_str());
	
	int freq[symbols];
	for(int i=0;i<symbols;i++)
		freq[i] = 0;
	
	for(int i=0;i<input.size()-1;i++)
		freq[chars[i]]++;
	
	root = CreateTree(freq);
	
	AssignCodes(root,"");
}
ostream& operator<<(ostream& screen,Huffman& rgt){
	screen<<"Huffman Tree:"<<endl;
	rgt.inorder(rgt.root);
	return screen;
}
Huffman::~Huffman(){
	RemoveNode(root);
}
