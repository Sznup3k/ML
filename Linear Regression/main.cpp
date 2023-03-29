/*
Example of Linear Regression

The input includes the given data (n pairs of (x,y) points) and then the query for wanted data (x of the wanted answer or -1 (exit command)).

Input format:
    //Given data
    [n]
    [X1] [Y1]
    [X2] [Y2]
    [X3] [Y3]
    ...
    [Xn] [Yn]

    //Wanted data
    [X] or -1

by Sznupek
*/

#include <iostream>
#include <bits/stdc++.h>

#define MAX_N 1000000

using namespace std;
    
int n;
float xData[MAX_N], yData[MAX_N];

float xSum, ySum, xMean, yMean, a, b, r;

float findY(float x)
{
    return a*x + b;
}
    
int main()
{   
    cout<<"How many points of data do you have? ";
    cin>>n;
    cout<<"Type in the (x, y) pairs: "<<endl;

    for(int i=0; i<n; i++)
    {
        float x, y;
        cin>>x>>y;
        
        xData[i] = x;
        yData[i] = y;

        xSum += x;
        ySum += y;
    }

    xMean = xSum / n;
    yMean = ySum / n;

    float n1, n2; //numerator
    float d1, d2; //denominator
    
    for(int i=0; i<n; i++)
    {
        float xDiff = xData[i] - xMean;
        float yDiff = yData[i] - yMean;
        
        n1 += xDiff * yDiff;
        d1 += xDiff * xDiff; 
    }

    a = n1 / d1;
    b = yMean - (a * xMean);

    for(int i = 0; i < n; i++)
    {
        float actToMeanDist = yData[i] - yMean;
        float estToMeanDist = findY(xData[i]) - yMean;

        n2 += estToMeanDist * estToMeanDist;
        d2 += actToMeanDist * actToMeanDist;
    }

    r = n2 / d2;
    cout<<endl<<"This estimation has a "<<r*100<<"% fit."<<endl;

    bool running = true;
    while(running)
    {
        cout<<">> ";
        string input;
        cin>>input;

        if(input == "exit") running = false;
        else
        {
            float x = stoi(input);
            cout<<"y = "<<findY(x)<<endl;
        }
    }

    return 0;
}

/*
Example 1:

2 2
3 3
4 4

Perfect fit.
y = x


Example 2: (Temperatures in march 2023 in Warsaw, 12 AM)
[day][temperature in celsius]

1 7
2 2.5
3 -0.6
4 2.5
5 0.25
6 0
7 2
8 5.2
9 0.45
10 5
11 2
12 3
13 10
14 15
15 6.5
16 7
17 8.5
18 11.5
19 16.99
20 16.48
21 9
22 10.9
23 19
24 15.5
25 15.88

67.4385% fit
Linear regression is a terrible choice for such tasks but the example serves it purpose for testing the algorithm (and its fun).
Source of the temperatures: https://www.meteo.waw.pl/hist.pl
Temperatues for the rest of the month:
26 9.8
27 5.5
28 0.1
*/