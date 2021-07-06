#include <iostream>
#include "FST.h"

namespace FST
{
	RELATION::RELATION(char c, short nn)				//ребро :символ->вершина графа переходов КА
	{
		symbol = c;										// символ перехода
		nnode = nn;										// номер смежной вершины
	}

	NODE::NODE()										// вершина графа переходов
	{
		n_relation = 0;									// количество инциндентных ребер
		relations = NULL;								// инцидентные ребра
	}

	NODE::NODE(short n, RELATION rel, ...)
	{
		n_relation = n;
		RELATION* ptr = &rel;							// список ребер
		relations = new RELATION[n_relation];
		for (int i = 0; i < n_relation; i++)
			relations[i] = ptr[i];
	}

	FST::FST(char* s, short ns, NODE n, ...)
	{
		string = s;										//цепочка (строка, завершатся 0x00 ) 
		position = 0;									//текущая позиция в цепочке
		nstates = ns;									//количество состояний автомата
		rstates = new short[nstates];					//возможные состояния автомата на данной позиции.
		for (int i = 0; i < nstates; i++)
			rstates[i] = 0;
		NODE* ptr = &n;									//граф переходов: [0] -начальное состояние, [nstate-1]-конечное
		nodes = new NODE[nstates];
		for (int i = 0; i < nstates; i++)
			nodes[i] = ptr[i];
	}

	bool step(FST& fst, short*& rstates)
	{
		bool rc = false;
		std::swap(rstates, fst.rstates);				//замена текущего состояния на новое
		for (short i = 0; i < fst.nstates; i++)
			if (rstates[i] == fst.position)
				for (short j = 0; j < fst.nodes[i].n_relation; j++)
					if (fst.nodes[i].relations[j].symbol == fst.string[fst.position])
					{
						fst.rstates[fst.nodes[i].relations[j].nnode] = fst.position + 1;
						rc = true;
					}
		return rc;
	}

	bool execute(FST& fst)								// выполнить распознавание цепочки, недетерминировнный конечный автомат
	{
		short length = strlen(fst.string);
		short* rstates = new short[fst.nstates];
		for (int i = 0; i < fst.nstates; i++)
			rstates[i] = -1;
		bool rc = true;
		while (fst.position < length && rc)
		{
			rc = step(fst, rstates);					//шаг автомата вперёд
			fst.position++;								//продвигаем позицию
			if (!rc)
				fst.posp = fst.position;
		}
		delete[] rstates;
		fst.position = 0;
		return (rc ? (fst.rstates[fst.nstates - 1] == length) : rc);
	}
}