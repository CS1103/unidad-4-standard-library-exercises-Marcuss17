#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <iomanip>

using namespace std;

template<typename T>
void print(vector<T> v){
    for(auto it : v)
        cout << it << " ";
}
int main()
{
    string myStr;
    vector<string> arboles;
    for(int i = 0;i <29;i++){
        getline(cin,myStr);
        arboles.push_back(myStr);
    }
    map<string, double> treeLog;
    for(auto const &a : arboles)
        treeLog[a]++;
    double sum = 0;
    for(auto &t : treeLog){
        sum += t.second;
    }
    double aux = 0;
    for(auto &t :treeLog){
        aux = t.second;
        t.second = aux/sum;
    }

    for(auto const &t: treeLog){
        cout << setprecision(5)<< t.first << " " << t.second *100<< endl;
    }
    return 0;
}
