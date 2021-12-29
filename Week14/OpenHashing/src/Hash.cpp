#include "Hash.hpp"

int Hash::HashCode(int number){
	return number % capacity;
}
Hash::Hash(int capacity){
	this->capacity = capacity;
	Table = new Node*[capacity];
	for(int i=0;i<capacity;i++)
		Table[i] = NULL;
}
void Hash::Add(int number){
	if(Search(number)) return;
	int index = HashCode(number);
	Table[index] = new Node(number,Table[index]);
}
bool Hash::Remove(int number){
	int index = HashCode(number);
	if(Table[index] == NULL) return false;
	if(Table[index]->data == number){
		Node *del = Table[index];
		Table[index] = del->next;
		delete del;
		return true;
	}
	Node* pre = Table[index];
	while(pre->next != NULL){
		if(pre->next->data == number){
			Node *del = pre->next;
			pre->next = del->next;
			delete del;
			return true;
		}
		pre = pre->next;
	}
	return false;
}
void Hash::Clear(){
	for(int i=0;i<capacity;i++){
		while(Table[i] != NULL){
			Remove(Table[i]->data);			
		}
	}
}
bool Hash::Search(int number){
	int index = HashCode(number);
	Node *tmp = Table[index];
	while(tmp != NULL){
		if(tmp->data == number) return true;
		tmp = tmp->next;
	}
	return false;
}
bool Hash::isEmpty(){
	for(int i=0;i<capacity;i++){
		if(Table[i] != NULL) return false;
	}
	return true;
}
void Hash::Print(){
	for(int i=0;i<capacity;i++){
		Node *tmp = Table[i];
		if(tmp == NULL) cout<<"Table["<<i<<"]";
		else cout<<"Table["<<i<<"]->";
		while(tmp != NULL){
			cout<<tmp->data<<"->";
			tmp = tmp->next;			
		}
		cout<<"->NULL"<<endl;
	}
}
Hash::~Hash(){
	Clear();
	delete [] Table;
}
