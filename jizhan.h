#include <stdio.h>
#ifndef jizhan_H

#define jizhan_H
#include <stdlib.h>
#include <string.h>
#include <malloc.h>
#include <math.h>
#define MAXLENGTH 20
#define MAX 15000
typedef struct LNode
{
	int data;
	struct LNode* next;

}LNode, * LinkList;//单链表

typedef struct Index
{

	int addressx;
	int addressy;
	LinkList pdata;
}Index;//int maxkeyx=308 int maxkeyy=308 分为130行 358列

typedef struct Information {
	char coorx[MAXLENGTH];
	char coory[MAXLENGTH];
	char area[MAXLENGTH];
	char qiangdu[MAXLENGTH];
	char number[MAXLENGTH];
}Information;//基站的数据结构

typedef struct YD {
	char Xs[MAXLENGTH];
	char Ys[MAXLENGTH];
	char Xe[MAXLENGTH];
	char Ye[MAXLENGTH];
	char vel[MAXLENGTH];
	char Hs[MAXLENGTH];
	char Ms[MAXLENGTH];
}YD;//移动端的数据结构

typedef struct WZ {
	char WXs[MAXLENGTH];
	char WYs[MAXLENGTH];
	char WXe[MAXLENGTH];
	char WYe[MAXLENGTH];
	char Wvel[MAXLENGTH];
	char WHs[MAXLENGTH];
	char WMs[MAXLENGTH];
	char Wnum[MAXLENGTH];
}WZ;//伪基站的数据结构


typedef struct checklist {
	int biaohao;
	double jvli;
	double qiangdu;
}checklist;//查找最强基站的数据结构

void location(LinkList K, int spem, int spen, Information list[]);
//求解信号最强基站函数
void sear(float checkx, float checky, Information list[], Index block[131][359], int* maxxx, int* minnn, checklist chengshi[], checklist xiangzheng[], checklist gaoshu[]);
//移动端轨迹链接基站序列
void guiji(int aa[], int* ii, float XS, float YS, float XE, float YE, Information list[], Index block[131][359], checklist chengshi[], checklist xiangzheng[], checklist gaoshu[], float bx[], float by[]);
void guiji2(int aa[], int* ii, float XS, float YS, float XE, float YE, Information list[], Index block[131][359], checklist chengshi[], checklist xiangzheng[], checklist gaoshu[], float bx[], float by[]);
//二分求边界
void bSection(float* serx, float* sery, float xs, float ys, float xe, float ye, Information list[], Index block[131][359], checklist chengshi[], checklist xiangzheng[], checklist gaoshu[]);
void bSection2(float* serx, float* sery, float xs, float ys, float xe, float ye, Information list[], Index block[131][359], checklist chengshi[], checklist xiangzheng[], checklist gaoshu[], int n);
//判断坐标是否在基站有效范围内
void range(float x, float y, Information list[], int num, int* flag);
//读取文件
void readlist(Information list[],int* numm);
void readlist2(YD ydlist[]);
void readlist3(WZ wzlist[]);

void checkwz(YD a, WZ b[]);
#endif
