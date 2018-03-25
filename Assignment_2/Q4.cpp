#include <bits/stdc++.h>
using namespace std;


bool sort_by(const pair<int,int> &a,
              const pair<int,int> &b)
{
    return (a.second < b.second);
}

int main(){
	int n,t;
	cin>>n;
	vector<pair<int,int> > task_times;
	for(int i=0;i<n;i++){
		cin>>t;
		task_times.push_back(make_pair(i+1,t));
	}
	sort(task_times.begin(),task_times.end(),sort_by);

	int total_cmp_time=0,cmp_time=0;
	double avg_cmp_time;
	for(int i=0;i<n;i++){
		cmp_time=cmp_time+task_times[i].second;
		total_cmp_time+=cmp_time;
	}
	avg_cmp_time = (double) total_cmp_time / n;

	cout<<"Minimum Average Completion Time : " <<avg_cmp_time<<endl;
	cout<<"Order of tasks"<<endl;
	for(int i=0;i<n;i++){
		cout<<task_times[i].first<<"("<<task_times[i].second<<" units)"<<" ";
	}
	cout<<endl;

}