#include <iostream>
#include <map>

using std::cin; using std::string; using std::map; using std::cout; using std::endl;

template<typename T, typename M>
void printMap(map<T,M> map1){
	for(auto it = map1.begin(); it != map1.end(); it++){
		cout << it->first << ':' << it->second;
		cout << endl;
	}
}

int main(){
	int test;
	cin >> test;
	cin.ignore(1,'\n');
	int paidCharacters;
	cin >> paidCharacters;
	cin.ignore(1,'\n');
	string myStr;
	char key;
	int num;
	double cent;
	string aux;
	string parr;
	map<char,double>map1;
	for(int i = 0; i < 7; i++){
		key = ' ';
		aux = ' ';
		fflush(stdin);
		getline(cin,myStr);
		for(auto it = myStr.begin(); it != myStr.end(); it++){
			if(it == myStr.begin())
				key = *it;
			if(it > myStr.begin()+1){
				aux += *it;
			}
			if(it == myStr.end()-1){
				num = atoi(aux.c_str());
				cent = num/100.0;
			}
		}
		map1.insert(std::pair<char,double>(key,cent));		
	}
	int nextLines;
	cin >> nextLines;
	cin.ignore(1,'\n');
	string line;
	for(int i = 0; i < 7; i++){
		fflush(stdin);
		getline(cin,line);
		parr += line;
	}
	double sum=0;

	for(auto it : parr){
		for(auto it2 = map1.begin();it2!=map1.end();it2++){
			if(it == it2->first)
				sum += it2->second;		
		}
	}
	cout << sum << '$';

return 0;
}
