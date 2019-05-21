#ifndef inputOutput
#define inputOutput
using namespace std;

class InputOutput: public Fila{

	private:
		Processo* processando;
		int tempoParaProcessar;
		int tempoProcessando;

	public:
		InputOutput();
		Processo* update();
		int getSize();
		void print();

};

#endif