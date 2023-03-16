//
// Created by david.arthur on 3/16/2023.
//

#include "functions.h"

vector <Points> neighborhoodListFromFile(char *input) {
    int nrPoints, nrEdges;
    ifstream f(input);
    f >> nrPoints >> nrEdges;

    vector <Point> points(nrPoints);
    for (int i = 0; i < nrEdges; i++) {
        int from, to;
        f >> from >> to;
        points.at(from - 1).neighbors.push_back(to - 1);
        points.at(to - 1).neighbors.push_back(from - 1);
    }
    for (int i = 0; i < nrPoints; i++) {
        sort(points.at(i).neighbors.begin(), points.at(i).neighbors.end());
    }
    return points;
}
vector<int> bfs_vector(vector <Point> &points, int startingPoint) {
    for (int i = 0; i < points.size(); i++) {
        points.at(i).color = 0;
        points.at(i).father = 0;
        points.at(i).distance = INT_MAX;
    }
    points.at(startingPoint).color = 1;
    points.at(startingPoint).distance = 0;
    queue<int> queue;
    vector<int> bfs;
    queue.push(0);
    while(!queue.empty()) {
        int u = queue.front();
        bfs.push_back(u);
        for (int i = 0; i < points.at(u).neighbors.size(); i++) {
            if (points.at(points.at(u).neighbors.at(i)).color == 0) {
                points.at(points.at(u).neighbors.at(i)).color = 1;
                points.at(points.at(u).neighbors.at(i)).father = 0;
                points.at(points.at(u).neighbors.at(i)).distance += 1;
                queue.push(points.at(u).neighbors.at(i));
            }
        }
        queue.pop();
        points.at(u).color = 2;
    }
    return bfs;
}
void print_vector(vector<int> vector1) {
    for(int i=0;i<vector1.size();i++)
        printf("%d ",vector1.at(i));
}
void dfsRun(vector<Point> &mPoints, int current, vector<int> &dfs) {
    dfs.push_back(current);
    mPoints.at(current).color = 1;
    for (int v = 0; v < mPoints.at(current).neighbors.size(); v++) {
        if (mPoints.at(mPoints.at(current).neighbors.at(v)).color == 0) {
            mPoints.at(mPoints.at(current).neighbors.at(v)).father = v;
            mPoints.at(mPoints.at(v).neighbors.at(v)).distance +=1;
            dfsRun(mPoints, mPoints.at(current).neighbors.at(v) , dfs);
        }
    }
    mPoints.at(current).color = 2;
}
vector<int> DFS(vector<Point> &mPoints) {
    for (int i = 0; i < mPoints.size(); i++) {
        mPoints.at(i).color = 0;
        mPoints.at(i).father = 0;
        mPoints.at(i).distance = INT_MAX;
    }
    vector<int> dfs;
    for (int i = 0; i < mPoints.size(); i++) {
        if (mPoints.at(i).color == 0) {
            dfsRun(mPoints, i, dfs);
        }
    }
    return dfs;
}