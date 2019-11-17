#include <iostream>
#include <string>
#include <vector>
#include <bits/stdc++.h>

using namespace std;


template<typename T>
void printVec(vector<T> v){
	for(auto it: v){
		cout << it.nombrePais << ' ' << it.puntos << "p," << '(' << it.ganados << '-' << it.empates << '-' << it.perdidos << ")," << ' ' << it.diferenciaGoles <<"gd" << ' ' << '(' << it.golesFavor << '-' << it.golesContra << ')' << endl;
	}
}

struct equipo{
	string nombrePais;
	int ranking;
	int juegos;
	int diferenciaGoles; 
	int puntos = 0; 
	int golesFavor = 0;
	int golesContra =0;
	int ganados = 0;
	int empates = 0;
	int perdidos = 0;
};

bool compareEquipo(equipo e1, equipo e2){
	return(e1.puntos < e2.puntos);
}

int main(){
	int N,T;
	cin >> N;
	string tournamentName;
	string team;
	string results;
	vector<equipo> equipos;
	unsigned G;
	string paisAux;
	string paisAux2;
	auto it2 = paisAux.begin();
	cin.ignore(1,'\n');
	while(N > 0){
		fflush(stdin);
		getline(cin,tournamentName);
		cout << tournamentName << endl;
		N--;
		cin >> T;
		while(T > 0){
			equipo e;
			fflush(stdin);
			cin >> team;
			e.nombrePais = team;
			equipos.push_back(e);
			cin.ignore(1,'\n');
			T--;
		}
		cin >> G;
		while(G > 0){
			fflush(stdin);
			cin >>results;
			paisAux = "";
			paisAux2 = "";
			char one = '#';
			char two = '@';
			auto it1 = results.begin();
			auto it2 = find(results.begin(),results.end(),one);
			auto it3 = next(it2,1);
			int gol1 = *it3 - '0';
			auto it4 = next(find(results.begin(),results.end(),two),1);
			int gol2 = *it4 - '0';
			auto it5 = next(find(it4,results.end(),one),1);
			auto it6 = results.end();		

			while (it1 != it2){
				paisAux += *it1;
				it1++;
			}
			while(it5 != it6){
				paisAux2 += *it5;
				it5++;
			}
			for(auto& it : equipos){
				if(it.nombrePais == paisAux){
					it.golesFavor += gol1;
					it.golesContra += gol2;
					if(gol1 > gol2)
						it.ganados++;
					if(gol1 < gol2)
						it.perdidos++;
					if(gol1 == gol2)
						it.empates++;
				}
				if(it.nombrePais == paisAux2){
					it.golesFavor += gol2;
					it.golesContra += gol1;
					if(gol2 > gol1)
						it.ganados++;
					if(gol2 < gol1)
						it.perdidos++;
					if(gol2 == gol1)
						it.empates++;
				}
			}
			G--;
			cin.ignore(1,'\n');
		}
	}
	for(auto& it : equipos){
		it.diferenciaGoles = it.golesFavor - it.golesContra;
		it.puntos += it.ganados*3 + it.empates*1;
	}
	sort(equipos.begin(),equipos.end(),compareEquipo);
	reverse(equipos.begin(),equipos.end());
	printVec(equipos);
	
return 0;
}
