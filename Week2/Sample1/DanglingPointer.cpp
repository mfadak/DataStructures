class Sayi{
  private:
    int deger;
  public:
    Sayi(int dgr){
      deger = dgr;
    }
    Sayi(){
      deger=0;
    }
    friend ostream& operator<<(ostream& ekran,Sayi& sag){
      ekran<<sag.deger<<endl;
      return ekran;
    }
};

int main(){
  Sayi *s1 = new Sayi(100);
  Sayi *s2 = s1;
  delete s1;
  Sayi *s3 = new Sayi(500);
  cout<<*s2;
  return 0;
}
