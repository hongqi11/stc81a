#ifndef APP_H
#define APP_H

#include "SYSTEM.H"



enum UpNum{				//名称
	Nothing = 0,
	VolA_Volt1,
	VolA_Volt2,
	ImpedB,
	LoaC,
	MulD_Mul1,
	MulD_Mul2,
	VolE_Volt1,
	VolE_Volt2,
	BOXF_M1_PASS,
	BOXF_M2_PASS,
	BOXF_CM_VX,
	BOXF_R1,
	BOXF_R2,
	BOXF_VM_JE,
	BOXG_IM_VTH,
	BOXG_ResD,
};

enum RelayStatus{				//�̵���
	OFF=0,
	ON = 1,
	
};
enum VoltageStatus{	
    CLOSE=0,			//��Դ
	PON = 1,
	NON=2,	
};
struct VoltageName{				//CH1
	enum VoltageStatus Voltage1;
	enum VoltageStatus Voltage2;
};

struct MultimeterX{				//���ñ�
	enum VoltageStatus Multimeter1;
	enum VoltageStatus Multimeter2;
};
struct Middle_Box1{				//middle_box
	enum RelayStatus 	M1_PASS;
	enum RelayStatus 	M2_PASS;
	enum VoltageStatus 	CM_VX;
	enum RelayStatus 	R1;
	enum RelayStatus 	R2;
	enum VoltageStatus 	VM_JE;
};

struct Middle_Box2{				//middle_box
	enum VoltageStatus IM_VTH;
	enum RelayStatus   ResD;
};

struct mainboxstruct{
	struct VoltageName  VoltageA;
	struct VoltageName  VoltageE;
	enum RelayStatus 	ImpedanceB;
	enum RelayStatus 	LoadC;
	struct MultimeterX	MultimeterD;
	struct Middle_Box1  BOXF;
	struct Middle_Box2  BOXG;	
};



void IO_Init();
void MainBoxAssignment(struct mainboxstruct  *p_box,  enum UpNum *p_status);
void MainBoxComparison(struct mainboxstruct  *p_newbox, struct mainboxstruct  *p_box,enum UpNum *p_status);
void MainBoxInit(struct mainboxstruct  *p_newbox, struct mainboxstruct  *p_box);
#endif
