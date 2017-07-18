/*1016. 部分A+B
正整数A的“DA（为1位整数）部分”定义为由A中所有DA组成的新整数PA。例如：给定A = 3862767，DA = 6，则A的“6部分”PA是66，因为A中有2个6。

现给定A、DA、B、DB，请编写程序计算PA + PB。

输入格式：

输入在一行中依次给出A、DA、B、DB，中间以空格分隔，其中0 < A, B < 1010。

输出格式：

在一行中输出PA + PB的值。

输入样例1：
3862767 6 13530293 3
输出样例1：
399
输入样例2：
3862767 1 13530293 8
输出样例2：
0
*/
//贼简单
#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
int search(string a, int b)
{
	int count = 0;
	for (int i = 0; i < a.length(); i++)
	{
		if (a[i] - '0' == b)
			count++;
	}
	return count;
}
int main() 
{
	string A, B;
	int DA, DB;
	int countA, countB;
	int PA = 0, PB = 0;
	cin >> A >> DA >> B >> DB;
	countA = search(A, DA);
	countB = search(B, DB);
	for (int i = 1; i <= countA; i++)
	{
		PA += PB +pow(10, i - 1) * DA;
	}
	for (int i = 1; i <= countB; i++)
	{
		PB = PB+pow(10, i - 1) * DB;
	}
	cout << PA + PB;
	system("pause");
	return 0;
}
