/*1015. 德才论
宋代史学家司马光在《资治通鉴》中有一段著名的“德才论”：“是故才德全尽谓之圣人，才德兼亡谓之愚人，德胜才谓之君子，才胜德谓之小人。凡取人之术，苟不得圣人，君子而与之，与其得小人，不若得愚人。”

现给出一批考生的德才分数，请根据司马光的理论给出录取排名。

输入格式：

输入第1行给出3个正整数，分别为：N（<=105），即考生总数；L（>=60），为录取最低分数线，即德分和才分均不低于L的考生才有资格被考虑录取；H（<100），为优先录取线——德分和才分均不低于此线的被定义为“才德全尽”，此类考生按德才总分从高到低排序；才分不到但德分到线的一类考生属于“德胜才”，也按总分排序，但排在第一类考生之后；德才分均低于H，但是德分不低于才分的考生属于“才德兼亡”但尚有“德胜才”者，按总分排序，但排在第二类考生之后；其他达到最低线L的考生也按总分排序，但排在第三类考生之后。

随后N行，每行给出一位考生的信息，包括：准考证号、德分、才分，其中准考证号为8位整数，德才分为区间[0, 100]内的整数。数字间以空格分隔。

输出格式：

输出第1行首先给出达到最低分数线的考生人数M，随后M行，每行按照输入格式输出一位考生的信息，考生按输入中说明的规则从高到低排序。当某类考生中有多人总分相同时，按其德分降序排列；若德分也并列，则按准考证号的升序输出。

输入样例：
14 60 80
10000001 64 90
10000002 90 60
10000011 85 80
10000003 85 80
10000004 80 85
10000005 82 77
10000006 83 76
10000007 90 78
10000008 75 79
10000009 59 90
10000010 88 45
10000012 80 100
10000013 90 99
10000014 66 60
输出样例：
12
10000013 90 99
10000012 80 100
10000003 85 80
10000011 85 80
10000004 80 85
10000007 90 78
10000006 83 76
10000005 82 77
10000002 90 60
10000014 66 60
10000008 75 79
10000001 64 90
*/
//好麻烦的，懒得写就从别人那里copy一份了--https://www.liuchuo.net/archives/498
#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
using namespace std;

struct node {
	int num;
	int de;
	int cai;
};

int cmp(struct node a, struct node b) {
	if ((a.de + a.cai) != (b.de + b.cai)) {
		return (a.de + a.cai) > (b.de + b.cai);
	}
	else if (a.de != b.de) {
		return a.de > b.de;
	}
	else
		return a.num < b.num;
}

int main() {
	int n, low, high;
	cin >> n >> low >> high;
	vector<node> a, b, c, d;
	node temp;
	int total = n;
	for (int i = 0; i < n; i++) {
		cin >> temp.num >> temp.de >> temp.cai;
		if (temp.de < low || temp.cai < low) {
			total--;
			continue;
		}
		if (temp.de >= high && temp.cai >= high) {
			a.push_back(temp);
		}
		else if (temp.de >= high && temp.cai < high) {
			b.push_back(temp);
		}
		else if (temp.de < high && temp.cai < high && temp.de >= temp.cai) {
			c.push_back(temp);
		}
		else {
			d.push_back(temp);
		}
	}

	sort(a.begin(), a.end(), cmp);
	sort(b.begin(), b.end(), cmp);
	sort(c.begin(), c.end(), cmp);
	sort(d.begin(), d.end(), cmp);

	printf("%d\n", total);
	vector<node>::iterator itr;
	for (itr = a.begin(); itr != a.end(); itr++)
		printf("%d %d %d\n", itr->num, itr->de, itr->cai);

	for (itr = b.begin(); itr != b.end(); itr++)
		printf("%d %d %d\n", itr->num, itr->de, itr->cai);

	for (itr = c.begin(); itr != c.end(); itr++)
		printf("%d %d %d\n", itr->num, itr->de, itr->cai);

	for (itr = d.begin(); itr != d.end(); itr++)
		printf("%d %d %d\n", itr->num, itr->de, itr->cai);

	return 0;
}