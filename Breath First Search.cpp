#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <queue>
#include <stack>
#include <list>

using namespace std;

class Graph {
private:
	vector < vector <int> > G;
	map < string, int > list;
	vector <string> key;
public:
	void initGraph() {
		int v, e;
		string u, j;
		cin >> v >> e;
		G = vector < vector <int> >(v, vector <int>(v, 0));
		for (int i = 0; i < v; i++) {
			cin >> u;
			list[u] = i;
			key.push_back(u);
		}
		for (int i = 0; i < v; i++)
			for (int j = 0; j < v; j++) {
				cin >> G[i][j];
			}
		while (e--) {
			cin >> u >> j;
			bfs(u, j, v);
		}
	}
	void bfs(string s, string t, int V) {
		int count = 1;
		queue <string> Open;
		vector < bool > Close(V, false);
		map < string, string> parent;
		Open.push(s);
		Close[list[s]] = true;
		while (!Open.empty()) {
			string u = Open.front();
			int index = list[u];
			Open.pop();
			for (int v = 0; v < V; v++) {
				if (G[index][v] > 0 && Close[v] == false) {
					string sIndex = key[v];
					Open.push(sIndex);
					parent[sIndex] = u;
					Close[v] = true;
					count++;
					if (sIndex == t) {
						int length = 0;
						std::list < string > Path;
						while (t != s) {
							Path.push_front(t);
							string u = parent[t];
							length += G[list[u]][list[t]];
							t = u;
						}
						Path.push_front(s);
						for (auto x : Path) {
							cout << x << " ";
						}
						cout << endl;
						cout << count << " " << length << endl;
						return;
					}
				}
			}
		}
		cout << "-unreachable-" << endl;
		cout << count << " " << 0 << endl;
	}

};

int main() {
	Graph G;
	G.initGraph();

}
