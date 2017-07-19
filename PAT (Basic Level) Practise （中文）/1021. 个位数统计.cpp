/*1021. 个位数统计
给定一个k位整数N = dk-1*10k-1 + ... + d1*101 + d0 (0<=di<=9, i=0,...,k-1, dk-1>0)，请编写程序统计每种不同的个位数字出现的次数。例如：给定N = 100311，则有2个0，3个1，和1个3。

输入格式：

每个输入包含1个测试用例，即一个不超过1000位的正整数N。

输出格式：

对N中每一种不同的个位数字，以D:M的格式在一行中输出该位数字D及其在N中出现的次数M。要求按D的升序输出。

输入样例：
100311
输出样例：
0:2
1:3
3:1
*/
//额。。。。
#include<iostream>
#include<string>
#include<algorithm>
#include<iomanip>
using namespace std;
int main()
{
	string a;
	int b[10] = { 0 };
	cin >> a;
	for (int i = 0; i < a.length(); i++)
	{
		switch (a[i])
		{
		case '0': b[0]++; break;
		case '1': b[1]++; break;
		case '2': b[2]++; break;
		case '3': b[3]++; break;
		case '4': b[4]++; break;
		case '5': b[5]++; break;
		case '6': b[6]++; break;
		case '7': b[7]++; break;
		case '8': b[8]++; break;
		case '9': b[9]++; break;
		}
	}
	for (int i = 0; i <= 8; i++)
	{
		if(b[i] != 0)
			cout << i << ":" << b[i] << endl;
	}
	if(b[9] != 0)
		cout << 9 << ":" << b[9] << endl;
	system("pause");
	return 0;
}
