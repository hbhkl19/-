//#include<iostream>
//#include<fstream>
//#include<string>
//
//using namespace std;
//
//int win[10000][10000];
//
//int visited[10000];
//
//void dfs(int n, int v)
//{
//	visited[v] = 1;
//	for (int i = 0; i < n; i++)
//	{
//		if (win[v][i] != 0)
//		{
//			if (visited[i] == 0)
//				dfs(n, i);
//		}
//	}
//}
//
//void bfs()
//
//int main()
//{
//	int n;
//	fstream fin("in.txt");
//	cin >> n;
//	int tmp;
//	for (int i = 0; i < n; i++)
//	{
//		for (int j = 0; j < n; j++)
//		{
//			cin >> tmp;
//			win[i][j] = tmp;
//		}
//	}
//
//	int ans = 1;
//	dfs(n, 0);
//	for (int i = 0; i < n; i++)
//	{
//		if (visited[i] == 0)
//		{
//			ans++;
//			dfs(n, i);
//		}
//	}
//	cout << ans;
//}


//#include<iostream>
//#include<string>
//#include<queue>
//
//using namespace std;
//
//int visited[10005];
//
//int head[10005];
//struct edg
//{
//	int adj;
//	int weight;
//	int next;
//} edge[10005];
//
//int cnt = 1;
//
//void add(int u, int v, int w)
//{
//	edge[cnt].adj = v;
//	edge[cnt].weight = w;
//	edge[cnt].next = head[u];
//	head[u] = cnt++;
//}
//
//void bfs(int v)
//{
//	visited[v] = 1;
//	queue<int>qu;
//	qu.push(v);
//	while (!qu.empty())
//	{
//		int tmp = qu.front();
//		qu.pop();
//		for (int i = head[tmp]; i != 0; i = edge[i].next)
//		{
//			if (visited[edge[i].adj] == 0)
//			{
//				visited[edge[i].adj] = 1;
//				qu.push(edge[i].adj);
//			}
//		}
//	}
//}
//
//void dfs(int v)
//{
//	visited[v] = 1;
//	for (int i = head[v]; i != 0; i = edge[i].next)
//	{
//		if (visited[edge[i].adj] == 0)
//		{
//			dfs(edge[i].adj);
//		}
//	}
//}
//int used[10000];
//struct node
//{
//	int val;
//	int dis;
//	node()
//	{
//		val = 0;
//		dis = 0;
//	}
//	node(int a, int b)
//	{
//		val = a;
//		dis = b;
//	}
//};
//
//int distance(int u, int v)
//{
//	
//	queue<node>qu;
//	qu.push(node(u, 0));
//	used[u] = 1;
//	while (!qu.empty())
//	{
//		node tmp = qu.front(); qu.pop();
//		if (tmp.val == v)
//			return tmp.dis;
//		for (int i = head[tmp.val]; i != 0; i = edge[i].next)
//		{
//			if (used[edge[i].adj] == 0)
//			{
//				used[edge[i].adj] = 1;
//				qu.push(node(edge[i].adj, tmp.dis + 1));
//			}
//		}
//	}
//	return 0x3ffffff;
//}
//
//int main()
//{
//	/*int tmp;
//	int n;
//	cin >> n;
//	for (int i = 0; i < n; i++)
//	{
//		for (int j = 0; j < n; j++)
//		{
//			cin >> tmp;
//			if (tmp == 1)
//			{
//				add(i, j, 1);
//			}
//		}
//	}*/
//	/*int ans = 1;
//	bfs(0);
//	for (int i = 0; i < n; i++)
//	{
//		if (visited[i] == 0)
//		{
//			ans++;
//			bfs(i);
//		}
//	}
//	cout << ans;*/
//	/*int ans = 1;
//	dfs(0);
//	for (int i = 0; i < n; i++)
//	{
//		if (visited[i] == 0)
//		{
//			ans++;
//			dfs(i);
//		}
//	}
//	cout << ans;*/
//
//
//
//}


//#include<iostream>
//
//
//using namespace std;
//
//
//int win[10005][10005];
//int lowcost[10005];
//int clost[10005];
//
//const int INF = 0x3f3f3f3f;
//
//int prime(int v,int n)
//{
//	int ans = 0;
//
//	for (int i = 0; i < n; i++)
//	{
//		lowcost[i] = win[v][i];
//		clost[i] = v;
//	}
//	for (int i = 1; i < n; i++)
//	{
//		int k = -1;
//		int min = INF;
//		for (int j = 0; j < n; j++)
//		{
//			if (lowcost[j] != 0 && min > lowcost[j])
//			{
//				min = lowcost[j];
//				k = j;
//			}
//		}
//			ans += lowcost[k];
//			lowcost[k] = 0;
//			for (int j = 0; j < n; j++)
//			{
//				if (lowcost[j] != 0 && lowcost[j] > win[k][j])
//				{
//					lowcost[j] = win[k][j];
//					clost[j] = k;
//				}
//			}
//		
//	}
//	return ans;
//}
//int main()
//{
//	int n;
//	int count;
//	cin >> n >> count;
//	for (int i = 0; i < n; i++)
//	{
//		for (int j = 0; j < n; j++)
//		{
//			if (i == j)
//			{
//				win[i][j] = 0;
//			}
//			else
//			{
//				win[i][j] = INF;
//			}
//		}
//	}
//
//	int i, j, weight;
//	for (int k = 0; k < count; k++)
//	{
//		cin >> i >> j >> weight;
//		win[i - 1][j - 1] = weight;
//		win[j - 1][i - 1] = weight;
//	}
//	cout << prime(0, n);
//
//}




//
//#include<iostream>
//#include<vector>
//#include<algorithm>
//using namespace std;
//
//struct edge
//{
//	int u, v, w;
//	edge()
//	{
//		u = 0;
//		v = 0;
//		w = 0;
//	}
//	edge(int a, int b, int c)
//	{
//		u = a;
//		v = b;
//		w = c;
//	}
//	bool operator<(const edge& s) const
//	{
//		return w < s.w;
//	}
//};
//
//int parent[10000];
//int rnk[10000];
//void init(int n)
//{
//	for (int i = 1; i <= n; i++)
//	{
//		parent[i] = i;
//		rnk[i] = 0;
//	}
//}
//
//int find(int x)
//{
//	if (x != parent[x])
//		parent[x] = find(parent[x]);
//	return parent[x];
//}
//
//void Union(int x, int y)
//{
//	int rx = find(x);
//	int ry = find(y);
//	if (rx == ry)
//		return;
//	if (rnk[rx] > rnk[ry])
//		parent[ry] = rx;
//	else
//	{
//		if (rnk[rx] == rnk[ry])
//			rnk[ry]++;
//		parent[rx] = ry;
//	}
//}
//
//int main()
//{
//	int n, count;
//	cin >> n >> count;
//	vector<edge>win;
//	int i, j, weight;
//	for (int k = 0; k < count; k++)
//	{
//		cin >> i >> j >> weight;
//		win.push_back(edge(i, j, weight));
//		win.push_back(edge(j, i, weight));
//	}
//
//	sort(win.begin(), win.end());
//
//	for (int i = 0; i < win.size(); i++)
//	{
//		cout << win[i].u << " " << win[i].v << " " << win[i].w << endl<<endl;
//	}
//
//	init(n);
//
//	int ans = 0;
//	int k = 1;
//	int index = 0;
//
//	while (k < n)
//	{
//		int u1 = win[index].u;
//		int v1 = win[index].v;
//		int sn1 = find(u1);
//		int sn2 = find(v1);
//		if (sn1 != sn2)
//		{
//			k++;
//			ans += win[index].w;
//			Union(sn1, sn2);
//		}
//		index++;
//	}
//	cout << ans;
//}


//弗洛伊德算法
//POJ1125—股票经纪人
#include<iostream>
#include<fstream>
#include<algorithm>
using namespace std;

int win[10005][10005];
const int INF = 0x3f3f3f3f;

int main()
{
	int n;
	fstream fin("in.txt");
	fin >> n;

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			if (i == j)
				win[i][j] = 0;
			else
				win[i][j] = INF;
		}
	}

	int tmp,a,b;
	for (int i = 1; i <= n; i++)
	{
		fin >> tmp;
		for (int j = 0; j < tmp; j++)
		{
			fin >> a >> b;
			win[i][a] = b;
		}
	}

	for (int k = 1; k <= n; k++)
	{
		for (int i = 1; i <= n; i++)
		{
			for (int j = 1; j <= n; j++)
			{
				if (win[i][j] > win[i][k] + win[k][j])
					win[i][j] = win[i][k] + win[k][j];
			}
		}
	}
	int index = 0;
	int  min = INF;
	for (int i = 1; i <= n; i++)
	{
		int max = 0;
		for (int j = 1; j <= n; j++)
		{
			max = max > win[i][j] ? max : win[i] [j] ;
		}
		if(min>max)
		{
			min =  max;
			index = i;
		}
	}
	if (min == INF)
		cout << "disjoint";
	else
		cout << index << " " << min;
}


//力扣743--网络延迟时间
#include<iostream>
#include<fstream>

using namespace std;

int win[101][101];

const int INF = 0x3f3f3f3f;

int main()
{
	fstream fin("in.txt");
	int n, kk;
	fin >> n >> kk;

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			if (i == j)
				win[i][j] = 0;
			else
				win[i][j] = INF;
		}
	}

	int a, b, c;
	while (fin >> a >> b >> c)
	{
		win[a][b] = c;
	}

	for (int k = 1; k <= n; k++)
	{
		for (int i = 1; i <= n; i++)
		{
			for (int j = 1; j <= n; j++)
			{
				if (win[i][j] > win[i][k] + win[k][j])
					win[i][j] = win[i][k] + win[k][j];
			}
		}
	}
	int max = -1;
	for (int j = 1; j <= n; j++)
	{
		if (max < win[kk][j])
			max = win[kk][j];
	}
	if (max == INF)
		cout << -1;
	else
		cout << max;
}
