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
    int SB3=0;
    int SB4=0;
    int SB5=0;
    int SB6=0;


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
        if ((HB1 == 0) && (HB2 == 0) && (SB0 == 0)){
            long CTS = (SB1<<16)|(SB2<<8)|SB3;
            long N = (SB4<< 16)|(SB5<<8)|SB6;
            cout<<"CTS: "<< CTS <<endl;
            cout<<"N: "<< N <<endl;
        }
        break;
    case 0x02:
        pflag=Packet_type(HB0);
        cout<<"packet type: "<<arr_type[pflag]<<endl;
        if (HB0 == 0x02){
              long layout = (HB1>>4);
              long sp0 = (HB1<<0)|(HB1<<1)|(HB1<<2)|(HB1<<3);
              long sp1 = (HB1<<4)>>4;
              long sp2 = (HB1>>2);
              long sp3 = (HB1>>3);
              long sf0 = (HB2>>0);
              long sf1 = (HB2>>1);
              long sf2 = (HB2>>2);
              long sf3 = (HB2>>3);
              long B0 = (HB2>>4);
              long B1 = (HB2>>5);
              long B2 = (HB2>>6);
              long B3 = (HB2>>7);
              cout<<"layout: "<<layout<<endl;
              cout<<"sample_present.sp0: "<<sp0<<endl;
              cout<<"sample_present.sp1: "<<sp1<<endl;
              cout<<"sample_present.sp2: "<<sp2<<endl;
              cout<<"sample_present.sp3: "<<sp3<<endl;
              cout<<"sample_flat.sp0: "<<sf0<<endl;
              cout<<"sample_flat.sp1: "<<sf1<<endl;
              cout<<"sample_flat.sp2: "<<sf2<<endl;
              cout<<"sample_flat.sp3: "<<sf3<<endl;
              cout<<"B: "<<B0<<endl;
              cout<<"B: "<<B1<<endl;
              cout<<"B: "<<B2<<endl;
              cout<<"B: "<<B3<<endl;
         }
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
