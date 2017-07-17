/*1007. 素数对猜想 
让我们定义 dn 为：dn = pn+1 - pn，其中 pi 是第i个素数。显然有 d1=1 且对于n>1有 dn 是偶数。“素数对猜想”认为“存在无穷多对相邻且差为2的素数”。

现给定任意正整数N (< 105)，请计算不超过N的满足猜想的素数对的个数。

输入格式：每个测试输入包含1个测试用例，给出正整数N。

输出格式：每个测试用例的输出占一行，不超过N的满足猜想的素数对的个数。

输入样例：
20
输出样例：
4
*/
//题意好奇怪，前半句话的描述有什么意义嘛，净干扰做题

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

int* GenerPrime(int n)//生成<=n的质数数组
{
	int  i = 1, j = 2;;
	int *num = new int[n];
	while (j <= n)
	{
		if (IsPrime(j))
			num[i++] = j;
		j++;
	}
	return num;
}

int main()
{
	int n,count = 0;
	cin >> n;
	int *num = new int(n);
	num = GenerPrime(n);
	for (int i = 1; num[i+1] <= n; i++)
	{
		if (num[i + 1] - num[i] == 2)
			count++;
	}
	cout << count;
	system("pause");
	return 0;
}



