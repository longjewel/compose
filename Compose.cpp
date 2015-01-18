// Compose.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <stdio.h>

void Range(char *src,int base,int lyr)
{
	if (lyr==base)//基底条件
	{
		puts(src);
		return;
	}

	int i;
	char tmp;
//
	Range(src,base,lyr+1);//递归调用
	for (i=1;lyr+i!=base;i++)
	{
		tmp=src[lyr+i];
		src[lyr+i]=src[lyr];
		src[lyr]=tmp;
		Range(src,base,lyr+1);
		tmp=src[lyr+i];
		src[lyr+i]=src[lyr];
		src[lyr]=tmp;
	}
}

void Compose(char *src,char *rslt,int base,int n,int lyr)
{
	if (lyr==base)
	{
		rslt[base]=0;
		puts(rslt);
		return;
	}

	int i;
//	for (i=0;i<n-1;i++)
	for (i=0;src[n-1+i]!=0;i++)
	{
		rslt[lyr]=src[i];
		Compose(&src[i+1],rslt,base,n-1,lyr+1);
	}
}

int main(int argc, char* argv[])
{
	char src[]="0123456789";
	char rslt[100];
	memset(rslt,0,100);
//	Range(src,3,0);
	Compose(src,rslt,4,4,0);
	return 0;
}
