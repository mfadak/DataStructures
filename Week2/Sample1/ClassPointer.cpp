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
  Sayi *s1,*s2,s3;
  s1 = &s3;
  s2 = &s3;
  cout<<*s1<<endl;
  cout<<*s2<<endl;
  cout<<s3<<endl;
  return 0;
}
