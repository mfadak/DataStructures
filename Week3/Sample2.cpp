#include <iostream>
using namespace std;
class Kisi{
  private:
    string isim;
    int yas;
  public:
    Kisi(string ism){
      isim=ism;
      yas=0;
    }
};
int main(){
  Kisi **kisiler = new Kisi*[10];
  for(int i=0;i<10;i++) kisiler[i] = new Kisi("Mehmet");
  for(int i=0;i<10;i++) delete kisiler[i];
  return 0;
}
