#include <stdio.h>
#include "jizhan.h"
int main(void)
{
	Information list[MAX] = { 0 };
	int num2;
	readlist(list,&num2);

    Index block[131][359] = { 0 };


	int ms, ns;
	for (ms = 0; ms <= 130; ms++) {
		for (ns = 0; ns <= 358; ns++)
		{
			block[ms][ns].pdata = (LinkList)malloc(sizeof(LNode));
			block[ms][ns].pdata->next = NULL;
		}
	}//�������ʼ��


	int i, m, n, retx, rety, maxkeyx = 308, maxkeyy = 308;
	for (i = 0; i <= (num2 - 2); i++)
	{
		retx = atoi(list[i].coorx);
		rety = atoi(list[i].coory);
		m = (rety + 82) / 308 + 1;
		n = (retx + 26) / 308 + 1;
		LinkList p = (LinkList)malloc(sizeof(LNode));
		p->data = i;
		p->next = block[m][n].pdata->next;
		block[m][n].pdata->next = p;
		p = NULL;
	}//ʵ�ַֿ�


	//��Ҫ����1

	LinkList L;
	int yourm, yourn, xx, yourx, youry;
	printf_s("������Ҫ���ҵ������");
	scanf_s("%d %d", &yourm, &yourn);
	L = block[yourm][yourn].pdata->next;
	yourx = -26 + (yourn - 1) * 308;
	youry = -82 + (yourm - 1) * 308;
	printf_s("��������ʼ����Ϊx=%d y=%d\n", yourx, youry);
	if (L == NULL)
		printf_s("���������޻�վ \n");
	while (L != NULL) {
		xx = L->data;
		printf_s("�б�Ϊ %s %s %s %s %s", list[xx].coorx, list[xx].coory, list[xx].area, list[xx].qiangdu, list[xx].number);
		L = L->next;
	}


	//��Ҫ����2
	LinkList K;
	int spem, spen;
	printf_s("����������\n");
	for (spem = 130; spem >= 128; spem--) {
		for (spen = 1; spen <= 3; spen++) {
			K = block[spem][spen].pdata->next;
			location(K, spem, spen, list);
		}
	}

	printf_s("���Ͻ�����\n");
	for (spem = 3; spem >= 1; spem--) {
		for (spen = 356; spen <= 358; spen++) {
			K = block[spem][spen].pdata->next;
			location(K, spem, spen, list);
		}
	}


	printf_s("��������\n");
	for (spem = 130; spem >= 128; spem--) {
		for (spen = 4; spen <= 6; spen++) {
			K = block[spem][spen].pdata->next;
			location(K, spem, spen, list);
		}
	}


	printf_s("�ϲ�����\n");
	for (spem = 127; spem >= 125; spem--) {
		for (spen = 1; spen <= 3; spen++) {
			K = block[spem][spen].pdata->next;
			location(K, spem, spen, list);
		}
	}


	printf_s("����������\n");
	for (spem = 6; spem >= 4; spem--) {
		for (spen = 353; spen <= 355; spen++) {
			K = block[spem][spen].pdata->next;
			location(K, spem, spen, list);
		}
	}


	printf_s("������ı�������\n");
	for (spem = 9; spem >= 7; spem--) {
		for (spen = 353; spen <= 355; spen++) {
			K = block[spem][spen].pdata->next;
			location(K, spem, spen, list);
		}
	}



	//��Ҫ����3��4
	float checkx, checky;
	int maxx, minn;
	printf_s("������Ҫ���ҵ�����");
	scanf_s("%f %f", &checkx, &checky);
	checklist chengshi[100];
	checklist xiangzheng[1000];
	checklist gaoshu[12250];
	sear(checkx, checky, list, block, &maxx, &minn, chengshi, xiangzheng, gaoshu);
	if (maxx == -1 && minn == -1)
		printf_s("������λ�þ����ڸ�����վ����Ч�źŷ�Χ��\n");
	else {
		printf_s("����λ��ǿ����ǿ�Ļ�վΪ");
		printf_s(" %s %s %s %s %s", list[maxx].coorx, list[maxx].coory, list[maxx].area, list[maxx].qiangdu, list[maxx].number);
		printf_s("����λ�þ�������Ļ�վΪ");
		printf_s(" %s %s %s %s %s", list[minn].coorx, list[minn].coory, list[minn].area, list[minn].qiangdu, list[minn].number);
	}



	YD ydlist[50] = { 0 };
	readlist2(ydlist);
	//��Ҫ����5
	float XS, YS, XE, YE;
	printf_s("�������ƶ��ն˵��ƶ��켣 ");
	scanf_s("%f %f %f %f", &XS, &YS, &XE, &YE);
	int aa[1000] = { 0 };
	float bx[1000] = { 0 };
	float by[1000] = { 0 };
	int ii;
	guiji(aa, &ii, XS, YS, XE, YE, list, block, chengshi, xiangzheng, gaoshu, bx, by);
	printf_s("���ӵĻ�վ����Ϊ\n");
	int tt;
	for (tt = 0; tt < ii; tt++) {
		if (aa[tt] != -1)
			printf_s("%s %s %s %s %s", list[aa[tt]].coorx, list[aa[tt]].coory, list[aa[tt]].area, list[aa[tt]].qiangdu, list[aa[tt]].number);
		else {
			printf_s("���ź�\n");
		}
	}
	//��չ����1
	int aa1[1000] = { 0 };
	float bx1[1000] = { 0 };
	float by1[1000] = { 0 };



	int i1 = 0;
	XS = atof(ydlist[0].Xs);
	YS = atof(ydlist[0].Ys);
	XE = atof(ydlist[0].Xe);
	YE = atof(ydlist[0].Ye);
	guiji2(aa1, &i1, XS, YS, XE, YE, list, block, chengshi, xiangzheng, gaoshu, bx1, by1);

	float serx, sery, vel1, hours1, minutes1, ydjvli1, ydminute1, ydminute2, ydsecond1, ydsecond2;
	vel1 = (1000 * atof(ydlist[0].vel)) / 60;//��λתΪ��/����
	hours1 = atof(ydlist[0].Hs);
	minutes1 = atof(ydlist[0].Ms);
	bSection(&serx, &sery, bx1[0], by1[0], bx1[1], by1[1], list, block, chengshi, xiangzheng, gaoshu);
	ydjvli1 = sqrt((serx - XS) * (serx - XS) + (sery - YS) * (sery - YS));
	ydminute1 = ydjvli1 / vel1;
	ydsecond1 = ydminute1 * 60.0;
	bSection(&serx, &sery, bx1[1], by1[1], bx1[2], by1[2], list, block, chengshi, xiangzheng, gaoshu);
	ydjvli1 = sqrt((serx - XS) * (serx - XS) + (sery - YS) * (sery - YS));
	ydminute2 = ydjvli1 / vel1;
	ydsecond2 = ydminute2 * 60.0;
	printf_s("��һ���ƶ��켣��%.0fСʱ%.0f����%f��ʱ�����׸���վ%s %s %s %s %s ��%.0fСʱ%.0f����%f��ʱ�뿪�׸���վ\n", hours1, minutes1, ydsecond1, list[aa1[1]].coorx, list[aa1[1]].coory, list[aa1[1]].area, list[aa1[1]].qiangdu, list[aa1[1]].number, hours1, minutes1, ydsecond2);

	//��չ����2 
	XS = atof(ydlist[2].Xs);
	YS = atof(ydlist[2].Ys);
	XE = atof(ydlist[2].Xe);
	YE = atof(ydlist[2].Ye);
	int aa2[1000] = { 0 };
	float bx2[1000] = { 0 };
	float by2[1000] = { 0 };

	int i2 = 0;
	guiji2(aa2, &i2, XS, YS, XE, YE, list, block, chengshi, xiangzheng, gaoshu, bx2, by2);
	vel1 = (1000 * atof(ydlist[2].vel)) / 60;//��λתΪ��/����
	hours1 = atof(ydlist[2].Hs);
	minutes1 = atof(ydlist[2].Ms);

	bSection2(&serx, &sery, bx2[0], by2[0], XE, YE, list, block, chengshi, xiangzheng, gaoshu, aa2[0]);
	ydjvli1 = sqrt((serx - XS) * (serx - XS) + (sery - YS) * (sery - YS));
	ydminute1 = ydjvli1 / vel1;
	ydsecond1 = ydminute1 * 60.0;
	bSection2(&serx, &sery, XS, YS, bx2[1], by2[1], list, block, chengshi, xiangzheng, gaoshu, aa2[1]);
	ydjvli1 = sqrt((serx - XS) * (serx - XS) + (sery - YS) * (sery - YS));
	ydminute2 = ydjvli1 / vel1;
	ydsecond2 = ydminute2 * 60.0;
	printf_s("��վ%d�л���%d,�ص�ʱ��%f-%f=%f��\n", aa2[0] + 1, aa2[1] + 1, ydsecond1, ydsecond2, ydsecond1 - ydsecond2);
	//2-2
	XS = atof(ydlist[5].Xs);
	YS = atof(ydlist[5].Ys);
	XE = atof(ydlist[5].Xe);
	YE = atof(ydlist[5].Ye);
	int aa3[1000] = { 0 };
	float bx3[1000] = { 0 };
	float by3[1000] = { 0 };

	int i3 = 0;
	guiji2(aa3, &i3, XS, YS, XE, YE, list, block, chengshi, xiangzheng, gaoshu, bx3, by3);
	vel1 = (1000 * atof(ydlist[5].vel)) / 60;//��λתΪ��/����
	hours1 = atof(ydlist[5].Hs);
	minutes1 = atof(ydlist[5].Ms);

	bSection2(&serx, &sery, bx3[0], by3[0], XE, YE, list, block, chengshi, xiangzheng, gaoshu, aa3[0]);
	ydjvli1 = sqrt((serx - XS) * (serx - XS) + (sery - YS) * (sery - YS));
	ydminute1 = ydjvli1 / vel1;
	ydsecond1 = ydminute1 * 60.0;
	bSection2(&serx, &sery, XS, YS, bx3[1], by3[1], list, block, chengshi, xiangzheng, gaoshu, aa3[1]);
	ydjvli1 = sqrt((serx - XS) * (serx - XS) + (sery - YS) * (sery - YS));
	ydminute2 = ydjvli1 / vel1;
	ydsecond2 = ydminute2 * 60.0;
	printf_s("��վ%d�л���%d,�ص�ʱ��%f-%f=%f��\n", aa3[0] + 1, aa3[1] + 1, ydsecond1, ydsecond2, ydsecond1 - ydsecond2);
	
	//��������
	WZ wzlist[50] = { 0 };
	readlist3(wzlist);
	checkwz(ydlist[12], wzlist);
	
	return 0;


}