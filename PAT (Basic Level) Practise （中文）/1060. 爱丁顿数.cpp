/*1060. 爱丁顿数
英国天文学家爱丁顿很喜欢骑车。据说他为了炫耀自己的骑车功力，还定义了一个“爱丁顿数”E，即满足有E天骑车超过E英里的最大整数E。据说爱丁顿自己的E等于87。

现给定某人N天的骑车距离，请你算出对应的爱丁顿数E（<=N）。

输入格式：

输入第一行给出一个正整数N（<=105），即连续骑车的天数；第二行给出N个非负整数，代表每天的骑车距离。

输出格式：

在一行中给出N天的爱丁顿数。

输入样例：
10
6 7 6 9 3 10 8 2 7 8
输出样例：
6*/
//不知道怎么的就过了，感觉数组越界了可能
#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
bool cmp(int a, int b)
{
	return a > b;
}
int a[100000];

int main()
{
	long int n;
	cin >> n;
	int i;
	int ans = 0;
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
	}
	sort(a+1, a + n+1, cmp);
	for (i = 1; i <= n; i++)
	{
		if (a[i] > i)
			ans++;
		else
			break;
	}
	cout << ans;
	system("pause");
	return 0;
}
