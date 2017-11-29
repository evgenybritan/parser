#include <fstream>
#include <iostream>
#include <stdlib.h>

using namespace std;

int main() {
    int HB0=0;
    int HB1=0;
    ifstream in("D:\\Evgeny\\txt\\1.txt",ios::binary|ios::in);
      in.read((char*)&HB0,sizeof HB0);
      in.read((char*)&HB1,sizeof HB1);
    in.close();

    enum type {
      Null , ACR, Audio_Sample
    };


    switch (HB0) {
    case 0x00:
        cout<<"packet type: "<< "Null" <<endl;
        break;
    case 0x01:
        cout<<"packet type: "<<"ACR"<<endl;
        break;
    case 0x02:
        cout<<"packet type: "<<"Audio Sample"<<endl;
        break;

    default:
        cerr<<"invalid byte"<<endl;
        break;
    }
    switch (HB1) {
    case 0x00:
        cout<<"packet-specific data: "<<"404"<<endl;
        break;
    case 1:
        cout<<"packet-specific data: "<<"505"<<endl;
        break;
    default:
        cerr<<"invalid byte"<<endl;
        break;
    }

}
