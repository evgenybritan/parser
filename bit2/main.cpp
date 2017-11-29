#include <stdlib.h>
#include <iostream>
#include <fstream>

using namespace std;

int main()
{
 int HB0=0;
 int HB1=0;

 cout<<"HB0 = ";
 cin>>HB0;
 cout<<"HB1 = ";
 cin>>HB1;
 ofstream out("D:\\Evgeny\\txt\\1.txt",ios::binary|ios::out);
   out.write((char*)&HB0,sizeof HB0);
   out.write((char*)&HB1,sizeof HB1);
 out.close();

 return(0);
}
