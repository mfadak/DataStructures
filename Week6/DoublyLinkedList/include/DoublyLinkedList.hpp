#ifndef DOUBLYLINKEDLIST
#define DOUBLYLINKEDLIST

#include "Node.hpp"

template <typename Object>
class DoublyLinkedList{
	private:
		Node<Object> *head;
		int size;
		
		Node<Object>* FindPreviousByPosition(int index){
			Node<Object> *prv = head;
			int i=1;
			for(Node<Object> *itr = head; itr->next != NULL && i != index; itr=itr->next,i++){
				prv = prv->next;
			}
			return prv;
		}			
	public:
		DoublyLinkedList(){
			head = NULL;
			size=0;
		}
		int Count()const{
			return size;
		}
		bool isEmpty()const{
			return size == 0;
		}
		void add(const Object& item){
			insert(size,item);
		}
		void insert(int index,const Object& item){
			// if(index < 0 || index > size) throw HATA
			if(index == 0){
				head = new Node<Object>(item,head);
				if(head->next != NULL) head->next->prev = head;
			}
			else{
				Node<Object> *prv = FindPreviousByPosition(index);
				prv->next = new Node<Object>(item,prv->next,prv);
				if(prv->next->next != NULL)
					prv->next->next->prev = prv->next;
			}
			size++;
		}
		const Object& first(){
			//if(isEmpty()) throw HATA
			return head->data;
		}
		const Object& last(){
			//if(isEmpty()) throw HATA
			return FindPreviousByPosition(size)->data;
		}
		int indexOf(const Object& item){
			int index=0;
			for(Node<Object> *itr=head;itr!=NULL;itr=itr->next){
				if(itr->data == item) return index;
				index++;
			}
			throw "HATA";
		}
		void remove(const Object& item){
			int index = indexOf(item);
			removeAt(index);
		}
		void removeAt(int index){
			// if(index < 0 || index >= size) throw HATA
			Node<Object> *del;
			if(index == 0){
				del = head;
				head = head->next;
				if(head != NULL) head->prev = NULL;
			}
			else{
				Node<Object> *prv = FindPreviousByPosition(index);
				del = prv->next;
				prv->next = del->next;
				if(del->next != NULL)
					del->next->prev = prv;
			}
			size--;
			delete del;
		}
		bool find(const Object& item){
			for(Node<Object> *itr=head;itr!=NULL;itr=itr->next){
				if(itr->data == item) return true;
			}
			return false;
		}
		const Object& elementAt(int index){
			// if(index < 0 || index >= size) throw HATA
			if(index == 0) return head->data;
			return FindPreviousByPosition(index)->next->data;
		}
		void clear(){
			while(!isEmpty())
				removeAt(0);
		}
		friend ostream& operator<<(ostream& screen,DoublyLinkedList& rgt){
			for(Node<Object> *itr=rgt.head;itr!=NULL;itr=itr->next){
				screen<<itr->data<<" <-> ";
			}
			screen<<endl;
			return screen;
		}
		void printNodesFromPositionInReverseOrder(int index){
			// if(index < 0 || index >= size) throw HATA
			for(Node<Object> *itr = FindPreviousByPosition(index+1);itr!=NULL;itr=itr->prev){
				cout<<itr->data<<" <-> ";
			}
			cout<<endl;
		}
		void printReverseOrder(){
			printNodesFromPositionInReverseOrder(size-1);			
		}
		~DoublyLinkedList(){
			clear();
		}

};

#endif
