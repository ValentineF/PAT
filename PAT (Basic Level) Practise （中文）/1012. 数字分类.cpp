/*1012. 数字分类
给定一系列正整数，请按要求对数字进行分类，并输出以下5个数字：

A1 = 能被5整除的数字中所有偶数的和；
A2 = 将被5除后余1的数字按给出顺序进行交错求和，即计算n1-n2+n3-n4...；
A3 = 被5除后余2的数字的个数；
A4 = 被5除后余3的数字的平均数，精确到小数点后1位；
A5 = 被5除后余4的数字中最大数字。
输入格式：

每个输入包含1个测试用例。每个测试用例先给出一个不超过1000的正整数N，随后给出N个不超过1000的待分类的正整数。数字间以空格分隔。

输出格式：

对给定的N个正整数，按题目要求计算A1~A5并在一行中顺序输出。数字间以空格分隔，但行末不得有多余空格。

若其中某一类数字不存在，则在相应位置输出“N”。

输入样例1：
13 1 2 3 4 5 6 7 8 9 10 20 16 18
输出样例1：
30 11 2 9.7 9
输入样例2：
8 1 2 4 5 6 7 9 16
输出样例2：
N 11 2 N 9*/
//可以选择用switch做，但是图方便就写了五个函数，然后A2判断时注意是可以相同的数字，然后相减就是0，需要改判断条件


#include <iostream>
#include<string>
#include <iomanip>
using namespace std;
int n;
void A1(int *a)
{
	int sum = 0;
	for (int i = 0; i < n; i++)
	{
		if (a[i] % 2 == 0 && a[i] % 5 == 0)
		{
			sum += a[i];
		}
	}
	if (sum)
		cout << sum << " ";
	else
	{
		cout << "N ";
	}
}
void A2(int *a)
{
	int sum = 0;
	bool flag = true;
	bool flag1 = false;
	for (int i = 0; i < n; i++)
	{
		if (a[i] % 5 == 1)
		{
			flag1 = true;
			if (flag)
				sum += a[i];
			else
			{
				sum -= a[i];
			}
			flag = !flag;
		}
	}
	if (flag1)
		cout << sum << " ";
	else
	{
		cout << "N ";
	}
}
void A3(int *a)
{
	int sum = 0;
	for (int i = 0; i < n; i++)
	{
		if (a[i] % 5 == 2)
		{
			sum++;
		}
	}
	if (sum)
		cout << sum << " ";
	else
	{
		cout << "N ";
	}
}
void A4(int *a)
{
	int count = 0;
	float sum = 0;
	for (int i = 0; i < n; i++)
	{
		if (a[i] % 5 == 3)
		{
			sum += a[i];
			count++;
		}
	}
	if (count)
	{
		sum = sum / count;
		cout << fixed << setprecision(1) << sum << " ";
	}
	else
	{
		cout << "N ";
	}
}
void A5(int *a)
{
	int sum = 0;
	for (int i = 0; i < n; i++)
	{
		if (a[i] % 5 == 4)
		{
			sum = sum > a[i] ? sum : a[i];
		}
	}
	if (sum)
		cout << sum;
	else
	{
		cout << "N";
	}
}
int main() 
{

	cin >> n;
	int *num = new int[n];
	for (int i = 0; i < n; i++)
		cin >> num[i];
	A1(num); A2(num); A3(num); A4(num); A5(num);
	system("pause");
	return 0;
}
