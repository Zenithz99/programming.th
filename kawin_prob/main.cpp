#include <iostream>
#include <vector>
using namespace std;

int k = 9, I = 4, J = 6;

int maps[1000][1000] = {
    {10,5,2,6,3,3},
    {7,8,-1,6,2,3},
    {5,1,7,6,7,7},
    {3,3,1,7,5,4}
    };
//output = 6

//find start point, save at (si,sj)
int si,sj;
void findstart() {
    for (int i=0; i<I; i++) {
        for (int j=0; j<J; j++) {
            if (maps[i][j] == -1) {
                si = i;
                sj = j;
                return;
            }
        }
    }
};

vector<int> check;
void findcheck() {
    check.push_back(1) ;
    if (!(si+1 >= I)) {check.push_back(maps[si+1][sj]);}
    if (!(sj+1 >= I)) {check.push_back(maps[si][sj+1]);}
    if (!(si-1 < 0)) {check.push_back(maps[si-1][sj]);}
    if (!(sj-1 < 0)) {check.push_back(maps[si][sj-1]);}
    return ;
} ;

bool visited[1000][1000];

void fillvisited() {
    for (int i ; i<I ; i++) {
        for (int j ; j<J ; j++) {
            visited[i][j] = false;
        }
    }
    visited[si][sj] = true;
    return;
};

int land;
void searchs(int i,int j,int high) {
    if (i<0 || j<0 || i>=I || j>=J) {return;}
    if (visited[i][j]) {return;}
    if (high >= maps[i][j]) {
        land += 1;
        searchs(i+1,j,maps[i][j]);
        searchs(i-1,j,maps[i][j]);
        searchs(i,j+1,maps[i][j]);
        searchs(i,j-1,maps[i][j]);
    }

}
int findhigh(int index) {
    if (check.size() == 1) {return check[0];}
    if (index >= check.size()) {return -1;}
    fillvisited();
    int high = check[index];
    land = 1;
    searchs(si+1,sj,high);
    searchs(si-1,sj,high);
    searchs(si,sj+1,high);
    searchs(si,sj-1,high);
    if (land >= k) {
        return check[index];
    }
    findhigh(index+1);
}
int main()
{
    /*cin >> I >> J >> k;
    for (int i ; i<I ; i++) {
        for (int j ; j<J ; j++) {
            cin >> maps[i][j];
        }
    }
    */
    cout << "Start \n" ;
    findstart();
    findcheck();
    cout << findhigh(0);
    cout << "End \n";
    return 0;
}
