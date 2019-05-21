#include <bits/stdc++.h>
#include "processo.h"
#include "fila.h"
using namespace std;

Fila::~Fila(){
	Processo* p;
	while(!this->fila.empty()){
		p = this->fila.front();
		delete p;
		this->fila.pop_front();
	}
}

Processo* Fila::getProcesso(){
	if(this->fila.empty()) return NULL;
	Processo* p = this->fila.front();
	this->fila.pop_front();
	return p;
}

void Fila::addProcesso(Processo* p){
	if(p != NULL) this->fila.push_back(p);
}

void Fila::print(){
	
	deque <Processo*>::iterator it;
	for(it = fila.begin(); it != fila.end() ; it++){
		cout << (*it)->getID() << " ";
	}
	cout << endl;

	return;
}

int Fila::getSize(){
	return this->fila.size();
}
