#include <bits/stdc++.h>
#define Point pair<int,int>
using namespace std;


bool sortbysec(Point l, Point r)
{
    return (l.second < r.second);
}

float dist(Point a , Point b){
	return (float) sqrt( (a.first-b.first)*(a.first-b.first) + (a.second-b.second)*(a.second-b.second) ) ;
}

void printSolution(pair<Point,Point> sol)
{
	cout<<endl<<"Closest Pair is { ("<<sol.first.first<<", "<<sol.first.second<<"), (";
	cout<<sol.second.first<<", "<<sol.second.second<<") } , Closest Distance : "<<dist(sol.first,sol.second)<<endl<<endl;
}


pair<Point,Point > bruteForce(vector<Point > a){
	float minDist = FLT_MAX;
	pair<Point,Point > sol;
	if(a.size()==1) return make_pair(a[0],a[0]);
	for(int i=0;i<a.size();i++){		
		for(int j=i+1;j<a.size();j++){
			if(dist(a[i],a[j])<minDist) {
				sol = make_pair(a[i],a[j]);
				minDist = dist(a[i],a[j]);
			}
		}	
	}

	return sol;
}


pair<Point,Point> closest_Pair_Rec(vector<Point > points){
	if(points.size()<=3) return bruteForce(points);

	pair<Point,Point> sol;
	vector<Point>::iterator mid = points.begin() + (points.size()/2);
	vector<Point> left(points.begin(),mid);
	vector<Point> right(mid,points.end());
	pair<Point,Point> solLeft = closest_Pair_Rec(left);
	pair<Point,Point> solRight = closest_Pair_Rec(right);
	//printSolution(solLeft);
	//printSolution(solRight);

	float min_d = min(dist(solLeft.first,solLeft.second),dist(solRight.first,solRight.second));
	Point mid_point = *mid;

	vector<Point> strip;

	float min_dst = min_d;
	for(int i=0;i<points.size();i++){
		if(dist(points[i],mid_point) < min_d) 
			strip.push_back(points[i]);
	}
	
	sort(strip.begin(),strip.end(),sortbysec);

	for(int i=0;i<strip.size();i++)
	{
		for(int j=i+1;j<strip.size() && strip[j].second-strip[i].second < min_dst;j++)
		{
			if(dist(strip[j],strip[i])<min_dst){
				min_dst = dist(strip[j],strip[i]);
				sol = make_pair(strip[i],strip[j]);

			}
		}
	}
	if(min_d == min_dst) {
		if(dist(solLeft.first,solLeft.second)<dist(solRight.first,solRight.second)){
			return solLeft;
		}
		else{
			return solRight;
		}
	}
	else{
		return sol;
	}

}

pair<Point,Point> closest_Pair(vector<Point > points){

	sort(points.begin(),points.end());
	pair<Point,Point> sol = closest_Pair_Rec(points);
	return sol;
}


int main(){

	int n,x,y;
	cin>>n;
	vector<Point > points;
	for(int i=0;i<n;i++)
	{
		cin>>x>>y;
		points.push_back(make_pair(x,y));
	}

	pair<Point,Point> sol; 

	sol = closest_Pair(points);

	printSolution(sol);
	

	return 0;
}