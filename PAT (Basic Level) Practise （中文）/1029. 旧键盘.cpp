/*1029. 旧键盘
旧键盘上坏了几个键，于是在敲一段文字的时候，对应的字符就不会出现。现在给出应该输入的一段文字、以及实际被输入的文字，请你列出肯定坏掉的那些键。

输入格式：

输入在2行中分别给出应该输入的文字、以及实际被输入的文字。每段文字是不超过80个字符的串，由字母A-Z（包括大、小写）、数字0-9、以及下划线“_”（代表空格）组成。题目保证2个字符串均非空。

输出格式：

按照发现顺序，在一行中输出坏掉的键。其中英文字母只输出大写，每个坏键只输出一次。题目保证至少有1个坏键。

输入样例：
7_This_is_a_test
_hs_s_a_es
输出样例：
7TI*/
#include <iostream>
#include <algorithm>
#include <iomanip>
#include <string>
using namespace std;
int main()
{
	string str1, str2,result;
	cin >> str1 >> str2;
	transform(str1.begin(), str1.end(), str1.begin(), ::toupper);
	transform(str2.begin(), str2.end(), str2.begin(), ::toupper);
	for (int i = 0; i < str2.length(); i++)
		str1.erase(remove(str1.begin(), str1.end(), str2[i]), str1.end());
	cout << str1[0];																				
	for (int i = 0; i < str1.length(); i++)
	{
 		for (int j = 0,count = 0; j < i; j++)
		{
			if (str1[i] == str1[j])
				break;
			else
				count++;
			if (count == i)
				cout << str1[i];
		}

	}	
	system("pause");
	return 0;
}

