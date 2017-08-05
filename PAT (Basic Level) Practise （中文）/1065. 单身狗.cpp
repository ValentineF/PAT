/*1065. 单身狗
“单身狗”是中文对于单身人士的一种爱称。本题请你从上万人的大型派对中找出落单的客人，以便给予特殊关爱。

输入格式：

输入第一行给出一个正整数N（<=50000），是已知夫妻/伴侣的对数；随后N行，每行给出一对夫妻/伴侣——为方便起见，每人对应一个ID号，为5位数字（从00000到99999），ID间以空格分隔；之后给出一个正整数M（<=10000），为参加派对的总人数；随后一行给出这M位客人的ID，以空格分隔。题目保证无人重婚或脚踩两条船。

输出格式：

首先第一行输出落单客人的总人数；随后第二行按ID递增顺序列出落单的客人。ID间用1个空格分隔，行的首尾不得有多余空格。

输入样例：
3
11111 22222
33333 44444
55555 66666
7
55555 44444 10000 88888 22222 11111 23333
输出样例：
5
10000 23333 44444 55555 88888*/
#include<iostream>
#include<string>
#include<algorithm>
#include<map>
#include<set>
using namespace std;
int a[100000] = {0};
int main()
{
	int num1;
	cin >> num1;
	map<int, int> m1;
	for (int i = 0; i < num1; i++)
	{
		int temp1, temp2;
		cin >> temp1 >> temp2;
		m1[temp1] = temp2;
		m1[temp2] = temp1;
	}
	int num2;
	cin >> num2;
	for (int i = 0; i < num2; i++)
	{
		int temp;
 		cin >> temp;
		if(a[temp] != 2)
			a[temp] = 1;//存在的数都设置为1
		if (m1.count(temp) == 1)
		{		
			a[m1[temp]] = 2;//把对象++
		}		
	}
	set<int> s;
	for (int i = 0; i < 100000; i++)
	{
		if (a[i] == 1)
			s.insert(i);
	}
	cout << s.size()<<endl;
	for (auto it = s.begin(); it != s.end(); it++) 
	{
		if (it != s.begin()) 
			printf(" ");
		printf("%05d", *it);
	}



	system("pause");
	return 0;
}