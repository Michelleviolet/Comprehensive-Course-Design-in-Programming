#include <stdio.h>
#include "jizhan.h"
void location(LinkList K, int spem, int spen, Information list[]) {

	int  xx, spex, spey;
	spex = -26 + (spen - 1) * 308;
	spey = -82 + (spem - 1) * 308;
	//printf_s("该区域起始坐标为x=%d y=%d\n", spex, spey);
	if (K == NULL) {}
	//printf_s("该区域内无基站 \n");
	while (K != NULL) {
		xx = K->data;
		printf_s(" %s %s %s %s %s", list[xx].coorx, list[xx].coory, list[xx].area, list[xx].qiangdu, list[xx].number);
		K = K->next;
	}


}
//求解信号最强基站函数
void sear(float checkx, float checky, Information list[], Index block[131][359], int* maxxx, int* minnn, checklist chengshi[], checklist xiangzheng[], checklist gaoshu[]) {
	int checkm, checkn;
	checkm = (checky + 82) / 308 + 1;
	checkn = (checkx + 26) / 308 + 1;
	LinkList Lchengshi;
	int im, in, checkxx, ichengshi = 0;
	for (im = checkm - 1; im <= checkm + 1; im++) {//查找城市基站
		if (im < 1 || im>130) { break; }
		for (in = checkn - 1; in <= checkn + 1; in++) {

			if (in < 1 || in>358) { break; }//判断边界
			else {
				Lchengshi = block[im][in].pdata->next;
				if (Lchengshi == NULL) {

				}
				while (Lchengshi != NULL) {
					checkxx = Lchengshi->data;
					float tempjvli1, tempqiangdu1;
					tempjvli1 = (checkx - atof(list[checkxx].coorx)) * (checkx - atof(list[checkxx].coorx)) + (checky - atof(list[checkxx].coory)) * (checky - atof(list[checkxx].coory));
					tempqiangdu1 = atof(list[checkxx].qiangdu) * (90000 / tempjvli1);
					if (strcmp(list[checkxx].area, "城区") == 0 && tempqiangdu1 >= 1.0) {
						chengshi[ichengshi].biaohao = checkxx;
						chengshi[ichengshi].jvli = tempjvli1;
						chengshi[ichengshi].qiangdu = tempqiangdu1;
						ichengshi++;
					}
					else {

					}
					Lchengshi = Lchengshi->next;
				}



			}
		}
	}


	//查找城市基站中距离最近和强度最大的基站
	float maxqiangdu1 = 0;
	int i1, max1 = chengshi[0].biaohao;
	for (i1 = 0; i1 < ichengshi; i1++) {//城市基站中强度最大
		if (maxqiangdu1 < chengshi[i1].qiangdu) {
			maxqiangdu1 = chengshi[i1].qiangdu;
			max1 = chengshi[i1].biaohao;
		}
	}

	float minjvli1 = 2e9;
	int t1, min1 = chengshi[0].biaohao;
	for (t1 = 0; t1 < ichengshi; t1++) {//城市基站中距离最小
		if (minjvli1 > chengshi[t1].jvli) {
			minjvli1 = chengshi[t1].jvli;
			min1 = chengshi[t1].biaohao;
		}
	}


	LinkList Lxiangzheng;
	int im2, in2, checkxx2, ixiangzheng = 0;
	for (im2 = checkm - 4; im2 <= checkm + 4; im2++) {//查找乡镇基站
		if (im2 < 1 || im2>130) { break; }
		for (in2 = checkn - 4; in2 <= checkn + 4; in2++) {

			if (in2 < 1 || in2>358) { break; }//判断边界
			else {
				Lxiangzheng = block[im2][in2].pdata->next;
				if (Lxiangzheng == NULL) {

				}
				while (Lxiangzheng != NULL) {
					checkxx2 = Lxiangzheng->data;
					float tempjvli2, tempqiangdu2;
					tempjvli2 = (checkx - atof(list[checkxx2].coorx)) * (checkx - atof(list[checkxx2].coorx)) + (checky - atof(list[checkxx2].coory)) * (checky - atof(list[checkxx2].coory));
					tempqiangdu2 = atof(list[checkxx2].qiangdu) * (1000000 / tempjvli2);
					if (strcmp(list[checkxx2].area, "乡镇") == 0 && tempqiangdu2 >= 1.0) {
						xiangzheng[ixiangzheng].biaohao = checkxx2;
						xiangzheng[ixiangzheng].jvli = tempjvli2;
						xiangzheng[ixiangzheng].qiangdu = tempqiangdu2;
						ixiangzheng++;
					}
					else {

					}
					Lxiangzheng = Lxiangzheng->next;
				}



			}
		}
	}



	//查找乡镇基站中距离最近和强度最大的基站
	float maxqiangdu2 = 0;
	int i2, max2 = xiangzheng[0].biaohao;
	for (i2 = 0; i2 < ixiangzheng; i2++) {//乡镇基站中强度最大
		if (maxqiangdu2 < xiangzheng[i2].qiangdu) {
			maxqiangdu2 = xiangzheng[i2].qiangdu;
			max2 = xiangzheng[i2].biaohao;
		}
	}


	float minjvli2 = 2e9;
	int t2, min2 = xiangzheng[0].biaohao;
	for (t2 = 0; t2 < ixiangzheng; t2++) {//乡镇基站中距离最小
		if (minjvli2 > xiangzheng[t2].jvli) {
			minjvli2 = xiangzheng[t2].jvli;
			min2 = xiangzheng[t2].biaohao;
		}
	}




	LinkList Lgaoshu;
	int im3, in3, checkxx3, igaoshu = 0;
	for (im3 = checkm - 17; im3 <= checkm + 17; im3++) {//查找高速基站
		if (im3 < 1 || im3>130) { break; }
		for (in3 = checkn - 17; in3 <= checkn + 17; in3++) {

			if (in3 < 1 || in3>358) { break; }//判断边界
			else {
				Lgaoshu = block[im3][in3].pdata->next;
				if (Lgaoshu == NULL) {

				}
				while (Lgaoshu != NULL) {
					checkxx3 = Lgaoshu->data;
					float tempjvli3, tempqiangdu3;
					tempjvli3 = (checkx - atof(list[checkxx3].coorx)) * (checkx - atof(list[checkxx3].coorx)) + (checky - atof(list[checkxx3].coory)) * (checky - atof(list[checkxx3].coory));
					tempqiangdu3 = atof(list[checkxx3].qiangdu) * (25000000 / tempjvli3);

					if (strcmp(list[checkxx3].area, "高速") == 0 && tempqiangdu3 >= 1.0) {
						gaoshu[igaoshu].biaohao = checkxx3;
						gaoshu[igaoshu].jvli = tempjvli3;
						gaoshu[igaoshu].qiangdu = tempqiangdu3;
						igaoshu++;
					}
					else {

					}
					Lgaoshu = Lgaoshu->next;
				}



			}
		}
	}



	//查找高速基站中距离最近和强度最大的基站
	float maxqiangdu3 = 0;
	int i3, max3 = gaoshu[0].biaohao;
	for (i3 = 0; i3 < igaoshu; i3++) {//高速基站中强度最大
		if (maxqiangdu3 < gaoshu[i3].qiangdu) {
			maxqiangdu3 = gaoshu[i3].qiangdu;
			max3 = gaoshu[i3].biaohao;
		}
	}

	float minjvli3 = 2e9;
	int t3, min3 = gaoshu[0].biaohao;
	for (t3 = 0; t3 < igaoshu; t3++) {//高速基站中距离最小
		if (minjvli3 > gaoshu[t3].jvli) {
			minjvli3 = gaoshu[t3].jvli;
			min3 = gaoshu[t3].biaohao;
		}
	}

	int maxx, minn;
	maxx = -1;
	minn = -1;
	//比较三种基站中强度最大的基站并输出
	if (ichengshi == 0 && ixiangzheng == 0 && igaoshu == 0) {
		maxx = -1;
		minn = -1;
	}
	else {
		float maxqiangdu = 0;

		if (maxqiangdu1 > maxqiangdu) {
			maxqiangdu = maxqiangdu1;
			maxx = max1;
		}
		if (maxqiangdu2 > maxqiangdu) {
			maxqiangdu = maxqiangdu2;
			maxx = max2;
		}
		if (maxqiangdu3 > maxqiangdu) {
			maxqiangdu = maxqiangdu3;
			maxx = max3;
		}
		int minjvli = 2e9;
		if (minjvli1 < minjvli) {
			minjvli = minjvli1;
			minn = min1;
		}
		if (minjvli2 < minjvli) {
			minjvli = minjvli2;
			minn = min2;
		}
		if (minjvli3 < minjvli) {
			minjvli = minjvli3;
			minn = min3;
		}



	}
	*maxxx = maxx;
	*minnn = minn;

}
//移动端轨迹链接基站序列
void guiji(int aa[], int* ii, float XS, float YS, float XE, float YE, Information list[], Index block[131][359], checklist chengshi[], checklist xiangzheng[], checklist gaoshu[], float bx[], float by[]) {
	int maxx2, minn2;

	float x0, y0;
	int p, q;

	int i = 0;
	sear(XS, YS, list, block, &maxx2, &minn2, chengshi, xiangzheng, gaoshu);
	p = -1;
	q = maxx2;
	aa[i] = q;
	bx[i] = XS;
	by[i] = YS;
	i++;

	if (XE != XS) {


		if (XE > XS)
		{
			float k = (YE - YS) / (XE - XS);
			for (x0 = XS + 0.500000; x0 <= XE; x0 = x0 + 0.500000) {

				y0 = k * (x0 - XS) + YS;
				sear(x0, y0, list, block, &maxx2, &minn2, chengshi, xiangzheng, gaoshu);
				p = q;
				q = maxx2;
				if (p != q) {
					aa[i] = q;
					bx[i] = x0;
					by[i] = y0;
					i++;
				}
			}
		}
		else if (XE < XS) {
			float k = (YS - YE) / (XS - XE);
			for (x0 = XS - 0.500000; x0 >= XE; x0 = x0 - 0.500000) {
				y0 = k * (x0 - XE) + YE;
				sear(x0, y0, list, block, &maxx2, &minn2, chengshi, xiangzheng, gaoshu);
				p = q;
				q = maxx2;
				if (p != q) {
					aa[i] = q;
					bx[i] = x0;
					by[i] = y0;
					i++;
				}
			}
		}

	}
	else if (XE == XS) {
		if (YS < YE) {

			for (y0 = YS + 0.500000; y0 <= YE; y0 = y0 + 0.500000) {
				x0 = XE;
				sear(x0, y0, list, block, &maxx2, &minn2, chengshi, xiangzheng, gaoshu);
				p = q;
				q = maxx2;
				if (p != q) {
					aa[i] = q;
					bx[i] = x0;
					by[i] = y0;
					i++;
				}

			}
		}
		else if (YS > YE) {
			for (y0 = YS - 0.500000; y0 >= YE; y0 = y0 - 0.500000) {
				x0 = XE;
				sear(x0, y0, list, block, &maxx2, &minn2, chengshi, xiangzheng, gaoshu);
				p = q;
				q = maxx2;
				if (p != q) {
					aa[i] = q;
					bx[i] = x0;
					by[i] = y0;
					i++;
				}

			}

		}
	}
	*ii = i;

}

void guiji2(int aa[], int* ii, float XS, float YS, float XE, float YE, Information list[], Index block[131][359], checklist chengshi[], checklist xiangzheng[], checklist gaoshu[], float bx[], float by[]) {
	int maxx2, minn2;

	float x0, y0;
	int p, q;

	int i = 0;
	sear(XS, YS, list, block, &maxx2, &minn2, chengshi, xiangzheng, gaoshu);
	p = -1;
	q = maxx2;
	aa[i] = q;
	bx[i] = XS;
	by[i] = YS;
	i++;

	if (XE != XS) {


		if (XE > XS)
		{
			float k = (YE - YS) / (XE - XS);
			for (x0 = XS + 0.100000; x0 <= XE; x0 = x0 + 0.100000) {

				y0 = k * (x0 - XS) + YS;
				sear(x0, y0, list, block, &maxx2, &minn2, chengshi, xiangzheng, gaoshu);
				p = q;
				q = maxx2;
				if (p != q) {
					aa[i] = q;
					bx[i] = x0;
					by[i] = y0;
					i++;
				}
				if (i >= 5)break;
			}
		}
		else if (XE < XS) {
			float k = (YS - YE) / (XS - XE);
			for (x0 = XS - 0.100000; x0 >= XE; x0 = x0 - 0.100000) {
				y0 = k * (x0 - XE) + YE;
				sear(x0, y0, list, block, &maxx2, &minn2, chengshi, xiangzheng, gaoshu);
				p = q;
				q = maxx2;
				if (p != q) {
					aa[i] = q;
					bx[i] = x0;
					by[i] = y0;
					i++;
				}
				if (i >= 5)break;
			}
		}

	}
	else if (XE == XS) {
		if (YS < YE) {

			for (y0 = YS + 0.100000; y0 <= YE; y0 = y0 + 0.100000) {
				x0 = XE;
				sear(x0, y0, list, block, &maxx2, &minn2, chengshi, xiangzheng, gaoshu);
				p = q;
				q = maxx2;
				if (p != q) {
					aa[i] = q;
					bx[i] = x0;
					by[i] = y0;
					i++;
				}
				if (i >= 5)break;
			}
		}
		else if (YS > YE) {
			for (y0 = YS - 0.100000; y0 >= YE; y0 = y0 - 0.100000) {
				x0 = XE;
				sear(x0, y0, list, block, &maxx2, &minn2, chengshi, xiangzheng, gaoshu);
				p = q;
				q = maxx2;
				if (p != q) {
					aa[i] = q;
					bx[i] = x0;
					by[i] = y0;
					i++;
				}
				if (i >= 5)break;
			}

		}
	}
	*ii = i;

}
//二分求边界
void bSection(float* serx, float* sery, float xs, float ys, float xe, float ye, Information list[], Index block[131][359], checklist chengshi[], checklist xiangzheng[], checklist gaoshu[]) {
	int low, high, mid;
	int maxx2, minn2;
	sear(xs, ys, list, block, &maxx2, &minn2, chengshi, xiangzheng, gaoshu);
	low = maxx2;
	sear(xe, ye, list, block, &maxx2, &minn2, chengshi, xiangzheng, gaoshu);
	high = maxx2;
	float distance, xm, ym;
	distance = (xe - xs) * (xe - xs) + (ye - ys) * (ye - ys);
	while (distance >= 0.01) {
		xm = (xs + xe) / 2;
		ym = (ys + ye) / 2;
		sear(xm, ym, list, block, &maxx2, &minn2, chengshi, xiangzheng, gaoshu);
		mid = maxx2;
		if (mid == low) {
			xs = xm;
			ys = ym;
			low = mid;
		}
		else {
			xe = xm;
			ye = ym;
			high = mid;
		}
		distance = (xe - xs) * (xe - xs) + (ye - ys) * (ye - ys);
	}
	*serx = xm;
	*sery = ym;

}

//判断坐标是否在基站有效范围内
void range(float x, float y, Information list[], int num, int* flag) {
	float x0 = atof(list[num].coorx);
	float y0 = atof(list[num].coory);
	float jvli, qiangdu;
	jvli = (x - x0) * (x - x0) + (y - y0) * (y - y0);
	float jvli0;
	int flag0 = 0;
	if (strcmp(list[num].area, "城区") == 0)jvli0 = 90000.000000;
	if (strcmp(list[num].area, "乡镇") == 0)jvli0 = 1000000.000000;
	else if (strcmp(list[num].area, "高速") == 0)jvli0 = 25000000.000000;
	qiangdu = atof(list[num].qiangdu) * (jvli0 / jvli);
	if (qiangdu >= 1.0)flag0 = 1;
	else if (qiangdu < 1.0)flag0 = -1;
	*flag = flag0;
}

void bSection2(float* serx, float* sery, float xs, float ys, float xe, float ye, Information list[], Index block[131][359], checklist chengshi[], checklist xiangzheng[], checklist gaoshu[], int n) {
	int low, high, mid;
	int maxx2;
	range(xs, ys, list, n, &maxx2);
	low = maxx2;
	range(xe, ye, list, n, &maxx2);
	high = maxx2;
	float distance, xm, ym;
	distance = (xe - xs) * (xe - xs) + (ye - ys) * (ye - ys);
	while (distance >= 0.01) {
		xm = (xs + xe) / 2;
		ym = (ys + ye) / 2;
		range(xm, ym, list, n, &maxx2);
		mid = maxx2;
		if (mid == low) {
			xs = xm;
			ys = ym;
			low = mid;
		}
		else {
			xe = xm;
			ye = ym;
			high = mid;
		}
		distance = (xe - xs) * (xe - xs) + (ye - ys) * (ye - ys);
	}
	*serx = xm;
	*sery = ym;

}

