#include <string>
#include <vector>
#include <queue>

using namespace std;

vector<vector<int>> matrix;

void init(int rows, int columns){
    int num = 1;
    matrix.resize(rows+1, vector<int> (columns+1));
    for(int i = 1; i<= rows; i++){
        for(int j = 1; j<=columns; j++)
            matrix[i][j] = num++;
    }
}

int rot(int x1, int y1, int x2, int y2){
    queue<int> q;
    int x, y;
    int res = 2e9;
    
    x = x1;
    y = y1;
    while(y<y2)
        q.push(matrix[x][y++]);
    while(x<x2)
        q.push(matrix[x++][y]);
    while(y>y1)
        q.push(matrix[x][y--]);
    while(x>x1)
        q.push(matrix[x--][y]);
    x = x1;
    y = y1;
    while(y<y2){
        res = min(res, q.front());
        matrix[x][++y] = q.front();
        q.pop();
    }
    while(x<x2){
        res = min(res, q.front());
        matrix[++x][y] = q.front();
        q.pop();
    }
    while(y>y1){
        res = min(res, q.front());
        matrix[x][--y] = q.front();
        q.pop();
    }
    while(x>x1){
        res = min(res, q.front());
        matrix[--x][y] = q.front();
        q.pop();
    }
    return res;
}


vector<int> solution(int rows, int columns, vector<vector<int>> queries) {
    vector<int> answer;
    int minimum;
    init(rows, columns);
    for(int i = 0; i<queries.size(); i++){
        minimum = rot(queries[i][0], queries[i][1], queries[i][2], queries[i][3]);
        answer.push_back(minimum);
    }
    return answer;
}