int* DiziOlusturSifirla(int uzunluk){
  int *sayilar = new int[uzunluk];
  for(int i=0;i<uzunluk;i++){
    sayilar[i]=0;
  }
  return sayilar;
}
int main(){
  int uzunluk;
  cout<<"Dizi Uzunlugu:";
  cin>>uzunluk;
  int *p = DiziOlusturSifirla(uzunluk);
  cout<<p[1];
  delete p;
  return 0;
}
