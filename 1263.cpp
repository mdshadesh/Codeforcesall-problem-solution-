#include<bits/stdc++.h>
using namespace std;

stack<int> stk;
int ndfn, cntSrc, cntSnk;
vector<vector<int>> adjList, comps, dagList;
vector<int> inStack, lowLink, dfn, comp, inDeg, outDeg;
void tarjan(int node) {
    lowLink[node] = dfn[node] = ndfn++, inStack[node] = 1;
    stk.push(node);
    for (int i = 0; i < adjList[node].size(); i++) {
        int ch = adjList[node][i];
        if (dfn[ch] == -1) {
            tarjan(ch);
            lowLink[node] = min(lowLink[node], lowLink[ch]);
        } else if (inStack[ch]) {
            lowLink[node] = min(lowLink[node], dfn[ch]);
        }
    }
    if (lowLink[node] == dfn[node]) {
        comps.push_back(vector<int>());
        int x = -1;
        while (x != node) {
            x = stk.top(), stk.pop(), inStack[x] = 0;
            comps.back().push_back(x);
            comp[x] = comps.size()-1;
        }
    }
}

void SCC() {
	int n = adjList.size();
	inStack.clear(); inStack.resize(n);
	lowLink.clear(); lowLink.resize(n);
	dfn.clear(); dfn.resize(n, -1);
	ndfn = 0;
	comp.clear(); comp.resize(n);
	comps.clear();
	for (int i = 0; i < n; i++) if (dfn[i] == -1) tarjan(i);
}

void computeCompGraph() {
	int csz = comps.size(), cntSrc = csz, cntSnk = csz;
	outDeg.clear(); outDeg.resize(csz);
	inDeg.clear(); inDeg.resize(csz);
	dagList.clear(); dagList.resize(csz);
	for (int i = 0; i < adjList.size(); i++) {
		for (int j = 0; j < adjList[i].size(); j++) {
			int k = adjList[i][j];
			if (comp[k] != comp[i]) {
				dagList[comp[i]].push_back(comp[k]);
				if (!(inDeg[comp[k]]++)) cntSrc--;
				if (!(outDeg[comp[i]]++)) cntSnk--;
			}
		}
	}
	printf("%d\n", cntSrc);
}

int arr[2002][3];
bool inRange(int a, int b) {
    if (2*abs(arr[a][0]-arr[b][0]) <= arr[a][2] && 2*abs(arr[a][1]-arr[b][1]) <= arr[a][2])
        return true;
    return false;
}

int main() {
    int t, n;
    scanf("%d", &t);
    while (t--) {
        scanf("%d", &n);
        adjList.clear(); adjList.resize(n);
        for (int i = 0; i < n; i++) scanf("%d %d %d", &arr[i][0], &arr[i][1], &arr[i][2]);
        for (int i = 0; i < n-1; i++) {
            for (int j = i+1; j < n; j++) {
                if (inRange(i,j)) adjList[i].push_back(j);
                if (inRange(j,i)) adjList[j].push_back(i);
            }
        }
        SCC();
        computeCompGraph();
    }
}