#include<bits/stdc++.h>

using namespace std;

int main()

{

           int n,e;

           cin>>n>>e;

           vector<pair<int,int>>graph[n+1];

           for(int i=1;i<=e;i++)

           {

                      int a,b,w;

                      cin>>a>>b>>w;

                      graph[a].push_back({b,w});

                      graph[b].push_back({a,w});

           }

           priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;

           pq.push({0,1});

           vector<int>dis(n+1,INT_MAX);

           dis[1]=0;

           while(!pq.empty())

           {

                      int cur=pq.top().second;

                      int cur_d=pq.top().first;

                      pq.pop();

                      for(pair<int,int> next: graph[cur])

                      {

                                 if(dis[next.first]>cur_d+next.second)

                                 {

                                            dis[next.first]=cur_d+next.second;

                                            pq.push({dis[next.first],next.first});

                                 }

                      }

                      cout<<endl;

           }

 

           for(int i=1;i<=n;i++)

           {

                      cout<<dis[i]<<endl;

           }

           return 0;

}

/*

6 9

1 2 4

1 6 2

2 3 5

2 6 1

6 3 8

6 5 10

3 4 6

3 5 3

5 4 5

*/
