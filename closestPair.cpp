
//given a set of points as input along with size of set,points can be real and float values,
// this program prints the least distance between two points among all possible combinations from given set

#include<bits/stdc++.h>
#include<iostream>
#include<cmath>
using namespace std;

typedef struct Point{
    float x,y;
}point;

//function to calculate distance b/w two points ,returns float value
float distance(point a,point b){ 
    return sqrt((a.x-b.x)*(a.x-b.x) + (a.y-b.y)*(a.y-b.y));
}

//divide and conquer approach to repeat same fn between two halves of sorted set of points
float closestPair(vector<point>vec,int l,int r){
    if(r-l+1 == 2) return distance(vec[0],vec[1]);
    else if(r-l+1 < 2) return LONG_MAX;  //for 0 or 1 point distance is not defined
    float lmin,rmin,min;
    long mid = (l+r)/2,i,j;
    point midPoint = vec[mid];
    lmin = closestPair(vec,l,mid);
    rmin = closestPair(vec,mid+1,r);
    min = lmin;
    if(rmin < lmin) min = rmin;
    vector<point> common;
    //take set of points which are capable of having least distance as less than min from above
    for(i = mid;midPoint.x - vec[i].x < min && i >= l;i--) common.push_back(vec[i]);
    for(i = mid+1;vec[i].x - midPoint.x < min && i <= r;i++) common.push_back(vec[i]);
    // for(i = 0; i < common.size();i++) cout<<common[i].x<<" " << common[i].y << " "<<  endl;
    sort(common.begin(),common.end(),[](point a,point b){return a.y < b.y;});
    for(i = 0; i < common.size(); i++){
        for(j = i+1; common[j].y - common[i].y < min && j < common.size();j++){
            if((lmin = distance(common[i],common[j]))< min) min = lmin;
        }
    }
    return min;
}

int main(){
    long i,j,n;
    point temp;
    cin >> n;
    vector<point> set;
    for(i = 0; i < n;i++){
        cin >> temp.x >> temp.y;
        set.push_back(temp);    
    }
    //sort with respect to x coordinate and call fn recursively on two halves of the set
    sort(set.begin(),set.end(),[](point p1,point p2){return (p1.x < p2.x);});
    //for(i = 0; i < n;i++) cout << set[i].x << " "<< set[i].y <<  endl;
    cout <<"Minimum distance  : " <<  closestPair(set,0,set.size()-1) << endl;
    return 0;
}