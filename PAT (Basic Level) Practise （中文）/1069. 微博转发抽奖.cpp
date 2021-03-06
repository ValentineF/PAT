/*1069. 微博转发抽奖
小明PAT考了满分，高兴之余决定发起微博转发抽奖活动，从转发的网友中按顺序每隔N个人就发出一个红包。请你编写程序帮助他确定中奖名单。

输入格式：

输入第一行给出三个正整数M（<= 1000）、N和S，分别是转发的总量、小明决定的中奖间隔、以及第一位中奖者的序号（编号从1开始）。随后M行，顺序给出转发微博的网友的昵称（不超过20个字符、不包含空格回车的非空字符串）。

注意：可能有人转发多次，但不能中奖多次。所以如果处于当前中奖位置的网友已经中过奖，则跳过他顺次取下一位。

输出格式：

按照输入的顺序输出中奖名单，每个昵称占一行。如果没有人中奖，则输出“Keep going...”。

输入样例1：
9 3 2
Imgonnawin!
PickMe
PickMeMeMeee
LookHere
Imgonnawin!
TryAgainAgain
TryAgainAgain
Imgonnawin!
TryAgainAgain
输出样例1：
PickMe
Imgonnawin!
TryAgainAgain
输入样例2：
2 3 5
Imgonnawin!
PickMe
输出样例2：
Keep going...*/
#include<iostream>
#include<string>
#include<algorithm>
#include<map>
using namespace std;
int main()
{
	int m, n, s;//转发的总量、小明决定的中奖间隔、以及第一位中奖者的序号
	cin >> m >> n >> s;
	string *str = new string[m];
	map<string, bool> map1;
	for (int i = 0; i < m; i++)
	{
		cin >> str[i];
		map1[str[i]] = true;
	}
	for (int i = s-1; i < m;)
	{
		if (map1[str[i]])
		{
			cout << str[i];
			map1[str[i]] = false;
			i = i + n;
			if (i < m)
			{
				cout << endl;
			}
			else
			{
				system("pause");
				return 0;
			}
		}
		else
		{
			i++;
		}	
	}
	cout << "Keep going...";
	system("pause");
	return 0;
}