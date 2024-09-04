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

}LNode, * LinkList;//������

typedef struct Index
{

	int addressx;
	int addressy;
	LinkList pdata;
}Index;//int maxkeyx=308 int maxkeyy=308 ��Ϊ130�� 358��

typedef struct Information {
	char coorx[MAXLENGTH];
	char coory[MAXLENGTH];
	char area[MAXLENGTH];
	char qiangdu[MAXLENGTH];
	char number[MAXLENGTH];
}Information;//��վ�����ݽṹ

typedef struct YD {
	char Xs[MAXLENGTH];
	char Ys[MAXLENGTH];
	char Xe[MAXLENGTH];
	char Ye[MAXLENGTH];
	char vel[MAXLENGTH];
	char Hs[MAXLENGTH];
	char Ms[MAXLENGTH];
}YD;//�ƶ��˵����ݽṹ

typedef struct WZ {
	char WXs[MAXLENGTH];
	char WYs[MAXLENGTH];
	char WXe[MAXLENGTH];
	char WYe[MAXLENGTH];
	char Wvel[MAXLENGTH];
	char WHs[MAXLENGTH];
	char WMs[MAXLENGTH];
	char Wnum[MAXLENGTH];
}WZ;//α��վ�����ݽṹ


typedef struct checklist {
	int biaohao;
	double jvli;
	double qiangdu;
}checklist;//������ǿ��վ�����ݽṹ

void location(LinkList K, int spem, int spen, Information list[]);
//����ź���ǿ��վ����
void sear(float checkx, float checky, Information list[], Index block[131][359], int* maxxx, int* minnn, checklist chengshi[], checklist xiangzheng[], checklist gaoshu[]);
//�ƶ��˹켣���ӻ�վ����
void guiji(int aa[], int* ii, float XS, float YS, float XE, float YE, Information list[], Index block[131][359], checklist chengshi[], checklist xiangzheng[], checklist gaoshu[], float bx[], float by[]);
void guiji2(int aa[], int* ii, float XS, float YS, float XE, float YE, Information list[], Index block[131][359], checklist chengshi[], checklist xiangzheng[], checklist gaoshu[], float bx[], float by[]);
//������߽�
void bSection(float* serx, float* sery, float xs, float ys, float xe, float ye, Information list[], Index block[131][359], checklist chengshi[], checklist xiangzheng[], checklist gaoshu[]);
void bSection2(float* serx, float* sery, float xs, float ys, float xe, float ye, Information list[], Index block[131][359], checklist chengshi[], checklist xiangzheng[], checklist gaoshu[], int n);
//�ж������Ƿ��ڻ�վ��Ч��Χ��
void range(float x, float y, Information list[], int num, int* flag);
//��ȡ�ļ�
void readlist(Information list[],int* numm);
void readlist2(YD ydlist[]);
void readlist3(WZ wzlist[]);

void checkwz(YD a, WZ b[]);
#endif
