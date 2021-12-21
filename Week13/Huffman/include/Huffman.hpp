#include "Node.hpp"
#include <fstream>
#include <cstring>

class Huffman{
	private:
		Node* root;
		int symbols;
		string input;
		
		Node* CreateTree(int freq[]);
		void AssignCodes(Node*,string);
		int MinNodeIndex(Node* trees[]);
		void ReadFile(string);
		void inorder(Node*);
		void RemoveNode(Node*&);
		
	public:
		Huffman(string);
		void Encode();
		friend ostream& operator<<(ostream&,Huffman&);
		~Huffman();
};
