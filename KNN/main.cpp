/*
Example of KNN

The input includes the training data (n data points consisting of {x, y, category}) and then the queries for wanted data (x and y of the wanted answer).

Input format:
    //Training data
    [n]
    [X1] [Y1][category]
    [X2] [Y2][category]
    [X3] [Y3][category]
    ...
    [Xn] [Yn][category]

    //Wanted data
    [X][Y]

by Sznupek
*/

#include <iostream>
#include <bits/stdc++.h>

#define MAX_N 1000001
#define f first
#define s second

using namespace std;

struct data_point
{
    float x=0, y=0;
    string cat="";
};
    
int n;
data_point data[MAX_N];

bool cmp(pair<float, int> a, pair<float, int> b)
{
    return a.f < b.f;
}
    
int main()
{   
    cout<<"How many points of data do you have? ";
    cin>>n;
    cout<<"Type in the [x][y][category] data points: "<<endl;

    for(int i=0; i<n; i++)
    {
        float x, y;
        string category;
        cin>>x>>y>>category;

        data[i].x = x;
        data[i].y = y;
        data[i].cat = category;
    }

    bool running = true;
    while(running)
    {
        float x, y;
        int k;
        
        cout<<">> ";
        cin>>x>>y>>k;

        vector<pair<float, int>> distances;
        for(int i=0; i<n; i++)
        {
            float xDiff = data[i].x - x;
            float yDiff = data[i].y - y;

            pair<float, int> distance = {sqrt(xDiff*xDiff + yDiff*yDiff), i};
            distances.push_back(distance);
        }

        sort(distances.begin(), distances.end(), cmp);

        map<string, int> votes;
        pair<string, int> best;
        for(int i=0; i<k; i++)
        {
            int idx = distances[i].s;
            string category = data[idx].cat;

            votes[category] += 1;
            if(votes[category] > best.s)
            {
                best.f = category;
                best.s = votes[category];
            }
        }

        cout<<"The given point belongs to the \""<<best.f<<"\" category."<<endl;
    }

    return 0;
}