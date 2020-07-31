#include <iostream>
#include <vector>
#include <queue>
#include <utility>
#include <climits>
using namespace std;

long long A, B, Q, X;
int numVertex;
 
int nextRandom() {
    X = (A * X + B) % Q;
    return X;
}

struct Edge {
    int v; // vertex
    int w; // weight
    Edge(int v_, int w_) : v(v_), w(w_) {}
};

bool bfs(vector<vector<Edge> > &rgraph, int s, int t, vector<pair<int,int> > &parents) {
    queue<int> q;
    vector<bool> visited(numVertex);
    q.push(s);
    while(!q.empty()) {
        int u = q.front();
        q.pop();
        for(int i=0; i<rgraph[u].size(); i++) {
            int v = rgraph[u][i].v;
            if(!visited[v] && rgraph[u][i].w>0) {
                visited[v] = true;
                parents[v] = make_pair(u,i);
                q.push(v);
                if(v == t) return true;
            }
            
        }
    }
    return false;
}

long long fordFulkerson(vector<vector<Edge> > &rgraph, int s, int t) {
    long long maxFlow = 0;
    vector<pair<int,int> > parents(numVertex);
    while(bfs(rgraph, 0, 1, parents)) {
        int pathFlow = INT_MAX;
        for(int v=t; v!=s; ) {
            int u=parents[v].first;

            int ui = parents[v].second;
            pathFlow = min(pathFlow, rgraph[u][ui].w);
            v = u;
        }
        maxFlow += pathFlow;
//        cout << pathFlow << " " << maxFlow << endl;
        for(int v=t; v!=s; ) {
            int u = parents[v].first;
            int ui = parents[v].second;
            if(rgraph[u][ui].w!=INT_MAX) rgraph[u][ui].w -= pathFlow;
            int vi = -1;
            for(int i=0; i<rgraph[v].size(); i++) {
                if(rgraph[v][i].v == u) {
                    vi = i;
                }
            }
            if(vi!=-1 && rgraph[v][vi].w!=INT_MAX) rgraph[v][vi].w += pathFlow;
            v = u;
        }
    }
    return maxFlow;
}

int main() {
    int N, M;
    cin >> N >> M >> A >> B >> Q >> X;
    numVertex = N * M + 2;
    // 0:source, 1:sink, 
    vector<vector<Edge> > graph(numVertex, vector<Edge>());
    
    int offset = 2;
    // construct graph
    for(int n=0; n<N-1; n++) {
        for(int m=0; m<M; m++) {
            int from = n*M+m+offset;
            int to = from+M;
            nextRandom();
            graph[from].push_back(Edge(to, X));
            graph[to].push_back(Edge(from, INT_MAX));
        }
    }
    
    for(int m=0; m<M; m++) {
        int from = 0;
        int to = m+offset;
        graph[from].push_back(Edge(to, INT_MAX));
    }
    
    for(int m=0; m<M; m++) {
        int from = (N-1)*M+m+offset;
        int to = 1;
        graph[from].push_back(Edge(to, INT_MAX));
    }
    
    long long maxFlow = 0;

    for(int n=1; n<N-1; n++) {
        for(int m=0; m<M-1; m++) {
            int from = n*M+m+offset;
            int to = from+1;
            nextRandom();
            graph[from].push_back(Edge(to, X));
            graph[to].push_back(Edge(from, X));
        }
    }
    
    maxFlow += fordFulkerson(graph, 0, 1);
    
    cout << maxFlow;
}



