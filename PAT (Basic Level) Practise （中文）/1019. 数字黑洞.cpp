/*1019. 数字黑洞
给定任一个各位数字不完全相同的4位正整数，如果我们先把4个数字按非递增排序，再按非递减排序，然后用第1个数字减第2个数字，将得到一个新的数字。一直重复这样做，我们很快会停在有“数字黑洞”之称的6174，这个神奇的数字也叫Kaprekar常数。

例如，我们从6767开始，将得到

7766 - 6677 = 1089
9810 - 0189 = 9621
9621 - 1269 = 8352
8532 - 2358 = 6174
7641 - 1467 = 6174
... ...
现给定任意4位正整数，请编写程序演示到达黑洞的过程。
输入格式：
输入给出一个(0, 10000)区间内的正整数N。
输出格式：
如果N的4位数字全相等，则在一行内输出“N - N = 0000”；否则将计算的每一步在一行内输出，直到6174作为差出现，输出格式见样例。注意每个数字按4位数格式输出。
输入样例1：
6767
输出样例1：
7766 - 6677 = 1089
9810 - 0189 = 9621
9621 - 1269 = 8352
8532 - 2358 = 6174
输入样例2：
2222
输出样例2：
2222 - 2222 = 0000*/

#include<iostream>
#include<string>
#include<algorithm>
#include<iomanip>
using namespace std;
bool cmp1(int a, int b) //降序
{
	return  a > b;
}
bool cmp2(int a, int b)//升序
{
	return  a < b;
}
int first(int *n)
{
	int a = 0;
	sort(n, n + 4, cmp2);
	for (int i = 3; i >= 0; i--)
		a = a + n[i] * pow(10, i);
	return a;
}
int last(int *n)
{
	int b = 0;
	sort(n, n + 4, cmp1);
	for (int i = 0; i <= 3; i++)
		b = b + n[i] * pow(10, i);
	return b;
}
int main()
{
	string s;
	int n[4];
	int res;
	cin >> s;
	s = s + "0000";
	for (int i = 0; i <= 3; i++)
		n[i] = s[i]-'0';
	while (1)
	{
		res = first(n) - last(n);
		cout<< setfill('0') << setw(4) << first(n) << " - " << setfill('0') << setw(4) << last(n) << " = " << setfill('0') << setw(4) << res;
		if (res == 0 || res == 6174)
			break;
		cout << endl;
		for (int i = 3; i >= 0; i--)
		{
			n[i] = res % 10;
			res /= 10;
		}
		
	}	
	return 0;
}
