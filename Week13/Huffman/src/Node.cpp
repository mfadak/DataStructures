#include "Node.hpp"

Node::Node(char ch,int frq,Node *lf,Node *rg){
	chracter = ch;
	freq = frq;
	left = lf;
	right = rg;
	code="";
}
bool Node::isLeaf()const{
	return left == NULL && right == NULL;
}
bool Node::operator==(Node& rgt){
	return this->chracter == rgt.chracter;
}
bool Node::operator!=(Node& rgt){
	return this->chracter == rgt.chracter;
}
bool Node::operator>(Node& rgt){
	return this->freq > rgt.freq;
}
