
#ifndef MAGIC_NO
#define MAGIC_NO 'K'
#endif

#ifndef RESETDEVICE
#define RESETDEVICE _IO(MAGIC_NO,0)
#endif

#ifndef GETREGSIZE
#define GETREGSIZE _IOR(MAGIC_NO,1,int)
#endif

#ifndef GETNOREG
#define GETNOREG _IOR(MAGIC_NO,2,int)
#endif

#ifndef GETDATASIZE
#define GETDATASIZE _IOR(MAGIC_NO,3,int)
#endif

#ifndef SETREGSIZE
#define SETREGSIZE _IOW(MAGIC_NO,4,int)
#endif

#ifndef SETNOREG
#define SETNOREG _IOW(MAGIC_NO,5,int)
#endif

//we can also declare a struct with all these parameters togther and pass/extract that instead


