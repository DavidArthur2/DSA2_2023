
using namespace std;
#include "functions.h"


int main(){
    vector<Point> points;
    points= neighborhoodListFromFile("test.txt");
    vector<int> bfs = bfs_vector(points,0);
    print_vector(bfs);
}