#include <iostream>
#include <vector>
#include <string>
#define N 5
using namespace std;

int main() {
    vector <int>array;
    vector <string>str(3);
    vector<int> :: iterator it;
    for(int i =0; i <N; ++i) {
        array.push_back(i);
    }
    str[0] = "kim";
    str[1] = "lee";
    str[2] = "park";

    for(it = array.begin(); it < array.end(); ++it) {
        cout << *it << endl;
    }
    for (int i=0; i < 3; i++) {
        cout << str[i] << endl;
    }
    return 0;
}