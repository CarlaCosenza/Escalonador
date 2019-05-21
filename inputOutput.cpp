#include <bits/stdc++.h>
#include "processo.h"
#include "fila.h"
#include "inputOutput.h"
using namespace std;

InputOutput::InputOutput(){
	this->processando = NULL;
	this->tempoParaProcessar = 20;
	this->tempoProcessando = 0;
}

Processo* InputOutput::update(){

	//If there is a process already being executed
	if(processando == NULL){
		processando = Fila::getProcesso();
	}
	else{
		tempoProcessando++;
		if(tempoProcessando == tempoParaProcessar){
			tempoProcessando = 0;
			Processo* p = processando;
			p->reduceInputOutput();
			processando = Fila::getProcesso();
			return p;
		}
	}

	return NULL;
}

int InputOutput::getSize(){
	return Fila::getSize() + (processando != NULL);
}

void InputOutput::print(){
	if(processando == NULL) printf("Nao ha nada processando no IO\n");
	else cout << "Processando no IO: " << processando->getID() << endl;
	cout << "IO:" << endl;
	Fila::print();
}