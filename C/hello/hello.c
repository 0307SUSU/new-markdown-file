#include <stdio.h>   /*编译预处理命令，声明了在程序编译之前要预先处理的内容。*/
#define Height 10   /*定义常量height*/
int calculate(int Long, int width);
int mainf() {    /*每个C程序都必须有一个main函数，表示程序的入口部分。*/
	printf("welcome to HangZhou\n");  /*printf是格式化输出函数，用于向控制台输出文字或符号。括号中的内容称为函数参数*/
	printf("梦想还是要有的，万一实现了呢！\n");
	printf("😊😊😍☆*: .｡. o(≧▽≦)o .｡.:*☆");


	/*计算长方形的体积*/
	int m_Long;
	int m_width;
	int result;

	printf("长方形的高度为：%d\n", Height);

	printf("请输入长度\n");
	scanf_s("%d",&m_Long);

	printf("请输入宽度\n");
	scanf_s("%d",&m_width);

	result = calculate(m_Long, m_width);
	printf("长方形的体积是：");
	printf("%d\n",result);

	return 0;   /*本行语句使main函数终止运行，并向操作系统返回一个整型常量0。前面介绍main函数时，说过它需要返回一个整型值，这里0就是要返回的整型值。*/
}

int calculate(int Long, int width) {
	int result = Long * width * Height; /*长方形的体积等于长*宽*高*/
	return result;
}