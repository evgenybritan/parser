#include <fstream>
#include <iostream>
#include <stdlib.h>

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

const char *iftype[]= {  "Vendor Specific InfoFrame",
                         "AVI InfoFrame",
                         "Source Product Descriptor InfoFrame",
                         "Audio InfoFrame",
                         "MPEG Source InfoFrame"
                        };
int main() {
    
    int HB0=0;
    int HB1=0;
    int HB2=0;
    int SB0=0;
    int SB1=0;
    int SB2=0;


    ifstream in("D:\\Evgeny\\txt\\1.txt",ios::binary|ios::in);
      in.read((char*)&HB0,sizeof HB0);
      in.read((char*)&HB1,sizeof HB1);
      in.read((char*)&HB2,sizeof HB2);
      in.read((char*)&SB0,sizeof SB0);
      in.read((char*)&SB1,sizeof SB1);
      in.read((char*)&SB2,sizeof SB2);
    in.close();
    int k = HB0-129;
    Packet_type pflag;



    switch (HB0) {
    case 0x00:
        pflag=Packet_type(HB0);
        cout<<"packet type: "<<arr_type[pflag]<<endl;
        break;
    case 0x01:
        pflag=Packet_type(HB0);
        cout<<"packet type: "<<arr_type[pflag]<<endl;
        if ((HB1 == 0) || (HB2 == 0)){

        }
        break;
    case 0x02:
        pflag=Packet_type(HB0);
        cout<<"packet type: "<<arr_type[pflag]<<endl;
        break;
    case 0x03:
        pflag=Packet_type(HB0);
        cout<<"packet type: "<<arr_type[pflag]<<endl;
        break;
    case 0x04:
        pflag=Packet_type(HB0);
        cout<<"packet type: "<<arr_type[pflag]<<endl;
        break;
    case 0x05:
        pflag=Packet_type(HB0);
        cout<<"packet type: "<<arr_type[pflag]<<endl;
        break;
    case 0x06:
        pflag=Packet_type(HB0);
        cout<<"packet type: "<<arr_type[pflag]<<endl;
        break;
    case 0x07:
        pflag=Packet_type(HB0);
        cout<<"packet type: "<<arr_type[pflag]<<endl;
        break;
    case 0x08:
        pflag=Packet_type(HB0);
        cout<<"packet type: "<<arr_type[pflag]<<endl;
        break;
    case 0x09:
        pflag=Packet_type(HB0);
        cout<<"packet type: "<<arr_type[pflag]<<endl;
        break;
    case 0x0A:
        pflag=Packet_type(HB0);
        cout<<"packet type: "<<arr_type[pflag]<<endl;
        break;
    case 0x80 :
        pflag=Packet_type(11);
        cout<<"packet type: "<<arr_type[pflag]<<endl;
        break;
    case 0x81 :
        pflag=Packet_type(11);
        cout<<"packet type: "<<arr_type[pflag]<<endl;
        break;
    case 0x82 :
        pflag=Packet_type(11);
        cout<<"packet type: "<<arr_type[pflag]<<endl;
        break;
    case 0x83 :
        pflag=Packet_type(11);
        cout<<"packet type: "<<arr_type[pflag]<<endl;
        break;
    case 0x84 :
        pflag=Packet_type(11);
        cout<<"packet type: "<<arr_type[pflag]<<endl;
        break;
    case 0x85 :
        pflag=Packet_type(11);
        cout<<"packet type: "<<arr_type[pflag]<<endl;
        break;
    default:
        cerr<<"invalid byte"<<endl;

        break;
    }
    switch (HB0) {
    case 0x81:
            cout<<"InfoFrame type: "<<iftype[k]<<endl;
            break;
    case 0x82:
            cout<<"InfoFrame type: "<<iftype[k]<<endl;
            break;
    case 0x83:
            cout<<"InfoFrame type: "<<iftype[k]<<endl;
            break;
    case 0x84:                      
            cout<<"InfoFrame type: "<<iftype[k]<<endl;
            break;
    case 0x85:           
            cout<<"InfoFrame type: "<<iftype[k]<<endl;
            break;
    default:
        break;
    }

}
