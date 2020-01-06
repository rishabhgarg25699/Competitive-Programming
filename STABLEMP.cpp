#include<bits/stdc++.h>
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

 vector<int> stableMariage(vector<vector<int>> &menPref, vector<vector<int>> &womenPref)
{
    int n = menPref.size();
 	vector<vector<int>> mapWM(n);
 	for (int i = 0; i < n; ++i)
        mapWM[i].resize(n);
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            mapWM[i][ womenPref[i][j] ] = j;
    vector<int> womanMatch(n, -1);
    vector<int> manMatch(n, -1);
    queue<int> q;
    for (int i = 0; i < n; ++i)
        q.push(i);
    while (!q.empty())
    {
        int man = q.front();
        q.pop();
        for (int woman : menPref[man])
        {
            if (womanMatch[woman] == -1) 
            {
                womanMatch[woman] = man;
                manMatch[man] = woman;
                break;
            }
            else
            {
                int otherMan = womanMatch[woman];
                if (mapWM[woman][otherMan] > mapWM[woman][man])
                {
                    manMatch[otherMan] = -1;
                    q.push(otherMan);
                    womanMatch[woman] = man;
                    manMatch[man] = woman;
                    break;
                }
            }
        }
    }
 
    return manMatch;
}

int main() {
	IOS;
	int t;
	cin>>t;
	while(t--) {
		int n,temp;
		cin>>n;
		vector<vector<int>> menPref(n), womenPref(n);
		for (int i = 0; i < n; ++i) {
			womenPref[i].resize(n);
			cin>>temp;
			for (int j = 0; j < n; ++j)  {
				cin>>womenPref[i][j];
				womenPref[i][j]--;
			}
		}
		for (int i = 0; i < n; ++i) {
			menPref[i].resize(n);
			cin>>temp;
			for (int j = 0; j < n; ++j)  {
				cin>>menPref[i][j];
				menPref[i][j]--;
			}
		}
		vector<int> marriages = stableMariage(menPref,womenPref);
		for (int i = 0; i < n; ++i) {
			cout<<i+1<<" "<<marriages[i]+1<<endl;
		}
	}

	return 0;
}