#include <windows.h>
#include <stdio.h>
#include <string>
#include <sstream>
#include <iostream>
#include <stdlib.h>
#include <cmath>
#include <fstream>
#include <sys/stat.h>
#include <memory.h>
#include <fcntl.h>
#include <stdio.h>
#include <io.h>
using namespace std;
int Print();
#pragma pack(push, 1)
typedef struct PART
{
  BYTE  ActFlag;
  BYTE  Begin_Hd;
  WORD  Begin_SecTrk;
  BYTE  SysCode;
  BYTE  End_Hd;
  WORD  End_SecTrk;
  DWORD RelSec; 
  DWORD Size;
};


typedef struct MBR
{
  BYTE        LoadCode[0x1BE];
  struct PART rt[4];
  WORD        EndFlag;
};
void PrintMBR(MBR mbr);
int Print2(string Patch);
void PrintMBR2(MBR mbr);
#pragma pack(pop)
int BinaryStringToDecimal(string a);
int main(){
  SetConsoleOutputCP(1251);
  SetConsoleCP(1251);
  Print();
  Print2("F:\\GPT1.txt");
  Print2("F:\\GPT2.txt");
 // Print2("F:\\GPT3.txt");
}

int Print()
{

  SetConsoleOutputCP(1251);
  SetConsoleCP(1251);
  HANDLE hDrive = CreateFile("\\\\.\\PhysicalDrive1", GENERIC_READ,
                              FILE_SHARE_READ | FILE_SHARE_WRITE, 0,
                              OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, 0);
  if (INVALID_HANDLE_VALUE == hDrive)
    fprintf(stderr, "CreateFile failed 0x%08X\n", GetLastError());
  else
  {
    struct MBR mbr;
    DWORD      NumberOfBytesRead = 0;

    RtlZeroMemory(&mbr, sizeof(mbr));
    if (0 == ReadFile(hDrive, &mbr, sizeof(mbr), &NumberOfBytesRead, 0))
      fprintf(stderr, "ReadFile failed 0x%08X\n", GetLastError());
    else if (sizeof(mbr) != NumberOfBytesRead)
      fprintf(stderr, "sizeof(mbr) = 0x%08X, ReadFile read 0x%08X\n",
        sizeof(mbr), NumberOfBytesRead);
    	else
    	{
        PrintMBR(mbr);
    	CloseHandle(hDrive);
  		}
	}
  return 0;

}




int BinaryStringToDecimal(string a)
{
    int num = 0;
    bool neg = false;
    if(a.at(0) == '1')
    {
        
    	for(int x = a.length()-1; x >= 0; x--)
        {
            if(a.at(x) == '2')
            {
                if(x-1 >= 0)
                {
                    if(a.at(x-1) == '1')
                        a.at(x-1) = '2';
                    if(a.at(x-1) == '0')
                        a.at(x-1) = '1';
                    a.at(x) = '0';
                }
            }
            else if(a.at(x) == '3')
            {
                if(x-1 >= 0)
                    a.at(x-1) += '2';
                a.at(x) = '1';
            }
        }
        if(a.at(0) == '2')
            a.at(0) = '0';
        else if(a.at(0) == '3')
            a.at(0) = '1';
    }
    for(int x = a.length()-1; x >= 0; x--)
    {
        if(a.at(x) == '1')
            num += pow(2.0, a.length()-x-1);
    }
    if(neg)
        num = num*-1;   
    return num;
 }



void PrintMBR(MBR mbr)
{
	fprintf(stdout, "Основная запись MBR\n");
	for (int j = 0; j < 4; j++){      
	    
        std::string CylH="",CylK="",CylSecS="",CylSecK="",SecH="",SecK="";
      	int Mass[16];
      	int k=0;
      	DWORD bayt=mbr.rt[j].Begin_SecTrk;
      	for(int g=0;g<16;g++){
      		Mass[k]=(bayt>>g)&1;
      		k++;
      	} 
      	for(int g=0;g<16;g++){
      		stringstream ss;
      		ss << Mass[g];
			string str = ss.str();
      		CylSecS=str+CylSecS;
      	}
      	for(int g=0;g<6;g++){
      		stringstream ss;
      		ss << Mass[g];
			string str = ss.str();
      		SecH=str+SecH;
      	}
      	for(int g=8;g<16;g++){
      		stringstream ss;
      		ss << Mass[g];
			string str = ss.str();
      		CylH=str+CylH;
      	}
      	for(int g=6;g<8;g++){
      		stringstream ss;
      		ss << Mass[g];
			string str = ss.str();
      		CylH=str+CylH;
      	}
      	bayt=mbr.rt[j].End_SecTrk;
      	k=0;
		for(int g=0;g<16;g++){
      		Mass[k]=(bayt>>g)&1;
      		k++;
      	} 
      	
      	
      	for(int g=0;g<16;g++){
      		stringstream ss;
      		ss << Mass[g];
			string str = ss.str();
      		CylSecK=str+CylSecK;
      	}
      	for(int g=0;g<6;g++){
      		stringstream ss;
      		ss << Mass[g];
			string str = ss.str();
      		SecK=str+SecK;
      	}
      	for(int g=8;g<16;g++){
      		stringstream ss;
      		ss << Mass[g];
			string str = ss.str();
      		CylK=str+CylK;
      	}
      	for(int g=6;g<8;g++){
      		stringstream ss;
      		ss << Mass[g];
			string str = ss.str();
      		CylK=str+CylK;
      	}      	
        fprintf(stdout, "Раздел %d\n"
                        "  Признак активности                  = 0x%02X = %d \n"
                        "  Номер поверхности начала            = 0x%02X = %d \n"
                        "  Номер цилиндра начала               = %sb = %d \n"
                        "  Номер сектора начала                = %sb = %d \n"
                        "  CHS начала раздела                  = (%d, %d, %d) \n"
                        "  Двухбайтное поле цилиндра и сектора = 0x%04X = %sb \n"
                        "  Системный код типа раздела          = 0x%02X = %d\n"
                        "  Номер поверхности конца             = 0x%02X = %d\n"
                        "  Номер цилиндра конца                = %sb = %d \n"
                        "  Номер сектора конца                 = %sb = %d \n"
                        "  CHS конца раздела                   = (%d, %d, %d) \n"
                        "  Двухбайтное поле цилиндра и сектора = 0x%04X = %sb \n"
                        "  LBA                                 = 0x%08X = %d\n"
                        "  Размер                              = 0x%08X = %d\n\n",
          j+1,
          mbr.rt[j].ActFlag, 		mbr.rt[j].ActFlag,
          mbr.rt[j].Begin_Hd, 		mbr.rt[j].Begin_Hd,
          CylH.c_str(),	 			BinaryStringToDecimal(CylH),
          SecH.c_str(),				BinaryStringToDecimal(SecH),
          BinaryStringToDecimal(CylH),mbr.rt[j].Begin_Hd,BinaryStringToDecimal(SecH),
          mbr.rt[j].Begin_SecTrk, 	CylSecS.c_str(),
          mbr.rt[j].SysCode, 		mbr.rt[j].SysCode,
          mbr.rt[j].End_Hd, 		mbr.rt[j].End_Hd,
          CylK.c_str(),	 			BinaryStringToDecimal(CylK),
          SecK.c_str(),				BinaryStringToDecimal(SecK),
          BinaryStringToDecimal(CylK),mbr.rt[j].End_Hd,BinaryStringToDecimal(SecK),
          mbr.rt[j].End_SecTrk, 	CylSecK.c_str(),
          mbr.rt[j].RelSec, 		mbr.rt[j].RelSec, 
          mbr.rt[j].Size, 			mbr.rt[j].Size);
    }
}



int Print2(string Patch)
{
  	SetConsoleOutputCP(1251);
	SetConsoleCP(1251);
    struct MBR mbr;
    DWORD      NumberOfBytesRead = 0;

    RtlZeroMemory(&mbr, sizeof(mbr));
    ifstream fin(Patch.c_str());
    fin.read((char*)&mbr, sizeof(mbr));
  
	PrintMBR2(mbr);
 	return 0;
}

void PrintMBR2(MBR mbr)
{
	fprintf(stdout, "ERP таблица\n");
	for (int j = 0; j < 2; j++){      
	    
        std::string CylH="",CylK="",CylSecS="",CylSecK="",SecH="",SecK="";
      	int Mass[16];
      	int k=0;
      	DWORD bayt=mbr.rt[j].Begin_SecTrk;
      	for(int g=0;g<16;g++){
      		Mass[k]=(bayt>>g)&1;
      		k++;
      	} 
      	for(int g=0;g<16;g++){
      		stringstream ss;
      		ss << Mass[g];
			string str = ss.str();
      		CylSecS=str+CylSecS;
      	}
      	for(int g=0;g<6;g++){
      		stringstream ss;
      		ss << Mass[g];
			string str = ss.str();
      		SecH=str+SecH;
      	}
      	for(int g=8;g<16;g++){
      		stringstream ss;
      		ss << Mass[g];
			string str = ss.str();
      		CylH=str+CylH;
      	}
      	for(int g=6;g<8;g++){
      		stringstream ss;
      		ss << Mass[g];
			string str = ss.str();
      		CylH=str+CylH;
      	}
      	bayt=mbr.rt[j].End_SecTrk;
      	k=0;
		for(int g=0;g<16;g++){
      		Mass[k]=(bayt>>g)&1;
      		k++;
      	} 
      	
      	
      	for(int g=0;g<16;g++){
      		stringstream ss;
      		ss << Mass[g];
			string str = ss.str();
      		CylSecK=str+CylSecK;
      	}
      	for(int g=0;g<6;g++){
      		stringstream ss;
      		ss << Mass[g];
			string str = ss.str();
      		SecK=str+SecK;
      	}
      	for(int g=8;g<16;g++){
      		stringstream ss;
      		ss << Mass[g];
			string str = ss.str();
      		CylK=str+CylK;
      	}
      	for(int g=6;g<8;g++){
      		stringstream ss;
      		ss << Mass[g];
			string str = ss.str();
      		CylK=str+CylK;
      	}      	
        fprintf(stdout, "Раздел %d\n"
                        "  Признак активности                  = 0x%02X = %d \n"
                        "  Номер поверхности начала            = 0x%02X = %d \n"
                        "  Номер цилиндра начала               = %sb = %d \n"
                        "  Номер сектора начала                = %sb = %d \n"
                        "  CHS начала раздела                  = (%d, %d, %d) \n"
                        "  Двухбайтное поле цилиндра и сектора = 0x%04X = %sb \n"
                        "  Системный код типа раздела          = 0x%02X = %d\n"
                        "  Номер поверхности конца             = 0x%02X = %d\n"
                        "  Номер цилиндра конца                = %sb = %d \n"
                        "  Номер сектора конца                 = %sb = %d \n"
                        "  CHS конца раздела                   = (%d, %d, %d) \n"
                        "  Двухбайтное поле цилиндра и сектора = 0x%04X = %sb \n"
                        "  LBA                                 = 0x%08X = %d\n"
                        "  Размер                              = 0x%08X = %d\n\n",
          j+1,
          mbr.rt[j].ActFlag, 		mbr.rt[j].ActFlag,
          mbr.rt[j].Begin_Hd, 		mbr.rt[j].Begin_Hd,
          CylH.c_str(),	 			BinaryStringToDecimal(CylH),
          SecH.c_str(),				BinaryStringToDecimal(SecH),
          BinaryStringToDecimal(CylH),mbr.rt[j].Begin_Hd,BinaryStringToDecimal(SecH),
          mbr.rt[j].Begin_SecTrk, 	CylSecS.c_str(),
          mbr.rt[j].SysCode, 		mbr.rt[j].SysCode,
          mbr.rt[j].End_Hd, 		mbr.rt[j].End_Hd,
          CylK.c_str(),	 			BinaryStringToDecimal(CylK),
          SecK.c_str(),				BinaryStringToDecimal(SecK),
          BinaryStringToDecimal(CylK),mbr.rt[j].End_Hd,BinaryStringToDecimal(SecK),
          mbr.rt[j].End_SecTrk, 	CylSecK.c_str(),
          mbr.rt[j].RelSec, 		mbr.rt[j].RelSec, 
          mbr.rt[j].Size, 			mbr.rt[j].Size);
    }
}

