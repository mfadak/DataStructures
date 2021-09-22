#ifndef BST_HPP
#define BST_HPP

#include <iostream>
#include <cmath>
using namespace std;

template <typename Object>
struct Node{
	Object data;
	Node<Object> *left;
	Node<Object> *right;
	
	Node(const Object& dt,Node<Object> *lf=NULL,Node<Object> *rg=NULL){
		data = dt;
		left = lf;
		right = rg;
	}
};

template <typename Object>
class BST{
	private:	
		Node<Object> *root;
		
		void SearchAndAdd(Node<Object> *&subNode,const Object& newItem){
			if(subNode == NULL) subNode = new Node<Object>(newItem);
			else if(newItem < subNode->data)
				SearchAndAdd(subNode->left,newItem);
			else if(newItem > subNode->data)
				SearchAndAdd(subNode->right,newItem);
			else return;
		}
		bool SearchAndDelete(Node<Object> *&subNode,const Object& data){
			if(subNode == NULL) return false;
			if(subNode->data == data) return DeleteNode(subNode);
			else if(data < subNode->data) return SearchAndDelete(subNode->left,data);
			else return SearchAndDelete(subNode->right,data);
		}
		bool DeleteNode(Node<Object> *&subNode){
			Node<Object> *DelNode = subNode;
			
			if(subNode->right == NULL) subNode = subNode->left;
			else if(subNode->left == NULL) subNode = subNode->right;
			else{
				DelNode = subNode->left;
				Node<Object> *parent = subNode;
				while(DelNode->right != NULL){
					parent = DelNode;
					DelNode = DelNode->right;
				}
				subNode->data = DelNode->data;
				if(parent == subNode) subNode->left = DelNode->left;
				else parent->right = DelNode->left;
			}
			delete DelNode;
			return true;
		}
		void inorder(Node<Object> *subNode){
			if(subNode != NULL){
				inorder(subNode->left);
				cout<<subNode->data<<" ";
				inorder(subNode->right);
			}
		}
		void preorder(Node<Object> *subNode){
			if(subNode != NULL){
				cout<<subNode->data<<" ";
				preorder(subNode->left);
				preorder(subNode->right);
			}
		}
		void postorder(Node<Object> *subNode){
			if(subNode != NULL){
				postorder(subNode->left);
				postorder(subNode->right);
				cout<<subNode->data<<" ";
			}
		}
		
		int Height(Node<Object> *subNode){
			if(subNode == NULL) return -1;
			return 1+max(Height(subNode->left),Height(subNode->right));
		}
		void PrintLevel(Node<Object> *subNode,int level){
			if(subNode == NULL) return;
			if(level == 0) cout<<subNode->data<<" ";
			else{
				PrintLevel(subNode->left,level-1);
				PrintLevel(subNode->right,level-1);
			}
		}
		bool Search(Node<Object> *subNode,const Object& item){
			if(subNode == NULL) return false;
			if(subNode->data == item) return true;
			if(item < subNode->data) return Search(subNode->left,item);
			else return Search(subNode->right,item);
		}
	public:
		BST(){
			root = NULL;
		}
		bool isEmpty()const{
			return root == NULL;
		}
		void Add(const Object& newItem){
			SearchAndAdd(root,newItem);
		}
		void Delete(const Object &data){
			if(SearchAndDelete(root,data) == false) throw "Item not found.";
		}
		void inorder(){
			inorder(root);
		}
		void preorder(){
			preorder(root);
		}
		void postorder(){
			postorder(root);
		}
		void levelorder(){
			int h = Height();
			for(int level=0;level<=h;level++){
				PrintLevel(root,level);
			}
		}
		int Height(){
			return Height(root);
		}
		bool Search(const Object& item){
			return Search(root,item);
		}
		void Clear(){
			while(!isEmpty()) DeleteNode(root);
		}
		~BST(){
			Clear();
		}
};


#endif
