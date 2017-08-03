/*1040. 有几个PAT
字符串APPAPT中包含了两个单词“PAT”，其中第一个PAT是第2位(P),第4位(A),第6位(T)；第二个PAT是第3位(P),第4位(A),第6位(T)。

现给定字符串，问一共可以形成多少个PAT？

输入格式：

输入只有一行，包含一个字符串，长度不超过105，只包含P、A、T三种字母。

输出格式：

在一行中输出给定字符串中包含多少个PAT。由于结果可能比较大，只输出对1000000007取余数的结果。

输入样例：
APPAPT
输出样例：
2
*/
//即A前有几个A 后有几个T 相乘即是当前有会有几个
#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
int main()
{
	string str;
	long long int ans = 0;
	int tempP = 0;
	int amountT = 0;
	cin >> str;
	int length = str.length();
	for (int i = 0; i < length; i++)
	{
		if (str[i] == 'T') amountT++;
	}
	for (int i = 0; i < length; i++)
	{
		if (str[i] == 'P')
			tempP++;
		if (str[i] == 'T')
			amountT--;
		if(str[i] == 'A')
			ans += tempP*amountT;
	}
	cout << ans % 1000000007;
	system("pause");
	return 0;
}