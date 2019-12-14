//finding all the subsets of a set using a recursive tree
#include<iostream>
#include<vector>
using namespace std;
//we start with a empty subset and choose whether the i th element of the master set is to be added
//or not
void subset(vector<int>& arr,vector<vector<int>>& result,vector<int>& sub,int i)
{
	int k;
	result.push_back(sub);//pushing the formed subset into the 2-d vector
	for(k=i;k<arr.size();k++)
	{       
		sub.push_back(arr[k]);//pushing the ith element in the vector sub
		subset(arr,result,sub,k+1);//recursive along that edge of tree
		sub.pop_back();//poping the element
	}
}
int main()
{
	int i,j;
	vector <int>arr={1,2,3};
	vector<vector<int>>result;
	vector<int>sub;
	subset(arr,result,sub,0);
	for(i=0;i<result.size();i++)
	{
		for(j=0;j<result[i].size();j++)
		cout<<result[i][j]<<" ";
		cout<<endl;
	}
}

