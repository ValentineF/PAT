/*1044. 火星数字
火星人是以13进制计数的：

地球人的0被火星人称为tret。
地球人数字1到12的火星文分别为：jan, feb, mar, apr, may, jun, jly, aug, sep, oct, nov, dec。
火星人将进位以后的12个高位数字分别称为：tam, hel, maa, huh, tou, kes, hei, elo, syy, lok, mer, jou。
例如地球人的数字“29”翻译成火星文就是“hel mar”；而火星文“elo nov”对应地球数字“115”。为了方便交流，请你编写程序实现地球和火星数字之间的互译。

输入格式：

输入第一行给出一个正整数N（<100），随后N行，每行给出一个[0, 169)区间内的数字 —— 或者是地球文，或者是火星文。

输出格式：

对应输入的每一行，在一行中输出翻译后的另一种语言的数字。

输入样例：
4
29
5
elo nov
tam
输出样例：
hel mar
may
115
13
*/
//慢慢来，一步一步来（呸，好烦的题
#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
int main()
{
	string strLow[13] = {"tret", "jan", "feb", "mar", "apr", "may", "jun", "jly", "aug", "sep", "oct", "nov", "dec" };
	string strHigh[13] = { "","tam", "hel", "maa", "huh", "tou", "kes", "hei", "elo", "syy", "lok", "mer", "jou" };
	int n;
	cin >> n;
	cin.get();
	string str;
	for (int i = 0; i < n; i++)
	{
		getline(cin, str);
		int length = str.length();
		int temp = 0;
		if (str[0] <= '9' && str[0] >= '0')//数字
		{
			for (int i = 0; i < length; i++)
			{
				temp += (str[i] - '0') * pow(10, length - 1 - i);
			}
			if (temp / 13 == 0)//<13
			{
				cout << strLow[temp % 13] << endl;
			}
			else//>13
			{
				cout << strHigh[temp / 13];
				if (temp % 13 != 0)
				{
					cout<<" " << strLow[temp % 13];
				}
				cout<< endl;
			}
		}
		else
		{
			if (length == 3 || length == 4)//13整数倍，或者小于13
			{
				for (int i = 1; i <= 12; i++)
				{
					if (str == strHigh[i])
					{
						cout << 13 * i << endl;
						break;
					}						
				}
				for (int i = 0; i <= 12; i++)
				{
					if (str == strLow[i])
					{
						cout << i << endl;
						break;
					}
				}
			}
			else
			{
				int sum = 0;
				string str1 = str.substr(0, 3);
				string str2 = str.substr(4, 3);
				for (int i = 1; i <= 12; i++)
				{
					if (str1 == strHigh[i])
					{
						sum += 13 * i;
						break;
					}
				}
				for (int i = 1; i <= 12; i++)
				{
					if (str2 == strLow[i])
					{
						sum += i;
						break;
					}
				}
				cout << sum << endl;
			}
		}
	}
	system("pause");
	return 0;
}

