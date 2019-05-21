#ifndef filas
#define filas
using namespace std;

class Fila{

	private:
		deque <Processo*> fila;

	public:
		~Fila();
		Processo* getProcesso();
		void addProcesso(Processo* p);
		void print();
		int getSize();

};

#endif