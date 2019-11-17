#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

struct contestant{
	int id, problemSolved, penalty;
	string status;
};

struct contestantOut{
	int id;
	int numproblems = 0;
	int penaltyTime = 0;
};

int main(){
	string line;
	vector<contestantOut> c2;
	int count =0;
	string aux,sid,sproblem,spenalty;
	char status;
	int id,problem,penalty,numproblems,penaltyTime;
	bool same;
	while(getline(cin,line)){
		if(count != 0){
			contestantOut c;
			aux = line;
			sid = "";
			sproblem = "";
			spenalty = "";
			status = '\0';
			numproblems = 0;
			penaltyTime = 0;
			for(int i = 0; i < 4; i++){
				auto it = find(aux.begin(),aux.end(),' ');
				auto it2 = aux.begin();
				if(i == 0){
					while(it2 != it){
						sid += *it2;
						it2++;
					}
					id = stoi(sid);
					aux.erase(0,2);
					cout << id << ':';
				}
				else if(i == 1){
					while(it2 != it){
						sproblem += *it2;
						it2++;
					}
					problem = stoi(sproblem);
					cout << problem << ':';
					aux.erase(0,2);
				}
				else if(i == 2){
					while(it2 != it){
						spenalty += *it2;
						it2++;
					}
					penalty = stoi(spenalty);
					cout << penalty << ':';
					aux.erase(0,3);
				}
				else{
					while(it2 != it){
						status += *it2;
						it2++;
					}
					cout << status << endl;
				}
			}		
			
			for(auto it : c2){
				if(id == it.id){
					cout << id << endl;
					if(status == 'C' || status == 'I'){
						it.penaltyTime += penalty;
						it.numproblems++;
					}
				}
				else{
					if(status == 'C' || status == 'I'){
						c.penaltyTime = penalty;
						c.id = id;
					}
					if(status == 'C'){c.numproblems++;}
					c2.push_back(c);
				}
			}
		}
		else if(count == 0){
			contestantOut c;
			aux = line;
			sid = "";
			sproblem = "";
			spenalty = "";
			status = '\0';
			numproblems = 0;
			penaltyTime = 0;
			for(int i = 0; i < 4; i++){
				auto it = find(aux.begin(),aux.end(),' ');
				auto it2 = aux.begin();
				if(i == 0){
					while(it2 != it){
						sid += *it2;
						it2++;
					}
					id = stoi(sid);
					cout << id << ':';
					aux.erase(0,2);
				}
				else if(i == 1){
					while(it2 != it){
						sproblem += *it2;
						it2++;
					}
					problem = stoi(sproblem);
					cout << problem << ':';
					aux.erase(0,2);
				}
				else if(i == 2){
					while(it2 != it){
						spenalty += *it2;
						it2++;
					}
					penalty = stoi(spenalty);
					cout << penalty << ':';
					aux.erase(0,3);
				}
				else{
					while(it2 != it){
						status += *it2;
						it2++;
					}
					cout << status << endl;
				}		
			}
			if(status == 'I' || status == 'C'){
				c.penaltyTime = penalty;
				c.id = id;			
			}
			if(status == 'C'){c.numproblems++;};
			c2.push_back(c);
			count++;
			cout << c.id << ' ' << c.penaltyTime << ' ' << c.numproblems << endl;	
		}
		
	}
	/*
	for(auto it : c2){
		cout << it.id << ' ' << it.numproblems << ' ' << it.penaltyTime << endl;
	}*/

return 0;
}
