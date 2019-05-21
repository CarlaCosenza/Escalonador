#include <bits/stdc++.h>
#include "processo.h"
#include "fila.h"
#include "roundRobin.h"
using namespace std;

RoundRobin::RoundRobin(int quantum){
	this->quantum = quantum;
}

int RoundRobin::getQuantum(){
	return quantum;
}

void RoundRobin::print(){
	cout << "RoundRobin:" << endl;
	Fila::print();
}
