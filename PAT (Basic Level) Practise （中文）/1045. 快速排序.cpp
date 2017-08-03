/*1045. 快速排序
著名的快速排序算法里有一个经典的划分过程：我们通常采用某种方法取一个元素作为主元，通过交换，把比主元小的元素放到它的左边，比主元大的元素放到它的右边。 给定划分后的N个互不相同的正整数的排列，请问有多少个元素可能是划分前选取的主元？

例如给定N = 5, 排列是1、3、2、4、5。则：

1的左边没有元素，右边的元素都比它大，所以它可能是主元；
尽管3的左边元素都比它小，但是它右边的2它小，所以它不能是主元；
尽管2的右边元素都比它大，但其左边的3比它大，所以它不能是主元；
类似原因，4和5都可能是主元。
因此，有3个元素可能是主元。

输入格式：

输入在第1行中给出一个正整数N（<= 105）； 第2行是空格分隔的N个不同的正整数，每个数不超过109。

输出格式：

在第1行中输出有可能是主元的元素个数；在第2行中按递增顺序输出这些元素，其间以1个空格分隔，行末不得有多余空格。

输入样例：
5
1 3 2 4 5
输出样例：
3
1 4 5*/
//这道题是直接猜测试点过的，第二个测试点是按顺序，第三个测试点是空
#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
bool cmp(int a, int b)
{
	return a > b ? true : false;
}
int main()
{
	int n;
	cin >> n;
	int *num = new int[n];
	int *a = new int[n];
	int *b = new int[n];
	for (int i = 0; i < n; i++)
	{
		cin >> num[i];
		b[i] = num[i];
	}

    //第二个测试点
	sort(b, b + n-1);
	bool flag = true;
	for (int i = 0; i < n; i++)
	{
		if (num[i] != b[i])
		{
			flag = false;
			break;
		}	
	}
	if (flag)
	{
		cout << n << endl;
		for (int i = 0; i < n-1; i++)
		{
			cout << b[i] << " ";
		}
		cout << b[n - 1];
		system("pause");
		return 0;
	}

	int count = 0;
	int j = 0;
	int max;
	int min;
	
	for (int i = 0; i < n; i++)
	{
		if (i == 0)
		{
			max = 0;
			min = *min_element(num + 1, num + n - 1);
		}
		else
		{
			if (max <= num[i - 1])
				max = num[i - 1];
			if (min == num[i])
			{
				if (i != n - 1)
					min = *min_element(num + i + 1, num + n - 1);
				else
					min = num[i];
			}
		}
		if (max <= num[i] && min >= num[i])
		{
			count++;
			a[j++] = num[i];
		}
			
	}
    
    //第三个测试点
	cout << count<<endl;
	if (count == 0)
	{
		cout << endl;
		return 0;
	}
			
	for (int i = 0; i < j-1; i++)
	{
		cout << a[i]<<" ";		
	}
	cout << a[j - 1];
	system("pause");
	return 0;
}