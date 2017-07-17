/*1013. 数素数
令Pi表示第i个素数。现任给两个正整数M <= N <= 104，请输出PM到PN的所有素数。

输入格式：

输入在一行中给出M和N，其间以空格分隔。

输出格式：

输出从PM到PN的所有素数，每10个数字占1行，其间以空格分隔，但行末不得有多余空格。

输入样例：
5 27
输出样例：
11 13 17 19 23 29 31 37 41 43
47 53 59 61 67 71 73 79 83 89
97 101 103*/
//格式输出比较麻烦，可以复用之前1007的函数
#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
bool IsPrime(int num)
{
	for (int i = 2; i <= sqrt(num); i++)
	{
		if (num%i == 0)
			return false;
	}
	return true;
}
int* GenerPrime(int n)//生成n个质数数组
{
	int  i = 1, j = 2;;
	int *num = new int[n];
	while (i <= n)
	{
		if (IsPrime(j))
		{
			num[i++] = j;		
		}
		j++;
	}
	return num;
}
int main() 
{
	int a, b, count = 1;
	cin >> a >> b;
	int *c = GenerPrime(b);
	for (int i = a; i <= b; i++)
	{
		cout << c[i];
		count++;
		if (count != 11 && i != b)
			cout << " ";
		if (count == 11)
		{
			count = 1;
			cout << endl;
		}
	}
	return 0;
}
