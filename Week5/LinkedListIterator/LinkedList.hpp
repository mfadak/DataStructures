#ifndef LinkedList_HPP
#define LinkedList_HPP

#include "Node.hpp"
#include "Iterator.hpp"

template <typename Object>
class LinkedList{
	private:
		Node<Object> *head;
		
		Node<Object>* FindPrevByPosition(int position){
			if(position < 0 || position > size()) throw "Index out of range";
			int index=0;
			Node<Object> *itr=head;
			for(;itr!=NULL;itr=itr->next,index++){
				if(position == index) return itr;
			}
			return NULL;
		}	
	public:
		LinkedList(){
			head = new Node<Object>(Object());
		}
		Iterator<Object> iterator(){
			Iterator<Object> itr(head);
			return itr;
		}
		bool isEmpty() const{
			return head->next == NULL;
		}
		int size() const{
			int length=0;
			for(Node<Object> *itr=head->next;itr!=NULL;itr=itr->next){
				length++;
			}
			return length;
		}
		const Object& first(){
			if(isEmpty()) throw "Empty list";
			return head->next->item;
		}
		const Object& last(){
			if(isEmpty()) throw "Empty list";
			return FindPrevByPosition(size())->item;
		}
		void add(const Object& item){
			insert(size(),item);
		}
		void insert(int index,const Object& item){
			Node<Object> *prev = FindPrevByPosition(index);
			prev->next = new Node<Object>(item,prev->next);
		}
		void remove(const Object& item){
			int position = indexOf(item);
			removeAt(position);			
		}
		void removeAt(int index){
			if(isEmpty()) throw "Empty list";
			Node<Object> *del;
			Node<Object> *prev = FindPrevByPosition(index);
			del = prev->next;
			prev->next = prev->next->next;
			
			delete del;
		}
		bool find(const Object& item) const{
			for(Node<Object> *itr=head->next;itr!=NULL;itr=itr->next){
				if(itr->item == item) return true;
			}
			return false;
		}
		int indexOf(const Object& item){
			int index=0;
			for(Node<Object> *itr=head->next;itr!=NULL;itr=itr->next,index++){
				if(itr->item == item) return index;
			}
			throw "Index out of range";
		}
		friend ostream& operator<<(ostream& screen, LinkedList &right){
			if(right.isEmpty()) screen<<"Empty list";
			else{
				for(Node<Object> *itr=right.head->next;itr!=NULL;itr=itr->next){
					screen<<itr->item<<" ";
				}
			}
			return screen;
		}
		void clear(){
			while(!isEmpty())
				removeAt(0);
		}
		~LinkedList(){
			clear();	
			delete head;
		}
};
#endif
