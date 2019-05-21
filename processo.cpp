#include <bits/stdc++.h>
#include "processo.h"
using namespace std;

Processo::Processo(std::string id, int numInputOutput, int surto){
	this->id = id;
	this->numInputOutput = numInputOutput;
	this->surto = surto;
	this->tempoDeEspera = 0;
	this->tempoQ0 = 0;
	this->tempoProcessando = 0;
}

string Processo::getID(){
	return this->id;
}

int Processo::getNumInputOutput(){
	return this->numInputOutput;
}

void Processo::reduceInputOutput(){
	this->numInputOutput--;
}

int Processo::getTempoProcessando(){
	return tempoProcessando;
}

void Processo::increaseTempoProcessando(){
	tempoProcessando++;
}

void Processo::zerarTempoProcessando(){
	tempoProcessando = 0;
}

int Processo::getSurto(){
	return this->surto;
}

int Processo::getTempoDeEspera(){
	return this->tempoDeEspera;
}

void Processo::increaseTempoDeEspera(){
	tempoDeEspera++;
}

void Processo::zerarTempoDeEspera(){
	tempoDeEspera = 0;
}

int Processo::getTempoQ0(){
	return tempoQ0;
}

void Processo::increaseTempoQ0(){
	tempoQ0++;
}

void Processo::zerarTempoQ0(){
	tempoQ0 = 0;
}

void Processo::print(){
	cout << "Nome do processo: " << this->getID() << endl;
	cout << "Quantidade de IO: " << this->getNumInputOutput() << endl;
	cout << "Tamanho do surto: " << this->getSurto() << endl;
}