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
        if ((HB1 == 0) && (HB2 == 0) && (SB0 == 0)&& ((SB1>>4) == 0)){
            long CTS = (SB1<<16)|(SB2<<8)|SB3;
            long N = (SB4<< 16)|(SB5<<8)|SB6;
            cout<<"CTS: "<< CTS <<endl;
            cout<<"N: "<< N <<endl;
        }
        else{
            cout<<"invalid"<<endl;
        }
        break;
    case 0x02:
        pflag=Packet_type(HB0);
        cout<<"packet type: "<<arr_type[pflag]<<endl;
        if ((HB1>>5) == 0){
              long layout = HB1&0x10;
              long spX = HB1&0xF;
              long sfX = HB2&0xF;
              long B = HB2&(0xF0);
              long L = (SB0<<4)|(SB1<<12)|(SB2<<20);
              long R = (SB3<<4)|(SB4<<12)|(SB5<<20);
              long Vl =(SB6&0x01);
              long Vr =(SB6&0x10);
              long Ul =(SB6&0x02);
              long Ur =(SB6&0x20);
              long Cl =(SB6&0x04);
              long Cr =(SB6&0x40);
              long Pl =(SB6&0x08);
              long Pr =(SB6&0x80);

              cout<<"layout: "<<layout<<endl;
              cout<<"sample_present.spX: "<<spX<<endl;
              cout<<"sample_flat.spX: "<<sfX<<endl;
              cout<<"B: "<<B<<endl;
              cout<<"L: "<<L<<endl;
              cout<<"R: "<<R<<endl;
              cout<<"Vl: "<<Vl<<endl;
              cout<<"Vr: "<<Vr<<endl;
              cout<<"Ul: "<<Ul<<endl;
              cout<<"Ur: "<<Ur<<endl;
              cout<<"Cl: "<<Cl<<endl;
              cout<<"Cr: "<<Cr<<endl;
              cout<<"Pl: "<<Pl<<endl;
              cout<<"Pr: "<<Pr<<endl;
         }
        else{
            cout<<"invalid"<<endl;
        }
        break;
    case 0x03:
        pflag=Packet_type(HB0);
        cout<<"packet type: "<<arr_type[pflag]<<endl;
         if ((HB1 == 0) && (HB2 == 0) && ((SB0&0xEE)==0) && ((SB2>>1)==0) && (SB3 == 0) && (SB4 == 0) && (SB5 == 0) && (SB6 == 0)){
             long setAVMUTE = (SB0&0x01);
             long clearAVMUTE = (SB0&0x10);
             long PP = (SB1)&(0xF0);
             long CD = (SB1&0xF);
             long defaultPhase = (SB2&0x01);
             cout<<"Set_AVMUTE: "<<setAVMUTE<<endl;
             cout<<"Clear_AVMUTE: "<<clearAVMUTE<<endl;
             cout<<"PP: "<<PP<<endl;
             cout<<"CD: "<<CD<<endl;
             cout<<"Default_Phase: "<<defaultPhase<<endl;
         }
        break;
    case 0x04:
        pflag=Packet_type(HB0);
        cout<<"packet type: "<<arr_type[pflag]<<endl;
        if (HB0 == 0x04){
            switch (HB1) {
            case 0x00:
                cout<<"ACP_Type: Generic Audio"<<endl;
                break;
            case 0x01:
                cout<<"ACP_Type: IEC 60958-Identified Audio"<<endl;
                break;
            case 0x02:
                cout<<"ACP_Type: DVD-Audio"<<endl;
                break;
            case 0x03:
                cout<<"ACP_Type: Super Audio CD"<<endl;
                break;
            default:
                cout<<"*reserved*"<<endl;
                break;
            }

        }
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
