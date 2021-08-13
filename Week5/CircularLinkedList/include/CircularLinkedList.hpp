#ifndef CIRCULARLINKEDLIST_HPP
#define CIRCULARLINKEDLIST_HPP

#include "Iterator.hpp"
#include "NoSuchElement.hpp"

template <typename Object>
class CircularLinkedList{
	private:
		Node<Object> *head;
		int size;
		
		Iterator<Object> FindPrevByPosition(int position){
			if(position < 0 || position > size) throw NoSuchElement("No Such Element");
			int index=0;
			Iterator<Object> iterator(head);
			while(position != index){
				iterator.next();
				index++;
			}
			return iterator;
		}
		void updateLastNode(){
			Node<Object> *lastNode = FindPrevByPosition(size).current;
			lastNode->next = head->next;
		}
	public:
		CircularLinkedList(){
			head = new Node<Object>();
			size=0;
		}
		bool isEmpty()const{
			return head->next == NULL;
		}
		int Count()const{
			return size;
		}
		void add(const Object& item){
			insert(size,item);
		}
		void insert(int index,const Object& item){
			Iterator<Object> iterator = FindPrevByPosition(index);
			iterator.current->next = new Node<Object>(item,iterator.current->next);
			size++;
			
			if(index == 0) updateLastNode();
		}
		const Object& first()const throw(NoSuchElement){
			if(isEmpty()) throw NoSuchElement("No Such Element");
			return head->next->item;
		}
		const Object& last()throw(NoSuchElement){
			if(isEmpty()) throw NoSuchElement("No Such Element");
			return FindPrevByPosition(size).getCurrent();
		}
		int indexOf(const Object& item)throw(NoSuchElement){
			int index=0;
			for(Iterator<Object> iterator(head->next);index<size;iterator.next()){
				if(iterator.getCurrent() == item) return index;
				index++;
			}
			throw NoSuchElement("No Such Element");
		}
		const Object& elementAt(int index)throw(NoSuchElement){
			if(index < 0 || index >= size) throw NoSuchElement("No Such Element");
			Iterator<Object> iterator = FindPrevByPosition(index);
			return iterator.current->next->item;
		}
		bool find(const Object& item)const{
			for(Iterator<Object> iterator(head->next);iterator.hasNext();iterator.next()){
				if(iterator.getCurrent() == item) return true;
			}
			return false;
		}
		void remove(const Object& item){
			int index = indexOf(item);
			removeAt(index);
		}
		void removeAt(int index)throw(NoSuchElement){
			if(index < 0 || index >= size) throw NoSuchElement("No Such Element");
			Iterator<Object> iterator = FindPrevByPosition(index);
			Node<Object> *del = iterator.current->next;
			iterator.current->next = iterator.current->next->next;
			delete del;
			size--;
			
			if(size != 0 && index == 0) updateLastNode();
		}
		friend ostream& operator<<(ostream& screen,CircularLinkedList<Object> &right)
		{
			int index=0;
			for(Iterator<Object> iterator(right.head->next);index<right.size;iterator.next()){
				screen<<iterator.getCurrent()<<" -> ";
				index++;
			}
			screen<<"NULL"<<endl;
			return screen;
		}
		void printAllFromPosition(int index)throw(NoSuchElement){
			if(index < 0 || index >= size) throw NoSuchElement("No Such Element");
			Iterator<Object> iterator = FindPrevByPosition(index);
			int ind=0;
			for(iterator.next();ind<size;iterator.next(),ind++){
				cout<<iterator.getCurrent()<<" -> ";
			}
			cout<<endl;
		}
		void clear(){
			while(!isEmpty())
				removeAt(0);
		}
		~CircularLinkedList(){
			clear();
			delete head;
		}
		
};

#endif
