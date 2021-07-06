#include <iostream>
#include <iomanip>
namespace FST
{
	struct RELATION  //ребро:символ -> вершина графа переходов  ј
	{
		char symbol; //символ перехода 
		short nnode; //новое состо€ние 
		RELATION(char c = 0x00, short ns = NULL);
	};
	struct NODE //вершина графа переходов 
	{
		short n_relation; //количество инцидентных ребер 
		RELATION *relation; //инцидентные ребра 
		NODE();
		NODE(short n, RELATION rel, ...); //количество инц. ребер, список ребер 
	};
	struct FST { //недетерминированный  ј 
		char* string; //цепочка(строка, завершатс€ 0х00)
		short position; //текуща€ позици€ в цепочке 
		short nstates; //кол-во состо€ний автомата 
		NODE* nodes; //граф переходов: [0]-нач. состо€ние, [nstate-1]-конечное 
		short* rstates; //возможные состо€ни€ автомата на данной позиции 
		FST(char* s, short ns, NODE n, ...); //цепочка(стр.,завершатс€ 0х00), кол-во состо€ний автомата, список состо€ний(граф переходов)
	};
	bool execute(FST& fst); //выполнить распознавание цепочки(недетерм. ј)
	bool step(FST& fst, short*& rstates);
	void FST_linecheck(char* string);
};