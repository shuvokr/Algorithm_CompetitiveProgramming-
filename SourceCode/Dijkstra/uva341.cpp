/*
        Shuvo
        Program algo: Dijkstra (SSSP)
        Problem name: Non-Stop Travel
        Problem ID: 341
*/
#include <stdio.h>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

#define INF 1e8

typedef vector<int> vi;
typedef pair<int, int> pi;
typedef vector<pi> vpi;

struct data
{
    int nod, time;
    data() {}
    data(int a, int b):nod(a), time(b) {}
    bool operator<(const data &x) const
    {
        return time < x.time;
    }
};

void Dijkstra(int s, int e);
void print_path(int s, int e);

int cost[ 1000 ], par[ 1000 ];
vector <vpi> graph;

int main()
{
    int node, n, t, i, j, num, s, e, kag = 0;
    while(~scanf("%d", &node) && node)
    {
        graph.assign(999, vpi());
        for(i = 1; i <= node; i++) cost[ i ] = INF, par[ i ] = 0;
        for(i = 1; i <= node; i++)
        {
            scanf("%d", &num);
            for(j = 0; j < num; j++)
            {
                scanf("%d%d", &n, &t);
                graph[ i ].push_back(pi(n, t));
            }
        }
        scanf("%d %d", &s, &e);
        Dijkstra(s, e);
        printf("Case %d: Path =", ++kag);
        print_path(s, e);
        printf(" %d; %d second delay\n", e, cost[ e ]);
    }
    return 0;
}
void Dijkstra(int s, int e)
{
    priority_queue <data> pq;
    cost[ s ] = 0;
    data tmp;
    int nd, tm;
    pq.push(data(s, 0));
    while(!pq.empty())
    {
        tmp = pq.top(); pq.pop();
        nd = tmp.nod; tm = tmp.time;
        if(cost[ nd ] == tm)
        {
            for(int i = 0; i < graph[ nd ].size(); i++)
            {
                pi pr = graph[ nd ][ i ];
                if(cost[ nd ] + pr.second < cost[ pr.first ])
                {
                    par[ pr.first ] = nd;
                    cost[ pr.first ] = cost[ nd ] + pr.second;
                    pq.push(data(pr.first, cost[ pr.first ]));
                }
            }
        }
    }
}
void print_path(int s, int e)
{
    if(par[ e ] != s) print_path(s, par[ e ]);
    printf(" %d", par[ e ]);
}
