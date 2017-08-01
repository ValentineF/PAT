/*1017. A除以B
本题要求计算A/B，其中A是不超过1000位的正整数，B是1位正整数。你需要输出商数Q和余数R，使得A = B * Q + R成立。

输入格式：

输入在1行中依次给出A和B，中间以1空格分隔。

输出格式：

在1行中依次输出Q和R，中间以1空格分隔。

输入样例：
123456789050987654321 7
输出样例：
17636684150141093474 3
*/
//其实题目很简单，但是被吓到了，注意当只有一位时，商为0的情况
#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
int main()
{
	string str;
	int mod;
	cin >> str >> mod;
	int length = str.length();
	int temp = 0;
	for (int i = 0; i < length; i++)
	{
		temp += str[i] - '0';		
		if (i == 0 && temp / mod == 0)
		{
			if (length == 1)
				cout << 0;
		}			
		else
			cout << temp / mod;
		temp = (temp % mod) * 10;
	}
	cout<<" " << temp / 10;
	system("pause");
	return 0;
}

