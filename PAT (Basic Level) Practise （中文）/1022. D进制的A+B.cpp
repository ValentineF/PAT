/*1022. D进制的A+B
输入两个非负10进制整数A和B(<=230-1)，输出A+B的D (1 < D <= 10)进制数。
输入格式：
输入在一行中依次给出3个整数A、B和D。
输出格式：
输出A+B的D进制数。
输入样例：
123 456 8
输出样例：
1103
*/
//始终牢记能用Int做的就用Int做，32次也不大
#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
void  convert(int a, int n)
{
	int b[200] = { 0 };
	int i = 0;
	while (a)
	{	
		b[i++] = a % n;
		a = a / n;
	}
	if (i == 0)//结果为0
		cout << 0;
	while (i--)
		cout << b[i];
}
int main()
{
	int a, b,c,n;
	cin >> a >> b>>n;
	c = a + b;
	convert(c, n);
	system("pause");
	return 0;
}


