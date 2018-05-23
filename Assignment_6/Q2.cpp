#include <bits/stdc++.h>
using namespace std;

double dist(pair<int,int> p1,pair<int,int> p2)
{
	return (double)sqrt((p1.first-p2.first)*(p1.first-p2.first) + (p1.second-p2.second)*(p1.second-p2.second));
}

int main()
{
    int n,k;
    vector<pair<int,int> > centers;
    cout<<"Enter number of points : ";
    cin>>n;
    cout<<"Enter number of centers : ";
    cin>>k;
    vector<pair<int,int> > points(n);

    for(int i=0;i<n;i++){
    cout<<"Enter point["<<i+1<<"] : ";
    cin>>points[i].first>>points[i].second;
    }
    centers.push_back(points[0]);
    
    while(centers.size()<k){
    	int max_dist_i=-1;
    	double max_dist=INT_MIN,distn;
    	for(int i=0;i<centers.size();i++)
	    {
	    	for(int j=0;j<n;j++)
	    	{
	    			distn=dist(centers[i],points[j]);
	    			if(distn>max_dist) 
	    			{
	    				max_dist = distn;
	    				max_dist_i = j;
	    			}
	    	}	    	
	    }	    
	    centers.push_back(points[max_dist_i]);
	}
	cout<<endl<<endl;
	for(int i=0;i<centers.size();i++){
    cout<<"Center ["<<i+1<<"] : ";
    cout<<"( "<<centers[i].first<<" , "<<centers[i].second<<" )"<<endl;
    }
    return 0;
}