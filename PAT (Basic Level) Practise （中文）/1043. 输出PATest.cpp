/*1043. 输出PATest
给定一个长度不超过10000的、仅由英文字母构成的字符串。请将字符重新调整顺序，按“PATestPATest....”这样的顺序输出，并忽略其它字符。当然，六种字符的个数不一定是一样多的，若某种字符已经输出完，则余下的字符仍按PATest的顺序打印，直到所有字符都被输出。

输入格式：

输入在一行中给出一个长度不超过10000的、仅由英文字母构成的非空字符串。

输出格式：

在一行中按题目要求输出排序后的字符串。题目保证输出非空。

输入样例：
redlesPayBestPATTopTeePHPereatitAPPT
输出样例：
PATestPATestPTetPTePePee*/
//好像用了挺多switch的。。
#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
int main()
{
	int a[6] = { 0 };
	string str;
	cin >> str;
	int length = str.length();
	for (int i = 0; i < length; i++)
	{
		switch (str[i])
		{
		    case 'P': a[0]++;
				break;
			case 'A': a[1]++;
				break;
			case 'T': a[2]++;
				break;
			case 'e': a[3]++;
				break;
			case 's': a[4]++;
				break;
			case 't': a[5]++;
				break;
		}
	} 
	int minNumber = *min_element(a, a + 6);
	int maxNumber = *max_element(a, a + 6);
	for (int i = 0; i <= 5; i++)
	{
		a[i] -= minNumber;
	}
	for (int i = 0; i < minNumber; i++)
	{
		cout << "PATest";
	}
	while (maxNumber)
	{
		for (int i = 0; i <= 5; i++)
		{
			if (a[i] != 0)
			{
				a[i]--;
				switch (i)
				{
				case 0: cout << 'P';
					break;
				case 1: cout << 'A';
					break;
				case 2: cout << 'T';
					break;
				case 3: cout << 'e';
					break;
				case 4: cout << 's';
					break;
				case 5: cout << 't';
					break;
				}
			}
			
		}
		maxNumber--;
	}
	system("pause");
	return 0;
}