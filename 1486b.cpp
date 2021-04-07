#include <iostream>
#include <utility>
#include <vector>
typedef long long ll;
using namespace std;

long long distance(pair<ll,ll> points[],int n,pair<ll,ll> p,string axis){
	ll s = 0;
	if(axis == "x"){
		for(int i = 0; i < n;++i){
			s += abs(points[i].first - p.first);
		}
	}
	else{
		for(int i = 0; i < n;++i){
			s += abs(points[i].second - p.second);
		}
	}
	return s;
}

int main(){

	int t;scanf("%d",&t);
	while(--t>=0){
		int n;scanf("%d",&n);
		pair<ll,ll> points[n];
		for(int i = 0; i < n;++i){
			scanf("%lld %lld",&points[i].first,&points[i].second);
		}
		long long xDistance = distance(points,n,{0,0},"x");
		long long yDistance = distance(points,n,{0,0},"y");
		ll xAvg = xDistance / n;
		xAvg = distance(points,n,{xAvg,0},"x") <= distance(points,n,{xAvg+1,0},"x") ? xAvg : xAvg + 1;
		ll mxRight = points[0].first;
		ll mxLeft = points[0].first; 
		for(int i = 1; i < n;++i){
			mxRight = points[i].first > mxRight ? points[i].first : mxRight;
			mxLeft =  points[i].first < mxLeft ? points[i].first : mxLeft;
		}

		ll begin = xAvg;
		ll end = mxRight;
		ll begDist = distance(points,n,{xAvg,0},"x");
		ll mid,midPrev = -1;
		while(end >= begin){
			mid = (begin + end) >> 1;
			ll dist = distance(points,n,{mid,0},"x");
			if(dist > begDist){
				end = mid - 1;
			}
			else if(dist == begDist){
				begin = mid + 1;
			}
			else{
				printf("ERROR IN LOGIC");
			}
		}

		ll xRight = begin - 1;

		begin = mxLeft;
		end = xAvg;
		while(end >= begin){
			mid = (begin + end) >> 1;
			ll dist = distance(points,n,{mid,0},"x");
			if(dist > begDist){
				begin = mid + 1;
			}
			else if(dist == begDist){
				end = mid - 1;
			}
			else{
				printf("ERROR IN LOGIC");
			}
		}

		ll xLeft = end + 1;

		ll xRange = xRight - xLeft + 1;

		ll yAvg = yDistance / n;
		yAvg = distance(points,n,{0,yAvg},"y") <= distance(points,n,{0,yAvg+1},"y") ? yAvg : yAvg + 1;
		ll myRight = points[0].second;
		ll myLeft = points[0].second;
		for(int i = 1; i < n;++i){
			myRight = points[i].second > myRight ? points[i].second : myRight;
			myLeft = points[i].second < myLeft ? points[i].second : myLeft;
		}
		// printf("mxRight : %lld\n",mxRight);

		begin = yAvg;
		end = myRight;
		// printf("End: %lld begin : %lld\n",end,begin);
		begDist = distance(points,n,{0,yAvg},"y");
		while(end >= begin){
			mid = (begin + end) >> 1;
			ll dist = distance(points,n,{0,mid},"y");
			if(dist > begDist){
				end = mid - 1;
			}
			else if(dist == begDist){
				begin = mid + 1;
			}
			else{
				printf("ERROR IN LOGIC");
			}
		}

		ll yRight = begin - 1;

		begin = myLeft;
		end = yAvg;
		while(end >= begin){
			mid = (begin + end) >> 1;
			ll dist = distance(points,n,{0,mid},"y");
			if(dist > begDist){
				begin = mid + 1;
			}
			else if(dist == begDist){
				end = mid - 1;
			}
			else{
				printf("ERROR IN LOGIC");
			}
		}

		ll yLeft = end + 1;

		ll yRange = yRight - yLeft + 1;

		printf("%lld\n",xRange * yRange );

	}
}