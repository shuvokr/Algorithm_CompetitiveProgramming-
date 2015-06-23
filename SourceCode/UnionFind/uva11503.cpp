/*
        Shuvo
        Problem algo: Data structure( Union find )
        Problem ID: 11503
        Problem name: Virtual Friends
*/
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
#include <stdlib.h>
#include <string>
#include <sstream>
#include <iostream>
#include <vector>
#include <stack>
#include <map>
#include <list>
#include <algorithm>

using namespace std;

#define sf scanf
#define pf printf
#define lld long long
#define fo(i, n) for(i = 0; i < n; i++)
#define INFP 1e8
#define INFN 1e-8
#define maxn 100000+1
#define mem(a, b) memset(a, b, sizeof(a))

typedef vector<int> vi;
typedef pair<int, int> pi;
typedef vector<vi> vpi;

void input();
int make_union(int a, int b);
int find_repragantetiv(int a);

int par[ maxn + maxn + 1 ], friend_num[ maxn + maxn + 1 ];

int main()
{
    //freopen("output.txt", "w", stdout);
    input();

    return 0;
}
void input()
{
    int T, n, num, i, tot;
    char ac[22], bc[22];
    map <string, int> m;
    scanf("%d", &T);
    while(T--)
    {
        scanf("%d", &n);
        num = 1;
        for(i = 1; i < n + n + 1; i++) par[ i ] = i, friend_num[ i ] = 1;
        m.clear();
        fo(i, n)
        {
            scanf("%s %s", ac, bc);
            if(!m[ ac ]) m[ ac ] = num++;
            if(!m[ bc ]) m[ bc ] = num++;
            int ck = make_union(m[ ac ], m[ bc ]);
            printf("%d\n", friend_num[ ck ]);
        }
    }
}
int make_union(int a, int b)
{
    int u = find_repragantetiv(a), v = find_repragantetiv(b);
    if(u == v) return u;
    else
    {
        friend_num[ u ] += friend_num[ v ];
        par[ v ] = u;
        return u;
    }
}
int find_repragantetiv(int a)
{
    if(par[ a ] == a) return a;
    else
    {
        return par[ a ] = find_repragantetiv(par[ a ]);
    }
}
