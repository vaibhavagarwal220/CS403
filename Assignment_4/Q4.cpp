#include <bits/stdc++.h>
using namespace std;

#define INF numeric_limits<double>::infinity()
using namespace std;

class Point {
	public:
	int x, y;
	// bool operator < (const Point& that) const {
	// 	return x < that.x;
	// }
};

pair<vector<double>,vector<int> > segmented_least_squares(vector<vector<double> > E, double C, int N)
{
	vector<double> OPT(N + 1);	
	vector<int> opt_segment(N + 1);
	double tmp,min;
	int i,j,k;

	OPT[0] = 0;
	opt_segment[0] = 0;

	for (j = 1; j <= N; j++)	{
		for (i = 1, min = INF, k = 0; i <= j; i++)	{
			tmp = E[i][j] + OPT[i-1];
			if (tmp < min)	{
				min = tmp;
				k = i;
			}
		}
		OPT[j] = min + C;
		opt_segment[j] = k;
	}

	return make_pair(OPT,opt_segment);
}


int main()	{
	int N, segment_length,k;
	long long x_sum, y_sum, xy_sum, xsquare_sum, nmr, dnmr;
	double C,tmp;


	printf("Enter penalty\n");
	cin>>C;
	printf("Enter number of points\n");
	cin>>N;

	vector<long long int> cml_x(N + 1), cml_y(N + 1), cml_xy(N + 1), cml_x_square(N + 1);
	
	vector<vector<double> > E(N + 1,vector<double>(N + 1)),slope(N + 1,vector<double>(N + 1))
	,intercept(N + 1,vector<double>(N + 1));	

	vector<Point> points(N+1);

	printf("Enter list of points\n");	

	for(int i=1;i<=N;i++) 
	{	
		cin>>points[i].x>>points[i].y;
	}

	cml_x[0] = cml_y[0] = cml_xy[0] = cml_x_square[0] = 0;
	for (int j = 1; j <= N; j++)	{
		cml_x[j] = cml_x[j-1] + points[j].x;
		cml_y[j] = cml_y[j-1] + points[j].y;
		cml_xy[j] = cml_xy[j-1] + points[j].x * points[j].y;
		cml_x_square[j] = cml_x_square[j-1] + points[j].x * points[j].x;

		for (int i = 1; i <= j; i++)	{
			segment_length = j - i + 1;
			x_sum = cml_x[j] - cml_x[i-1];
			y_sum = cml_y[j] - cml_y[i-1];
			xy_sum = cml_xy[j] - cml_xy[i-1];
			xsquare_sum = cml_x_square[j] - cml_x_square[i-1];

			nmr = segment_length * xy_sum - x_sum * y_sum;
			// printf("The Num is %lld, the j is %d, the i is %d: %d, %lld, %lld, %lld, %lld\n", num, j, i, segment_length, xy_sum, x_sum, y_sum, xsquare_sum);

			if (nmr == 0)
				slope[i][j] = 0.0;
			else {
				dnmr = segment_length * xsquare_sum - x_sum * x_sum;
				slope[i][j] = (dnmr == 0) ? INF : (nmr / double(dnmr));
			}
			intercept[i][j] = (y_sum - slope[i][j] * x_sum) / double(segment_length);

			for (k = i, E[i][j] = 0.0; k <= j; k++)	{
				tmp = points[k].y - slope[i][j] * points[k].x - intercept[i][j];
				E[i][j] += tmp * tmp;
			}
		}
	}

	pair<vector<double>,vector<int> > soln = segmented_least_squares(E,C,N);
	vector<double> OPT = soln.first;	
	vector<int> opt_segment = soln.second;

	cout<<endl<<"Cost : "<<OPT[N]<<endl<<endl;

	vector<pair<int,int> > segments;
	for (int i = N, j = opt_segment[N]; i > 0; i = j-1, j = opt_segment[i])	{
		segments.push_back(make_pair(j,i));
	}

	for (k=segments.size()-1;k>=0;k--)	{
		pair<int,int> segment = segments[k];
		int i = segment.first;
		int j = segment.second;

		cout<<"Segment #"<<segments.size()-k<<endl;
		cout<<"Equation : y = "<<slope[i][j]<<"*x + "<<intercept[i][j]<<endl;
		cout<<"Start point :  #"<<i<<" - ("<<points[i].x<<","<<points[i].y<<")"<<endl;
		cout<<"End point :  #"<<j<<" - ("<<points[j].x<<","<<points[j].y<<") "<<endl;
		cout<<"Least Squared Error : "<<E[i][j]<<endl<<endl;
	}
	return 0;
}