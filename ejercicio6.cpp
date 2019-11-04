#include <iostream>
#include <vector>

using namespace std;

void bubbleSort(vector<int>& a);

int nSwaps =0;

int main(int argc, char const *argv[])
{
    vector<int> vec;
    int num1;
    int num2;
    for(int i = 0; i < 3; i++){
        vec.clear();
        cin >> num1;
        for(auto j = 0; j < num1; j++){
            cin>>num2;
            vec.push_back(num2);
        }
        bubbleSort(vec);
    }
}

void bubbleSort(vector<int>& a)
{
    nSwaps = 0;
    bool swapp = true;
    while(swapp){
        swapp = false;
        for (size_t i = 0; i < a.size()-1; i++) {
            if (a[i]>a[i+1] ){
                a[i] += a[i+1];
                a[i+1] = a[i] - a[i+1];
                a[i] -=a[i+1];
                swapp = true;
                nSwaps++;
            }
        }
    }
    cout << "Optimal train swapping takes" << nSwaps << " swaps" << endl;
}

