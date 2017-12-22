#include <fstream>
#include <iostream>
#include <stdlib.h>
#include <QString>



using namespace std;

enum Packet_type{
                         Null ,
                         Audio_Clock_Regeneration,
                         Audio_Sample,
                         General_Control,
                         ACP_Packet,
                         ISRC1_Packet,
                         ISRC2_Packet,
                         One_Bit_Audio_Sample_Packet,
                         DST_Audio_Packet,
                         High_Bitrate_Audio_Stream_Packet,
                         Gamut_Metadata_Packet,
                         InfoFrame_Packet

};

const char *arr_type[]= {"Null",
                         "Audio Clock Regeneration",
                         "Audio Sample",
                         "General Control",
                         "ACP Packet",
                         "ISRC1 Packet",
                         "ISRC2 Packet",
                         "One Bit Audio Sample Packet",
                         "DST Audio Packet",
                         "High Bitrate (HBR) Audio Stream Packet (IEC 61937)",
                         "Gamut Metadata Packet",
                         "InfoFrame Packet"
};

const char *iftype[]= {  "none",
                         "Vendor Specific InfoFrame",
                         "AVI InfoFrame",
                         "Source Product Descriptor InfoFrame",
                         "Audio InfoFrame",
                         "MPEG Source InfoFrame"
};

int HB0;
int HB1;
int HB2;
int SB0;
int SB1;
int SB2;
int SB3;
int SB4;
int SB5;
int SB6;

int in(){
    ifstream in("E:\\test_files\\parser1.txt",ios::binary|ios::in);
      in.read((char*)&HB0,sizeof HB0);
      in.read((char*)&HB1,sizeof HB1);
      in.read((char*)&HB2,sizeof HB2);
      in.read((char*)&SB0,sizeof SB0);
      in.read((char*)&SB1,sizeof SB1);
      in.read((char*)&SB2,sizeof SB2);
      in.read((char*)&SB3,sizeof SB3);
      in.read((char*)&SB4,sizeof SB4);
      in.read((char*)&SB5,sizeof SB5);
      in.read((char*)&SB6,sizeof SB6);
    in.close();
return(0);
}



//void name(){
//    in();
//    if (((HB0 >0x0A) && (HB0<0x80) )||(HB0>0x85)){
//       cout<<"invalid "<<endl;
//}
//    else{
//        if (HB0 <0x80){
//        string name = arr_type[HB0];
//        cout<<"packet type: "<<name<<endl;
//        }
//        else{
//        string name = arr_type[11];
//        cout<<"packet type: "<<name<<endl;
//        int k=HB0 - 128;
//        cout<<"InfoFrame type: "<<iftype[k]<<endl;
//        }
//    }
//}
class Packet{
public:
     parse();
     print();
};

string pname;

class Null: public Packet{
public:

    void  parse() {
      pname = arr_type[HB0];
           return(0); }
    print() {
        cout<< "packet type: " << pname<< endl;
          return(0);  }

};

int main(){
    Packet p;

    switch(HB0)
    {
        case 0x00:
        p = new class Null();
        break;
    default:
        break;
    }

    p.parse();
    p.print();

}
