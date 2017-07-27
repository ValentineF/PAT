/*1037. 在霍格沃茨找零钱
如果你是哈利·波特迷，你会知道魔法世界有它自己的货币系统 —— 就如海格告诉哈利的：“十七个银西可(Sickle)兑一个加隆(Galleon)，二十九个纳特(Knut)兑一个西可，很容易。”现在，给定哈利应付的价钱P和他实付的钱A，你的任务是写一个程序来计算他应该被找的零钱。

输入格式：

输入在1行中分别给出P和A，格式为“Galleon.Sickle.Knut”，其间用1个空格分隔。这里Galleon是[0, 107]区间内的整数，Sickle是[0, 17)区间内的整数，Knut是[0, 29)区间内的整数。

输出格式：

在一行中用与输入同样的格式输出哈利应该被找的零钱。如果他没带够钱，那么输出的应该是负数。

输入样例1：
10.16.27 14.1.28
输出样例1：
3.2.1
输入样例2：
14.1.28 10.16.27
输出样例2：
-3.2.1
*/
#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
struct Money
{
	int Galleon;
	int Sickle;
	int Knut;
	int Sum;
};
int main()
{
	Money deal, pay, result;
	char dot;
	int remain;
	cin >> deal.Galleon >> dot >> deal.Sickle >> dot >> deal.Knut;
	cin >> pay.Galleon >> dot >> pay.Sickle >> dot >> pay.Knut;
	deal.Sum = (deal.Galleon * 17 + deal.Sickle) * 29 + deal.Knut;
	pay.Sum = (pay.Galleon * 17 + pay.Sickle) * 29 + pay.Knut;

	remain = deal.Sum - pay.Sum;
	if (remain > 0)
	{
		result.Galleon = remain / 493;
		result.Sickle = (remain - result.Galleon * 493) / 29;
		result.Knut = remain % 29;
		cout << '-' << result.Galleon << '.' << result.Sickle << '.' << result.Knut;
	}
	if (remain <= 0)
	{
		remain = abs(remain);
		result.Galleon = remain / 493;
		result.Sickle = (remain - result.Galleon * 493) / 29;
		result.Knut = remain % 29;
		cout << result.Galleon << '.' << result.Sickle << '.' << result.Knut;
	}
	system("pause");
	return 0;
}




