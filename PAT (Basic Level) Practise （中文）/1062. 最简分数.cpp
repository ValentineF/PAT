/*1062. 最简分数
一个分数一般写成两个整数相除的形式：N/M，其中M不为0。最简分数是指分子和分母没有公约数的分数表示形式。

现给定两个不相等的正分数 N1/M1 和 N2/M2，要求你按从小到大的顺序列出它们之间分母为K的最简分数。

输入格式：
输入在一行中按N/M的格式给出两个正分数，随后是一个正整数分母K，其间以空格分隔。题目保证给出的所有整数都不超过1000。
输出格式：
在一行中按N/M的格式列出两个给定分数之间分母为K的所有最简分数，按从小到大的顺序，其间以1个空格分隔。行首尾不得有多余空格。题目保证至少有1个输出。
输入样例：
7/18 13/20 12
输出样例：
5/12 7/12*/
// = = ,他居然和我说，输入的两个数大小没确定
#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
int gcd(int a, int b)
{
	return a%b ? gcd(b, a%b) : b;
}
int main()
{
	int n1, m1, n2, m2, n;
	char ch;
	cin >> n1 >> ch >> m1 >> n2 >> ch >> m2 >> n;
	int *ans = new int[n];
	int j = 0;
	double num1 = (double)n1 / m1;
	double num2 = (double)n2 / m2;
	for (int i = 1; i < n; i++)
	{
		double num = (double)i / n;
		ans[j] = 0;
		if ((num < num2 && num > num1) || (num > num2 && num < num1))
		{
			if (gcd(i, n) == 1)
			{
				ans[j++] = i;
			}
		}
	}
	for (int i = 0; i < j-1; i++)
	{
		cout << ans[i] << "/" << n << " ";
	}
	cout << ans[j - 1] << "/" << n;
	system("pause");
	return 0;
}

