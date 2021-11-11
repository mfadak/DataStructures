#include "BaseConverter.hpp"

int main(){
	BaseConverter *bc = new BaseConverter();
	cout<<*bc;
	delete bc;
	return 0;
}
