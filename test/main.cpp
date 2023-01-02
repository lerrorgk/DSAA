#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>
using namespace std;

//ofstream mycout("/home/lerrorgk/桌面/test1.txt");

void Random(int *a,int n,int l,int r)//生成范围在l~r的随机数
{

	srand(time(0));  //设置时间种子
	for(int i=0;i<n;i++){

		a[i]=rand()%(r-l+1)+l;//生成区间r~l的随机数
	}
}

void Print(int *a,int n)
{

	for(int i=0;i<n;i++)
		cout<<a[i]<<" ";
	cout<<endl;
}

int main()
{


	int n=10;//数组元素的个数，即生成随机数的个数
	int a[n];
	Random(a,n,1,100);//生成随机数的通常范围为0~32767，这里通过取模控制取值为0~100
	Print(a,n);
	return 0;
}
