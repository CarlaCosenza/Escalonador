#ifndef processo
#define processo
using namespace std;

class Processo{
	
	private:
		string id;
		int numInputOutput;
		int surto;
		int tempoDeEspera;
		int tempoProcessando;
		int tempoQ0;

	public:
		Processo(std::string id, int numInputOutput, int surto);
		string getID();
		int getNumInputOutput();
		void reduceInputOutput();
		int getTempoProcessando();
		void increaseTempoProcessando();
		void zerarTempoProcessando();
		int getSurto();
		int getTempoDeEspera();
		void increaseTempoDeEspera();
		void zerarTempoDeEspera();
		int getTempoQ0();
		void increaseTempoQ0();
		void zerarTempoQ0();
		void print();
};

#endif