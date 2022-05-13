#include <iostream>
#include <utility>
#include <algorithm>
#include <cmath>
#include <vector>
#include <fstream>

using namespace std;
typedef pair<int, int> pii;

const int MAX = 1e9 + 10;


struct distWithIndices{
    double d;
    pair<int, int> p1, p2;
};

void print(pii p){
    cout << p.first << " " << p.second << "\n";
}

void print(distWithIndices r){
    cout << "dist : " << r.d << "\n";
    print(r.p1);
    print(r.p2);
}

double distance(pair<int, int> p1, pair<int , int> p2){
    int dx = p1.first - p2.first;
    int dy = p1.second - p2.second;
    int rs = dx * dx + dy * dy;
    return sqrt(rs);
}

int t = 0;

void debug(){
    cout << "here\n";
}

distWithIndices closestPair(vector<pii> &X, vector<pii> &Y, int n, bool storeIndex){

    cout << "n = " << n <<"\n";
    if(n <= 3){
        distWithIndices res;
        res.d = MAX;
        for(int i = 1; i < n; ++i){
            double curr = distance(X[i], X[i - 1]);
            if(res.d > curr){
                res.d = curr;
                res.p1 = X[i];
                res.p2 = X[i-1];
            }
        }
        if(n == 3){
            double d = distance(X[2],X[0]);
            if(d < res.d){
                res.d = d;
                res.p1 = X[0];
                res.p2 = X[2];
            }
        }
        return res;
    }
    int mid = n / 2 ;
    vector<pii> left(mid), right(n - mid);
    int li = 0, ri = 0;
    for(int i = 0; i < n; ++i){
        if(Y[i].first <= X[mid - 1].first && li < mid){
            left[li++] = Y[i];
        }
        else{
            right[ri++] = Y[i];
        }
    }

    // cout << mid << n - mid << "\n";

    vector<pii> xLeft(mid);
    vector<pii> xRight(n - mid);

    // cout << "left\n" ;

    for(int i = 0; i < mid; ++i)
        xLeft[i] = X[i];
    for(int i = mid; i < n; ++i)
        xRight[i - mid] = X[i];



    distWithIndices d1 = closestPair(xLeft, left, mid, false);
    distWithIndices d2 = closestPair(xRight, right, n - mid, false);
    distWithIndices mx, mn;

    if(d1.d < d2.d){
        mx = d2;
        mn = d1;
    }
    else{
        mx = d1;
        mn = d2;
    }


    vector<pii> pointsInside2d;
    int pi = 0;
    for(int i = 0; i < n; ++i){
        if(abs(X[mid - 1].first - Y[i].first) < mn.d){
            pointsInside2d.push_back(Y[i]);
        }
    }

    pi = pointsInside2d.size();

    t+= pi;

    distWithIndices res = mn;

    for(int i = 0; i < pi; ++i){
        for(int j = i + 1; (j < pi) && (pointsInside2d[j].second -  pointsInside2d[i].second) < mn.d;++j ){
            double dCurr = distance(pointsInside2d[i], pointsInside2d[j]);
            if(dCurr < mn.d){
                res.d = dCurr;
                res.p1 = pointsInside2d[i];
                res.p2 = pointsInside2d[j];
            }
        }
    }

    return res;

}

bool compX(pair<int, int> &p1, pair<int, int> &p2){
    if(p1.first == p2.first) return p1.second < p2.second;
    return p1.first < p2.first;
}

bool compY(pair<int, int> &p1, pair<int, int> &p2){
    if(p1.second == p2.second) return p1.first < p2.first;
    return p1.second < p2.second;
}



distWithIndices closestPairExcPair(vector<pii> X, vector<pii> Y, pii del){
    auto it = find(X.begin(), X.end(), del);
    X.erase(it);
    it = find(Y.begin(), Y.end(), del);
    Y.erase(it);
    // for(auto x : Y){
    //     print(x);
    // }
    return closestPair(X, Y, X.size(), false);
}


void createTestCases(int n, char *name){
    ofstream file(name);
    file << n << "\n";
    for(int i = 0; i < n ; ++i)
        file << rand() % (20000) - 10000 << " " << rand() % (20000) - 10000 << "\n";
//        file << i << " " << i + 10 << "\n";

}

int main(){

//    createTestCases(10000, "test cases/mine2.txt");

    // fstream file("test cases/mine2.txt");


    int n;
    cin >> n;

    vector<pii>  houses(n);
    vector<pii>  sortedX(n);
    vector<pii>  sortedY(n);
    cout << n << "\n";

    for(int i = 0; i < n; ++i){
        int a, b;
        cin >> a >> b;
        houses[i] = {a, b};
        sortedX[i] = houses[i];
        sortedY[i] = houses[i];
    }
        // cin >> houses[i].first >> houses[i].second;
        // cout << i << "\n";


    cout << n << "\n";


    // for(int i = 0; i < n; ++i){
    //     sortedX[i] = sortedY[i] = houses[i];
    // }
    sort(sortedX.begin(), sortedX.end(), compX);
    sort(sortedY.begin(), sortedY.end(), compY);



    // for(int i = 0; i < n; ++i){
    //     cout << sortedY[i].first <<  " " << sortedY[i].second << "\n";
    // }


    // for(int i = 0; i < n; ++i){
    //     cout << sortedX[i].first <<  " " << sortedX[i].second << "\n";
    // }

    pair<int, int> p1, p2;

    distWithIndices closest = closestPair(sortedX, sortedY, n, false);

    print(closest);

    // print(closest);
    // auto r1 = closestPairExcPair(sortedX, sortedY, closest.p1);

    // // print(r1);
    // auto r2 = closestPairExcPair(sortedX, sortedY, closest.p2);

    // cout << "here\n";

    // distWithIndices res = r1;
    // if(r2.d < r1.d){
    //     res = r2;
    // }

    // print(r1);
    // print(r2);

    // cout << "res : " << res.d << "\n";
    // print(res);

    return 0;
}
