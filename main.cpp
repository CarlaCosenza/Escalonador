#include <bits/stdc++.h>
#include "processo.h"
#include "fila.h"
#include "roundRobin.h"
#include "FCFS.h"
#include "inputOutput.h"
#include "escalonador.h"
using namespace std;

string makeID(int i){
	string s = "";
	while(i != 0){
		int resto = i%10;
		i = i/10;
		char c = '0' + resto;
		s += c;
	}
	s += 'P';
	reverse(s.begin(), s.end());
	return s;
}

int main(){

	Escalonador es = Escalonador();

	int n;
	printf("Digite quantos processos teremos:\n");
	scanf("%d" , &n);
	for(int i = 0 ; i < n ; i++){
		int s, o;
		printf("Digite o tamanho do surto e a quantidade de IO para o processo %d\n", i+1);
		scanf("%d %d" , &s, &o);
		Processo* p = new Processo(makeID(i+1), o, s);
		es.addProcesso(p);
	}

	es.run();

	return 0;

}