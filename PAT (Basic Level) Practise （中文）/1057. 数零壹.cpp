/*1057. 数零壹
给定一串长度不超过105的字符串，本题要求你将其中所有英文字母的序号（字母a-z对应序号1-26，不分大小写）相加，得到整数N，然后再分析一下N的二进制表示中有多少0、多少1。例如给定字符串“PAT (Basic)”，其字母序号之和为：16+1+20+2+1+19+9+3=71，而71的二进制是1000111，即有3个0、4个1。

输入格式：

输入在一行中给出长度不超过105、以回车结束的字符串。

输出格式：

在一行中先后输出0的个数和1的个数，其间以空格分隔。

输入样例：
PAT (Basic)
输出样例：
3 4*/
#include<string>
#include<iostream>
#include<algorithm>
using namespace std;
int main(){
	string str;
	int zero = 0, one = 0;
	getline(cin,str);
	transform(str.begin(), str.end(), str.begin(), ::tolower);
	int length = str.length();
	int sum = 0;
	for (int i = 0; i < length; i++)
	{
		if(str[i] <= 'z' && str[i] >= 'a')
			sum += str[i] - 'a' + 1;
	}
	while (sum)
	{
		if (sum % 2 == 0)
			zero++;
		else
		{
			one++;
		}			
		sum /= 2;
	}
	cout << zero << " " << one;
	system("pause");
	return 0;
}
