#include<bits/stdc++.h>
using namespace std;

pair<int,vector<int> > merge_and_Count(vector<int> A,vector<int> B)
{
	int p1=0,p2=0,count=0;
	vector<int> newList;
	while(p1<A.size() && p2<B.size()){

		if(B[p2]<A[p1]) {
			count+=A.size()-p1;
			newList.push_back(B[p2]);
			p2++;
		}
		else{
			newList.push_back(A[p1]);
			p1++;
		}
	}
	while(p1<A.size()){
		newList.push_back(A[p1]);
		p1++;
	}
	while(p2<B.size()){
		newList.push_back(B[p2]);
		p2++;		
	}

	return make_pair(count,newList);
}

pair<int,vector<int> > sort_and_Count(vector<int> L)
{
	if(L.size()<=1) return make_pair(0,L);
	else
	{
		vector<int>::iterator mid = L.begin() + (L.size()/2);
		vector<int> left(L.begin(),mid);
		vector<int> right(mid,L.end());

		pair<int,vector<int> > leftRes = sort_and_Count(left);
		pair<int,vector<int> > rightRes = sort_and_Count(right);
		pair<int,vector<int> > mergeRes = merge_and_Count(leftRes.second,rightRes.second);
		
		return make_pair(leftRes.first+rightRes.first+mergeRes.first,mergeRes.second);
	}	
}

int main(){
	int n,x,n2;
	cin>>n;
	
	vector<int> array(n);
	srand(time(NULL));
	
	for (int i=0; i<n; ++i) 
	{
		array[i]=i+1;
	}

	random_shuffle ( array.begin(), array.end());  	 
	cout<<"Random Array : ";
	for(int i=0;i<n;i++)
	{
		cout<<array[i]<<" ";		
	}
	cout<<endl;

	pair<int,vector<int> > value = sort_and_Count(array);
	cout<<endl<<"Number of Inversions : "<<value.first<<endl<<endl;
	cout<<"Sorted Array : ";
	for(int i=0;i<value.second.size();i++){
		cout<<value.second[i]<<" ";		
	}
	cout<<endl<<endl;
	return 0;


}