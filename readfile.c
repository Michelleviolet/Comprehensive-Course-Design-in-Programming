#include <stdio.h>
#include "jizhan.h"

void readlist(Information list[],int* numm) {
	FILE* file1;
	fopen_s(&file1, "jz001.txt", "r");
	char buffer[200] = { 0 };
	int num = 0;
	fgets(buffer, 200, file1);
	while (fgets(buffer, 200, file1) != NULL && buffer != "-1,-1")
	{
		char cr_coorx[MAXLENGTH] = { 0 };
		char cr_coory[MAXLENGTH] = { 0 };
		char cr_area[MAXLENGTH] = { 0 };
		char cr_qiangdu[MAXLENGTH] = { 0 };
		char cr_number[MAXLENGTH] = { 0 };
		int j;
		int js = 0;
		int count = 0;
		for (j = 0; j < strlen(buffer); j++)
		{
			if (buffer[j] == ',')
			{
				js = 0;
				count++;
				continue;
			}
			if (buffer[j] == ' ')
			{
				js = 0;
				count++;
				j++;
				continue;
			}
			if (count == 0)
			{
				cr_coorx[js] = buffer[j];
				js++;
			}
			else if (count == 1)
			{
				cr_coory[js] = buffer[j];
				js++;
			}
			else if (count == 2)
			{
				cr_area[js] = buffer[j];
				js++;
			}
			else if (count == 3)
			{
				cr_qiangdu[js] = buffer[j];
				js++;
			}
			else {
				cr_number[js] = buffer[j];
				js++;
			}
		}
		strcpy_s(list[num].coorx, strlen(cr_coorx) + 1, cr_coorx);
		strcpy_s(list[num].coory, strlen(cr_coory) + 1, cr_coory);
		strcpy_s(list[num].area, strlen(cr_area) + 1, cr_area);
		strcpy_s(list[num].qiangdu, strlen(cr_qiangdu) + 1, cr_qiangdu);
		strcpy_s(list[num].number, strlen(cr_number) + 1, cr_number);
		num++;
	}//将jz.1文件数据存入结构体
	fclose(file1);
	int num2 = 7344;

	FILE* file2;
	fopen_s(&file2, "jz002.txt", "r");

	char buffer2[200] = { 0 };
	fgets(buffer2, 200, file2);
	while (fgets(buffer2, 200, file2) != NULL && buffer2 != "-1,-1")
	{
		char cr_coorx[MAXLENGTH] = { 0 };
		char cr_coory[MAXLENGTH] = { 0 };
		char cr_area[MAXLENGTH] = { 0 };
		char cr_qiangdu[MAXLENGTH] = { 0 };
		char cr_number[MAXLENGTH] = { 0 };
		int j;
		int js = 0;
		int count = 0;
		for (j = 0; j < strlen(buffer2); j++)
		{
			if (buffer2[j] == ',')
			{
				js = 0;
				count++;
				continue;
			}
			if (buffer2[j] == ' ')
			{
				js = 0;
				count++;
				continue;
			}
			if (count == 0)
			{
				cr_coorx[js] = buffer2[j];
				js++;
			}
			else if (count == 1)
			{
				cr_coory[js] = buffer2[j];
				js++;
			}
			else if (count == 2)
			{
				cr_area[js] = buffer2[j];
				js++;
			}
			else if (count == 3)
			{
				cr_qiangdu[js] = buffer2[j];
				js++;
			}
			else {
				cr_number[js] = buffer2[j];
				js++;
			}
		}
		strcpy_s(list[num2].coorx, strlen(cr_coorx) + 1, cr_coorx);
		strcpy_s(list[num2].coory, strlen(cr_coory) + 1, cr_coory);
		strcpy_s(list[num2].area, strlen(cr_area) + 1, cr_area);
		strcpy_s(list[num2].qiangdu, strlen(cr_qiangdu) + 1, cr_qiangdu);
		strcpy_s(list[num2].number, strlen(cr_number) + 1, cr_number);
		num2++;
	}//将jz.2文件数据存入结构体
	fclose(file2);
	*numm = num2;
}

void readlist2(YD ydlist[]) {
	FILE* file3;
	fopen_s(&file3, "yd001.txt", "r");
	int ydnum = 0;
	char buffer3[200] = { 0 };
	fgets(buffer3, 200, file3);
	while (fgets(buffer3, 200, file3) != NULL &&buffer3 != "-1,-1")
	{
		char cr_Xs[MAXLENGTH] = { 0 };
		char cr_Ys[MAXLENGTH] = { 0 };
		char cr_Xe[MAXLENGTH] = { 0 };
		char cr_Ye[MAXLENGTH] = { 0 };
		char cr_vel[MAXLENGTH] = { 0 };
		char cr_Hs[MAXLENGTH] = { 0 };
		char cr_Ms[MAXLENGTH] = { 0 };
		int j;
		int js = 0;
		int count = 0;
		for (j = 0; j < strlen(buffer3); j++)
		{
			if (buffer3[j] == ',')
			{
				js = 0;
				count++;
				continue;
			}

			if (count == 0)
			{
				cr_Xs[js] = buffer3[j];
				js++;
			}
			else if (count == 1)
			{
				cr_Ys[js] = buffer3[j];
				js++;
			}
			else if (count == 2)
			{
				cr_Xe[js] = buffer3[j];
				js++;
			}
			else if (count == 3)
			{
				cr_Ye[js] = buffer3[j];
				js++;
			}
			else if (count == 4) {
				cr_vel[js] = buffer3[j];
				js++;
			}
			else if (count == 5) {
				cr_Hs[js] = buffer3[j];
				js++;
			}
			else {
				cr_Ms[js] = buffer3[j];
				js++;
			}
		}
		strcpy_s(ydlist[ydnum].Xs, strlen(cr_Xs) + 1, cr_Xs);
		strcpy_s(ydlist[ydnum].Ys, strlen(cr_Ys) + 1, cr_Ys);
		strcpy_s(ydlist[ydnum].Xe, strlen(cr_Xe) + 1, cr_Xe);
		strcpy_s(ydlist[ydnum].Ye, strlen(cr_Ye) + 1, cr_Ye);
		strcpy_s(ydlist[ydnum].vel, strlen(cr_vel) + 1, cr_vel);
		strcpy_s(ydlist[ydnum].Hs, strlen(cr_Hs) + 1, cr_Hs);
		strcpy_s(ydlist[ydnum].Ms, strlen(cr_Ms) + 1, cr_Ms);

		ydnum++;
	}//将yd.1文件数据存入结构体
	fclose(file3);
}

void readlist3(WZ wzlist[]) {
	FILE* file4;
	fopen_s(&file4, "wz001.txt", "r");
	int wznum = 0;
	char buffer4[200] = { 0 };
	fgets(buffer4, 200, file4);
	while (fgets(buffer4, 200, file4) != NULL )
	{
		char cr_Xs[MAXLENGTH] = { 0 };
		char cr_Ys[MAXLENGTH] = { 0 };
		char cr_Xe[MAXLENGTH] = { 0 };
		char cr_Ye[MAXLENGTH] = { 0 };
		char cr_vel[MAXLENGTH] = { 0 };
		char cr_Hs[MAXLENGTH] = { 0 };
		char cr_Ms[MAXLENGTH] = { 0 };
		char cr_Num[MAXLENGTH] = { 0 };
		int j;
		int js = 0;
		int count = 0;
		for (j = 0; j < strlen(buffer4)-1; j++)
		{
			if (buffer4[j] == ',')
			{
				js = 0;
				count++;
				continue;
			}

			if (count == 0)
			{
				cr_Xs[js] = buffer4[j];
				js++;
			}
			else if (count == 1)
			{
				cr_Ys[js] = buffer4[j];
				js++;
			}
			else if (count == 2)
			{
				cr_Xe[js] = buffer4[j];
				js++;
			}
			else if (count == 3)
			{
				cr_Ye[js] = buffer4[j];
				js++;
			}
			else if (count == 4) {
				cr_vel[js] = buffer4[j];
				js++;
			}
			else if (count == 5) {
				cr_Hs[js] = buffer4[j];
				js++;
			}
			else if (count == 6) {
				cr_Ms[js] = buffer4[j];
				js++;
			}
			else {
				cr_Num[js] = buffer4[j];
				js++;
			}
		}
		strcpy_s(wzlist[wznum].WXs, strlen(cr_Xs) + 1, cr_Xs);
		strcpy_s(wzlist[wznum].WYs, strlen(cr_Ys) + 1, cr_Ys);
		strcpy_s(wzlist[wznum].WXe, strlen(cr_Xe) + 1, cr_Xe);
		strcpy_s(wzlist[wznum].WYe, strlen(cr_Ye) + 1, cr_Ye);
		strcpy_s(wzlist[wznum].Wvel, strlen(cr_vel) + 1, cr_vel);
		strcpy_s(wzlist[wznum].WHs, strlen(cr_Hs) + 1, cr_Hs);
		strcpy_s(wzlist[wznum].WMs, strlen(cr_Ms) + 1, cr_Ms);
		strcpy_s(wzlist[wznum].Wnum, strlen(cr_Num) + 1, cr_Num);
		
		wznum = wznum + 1;
	}//将WZ.1文件数据存入结构体
	fclose(file4);
	
}