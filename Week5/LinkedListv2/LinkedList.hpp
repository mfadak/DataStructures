#ifndef LinkedList_HPP
#define LinkedList_HPP

#include "Node.hpp"

template <typename Object>
class LinkedList{
	private:
		Node<Object> *head;
		int size;
		
		Node<Object>* FindPrevByPosition(int position){
			if(position < 0 || position > size) throw "Index out of range";
			int index=1;
			
			for(Node<Object> *itr=head;itr!=NULL;itr=itr->next,index++){
				if(position == index) return itr;
			}
			return NULL;
		}	
	public:
		LinkedList(){
			head = NULL;	
			size=0;
		}
		bool isEmpty() const{
			return head == NULL;
		}
		int Count() const{
			return size;
		}
		const Object& first(){
			if(isEmpty()) throw "Empty list";
			return head->item;
		}
		const Object& last(){
			if(isEmpty()) throw "Empty list";
			return FindPrevByPosition(size)->item;
		}
		void add(const Object& item){
			insert(size,item);
		}
		void insert(int index,const Object& item){
			if(index == 0) head = new Node<Object>(item, head);
			else{
				Node<Object> *prev = FindPrevByPosition(index);
				prev->next = new Node<Object>(item,prev->next);
			}						
			size++;
		}
		void remove(const Object& item){
			int position = indexOf(item);
			removeAt(position);			
		}
		void removeAt(int index){
			if(size == 0) throw "Empty list";
			Node<Object> *del;
			if(index == 0){
				del = head;
				head = head->next;
			}
			else{
				Node<Object> *prev = FindPrevByPosition(index);
				del = prev->next;
				prev->next = prev->next->next;
			}
			delete del;
			size--;
		}
		bool find(const Object& item) const{
			for(Node<Object> *itr=head;itr!=NULL;itr=itr->next){
				if(itr->item == item) return true;
			}
			return false;
		}
		int indexOf(const Object& item){
			int index=0;
			for(Node<Object> *itr=head;itr!=NULL;itr=itr->next,index++){
				if(itr->item == item) return index;
			}
			throw "Index out of range";
		}
		friend ostream& operator<<(ostream& screen, LinkedList &right){
			if(right.isEmpty()) screen<<"Empty list";
			else{
				for(Node<Object> *itr=right.head;itr!=NULL;itr=itr->next){
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
		}
};
#endif
