#include <bits/stdc++.h>
#include "processo.h"
#include "fila.h"
#include "FCFS.h"
using namespace std;

FCFS::FCFS(){
	this->timeLimit = 25;
}

FCFS::~FCFS(){
	Processo* p;
	while(!fila.empty()){
		p = fila.front();
		fila.pop_front();
		delete p;
	}

	return;
}

int FCFS::getSize(){
	return fila.size();
}

void FCFS::addProcesso(Processo* p){
	if(p != NULL) fila.push_back(p);
}

void FCFS::addFront(Processo* p){
	if(p != NULL) fila.push_front(p);
}

vector <Processo*> FCFS::updateTime(){
	deque <Processo*>::iterator it;
	vector <Processo*> processos;
	for(it = fila.begin() ; it != fila.end() ;){
		(*it)->increaseTempoDeEspera();
		if((*it)->getTempoDeEspera() == 25){
			(*it)->zerarTempoDeEspera();
			processos.push_back(*it);
			it = fila.erase(it);
		}
		else it++;
	}

	return processos;
}

Processo* FCFS::getProcesso(){
	Processo* p = fila.front();
	fila.pop_front();
	return p;
}

void FCFS::print(){
	
	deque <Processo*>::iterator it;
	cout << "FCFS:" << endl;
	for(it = fila.begin(); it != fila.end() ; it++){
		cout << (*it)->getID() << " ";
	}
	cout << endl;

	return;
}