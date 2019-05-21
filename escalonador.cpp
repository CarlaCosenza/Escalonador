#include <bits/stdc++.h>
#include <unistd.h>
#include "processo.h"
#include "fila.h"
#include "FCFS.h"
#include "roundRobin.h"
#include "inputOutput.h"
#include "escalonador.h"
using namespace std;

Escalonador::Escalonador(): q0(10){
	processando = NULL;
	tempo = 0;
	tempoDeProcessamento = 0;
	origem = "none";
	processedThisCycle = false;
}

void Escalonador::updateGantt(){
	if(processando != NULL){
		gantt.push_back(processando->getID());
	}
	else gantt.push_back("none");
}

void Escalonador::updateProcessando(){
	if(processando == NULL) return;
	if(processedThisCycle) return;
	processedThisCycle = true;
	processando->increaseTempoProcessando();
	if(origem == "q0") processando->increaseTempoQ0();
	updateGantt();
	if(processando->getTempoProcessando() == processando->getSurto()){
		processando->zerarTempoProcessando();
		processando->zerarTempoQ0();
		if(processando->getNumInputOutput() > 0){
			io.addProcesso(processando);
		}
		else{
			delete processando;
		}
		processando = NULL;
		origem = "none";
		return;
	}
	if(origem == "q0"){
		if(processando->getTempoQ0() == q0.getQuantum()){
			processando->zerarTempoQ0();
			q1.addProcesso(processando);
			processando = NULL;
			origem = "none";
			return;
		}
	}
	return;
}

void Escalonador::pickProcessando(){
	if(processando != NULL) return;
	if(q0.getSize() > 0){
		processando = q0.getProcesso();
		origem = "q0";
		return;
	}
	if(q1.getSize() > 0){
	 	processando = q1.getProcesso();
		origem = "q1";
		return;
	}
}

void Escalonador::update(){

	processedThisCycle = false;
	tempo++;

	// printf("TEMPO %d\n", tempo);
	// q0.print();
	// q1.print();
	// io.print();
	// printf("Estamos processando: ");
	// if(processando != NULL) cout << processando->getID() << endl;
	// else cout << "none" << endl;

	//Verificar o tempo na fila q1
	vector <Processo*> v = q1.updateTime();

	//Coloca em q0 esses processos
	for(int i = 0 ; i < v.size() ; i++){
		q0.addProcesso(v[i]);
	}

	//Executa IO
	Processo* inout = io.update();

	//Se terminou, coloca em q0
	if(inout != NULL) q0.addProcesso(inout);

	//Verificar se o processando é de q1 e se há processo em q0
	if(origem == "q1" and q0.getSize() > 0){
		origem = "none";
		q1.addFront(processando);
		processando = NULL;
	}

	//Coloca novo processo caso necessário
	pickProcessando();

	//Processa
	updateProcessando();

	//Coloca novo processo caso necessário
	pickProcessando();

	//Ve se ja processou, se não, da update
	if(!processedThisCycle) updateGantt();

	return;

}

void Escalonador::printGantt(){
	string current = gantt[0];
	int beginning = 0;
	for(int i = 0 ; i < gantt.size() ; i++){
		while(i < gantt.size() and gantt[i] == current){
			i++;
		}
		cout << beginning << " " << current << " " << i << endl;
		current = gantt[i];
		beginning = i;
	}

	return;
}

void Escalonador::run(){
	while(processando != NULL or q0.getSize() > 0 or q1.getSize() > 0 or io.getSize() > 0){
		update();
	}
	printGantt();
}

void Escalonador::addProcesso(Processo* p){
	q0.addProcesso(p);
}