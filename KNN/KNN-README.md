# K-Nearest Neighbors
This is my take on the KNN algorithm. It's a really simple implementation for 2D data.

## Input
The input template:
```
[N]
[X1] [Y1] [category]
[X2] [Y2] [category]
[X3] [Y3] [category]
...
[Xn] [Yn] [category]
[x] [y] [k]
```

The first part of the input is the training data. The first line contains the number N (N < 1000000) which is the number of data points (x, y, category). The next N lines are the individual data points that consist of the X and Y values (`int` type) and the category (`string` type). The N+2 line (first line after the N data points) and all the following lines are the second part of the input. You input the data point and K value and the program will return the category to which the data point belongs. The template for this part looks as follows: the X and Y values and the K value. After the query is answered the program will repeat the question and it will loop infinitely. **At the moment there is no command to stop the program so you either have to use something like c+ctrl on windows or simply close the window but I'll fix that in the future.** <br><br>

Example input:
```
5
1 5 blue
2 5 blue
4 2 red
1 1 green
4 4 yellow
1 4 3
1 4 2
2 2 5
3 3 4
...
```

If you want to test the program I have cleaned data from the [Iris database](https://archive.ics.uci.edu/ml/datasets/iris) in the `Iris-data-cleaned.txt` file. It contains 150 lines of training data to experiment for yourself. I also found a nice graph of the data if you want some kind of visualization but I plan on doing a built-in graph that will update accordingly with the queries you ask the program. <br> <br>
![The graph I found](https://scipy-lectures.org/_images/sphx_glr_plot_iris_scatter_001.png) 
