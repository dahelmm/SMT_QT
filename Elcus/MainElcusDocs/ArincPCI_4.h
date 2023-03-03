

//коды операций

#define KVP(hDevice,bufInput,nOutput,adr)	bufInput[0] =0x2;	\
			bufInput[1] = (unsigned short)adr;\
			DeviceIoControl(hDevice,DRV2K_PCI429_4_writeKOP_1,\
				bufInput, 4, NULL, 0, &nOutput, NULL)

#define KPP(hDevice,bufInput,nOutput,adr,prm)	bufInput[0] =0x3;	\
			bufInput[1] = (unsigned short)adr;\
			bufInput[2] = (unsigned short)(prm&0xffff);\
			bufInput[3] = (unsigned short)(((prm)>>16)&0xffff);\
			DeviceIoControl(hDevice,DRV2K_PCI429_4_writeKOP_3,\
				bufInput, 8, NULL, 0, &nOutput, NULL)


#define KMP(hDevice,bufInput,nOutput) bufInput[0] = 0x4;\
			DeviceIoControl(hDevice,DRV2K_PCI429_4_writeKOP_0,\
				bufInput, 2, NULL, 0, &nOutput, NULL)

#define KCB(hDevice,bufInput,nOutput,msk)	bufInput[0] = 0x5;\
			bufInput[1] = (unsigned short)msk;\
			DeviceIoControl(hDevice,DRV2K_PCI429_4_writeKOP_1,\
                bufInput, 4, NULL, 0, &nOutput, NULL)

#define KCT(hDevice,bufInput,nOutput) bufInput[0]=0x6;\
			DeviceIoControl(hDevice,DRV2K_PCI429_4_writeKOP_0,\
				bufInput, 2, NULL, 0, &nOutput, NULL)
			
	
#define KPT(hDevice,bufInput,nOutput,tmr)	bufInput[0] = 0x7; bufInput[1] = (unsigned short)tmr;\
			DeviceIoControl(hDevice,DRV2K_PCI429_4_writeKOP_1,\
			bufInput, 4, NULL, 0, &nOutput, NULL)


#define KVM0(hDevice,bufInput,nOutput)	bufInput[0] = 0x8;	\
			DeviceIoControl(hDevice,DRV2K_PCI429_4_writeKOP_0,\
			bufInput, 2, NULL, 0, &nOutput, NULL)
#define KVM1(hDevice,bufInput,nOutput)	bufInput[0] = 0x9;	\
			DeviceIoControl(hDevice,DRV2K_PCI429_4_writeKOP_0,\
			bufInput, 2, NULL, 0, &nOutput, NULL)
#define KVM2(hDevice,bufInput,nOutput)	bufInput[0] = 0xA;	\
			DeviceIoControl(hDevice,DRV2K_PCI429_4_writeKOP_0,\
			bufInput, 2, NULL, 0, &nOutput, NULL)
#define KVM3(hDevice,bufInput,nOutput)	bufInput[0] = 0xB;	\
			DeviceIoControl(hDevice,DRV2K_PCI429_4_writeKOP_0,\
			bufInput, 2, NULL, 0, &nOutput, NULL)
#define KVM4(hDevice,bufInput,nOutput)	bufInput[0] = 0xC;	\
			DeviceIoControl(hDevice,DRV2K_PCI429_4_writeKOP_0,\
			bufInput, 2, NULL, 0, &nOutput, NULL)
#define KVM5(hDevice,bufInput,nOutput)	bufInput[0] = 0xD;	\
			DeviceIoControl(hDevice,DRV2K_PCI429_4_writeKOP_0,\
			bufInput, 2, NULL, 0, &nOutput, NULL)
#define KVM6(hDevice,bufInput,nOutput)	bufInput[0] = 0xE;	\
			DeviceIoControl(hDevice,DRV2K_PCI429_4_writeKOP_0,\
			bufInput, 2, NULL, 0, &nOutput, NULL)
#define KVM7(hDevice,bufInput,nOutput)	bufInput[0] = 0xF;	\
			DeviceIoControl(hDevice,DRV2K_PCI429_4_writeKOP_0,\
			bufInput, 2, NULL, 0, &nOutput, NULL)


//безусловный спуск задания режима каналу приема

#define KP_PFA_BKP(hDevice,bufInput,nOutput,nc,ch,m_ch,ap,m_ap)	bufInput[0] =((nc-1)&0xF)+0x10;	\
			bufInput[1] = ((m_ch&1)<<15)|(ch&0x3ff);\
			bufInput[2] = (unsigned short)(((m_ap&1)<<13)|(ap&0xff));\
			DeviceIoControl(hDevice,DRV2K_PCI429_4_writeKOP_2,\
			bufInput, 6, NULL, 0, &nOutput, NULL)
#define KP_PFA_BKP2(hDevice,bufInput,nOutput,nc,ch,m_ch,ap,m_ap)	bufInput[0] =((nc-1)&0xF)+0x10;	\
			bufInput[1] = ((m_ch&1)<<15)|(0x400)|(ch&0x1ff);\
			bufInput[2] = (unsigned short)(((m_ap&1)<<13)|(ap&0xff));\
			DeviceIoControl(hDevice,DRV2K_PCI429_4_writeKOP_2,\
			bufInput, 6, NULL, 0, &nOutput, NULL)
#define KP_PFR_BKP(hDevice,bufInput,nOutput,nc,ch,m_ch)	bufInput[0] =((nc-1)&0xF)+0x10;	\
			bufInput[1] = ((m_ch&1)<<15)|(0x1000)|(ch&0x3ff);\
			DeviceIoControl(hDevice,DRV2K_PCI429_4_writeKOP_1,\
			bufInput, 4, NULL, 0, &nOutput, NULL)
#define KP_PFR_BKP2(hDevice,bufInput,nOutput,nc,ch,m_ch)	bufInput[0] =((nc-1)&0xF)+0x10;	\
			bufInput[1] = ((m_ch&1)<<15)|(0x1400)|(ch&0x1ff);\
			DeviceIoControl(hDevice,DRV2K_PCI429_4_writeKOP_1,\
			bufInput, 4, NULL, 0, &nOutput, NULL)
#define KP_PFC_BKP(hDevice,bufInput,nOutput,nc,ch,ap,m_ap)	bufInput[0] =((nc-1)&0xF)+0x10;	\
			bufInput[1] = (0x1800)|(ch&0x3ff);\
			bufInput[2] = (unsigned short)(((m_ap&1)<<13)|(ap&0xff));\
			DeviceIoControl(hDevice,DRV2K_PCI429_4_writeKOP_2,\
			bufInput, 6, NULL, 0, &nOutput, NULL)
#define KP_PFC_BKP2(hDevice,bufInput,nOutput,nc,ch,ap,m_ap)	bufInput[0] =((nc-1)&0xF)+0x10;	\
			bufInput[1] = (0x1C00)|(ch&0x1ff);\
			bufInput[2] = (unsigned short)(((m_ap&1)<<13)|(ap&0xff));\
			DeviceIoControl(hDevice,DRV2K_PCI429_4_writeKOP_2,\
			bufInput, 6, NULL, 0, &nOutput, NULL)
#define KP_PA_BKP1(hDevice,bufInput,nOutput,nc,ap,m_ap)	bufInput[0] =((nc-1)&0xF)+0x10;	\
			bufInput[1] = 0x2000;\
			bufInput[2] = (unsigned short)(((m_ap&1)<<13)|(ap&0xff));\
			DeviceIoControl(hDevice,DRV2K_PCI429_4_writeKOP_2,\
			bufInput, 6, NULL, 0, &nOutput, NULL)
#define KP_PA_BKP2(hDevice,bufInput,nOutput,nc,ap,m_ap)	bufInput[0] =((nc-1)&0xF)+0x10;	\
			bufInput[1] = 0x2400;\
			bufInput[2] = (unsigned short)(((m_ap&1)<<13)|(ap&0xff));\
			DeviceIoControl(hDevice,DRV2K_PCI429_4_writeKOP_2,\
			bufInput, 6, NULL, 0, &nOutput, NULL)
#define KP_PG(hDevice,bufInput,nOutput,nc)	bufInput[0] =((nc-1)&0xF)+0x10;	\
			bufInput[1] = 0x3000;\
			DeviceIoControl(hDevice,DRV2K_PCI429_4_writeKOP_1,\
			bufInput, 4, NULL, 0, &nOutput, NULL)



//безусловный спуск задания режима каналу выдачи

#define KV_VR_BKV(hDevice,bufInput,nOutput,nc,ch,m)	bufInput[0] =((nc-1)&0xF)+0x20;	\
			bufInput[1] = ((m&1)<<15)|(ch&0x3ff);\
			DeviceIoControl(hDevice,DRV2K_PCI429_4_writeKOP_1,\
			bufInput, 4, NULL, 0, &nOutput, NULL)
#define KV_VR_BKV2(hDevice,bufInput,nOutput,nc,ch,m)	bufInput[0] =((nc-1)&0xF)+0x20;	\
			bufInput[1] = ((m&1)<<15)|(0x400)|(ch&0x1ff);\
			DeviceIoControl(hDevice,DRV2K_PCI429_4_writeKOP_1,\
			bufInput, 4, NULL, 0, &nOutput, NULL)
#define KV_VC_BKV(hDevice,bufInput,nOutput,nc,ch,m)	bufInput[0] =((nc-1)&0xF)+0x20;	\
			bufInput[1] = ((m&1)<<15)|(0x800)|(ch&0x3ff);\
			DeviceIoControl(hDevice,DRV2K_PCI429_4_writeKOP_1,\
			bufInput, 4, NULL, 0, &nOutput, NULL)
#define KV_VC_BKV2(hDevice,bufInput,nOutput,nc,ch,m)	bufInput[0] =((nc-1)&0xF)+0x20;	\
			bufInput[1] = ((m&1)<<15)|(0xC00)|(ch&0x1ff);\
			DeviceIoControl(hDevice,DRV2K_PCI429_4_writeKOP_1,\
			bufInput, 4, NULL, 0, &nOutput, NULL)
#define KV_VO_BKV(hDevice,bufInput,nOutput,nc,ch,m)	bufInput[0] =((nc-1)&0xF)+0x20;	\
			bufInput[1] = ((m&1)<<15)|(0x1800)|(ch&0x3ff);\
			DeviceIoControl(hDevice,DRV2K_PCI429_4_writeKOP_1,\
			bufInput, 4, NULL, 0, &nOutput, NULL)
#define KV_VO_BKV2(hDevice,bufInput,nOutput,nc,ch,m)	bufInput[0] =((nc-1)&0xF)+0x20;	\
			bufInput[1] = ((m&1)<<15)|(0x1C00)|(ch&0x1ff);\
			DeviceIoControl(hDevice,DRV2K_PCI429_4_writeKOP_1,\
			bufInput, 4, NULL, 0, &nOutput, NULL)
#define KV_VG(hDevice,bufInput,nOutput,nc,m)	bufInput[0] =((nc-1)&0xF)+0x20;	\
			bufInput[1] = ((m&1)<<15)|(0x2000);\
			DeviceIoControl(hDevice,DRV2K_PCI429_4_writeKOP_1,\
			bufInput, 4, NULL, 0, &nOutput, NULL)

//обнулить массив  числа слов
#define KOM(hDevice,bufInput,nOutput,am,ch)	bufInput[0] =0x30;	\
			bufInput[1] = (unsigned short)am;\
			bufInput[2] = (unsigned short)ch;\
			DeviceIoControl(hDevice,DRV2K_PCI429_4_writeKOP_2,\
			bufInput, 6, NULL, 0, &nOutput, NULL)
#define KOMP(hDevice,bufInput,nOutput,am,ch)	bufInput[0] =0x31;	\
			bufInput[1] = (unsigned short)am;\
			bufInput[2] = (unsigned short)ch;\
			DeviceIoControl(hDevice,DRV2K_PCI429_4_writeKOP_2,\
			bufInput, 6, NULL, 0, &nOutput, NULL)

// передать массив параметров
#define KPM0(hDevice,bufInput,nOutput)	bufInput[0] = 0x38;	\
			DeviceIoControl(hDevice,DRV2K_PCI429_4_writeKOP_0,\
			bufInput, 2, NULL, 0, &nOutput, NULL)

#define KPM1(hDevice,bufInput,nOutput)	bufInput[0] = 0x39;	\
			DeviceIoControl(hDevice,DRV2K_PCI429_4_writeKOP_0,\
			bufInput, 2, NULL, 0, &nOutput, NULL)

#define KPM2(hDevice,bufInput,nOutput)	bufInput[0] = 0x3A;	\
			DeviceIoControl(hDevice,DRV2K_PCI429_4_writeKOP_0,\
			bufInput, 2, NULL, 0, &nOutput, NULL)

#define KPM3(hDevice,bufInput,nOutput)	bufInput[0] = 0x3B;	\
			DeviceIoControl(hDevice,DRV2K_PCI429_4_writeKOP_0,\
			bufInput, 2, NULL, 0, &nOutput, NULL)

#define KPM4(hDevice,bufInput,nOutput)	bufInput[0] = 0x3C;	\
			DeviceIoControl(hDevice,DRV2K_PCI429_4_writeKOP_0,\
			bufInput, 2, NULL, 0, &nOutput, NULL)

#define KPM5(hDevice,bufInput,nOutput)	bufInput[0] = 0x3D;	\
			DeviceIoControl(hDevice,DRV2K_PCI429_4_writeKOP_0,\
			bufInput, 2, NULL, 0, &nOutput, NULL)

#define KPM6(hDevice,bufInput,nOutput)	bufInput[0] = 0x3E;	\
			DeviceIoControl(hDevice,DRV2K_PCI429_4_writeKOP_0,\
			bufInput, 2, NULL, 0, &nOutput, NULL)

#define KPM7(hDevice,bufInput,nOutput)	bufInput[0] = 0x3F;	\
			DeviceIoControl(hDevice,DRV2K_PCI429_4_writeKOP_0,\
			bufInput, 2, NULL, 0, &nOutput, NULL)


//установка задания режима канала приема в БУКП

#define PFA_BKP(hDevice,bufInput,nOutput,nc,ch,m_ch,ap,m_ap)	bufInput[0] =((nc-1)&0xF)+1;	\
			bufInput[1] = ((m_ch&1)<<15)|(ch&0x3ff);\
			bufInput[2] = (unsigned short)(((m_ap&1)<<13)|(ap&0xff));\
			DeviceIoControl(hDevice,DRV2K_PCI429_4_writeBU_I,\
			bufInput, 6, NULL, 0, &nOutput, NULL)
#define PFA_BKP2(hDevice,bufInput,nOutput,nc,ch,m_ch,ap,m_ap)	bufInput[0] =((nc-1)&0xF)+1;	\
			bufInput[1] = ((m_ch&1)<<15)|(0x400)|(ch&0x1ff);\
			bufInput[2] = (unsigned short)(((m_ap&1)<<13)|(ap&0xff));\
			DeviceIoControl(hDevice,DRV2K_PCI429_4_writeBU_I,\
			bufInput, 6, NULL, 0, &nOutput, NULL)
#define PFR_BKP(hDevice,bufInput,nOutput,nc,ch,m_ch)	bufInput[0] =((nc-1)&0xF)+1;	\
			bufInput[1] = ((m_ch&1)<<15)|(0x1000)|(ch&0x3ff);\
			bufInput[2] = 0;\
			DeviceIoControl(hDevice,DRV2K_PCI429_4_writeBU_I,\
			bufInput, 6, NULL, 0, &nOutput, NULL)
#define PFR_BKP2(hDevice,bufInput,nOutput,nc,ch,m_ch)	bufInput[0] =((nc-1)&0xF)+1;	\
			bufInput[1] = ((m_ch&1)<<15)|(0x1400)|(ch&0x1ff);\
			bufInput[2] = 0;\
			DeviceIoControl(hDevice,DRV2K_PCI429_4_writeBU_I,\
			bufInput, 6, NULL, 0, &nOutput, NULL)
#define PFC_BKP(hDevice,bufInput,nOutput,nc,ch,ap,m_ap)	bufInput[0] =((nc-1)&0xF)+1;	\
			bufInput[1] = (0x1800)|(ch&0x3ff);\
			bufInput[2] = (unsigned short)(((m_ap&1)<<13)|(ap&0xff));\
			DeviceIoControl(hDevice,DRV2K_PCI429_4_writeBU_I,\
			bufInput, 6, NULL, 0, &nOutput, NULL)
#define PFC_BKP2(hDevice,bufInput,nOutput,nc,ch,ap,m_ap)	bufInput[0] =((nc-1)&0xF)+1;	\
			bufInput[1] = (0x1C00)|(ch&0x1ff);\
			bufInput[2] = (unsigned short)(((m_ap&1)<<13)|(ap&0xff));\
			DeviceIoControl(hDevice,DRV2K_PCI429_4_writeBU_I,\
			bufInput, 6, NULL, 0, &nOutput, NULL)
#define PA_BKP1(hDevice,bufInput,nOutput,nc,ap,m_ap)	bufInput[0] =((nc-1)&0xF)+1;	\
			bufInput[1] = 0x2000;\
			bufInput[2] = (unsigned short)(((m_ap&1)<<13)|(ap&0xff));\
			DeviceIoControl(hDevice,DRV2K_PCI429_4_writeBU_I,\
			bufInput, 6, NULL, 0, &nOutput, NULL)
#define PA_BKP2(hDevice,bufInput,nOutput,nc,ap,m_ap)	bufInput[0] =((nc-1)&0xF)+1;	\
			bufInput[1] = 0x2400;\
			bufInput[2] = (unsigned short)(((m_ap&1)<<13)|(ap&0xff));\
			DeviceIoControl(hDevice,DRV2K_PCI429_4_writeBU_I,\
			bufInput, 6, NULL, 0, &nOutput, NULL)
#define PG(hDevice,bufInput,nOutput,nc)	bufInput[0] =((nc-1)&0xF)+1;	\
			bufInput[1] = 0x3000;\
			bufInput[2] = 0;\
			DeviceIoControl(hDevice,DRV2K_PCI429_4_writeBU_I,\
			bufInput, 6, NULL, 0, &nOutput, NULL)



//установка задания режима канала выдачи в БУКВ

#define VR_BKV(hDevice,bufInput,nOutput,nc,ch,m)	bufInput[0] =((nc-1)&0xF)+1;	\
			bufInput[1] = ((m&1)<<15)|(ch&0x3ff);\
			DeviceIoControl(hDevice,DRV2K_PCI429_4_writeBU_O,\
			bufInput, 4, NULL, 0, &nOutput, NULL)
#define VR_BKV2(hDevice,bufInput,nOutput,nc,ch,m)	bufInput[0] =((nc-1)&0xF)+1;	\
			bufInput[1] = ((m&1)<<15)|(0x400)|(ch&0x1ff);\
			DeviceIoControl(hDevice,DRV2K_PCI429_4_writeBU_O,\
			bufInput, 4, NULL, 0, &nOutput, NULL)
#define VC_BKV(hDevice,bufInput,nOutput,nc,ch,m)	bufInput[0] =((nc-1)&0xF)+1;	\
			bufInput[1] = ((m&1)<<15)|(0x800)|(ch&0x3ff);\
			DeviceIoControl(hDevice,DRV2K_PCI429_4_writeBU_O,\
			bufInput, 4, NULL, 0, &nOutput, NULL)
#define VC_BKV2(hDevice,bufInput,nOutput,nc,ch,m)	bufInput[0] =((nc-1)&0xF)+1;	\
			bufInput[1] = ((m&1)<<15)|(0xC00)|(ch&0x1ff);\
			DeviceIoControl(hDevice,DRV2K_PCI429_4_writeBU_O,\
			bufInput, 4, NULL, 0, &nOutput, NULL)
#define VO_BKV(hDevice,bufInput,nOutput,nc,ch,m)	bufInput[0] =((nc-1)&0xF)+1;	\
			bufInput[1] = ((m&1)<<15)|(0x1800)|(ch&0x3ff);\
			DeviceIoControl(hDevice,DRV2K_PCI429_4_writeBU_O,\
			bufInput, 4, NULL, 0, &nOutput, NULL)
#define VO_BKV2(hDevice,bufInput,nOutput,nc,ch,m)	bufInput[0] =((nc-1)&0xF)+1;	\
			bufInput[1] = ((m&1)<<15)|(0x1C00)|(ch&0x1ff);\
			DeviceIoControl(hDevice,DRV2K_PCI429_4_writeBU_O,\
			bufInput, 4, NULL, 0, &nOutput, NULL)
#define VG(hDevice,bufInput,nOutput,nc,m)	bufInput[0] =((nc-1)&0xF)+1;	\
			bufInput[1] = ((m&1)<<15)|(0x2000);\
			DeviceIoControl(hDevice,DRV2K_PCI429_4_writeBU_O,\
			bufInput, 4, NULL, 0, &nOutput, NULL)

//подготовка расписания канала, работающего в глобальном режиме

//выходные каналы

#define TAB_VG_WORD(bufInput,ss,adr,km,nl)	bufInput[ss+2] =((km&0x1)<<14)+((nl&0x1)<<13)+(adr&0x1fff)


#define TAB_VG_PAUSE(bufInput, ss, ch_p)	bufInput[ss+2] =(ch_p&0x1FF)+0x8000

//входные каналы

#define TAB_PG_WORD(bufInput,ap,adr,m)	bufInput[ap+2] =((m&0x1)<<15)+0x2000+(adr&0x1fff)


#define TAB_PG_PAUSE(bufInput, ap)	bufInput[ap+2] =0
