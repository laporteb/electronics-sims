// Automatically generated C++ file on Sat Dec 16 08:24:57 2023
//
// To build with Digital Mars C++ Compiler:
//
//    dmc -mn -WD controlsignals.cpp kernel32.lib

#include <malloc.h>

union uData
{
   bool b;
   char c;
   unsigned char uc;
   short s;
   unsigned short us;
   int i;
   unsigned int ui;
   float f;
   double d;
   long long int i64;
   unsigned long long int ui64;
   char *str;
   unsigned char *bytes;
};

// int DllMain() must exist and return 1 for a process to load the .DLL
// See https://docs.microsoft.com/en-us/windows/win32/dlls/dllmain for more information.
int __stdcall DllMain(void *module, unsigned int reason, void *reserved) { return 1; }

void bzero(void *ptr, unsigned int count)
{
   unsigned char *first = (unsigned char *) ptr;
   unsigned char *last  = first + count;
   while(first < last)
      *first++ = '\0';
}

// #undef pin names lest they collide with names in any header file(s) you might include.
#undef TRI
#undef MotorU
#undef MotorV
#undef MotorW
#undef GateS1
#undef GateS2
#undef GateS3
#undef GateS4
#undef GateS5
#undef GateS6

struct sCONTROLSIGNALS
{
  // declare the structure here
};

extern "C" __declspec(dllexport) void controlsignals(struct sCONTROLSIGNALS **opaque, double t, union uData *data)
{
   double TRI    = data[ 0].d; // input
   double MotorU = data[ 1].d; // input
   double MotorV = data[ 2].d; // input
   double MotorW = data[ 3].d; // input
   bool  &GateS1 = data[4].b; // output
   bool  &GateS2 = data[5].b; // output
   bool  &GateS3 = data[6].b; // output
   bool  &GateS4 = data[7].b; // output
   bool  &GateS5 = data[8].b; // output
   bool  &GateS6 = data[9].b; // output

   if(!*opaque)
   {
      *opaque = (struct sCONTROLSIGNALS *) malloc(sizeof(struct sCONTROLSIGNALS));
      bzero(*opaque, sizeof(struct sCONTROLSIGNALS));
   }
   struct sCONTROLSIGNALS *inst = *opaque;

// Implement module evaluation code here:

   if (MotorU >= TRI){
      GateS1 = 0;
      GateS2 = 1;
   }
   else{
      GateS1 = 1;
      GateS2 = 0;
   }

   if (MotorV >= TRI){
      GateS3 = 0;
      GateS4 = 1;
   }
   else{
      GateS3 = 1;
      GateS4 = 0;
   }

   if (MotorW >= TRI){
      GateS5 = 0;
      GateS6 = 1;
   }
   else{
      GateS5 = 1;
      GateS6 = 0;
   }

}

extern "C" __declspec(dllexport) void Destroy(struct sCONTROLSIGNALS *inst)
{
   free(inst);
}
