#ifndef escalonador
#define escalonador
using namespace std;

class Escalonador{

	private:
		Processo* processando;
		int tempo;
		int tempoDeProcessamento;
		string origem;
		RoundRobin q0;
		FCFS q1;
		InputOutput io;
		vector <string> gantt;
		bool processedThisCycle;

		void updateGantt();
		void updateProcessando();
		void pickProcessando();

	public:
		Escalonador();
		void update();
		void printGantt();
		void run();
		void addProcesso(Processo* p);

};

#endif