#include <fstream>
#include <iostream>
#include <stdlib.h>

using namespace std;

enum type{
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
  Gamut_Metadata_Packet
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
                         "Gamut Metadata Packet"
                        };


int main() {
    int HB0=0;
    int HB1=0;
    ifstream in("D:\\Evgeny\\txt\\1.txt",ios::binary|ios::in);
      in.read((char*)&HB0,sizeof HB0);
      in.read((char*)&HB1,sizeof HB1);
    in.close();
    type flag;


    switch (HB0) {
    case 0x00:
        flag=type(HB0);
        cout<<"packet type: "<<arr_type[flag]<<endl;
        break;
    case 0x01:
        flag=type(HB0);
        cout<<"packet type: "<<arr_type[flag]<<endl;
        break;
    case 0x02:
        flag=type(HB0);
        cout<<"packet type: "<<arr_type[flag]<<endl;
        break;
    case 0x03:
        flag=type(HB0);
        cout<<"packet type: "<<arr_type[flag]<<endl;
        break;
    case 0x04:
        flag=type(HB0);
        cout<<"packet type: "<<arr_type[flag]<<endl;
        break;
    case 0x05:
        flag=type(HB0);
        cout<<"packet type: "<<arr_type[flag]<<endl;
        break;
    case 0x06:
        flag=type(HB0);
        cout<<"packet type: "<<arr_type[flag]<<endl;
        break;
    case 0x07:
        flag=type(HB0);
        cout<<"packet type: "<<arr_type[flag]<<endl;
        break;
    case 0x08:
        flag=type(HB0);
        cout<<"packet type: "<<arr_type[flag]<<endl;
        break;
    case 0x09:
        flag=type(HB0);
        cout<<"packet type: "<<arr_type[flag]<<endl;
        break;
    case 0x0A:
        flag=type(HB0);
        cout<<"packet type: "<<arr_type[flag]<<endl;
        break;
    default:
        cerr<<"invalid byte"<<endl;
        break;
    }

}
