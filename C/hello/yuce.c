#include <stdio.h>
double songHeight(double fHeight, double mHeight);
int mains() {

	double fatherHeight;
	double matherHeight;
	double Height;

	printf("�����븸����ߣ�\n");
	scanf_s("%lf",&fatherHeight);

	printf("������ĸ����ߣ�\n");
	scanf_s("%lf",&matherHeight);

	Height = songHeight(fatherHeight, matherHeight);
	printf("Ԥ�⺢�ӵ���ߣ�\n");
	printf("%lf\n",Height);
	return 0;
}

double songHeight(double fHeight,double mHeight) {
	double Height = fHeight + mHeight;
	return Height;
}
