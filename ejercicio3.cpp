#include <iostream>
#include <vector>

using namespace std;

int main() {
    vector<int> v;
    int num;
    for(int i =0; i < 5; i++){
        cin >> num;
        v.push_back(num);
    }
    int y,i;

    for(auto it:v){
        y = 0;
        for(i = 0; i < 4; i++){
            y = (y<<8) | ((it>>(8*i))&255);
        }
        cout << it << " converts to " << y;
        cout << endl;
    }
    return 0;
}
