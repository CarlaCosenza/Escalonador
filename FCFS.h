#ifndef fcfs
#define fcfs
using namespace std;

class FCFS{

	private:
		deque <Processo*> fila;
		int timeLimit;

	public:
		FCFS();
		~FCFS();
		int getSize();
		void addProcesso(Processo* p);
		void addFront(Processo* p);
		vector <Processo*> updateTime();
		Processo* getProcesso();
		void print();

};

#endif