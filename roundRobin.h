#ifndef roundRobin
#define roundRobin
using namespace std;

class RoundRobin: public Fila{

	private:
		int quantum;

	public:
		RoundRobin(int quantum);
		int getQuantum();
		void print();

};

#endif