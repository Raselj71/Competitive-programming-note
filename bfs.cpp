#include<bits/stdc++.h>
using namespace std;


void addEdges(vector<vector<int>>& adjacencylist,int s,int d){

         adjacencylist[s].push_back(d);
         adjacencylist[d].push_back(s);
}

void bfs(vector<vector<int>>& adjacencylist, int source,int node){
    vector<int> visited(node,0);
    vector<int> level(node,9999);


   visited[source]=1;
   level[source]=0;

   queue<int> q;
   q.push(source);

   while(!q.empty()){
      
      int currentNode=q.front();
      cout<<currentNode<<" ";
      q.pop();

      for(int neighbour:adjacencylist[currentNode]){
        if(visited[neighbour]==0){
             visited[neighbour]=1;
             level[neighbour]=level[currentNode]+1;
             q.push(neighbour);
        }

      }

      visited[currentNode]=2;

   }

   cout<<endl;

   for(int i=0; i<node; i++){

      cout<<"current Node :"<< i <<" Level:"<<level[i]<<endl;
   }



}

int main(){

     

     int node,edge;
     cout<<"enter node and ages"<<endl;
     cin>>node>>edge;

     vector<vector<int>> adjacenlist(node);


     for(int i=0; i<edge; i++){
         cout<<"Enter source and destination:";
         int s,d;
         cin>>s>>d;
         addEdges(adjacenlist,s,d);
     }

     bfs(adjacenlist,0 ,node);




    return 0;
}