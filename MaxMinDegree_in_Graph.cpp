// This program is to input a graph and save it in the form of an Adjacency Matrix in C++ and
// then find the nodes with minimum and maximum degrees
// Code by Nishit Anand

#include <iostream>
using namespace std;

    // Function to take input from user that the edges
    // are between which two vertices and also the weight of that edge
    void takeInput(int adj[25][25],int e)
    {
    int i, x, y, w;
    // Now we will make a for loop from 1 to e (which is number  of edges)
    // and take input from user that the edge is between which two vertices
    // and also take input the weight of the edge
        for (i = 0; i < e; i++) 
        {
            cout << "Enter the two vertices between which edge exists" << endl;
            cin >> x >> y;
            cout << "Enter the weight of the edge" << endl;
            cin >> w;
            // And since this is an undirected graph, we will make adj[x][y]
            // and adj[y][x] both equal to w (which is weight of that edge)
            adj[x][y] = w;
            adj[y][x] = w;
        }
    cout << endl;
    }

    // Function to print Adjacency Matrix
    void printAdjMatrix (int adj[25][25],int v)
    {
    int i, j;
    // This loop below is used to print the adjacency matrix
    cout << "The Adjacency Matrix is-" << endl << endl;
        for (i = 1; i <= v; i++) 
        {
            for (j = 1; j <= v; j++) 
            {
                cout << adj[i][j] << " ";
            }
        cout << endl;
        }
    }

    // Function to find minimum and maximum degree vertices and print them
    void findMaxMin (int adj[25][25], int v)
    {
    int i, j;
    // Max and Min store the maximum and minimum degrees
    // Maxnode and Minnode store the nodes which have
    // these maximum and minimum degrees
    int max = 0, min = 100, count = 0, maxnode, minnode;
    // Now to find the vertices/nodes with maximum and minimum degree we will
    // traverse the 2D array.
    for (i = 1; i <= v; i++) 
        {
            // Count is initialized as zero for every row and it tells us the
            // degree of each vertex/node.
            count = 0;
            // We will traverse the each row and for each adj[i][j] which is
            // not 0 (zero), we will increase the variable 'Count' by 1
            for (j = 0; j <= v; j++) 
                {
                if (adj[i][j] != 0)
                    count++;
                }
            // Then will will compare this count to max and if it is greater than max
            // then max will become equal to count
            // and maxnode will become that vertex (which is 'i')
            if (count > max) 
                {
                    max = count;
                    maxnode = i;
                }
            // Similarly we will check count and min
            if (count < min) 
                {
                    min = count;
                    minnode = i;
                }
        }
    //In the end we will print Maximum and minimum degree nodes and their degrees
    cout << endl;
    cout <<"MAXIMUM DEGREE NODE IS "<< maxnode <<" and it's degree is "<< max;
    cout << endl;
    cout << "MINIMUM DEGREE NODE IS " << minnode << " and it's degree is "<< min;
    cout << endl;
    }

int main()
{
    int i, j;
    // Now we will create a 2D integer array and initialize
    // it with each element as 0
    int adj[25][25];
    for (i = 0; i < 25; i++) 
    {
        for (j = 0; j < 25; j++) 
        {
            adj[i][j] = 0;
        }
    }
    int v, e;
    // v and e denote the number of vertices and edges in the graph
    // We will take input the number of vertices and edges from the user
    cout << "Enter number of vertices and edges" << endl;
    cin >> v >> e;
    // Calling function to take input from user that the edges
    // are between which two vertices and also the weight of that edge
    takeInput(adj,e);
    // Calling function to print Adjacency Matrix
    printAdjMatrix(adj,v);
    //Calling function to find minimum and maximum degree vertices and print them
    findMaxMin(adj,v);
    return 0;
}
