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

char sim[2001][2001];
int a, b, c, d, totalArea = 0;

int main() {

    ifstream in;
    ofstream out;

    in.open("billboard.in");
    out.open("billboard.out");

    for (int i = 0; i < 2; i++) {
        in >> a >> b >> c >> d;
        a += 1000; b += 1000; c += 1000; d += 1000;
        for (int row = a; row < c; row++) {
            for (int col = b; col < d; col++) {
                sim[row][col] = 'b';
                totalArea++;
            }
        }
    }

    int count = 0;

    in >> a >> b >> c >> d;
    a += 1000; b += 1000; c += 1000; d += 1000;
    for (int row = a; row < c; row++) {
        for (int col = b; col < d; col++) {
            if (sim[row][col] == 'b')
                count++;
            sim[row][col] = 'v';
        }
    }

    out << totalArea - count;

    return 0;
}
