/*1048. 数字加密
本题要求实现一种数字加密方法。首先固定一个加密用正整数A，对任一正整数B，将其每1位数字与A的对应位置上的数字进行以下运算：对奇数位，对应位的数字相加后对13取余——这里用J代表10、Q代表11、K代表12；对偶数位，用B的数字减去A的数字，若结果为负数，则再加10。这里令个位为第1位。

输入格式：

输入在一行中依次给出A和B，均为不超过100位的正整数，其间以空格分隔。

输出格式：

在一行中输出加密后的结果。

输入样例：
1234567 368782971
输出样例：
3695Q8118
*/
//当B字符串不够长的时候需要补0
#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
char Ans1(char a, char b)//奇数
{
	int c = ((a - '0') + (b - '0')) % 13;
	switch (c)
	{
	case 10: return 'J';
		break;
	case 11: return 'Q';
		break;
	case 12: return 'K';
		break;
	default: return c + '0';
		break;
	}
}
char Ans2(char a, char b)
{
	int c = b - a;
	if (c >= 0)
		return c + '0';
	else
		return c + 10 + '0';
}
int main()
{
	string str1, str2;
	string str = "";
	cin >> str1 >> str2;
	int length1 = str1.length();
	int length2 = str2.length();
	bool flag = true;
	int p = 0;
	for (int i = length1 - 1, j = length2 - 1; i >= 0; i--, j--)
	{
		if (j >= 0)
		{
			if (flag)
				str2[j] = Ans1(str1[i], str2[j]);
			else
				str2[j] = Ans2(str1[i], str2[j]);
		}
		else
		{
			if (flag)
				str += Ans1(str1[i], '0');
			else
				str += Ans2(str1[i], '0');
		}
		flag = !flag;
	}
	reverse(str.begin(), str.end());
	str2 = str + str2;
	cout << str2;
	system("pause");
	return 0;
}