#include<bits/stdc++.h>
using namespace std;

int main(){
	int v,e,x,n;
	cin>>v>>e;
	vector<vector<int> > G;
	vector<int> cnt(v,0);

	for(int i=0;i<v;i++){
		vector<int> row;
		for(int j=0;j<e;j++){
			cin>>x;
			row.push_back(x);
		}
		G.push_back(row);
	}
	
	for(int i=0;i<v;i++){
		for(int j=0;j<e;j++){
			cout<<G[i][j]<<" ";
		}
		cout<<endl;
	}
	
	cin>>n;		//number of columns to check for independence
	for(int i=0;i<n;i++)
	{
		cin>>x;//index of column
		for(int j=0;j<v;j++)
		{
			cnt[j] = cnt[j]+G[j][x];
		}
	}
	for(int i=0;i<v;i++){
		if(cnt[i]!=0) 
			{
				cout<<"Independent, hence no directed cycle"<<endl;
				return 0;
			}
	}
	cout<<"Cycle is present , hence dependent"<<endl;

	return 0;


}