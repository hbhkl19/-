#include<iostream>
#include<fstream>
#include<string>
#include<stack>
#include<queue>
#include<vector>
using namespace std;


struct node
{
	int val;
	node* lchild;
	node* rchild;
	node()
	{
		val = 0;
		lchild = NULL;
		rchild = NULL;
	}
	node(int a)
	{
		val = a;
		lchild = NULL;
		rchild = NULL;
	}
};

node* fun(string str)  //括号表示建树
{
	node* head = NULL;
	node* p;
	bool flag=0;
	stack<node*>st;

	int len = str.length();
	for (int i = 0; i < len; i++)
	{
		if (str[i] == '(')
		{
			st.push(p);
			flag = 1;
		}
		else if (str[i] == ')')
		{
			st.pop();
		}
		else if (str[i] == ',')
		{
			flag = 0;
		}
		else
		{
			int tmp = 0;
			while (str[i] <= '9' && str[i] >= '0')
			{
				tmp = tmp * 10 + (str[i] - '0');
				i++;
			}
			i--;
			p = new node(tmp);
			if (head == NULL)
			{
				head = p;
			}
			else
			{
				if (flag && !st.empty())
				{
					st.top()->lchild = p;
				}
				else if (!st.empty())
				{
					st.top()->rchild = p;
				}
			}
		}
	}
	return head;
}

void display(node* win) //中序遍历
{
	if (win != NULL)
	{
		display(win->lchild);
		cout << win->val << " ";
		display(win->rchild);
	}
}

void fun1(node* win)    //输出叶子节点（由左到右
{
	if (win == NULL)
		return;
	if (win->lchild == NULL && win->rchild == NULL)
		cout << win->val << " ";
	else {
		fun1(win->lchild);
		fun1(win->rchild);
	}
}

void fun2(node* win)       //输出叶子节点
{
	if (win == NULL)
		return;
	if (win->lchild == NULL && win->rchild == NULL)
		cout << win->val << " ";
	else
	{
		fun2(win->rchild);
		fun2(win->lchild);
	}
}

void fun3(node* win)       //层次遍历
{
	queue<node*>qu;
	qu.push(win);
	node* p;
	while (!qu.empty())
	{
		p = qu.front();
		qu.pop();
		cout << p->val << " ";
		if (p->rchild != NULL)
		{
			qu.push(p->rchild);
		}
		if (p->lchild != NULL)
		{
			qu.push(p->lchild);
		}
	}
}

int height(node* win) //求高度
{
	if (win == NULL)
		return 0;
	return 1 + max(height(win->lchild), height(win->rchild));
}

bool fun4(int now, int deep, node* win)     //判断二叉树
{
	if (win == NULL)
		return 1;
	if (now <= deep - 2)
	{
		if (win->lchild == NULL || win->rchild == NULL)
			return 0;
	}
	else
	{
		if (win->lchild == NULL && win->rchild != NULL)
			return 0;
	}
	return fun4(now + 1, deep, win->lchild) && fun4(now + 1, deep, win->rchild);
}

node* fun5(string str, int i)      //顺序存储结构递归建树
{
	if (i < str.length())
	{
		if (str[i] == '#')
			return NULL;
		else
		{
			node* win = new node(str[i]);
			win->lchild = fun5(str, 2 * i + 1);
			win->rchild = fun5(str, 2 * i + 2);
			return win;
		}
	}
	return NULL;
}


bool best(node* win,int deep)    //层次遍历判断是否为二叉树
{
	int now = 1;
	int num = 1;
	queue<node*>qu;
	qu.push(win);
	while (!qu.empty())
	{
		int n = qu.size();
		if (now <= deep - 1)
		{
			if (n == num)
			{
				num *= 2;
			}
			else
				return 0;
		}
		if (now < deep - 1) {
			for (int i = 0; i < n; i++)
			{
				node* p = qu.front();
				qu.pop();
				if (p->lchild != NULL)
					qu.push(p->lchild);
				if (p->rchild != NULL)
					qu.push(p->rchild);
			}
		}
		else if (now == deep - 1)
		{
			int n = qu.size();
			bool flag = 1;
			for (int i = 0; i < n; i++)
			{
				node* p = qu.front();
				qu.pop();
				if (!flag && (p->lchild != NULL || p->rchild != NULL))
					return 0;
				if (p->lchild == NULL && p->rchild != NULL)
					return 0;
				if (p->rchild == NULL)
					flag = 0;
			}
			return 1;
		}

		now++;

	}
}

node* fun6(vector<int> a, int i, vector<int> b, int j, int n) //先序中序建立二叉树
{
	if (n <= 0)
		return NULL;
	int tmp = a[i];
	node* win = new node(tmp);
	int p = j;
	while (b[p] != tmp) p++;
	int k = p - j;
	win->lchild = fun6(a, i + 1, b, j, k);
	win->rchild = fun6(a, i + k + 1, b, p + 1, n - k - 1);

	return win;
}

void fun7(node* win)
{
	if (win != NULL)
	{
		fun7(win->lchild);
		fun7(win->rchild);
		cout << win->val << " ";
	}
}

int main()
{
	/*fstream fin("in.txt");
	string str;
	getline(fin, str);
	node* win = new node;
	win = fun(str);
	display(win);
	fun1(win);
	cout << endl;
	fun2(win);
	cout << endl;
	fun3(win);
	int deep = height(win);
	cout << fun4(1, deep, win);
	string str;
	getline(cin, str);
	node* win = new node;
	win = fun5(str, 0);
	display(win);
	cout << endl;
	fun1(win);
	cout << endl;
	fun2(win);
	cout << endl;
	fun3(win);

	string str;
	fstream fin("in.txt");
	getline(fin, str);
	node* win = new node;
	win = fun(str);
	int deep = height(win);
	cout << best(win,deep);*/

	int n;
	fstream fin("in.txt");
	vector<int>a, b;
	fin >> n;
	int tmp;
	for (int i = 0; i < n; i++)
	{
		fin >> tmp;
		a.push_back(tmp);
	}
	for (int i = 0; i < n; i++)
	{
		fin >> tmp;
		b.push_back(tmp);
	}
	node* win = new node;
	win = fun6(a, 0, b, 0, n);
	fun7(win);
}
