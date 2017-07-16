/*1006. 换个格式输出整数
让我们用字母B来表示“百”、字母S表示“十”，用“12...n”来表示个位数字n（<10），换个格式来输出任一个不超过3位的正整数。例如234应该被输出为BBSSS1234，因为它有2个“百”、3个“十”、以及个位的4。

输入格式：每个测试输入包含1个测试用例，给出正整数n（<1000）。

输出格式：每个测试用例的输出占一行，用规定的格式输出n。

输入样例1：
234
输出样例1：
BBSSS1234
输入样例2：
23
输出样例2：
SS123*/

#include<iostream>
#include<string>
using namespace std;
void outB(int n)
{
	while (n--)
		cout << 'B';
}
void outS(int n)
{
	while (n--)
		cout << 'S';
}
void outG(int n)
{
	for(int i = 1; i<=n;i++)
		cout << i;
}
int main()
{
	int num;
	int B = 0, S = 0, G = 0;
	cin >> num;
	B = num / 100;
	outB(B);
	S = (num / 10) % 10;
	outS(S);
	G = num % 10;
	outG(G);
	return 0;
}



