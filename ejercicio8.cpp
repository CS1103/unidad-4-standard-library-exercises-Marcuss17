#include <iostream>
#include <vector>
#include <sstream>
#include <map>

using namespace std;

template<typename T>
void printV(vector<T> v){
	for(auto it : v)
		cout << it << endl;
}

void printMap(map<int,string,greater<int> > mp1){
	for(auto it :mp1)
		cout << it.second<< endl;
}

int main(){
	string s;
	vector<string> v1;
	vector<int> counts;
	vector<string> uppers;
	int count =0;
	map<int, string,greater<int> > map1;
	for(int i = 0; i < 11; i++){
		fflush(stdin);
		getline(cin,s);
		v1.push_back(s);		 	
	}
	
	for(auto it = v1.begin(); it != v1.end(); it++){
		char c =(*it)[0] ;
		if(it == v1.begin() && isupper(c)){
			uppers.push_back(*it);
		}
		if(islower(c)){
			count++;
		}
		if(isupper(c) && it != v1.begin()){
			counts.push_back(count);
			count = 0;
			uppers.push_back(*it);
		}
	}
	counts.push_back(0);
 	cout << endl;
	auto it1 = uppers.begin();
	auto it2 = counts.begin();
	for(auto it : uppers){
		map1.insert(pair<int,string>(*it2,*it1));
		it1++;
		it2++;
	}
	printMap(map1);
return 0;
}
