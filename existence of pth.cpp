#include<iostream>
#include<fstream>
#include<vector>
using namespace std;

bool findPath (bool graph[100][100],vector<int> path,int n){
for(int i=0;i<n-1;i++)
{
    int x = path[i];
    int y = path[i+1];
    if (graph[x][y]!=1)
        return false;

}
return true;

}


int main (int argc,char* argv[]) {
    char* inpFile = argv[1];
    char* outFile = argv[2];
    ifstream fout;
    ofstream fin;
    fout.open (inpFile);
    fin.open (outFile);
    string s;
    getline (fout,s);
    //int vertices = s[0] - '0';
    bool graph[100][100];
    for (int i=0;i<100;i++) 
    {
        for (int j=0;j<100;j++)
            graph[i][j] = 0;
    }
    getline (fout,s);
    vector<int> path;
    while (!fout.eof())
    {
        string s;
        getline (fout,s);
        int len = s.length();
        if (!fout.eof())   //filling up of the graph
        {
            int src = s[0]- '0',des = s[2] - '0';
            graph[src][des] = 1;
        }
        if (fout.eof())
        {
            for (int i=0;i<len;i+=2)
            {
                path.push_back(s[i]-'0');
            }
        }

    }
    int n = path.size();
    fin<<findPath(graph,path,n);
    fout.close();
    fin.close();
}