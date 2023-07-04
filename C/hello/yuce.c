#include <stdio.h>
double songHeight(double fHeight, double mHeight);
int mains() {

	double fatherHeight;
	double matherHeight;
	double Height;

	printf("请输入父亲身高：\n");
	scanf_s("%lf",&fatherHeight);

	printf("请输入母亲身高：\n");
	scanf_s("%lf",&matherHeight);

	Height = songHeight(fatherHeight, matherHeight);
	printf("预测孩子的身高：\n");
	printf("%lf\n",Height);
	return 0;
}

double songHeight(double fHeight,double mHeight) {
	double Height = fHeight + mHeight;
	return Height;
}
