#include <iostream>
#include <vector>
#include <fstream>
#include <stdlib.h>
#include <map>

using std::cin; using std::cout; using std::endl; using std::getline; using std::string; using std::vector;
using std::map;

template<typename T, typename M>
void printMap(map<T,M> map1){
	for(auto it = map1.begin(); it != map1.end(); it++){
		cout << it->second;
		cout << endl;
	}
}

int main(){
	int casos;
	int num;
	double num2;
	int unoOno;
	string aux;
	cin >> casos;
	cin.ignore(1,'\n');
	string linea1;
	getline(cin,linea1);
	string linea2;
	getline(cin,linea2);
	vector<int> v1;
	vector<double> v2;
	for(auto it = linea1.begin(); it != linea1.end(); it++){
		if(*it != ' ')
			aux += *it;
		if(*it == ' ' or it == linea1.end()-1){
			num = atoi(aux.c_str());
			v1.push_back(num);
			aux = ' ';
		}
	}
	aux = ' ';
	for(auto it = linea2.begin(); it != linea2.end(); it++){
		if(*it == '-')
			unoOno = -1;
		else
			unoOno = 1;
		if(*it != ' ')
			aux += *it;
		if(*it == ' ' or it == linea2.end()-1){
			num2 = stod(aux);
			num2 *= unoOno;
			v2.push_back(num2);
			aux = ' ';
		}
	}
	map<int,double>map1;
	auto it1 = v1.begin();
	auto it2 = v2.begin();
	for(auto it:v1){
		map1.insert(std::pair<int,double>(*it1,*it2));
		it1++;
		it2++;
	}
	printMap(map1);
return 0;
}
