//POJ2418--硬木的种类
#include<iostream>
#include<vector>
#include<string>
#include<fstream>
#include<cstdio>
using namespace std;

struct node
{
	string val;
	int cnt;
	node* lchild;
	node* rchild;
	node()
	{
		val = "";
		cnt = 0;
		lchild = NULL;
		rchild = NULL;
	}
	node(int a, string b)
	{
		val = b;
		cnt = a;
		lchild = NULL;
		rchild = NULL;
	}
};

void insert(node*& win, string a)
{
	if (win == NULL)
		win = new node(1, a);
	else if (a < win->val)
		insert(win->lchild, a);
	else if (a > win->val)
		insert(win->rchild, a);
	else if (a == win->val)
		win->cnt++;
}

void fun(node* win, double n)
{
	if (win != NULL)
	{
		fun(win->lchild, n);
		cout << win->val << " ";
		int cnt = win->cnt;
		double ans = cnt / n;
		ans *= 100;
		printf("%.4lf", ans);
		cout << endl;
		fun(win->rchild, n);
	}
}

int main()
{
	node* win = NULL;
	double n = 0;
	string str;
	fstream fin("in.txt");
	while (getline(fin, str))
	{
		n++;
		insert(win, str);
	}

	fun(win, n);
}
