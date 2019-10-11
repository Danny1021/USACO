#include <iostream>
#include <vector>
#include <sstream>
#include <numeric>
#include <string>
#include <algorithm>
#include <cmath>
#include <regex>
#include <map>
#include <set>
#include <queue>
#include <fstream>

using namespace std;

int transR[] = {0, 0, 1, -1};
int transC[] = {1, -1, 0, 0};

char grid[10][10];

pair<int, int> findB() {
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            if (grid[i][j] == 'B')
                return make_pair(i, j);
        }
    }
    return make_pair(-1, -1);
}

pair<int, int> findL() {
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            if (grid[i][j] == 'L')
                return make_pair(i, j);
        }
    }
    return make_pair(-1, -1);
}

bool inBounds(int x, int y) {
    return x >= 0 && y >= 0 && x < 10 && y < 10;
}

int main() {

    ifstream in;
    ofstream out;

    in.open("buckets.in");
    out.open("buckets.out");

    int fill[10][10];

    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            fill[i][j] = -1;
            in >> grid[i][j];
        }
    }

    pair<int, int> start = findL();
    pair<int, int> end = findB();

    fill[start.first][start.second] = 0;

    queue<pair<int, int>> q;
    q.push(start);

    while (fill[end.first][end.second] == -1) {
        pair<int, int> curr = q.front();
        q.pop();
        for (int i = 0; i < 4; i++) {
            int newR = curr.first + transR[i];
            int newC = curr.second + transC[i];
            if (!inBounds(newR, newC))
                continue;
            if (fill[newR][newC] == -1 && (grid[newR][newC] == '.' || grid[newR][newC] == 'B')) {
                fill[newR][newC] = fill[curr.first][curr.second] + 1;
                q.push(make_pair(newR, newC));
            }
        }
    }

    out << fill[end.first][end.second]-1;

    return 0;
}
