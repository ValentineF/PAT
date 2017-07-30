/*1061. 判断题
输入格式：

输入在第一行给出两个不超过100的正整数N和M，分别是学生人数和判断题数量。第二行给出M个不超过5的正整数，是每道题的满分值。第三行给出每道题对应的正确答案，0代表“非”，1代表“是”。随后N行，每行给出一个学生的解答。数字间均以空格分隔。

输出格式：

按照输入的顺序输出每个学生的得分，每个分数占一行。

输入样例：
3 6
2 1 3 3 4 5
0 0 1 0 1 1
0 1 1 0 0 1
1 0 1 0 1 0
1 1 0 0 1 1
输出样例：
13
11
12*/
#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
	int n, m;
	cin >> n >> m;
	int *score = new int[m];
	int *ans = new int[m];
	int *sum = new int[n];
	int temp;
	for (int i = 0; i < m; i++)
	{
		cin >> score[i];
	}
	for (int i = 0; i < m; i++)
	{
		cin >> ans[i];
	}
	for (int i = 0; i < n; i++)
	{
		sum[i] = 0;
		for (int j = 0; j < m; j++)
		{
			cin >> temp;
			if (temp == ans[j])
			{
				sum[i] += score[j];
			}
		}
	}
	for (int i = 0; i < n-1; i++)
	{
		cout << sum[i] << endl;
	}
	cout << sum[n-1];
	system("pause");
	return 0;
}

