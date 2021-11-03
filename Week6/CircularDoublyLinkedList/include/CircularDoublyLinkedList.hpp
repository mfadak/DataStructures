#ifndef CIRCULARDOUBLYLINKEDLIST_HPP
#define CIRCULARDOUBLYLINKEDLIST_HPP

#include "Node.hpp"
#include "NoSuchElement.hpp"

template <typename Object>
class CircularDoublyLinkedList{
	private:
		Node<Object> *head;
		int size;
		
		Node<Object>* FindPreviousByPosition(int index){
			Node<Object> *prv = head;
			int i=1;
			for(Node<Object> *itr = head; i != index; itr=itr->next,i++){
				prv = prv->next;
			}
			return prv;
		}			
	public:
		CircularDoublyLinkedList(){
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
		void insert(int index,const Object& item)throw(NoSuchElement){
			if(index < 0 || index > size) throw NoSuchElement("No Such Element");
			if(index == 0){
				if(size == 0){
					head = new Node<Object>(item,head);
					head->next=head->prev=head;
				}
				else{
					head = new Node<Object>(item,head,head->prev);
					head->next->prev = head;
					head->prev->next = head; 
				}
			}
			else{
				Node<Object> *prv = FindPreviousByPosition(index);
				prv->next = new Node<Object>(item,prv->next,prv);
				prv->next->next->prev = prv->next;
			}
			size++;
		}
		const Object& first()throw(NoSuchElement){
			if(isEmpty()) throw NoSuchElement("No Such Element");
			return head->data;
		}
		const Object& last()throw(NoSuchElement){
			if(isEmpty()) throw NoSuchElement("No Such Element");
			return head->prev->data;
		}
		int indexOf(const Object& item)throw(NoSuchElement){
			int index=0;
			for(Node<Object> *itr=head;index<size;itr=itr->next){
				if(itr->data == item) return index;
				index++;
			}
			throw NoSuchElement("No Such Element");
		}
		void remove(const Object& item){
			int index = indexOf(item);
			removeAt(index);
		}
		void removeAt(int index)throw(NoSuchElement){
			if(index < 0 || index >= size) throw NoSuchElement("No Such Element");
			Node<Object> *del;
			if(index == 0){
				del = head;
				if(size == 1) head = NULL;
				else{
					head = head->next;
					head->prev = del->prev;
					del->prev->next = head;
				}	
			}
			else{
				Node<Object> *prv = FindPreviousByPosition(index);
				del = prv->next;
				prv->next = del->next;
				del->next->prev = prv;
			}
			size--;
			delete del;
		}
		bool find(const Object& item){
			int index=0;
			for(Node<Object> *itr=head;index<size;itr=itr->next,index++){
				if(itr->data == item) return true;
			}
			return false;
		}
		const Object& elementAt(int index)throw(NoSuchElement){
			if(index < 0 || index >= size) throw NoSuchElement("No Such Element");
			if(index == 0) return head->data;
			return FindPreviousByPosition(index)->next->data;
		}
		void clear(){
			while(!isEmpty())
				removeAt(0);
		}
		friend ostream& operator<<(ostream& screen,CircularDoublyLinkedList& rgt){
			int index=0;
			for(Node<Object> *itr=rgt.head;index<rgt.size;itr=itr->next,index++){
				screen<<itr->data<<" <-> ";
			}
			screen<<endl;
			return screen;
		}
		void printNodesFromPositionInReverseOrder(int index)throw(NoSuchElement){
			int i=0;
			if(index < 0 || index >= size) throw NoSuchElement("No Such Element");
			for(Node<Object> *itr = FindPreviousByPosition(index+1);i<size;itr=itr->prev,i++){
				cout<<itr->data<<" <-> ";
			}
			cout<<endl;
		}
		void printNodesFromPositionInOrder(int index)throw(NoSuchElement){
			int i=0;
			if(index < 0 || index >= size) throw NoSuchElement("No Such Element");
			for(Node<Object> *itr = FindPreviousByPosition(index+1);i<size;itr=itr->next,i++){
				cout<<itr->data<<" <-> ";
			}
			cout<<endl;
		}
		void printReverseOrder(){
			printNodesFromPositionInReverseOrder(size-1);			
		}
		~CircularDoublyLinkedList(){
			clear();
		}

};

#endif
