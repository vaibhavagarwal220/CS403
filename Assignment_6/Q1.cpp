
#include <bits/stdc++.h>
using namespace std;
 
int min_index(vector<int> vec)
{
	int min_i=0,min_v=vec[0];
	for(int i=1;i<vec.size();i++)
	{
		if(vec[i]<min_v)
		{
			min_v = vec[i];
			min_i = i;
		}
	}
	return min_i;
}

int main()
{
    int n,m;
    cout<<"Enter number of jobs : ";
    cin>>n;
    cout<<"Enter number of servers : ";
    cin>>m;
   	vector<pair<int,int> > job_times(n);
   	vector<int> server_load(m,0);
   	vector<set<pair<int,int> > > servers(m);

    for(int i=0;i<n;i++){
    	cout<<"Enter time required for Job["<<i+1<<"]  : ";
    	cin>>job_times[i].first;
    	job_times[i].second=i+1;
    }
    sort(job_times.rbegin(), job_times.rend());
  
    for(int i=0;i<n;i++){
    	int min_i = min_index(server_load);
    	server_load[min_i]+=job_times[i].first;
    	servers[min_i].insert(job_times[i]);
    }
    cout<<endl<<endl;
    for(int i=0;i<m;i++)
    {
    	cout<<"Server["<<i+1<<"] jobs :";
    	for (set<pair<int,int> >::iterator it=servers[i].begin(); it!=servers[i].end(); ++it)
    	{
    		cout<<' '<< (*it).second <<" (Time : "<<(*it).first<<")";
    	}
    	cout<<endl;
  	}
    return 0;
}