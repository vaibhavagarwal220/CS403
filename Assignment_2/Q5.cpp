#include<bits/stdc++.h>
using namespace std;

int main(){
	int n,s,f,u,v,max;
	cin>>n;
	vector<vector<int> > G(n,vector<int>(n,0));
	vector<int> colors(n,-1);
	vector<pair<int,int> > class_time;
	for(int i=0;i<n;i++){
		cin>>s;
		cin>>f;
		class_time.push_back(make_pair(s,f));
	}

	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			if(i!=j && class_time[i].first>class_time[j].first && class_time[i].first<class_time[j].second){
				G[i][j]=1;
				G[j][i]=1;
			}
			else if(i!=j && class_time[i].second>class_time[j].first && class_time[i].second<class_time[j].second){
				G[i][j]=1;
				G[j][i]=1;	
			}
		}
	}

	// for(int i=0;i<n;i++){
	// 	for(int j=0;j<G[i].size();j++)
	// 		cout<<G[i][j]<<" ";
	// 	cout<<endl;
	// }
	int max_col = INT_MIN;
	for(int i=0;i<n;i++){
		int col=1;
		for(int j=0;j<n;j++){
			if(G[i][j] && colors[j]==col){
				col++;
			}			
		}
		colors[i]=col;
		if(col>max_col) max_col=col;	
	}
	cout<<"Number of Classrooms required - "<<max_col<<endl;
	for(int i=0;i<n;i++){
		cout<<"Activity "<<i+1<<" - Classroom "<<colors[i]<<endl;
	}

	return 0;

}