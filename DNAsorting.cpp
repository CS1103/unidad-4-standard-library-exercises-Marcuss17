#include <iostream>
#include <vector>
#include <string>
#include <map>

using namespace std;

template<typename T>
void printVector(vector<T> v){
	for(auto it : v)
		cout << it << " ";
}

void bubbleSort(string s, int n, int& count){
	int i, j;
	int temp;
	for(i = 0; i < n-1;i++)
		for(j = 0; j < n-i-1;j++)
			if(s[j] > s[j+1]){
				temp = s[j];		
				s[j] = s[j+1];
				s[j+1] = temp;
				count ++;
			}
}

void printMap(map<int,string> m){
	for(auto it : m)
		cout << it.second << endl;
}
	
int main(){
	map<int,string> map1;
	int count;
	string s;
	
	for(int i = 0; i < 6; i++){
		count =0;
		cin >>s;
		bubbleSort(s,s.size(),count);
		map1.insert(pair<int,string>(count,s));
	}
	printMap(map1);
return 0;
}
