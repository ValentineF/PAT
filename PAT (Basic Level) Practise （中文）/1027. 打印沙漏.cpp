/*1027. 打印沙漏
本题要求你写个程序把给定的符号打印成沙漏的形状。例如给定17个“*”，要求按下列格式打印

*****
 ***
  *
 ***
*****
所谓“沙漏形状”，是指每行输出奇数个符号；各行符号中心对齐；相邻两行符号数差2；符号数先从大到小顺序递减到1，再从小到大顺序递增；首尾符号数相等。

给定任意N个符号，不一定能正好组成一个沙漏。要求打印出的沙漏能用掉尽可能多的符号。

输入格式：

输入在一行给出1个正整数N（<=1000）和一个符号，中间以空格分隔。

输出格式：

首先打印出由给定符号组成的最大的沙漏形状，最后在一行中输出剩下没用掉的符号数。

输入样例：
19 *
输出样例：
*****
 ***
  *
 ***
*****
2*/
//就算用完了你也得告诉他有个0，原来是这个意思
#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
int main()
{
	int n;
	int row;
	int count;
	int remain;
	char ch;
	cin >> n;
	cin.get();
	ch = getchar();
	row = sqrt((n + 1) / 2);
	count = 2 * row - 1;
	remain = n - 2 * row*row + 1;
	if (n == 0)
		return 0;
	for (int i = 0; i < row; i++)
	{
		for (int p = 0; p < i; p++)
		{
			cout << " ";
		}
		for (int q = 0; q < (count - 2 * i); q++)
		{
			cout << ch;
		}
		cout << endl;
	}
	int j = row - 2;
	for (int i = 1; i < row; i++,j--)
	{
		for (int p = 0; p < j; p++)
		{
			cout << " ";
		}
		for (int q = 0; q < (2*i+1); q++)
		{
			cout << ch;
		}
		cout << endl;
	}
	cout << remain << endl;
	system("pause");
	return 0;
}