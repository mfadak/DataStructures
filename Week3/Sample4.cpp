#include <iostream>
#include <ctime>
using namespace std;

int** MatrisOlustur(int satir,int sutun){
	int **matris = new int*[satir];
	for(int i=0;i<satir;i++){
		matris[i] = new int[sutun];
		for(int j=0;j<sutun;j++){
			matris[i][j] = rand()%5+1;
		}
	}
	return matris;
}
void MatrisYazdir(int** matris,int satir,int sutun){
	for(int i=0;i<satir;i++){
		cout<<"| ";
		for(int j=0;j<sutun;j++){
			cout<<matris[i][j]<<" ";
		}
		cout<<" |"<<endl;
	}
}
int** MatrisCarpim(int **matris1,int** matris2,int satir1,int satir2,int sutun2){
	int toplam=0;
	int **matrisSonuc = new int*[satir1];
	for(int i=0;i<satir1;i++){
		matrisSonuc[i] = new int[sutun2];
		for(int j=0;j<sutun2;j++){
			for(int k=0;k<satir2;k++){
				toplam = toplam + matris1[i][k] * matris2[k][j];
			}
			matrisSonuc[i][j] = toplam;
			toplam=0;
		}
	}
	return matrisSonuc;
}
void MatrisYoket(int** matris,int satir){
	for(int i=0;i<satir;i++){
		delete [] matris[i];
	}
	delete [] matris;
}

int main(){
	srand(time(NULL));
	int **A = MatrisOlustur(3,4);
	int **B = MatrisOlustur(4,3);
	cout<<"A:"<<endl;
	MatrisYazdir(A,3,4);
	cout<<"\nB:"<<endl;
	MatrisYazdir(B,4,3);
	int** sonuc = MatrisCarpim(A,B,3,4,3);
	cout<<"\nAxB:"<<endl;
	MatrisYazdir(sonuc,3,3);
	
	MatrisYoket(A,3);
	MatrisYoket(B,4);
	MatrisYoket(sonuc,3);
	return 0;
}
