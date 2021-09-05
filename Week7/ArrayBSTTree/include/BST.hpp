#ifndef BST_HPP
#define BST_HPP

#include <cmath>
#include <iostream>
#define SIZE 5000

using namespace std;

template <typename Object>
class BST{
	private:
		Object *items;
		int IndexFill[SIZE];
		
		int FindIndex(const Object& item,int currentIndex=0){
			while(true){
				if(IndexFill[currentIndex] == 0 || currentIndex == SIZE){
					return -1;
				}
				if(items[currentIndex] == item && IndexFill[currentIndex] == 1) 
					return currentIndex;
				else if(item < items[currentIndex]) currentIndex = 2*currentIndex+1;
				else if(item > items[currentIndex]) currentIndex = 2*currentIndex+2;
				
			}
		}
		bool IsPowerOfTwo(int x){
			while(((x%2) == 0 ) && x > 1) x/=2;
			return (x==1);
		}
		int MinValue(int i=0){
			if(2*i+1 > SIZE) return i;
			else if(IndexFill[2*i+1] == 0) return i;
			else return MinValue(2*i+1);
		}
	public:
		BST(){
			items = new Object[SIZE];
			clear();
		}
		void clear(){
			for(int i=0;i<SIZE;i++){
				IndexFill[i] = 0;
			}
		}
		void add(const Object& item){
			int currentIndex=0;
			while(true){
				if(IndexFill[currentIndex] == 0){
					items[currentIndex] = item;
					IndexFill[currentIndex] = 1;
					break;
				}
				else if(item < items[currentIndex]) currentIndex = 2*currentIndex+1;
				else if(item > items[currentIndex]) currentIndex = 2*currentIndex+2;
				else return;
			}
		}
		bool find(const Object& item){
			if(FindIndex(item) == -1) return false;
			return true;
		}
		int Height(int index=0){
			if(IndexFill[index] == 0) return -1;
			return 1+max(Height(2*index+1),Height(2*index+2));
		}
		void inorder(int index=0){
			if(index < SIZE && IndexFill[index] != 0){
				inorder(2*index+1);
				cout<<items[index]<<" ";
				inorder(2*index+2);
			}
		}
		void preorder(int index=0){
			if(index < SIZE && IndexFill[index] != 0){
				cout<<items[index]<<" ";
				preorder(2*index+1);
				preorder(2*index+2);
			}
		}
		void postorder(int index=0){
			if(index < SIZE && IndexFill[index] != 0){
				postorder(2*index+1);
				postorder(2*index+2);
				cout<<items[index]<<" ";
			}
		}
		void levelorder(){
			for(int i=0;i<SIZE;i++){
				if(IndexFill[i] == 1){
					cout<<items[i]<<" ";
				}
			}
		}
		void Delete(const Object& eleman, int ind=0) throw(){
			int i = FindIndex(eleman, ind);
			if(i == -1) throw "No such an element.";
			else{
				IndexFill[i] = 0;		
				if(IndexFill[2*i+2] == 0)
				{
					if(IndexFill[2*i+1] == 1) 
					{
						int k = 2*i+1; int Backup[SIZE];
						for(int iter = 0; iter < SIZE ; iter++) Backup[iter] = 0;
						Backup[0] = k; int index = 0;
						
						// BFS Algorithm
						for(int iter = 0; iter < SIZE && Backup[iter] != 0; iter++) 
						{
							for(int x = 0; x < SIZE; x++)
							{
								if(IsPowerOfTwo(Backup[iter]+1-x))
								{
									items[(Backup[iter]+x-1)/2] = items[Backup[iter]];
									IndexFill[(Backup[iter]+x-1)/2] = 1;
									IndexFill[Backup[iter]] = 0;
									break;
								}
							}
							if(IndexFill[2*Backup[iter] + 1] != 0)
							{
									Backup[++index] = 2*Backup[iter] + 1;
							}
							if(IndexFill[2*Backup[iter] + 2] != 0)
							{
									Backup[++index] = 2*Backup[iter] + 2;
							}
						}
					}
				}
				else
				{
					if(IndexFill[2*i+1] == 0) 
					{
						int k = 2*i+2; int Backup[SIZE];
						for(int iter = 0; iter < SIZE ; iter++) Backup[iter] = 0;
						Backup[0] = k; int index = 0;
						
					// BFS Algorithm
					for(int iter = 0; iter < SIZE && Backup[iter] != 0; iter++){
							for(int x = 0; x < SIZE; x++){
								if(IsPowerOfTwo((Backup[iter]+x)/2+1)){
									items[(Backup[iter]-2-x)/2] = items[Backup[iter]];
									IndexFill[(Backup[iter]-2-x)/2] = 1;
									break;
								}
							}
							IndexFill[Backup[iter]] = 0;
							if(IndexFill[2*Backup[iter] + 1] != 0)
							{
									Backup[++index] = 2*Backup[iter] + 1;
							}
							if(IndexFill[2*Backup[iter] + 2] != 0)
							{
									Backup[++index] = 2*Backup[iter] + 2;
							}
						}
					}
					else
					{
						int x = MinValue(2*i+2);
						Object tmp = items[x];
						IndexFill[i] = IndexFill[x];
						items[i] = items[x];
						Delete(tmp, x);
					}
				}
			}
		}

		~BST(){
			delete [] items;
		}
};		


#endif
