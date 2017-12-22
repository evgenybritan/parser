#include <stdlib.h>
#include <iostream>
#include <fstream>


using namespace std;

int main()
{
    int HB0=0;
    int HB1=0;
    int HB2=0;
    int SB0=0;
    int SB1=0;
    int SB2=0;
    int SB3=0;
    int SB4=0;
    int SB5=0;
    int SB6=0;

 cout<<"HB0 = ";
 cin>>HB0;
 cout<<"HB1 = ";
 cin>>HB1;
 cout<<"HB2 = ";
 cin>>HB2;
 cout<<"SB0 = ";
 cin>>SB0;
 cout<<"SB1 = ";
 cin>>SB1;
 cout<<"SB2 = ";
 cin>>SB2;
 cout<<"SB3 = ";
 cin>>SB3;
 cout<<"SB4 = ";
 cin>>SB4;
 cout<<"SB5 = ";
 cin>>SB5;
 cout<<"SB6 = ";
 cin>>SB6;
 ofstream out("E:\\test_files\\parser1.txt",ios::binary|ios::out);
   out.write((char*)&HB0,sizeof HB0);
   out.write((char*)&HB1,sizeof HB1);
   out.write((char*)&HB2,sizeof HB0);
   out.write((char*)&SB0,sizeof SB0);
   out.write((char*)&SB1,sizeof SB1);
   out.write((char*)&SB2,sizeof SB2);
   out.write((char*)&SB3,sizeof SB3);
   out.write((char*)&SB4,sizeof SB4);
   out.write((char*)&SB5,sizeof SB5);
   out.write((char*)&SB6,sizeof SB6);


 out.close();

 return(0);
}
