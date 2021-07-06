#include "FST.h"
// ���������� ������������ ��������� RELATION

FST::RELATION::RELATION(char c, short ns)
{
	symbol = c;
	nnode = ns;
};

//���������� ������������ ��������� NODE

FST::NODE::NODE()//�� ���������
{
	n_relation = 0;
	RELATION* relations = NULL;
};

FST::NODE::NODE(short n, RELATION rel, ...)//� �����������
{
	n_relation = n;
	RELATION* p = &rel;
	relation = new RELATION[n];
	for (short i = 0; i < n; i++) relation[i] = p[i];
};

//���������� ������������ ��������� FST

FST::FST::FST(char* s, short ns, NODE n, ...)
{
	string = s;
	nstates = ns;
	nodes = new NODE[ns];
	NODE* p = &n;
		for (int k = 0; k < ns; k++) nodes[k] = p[k];
	rstates = new short[nstates];
	memset(rstates, 0xff, sizeof(short) * nstates);
	rstates[0] = 0;
	position = -1;
};


bool FST::step(FST& fst, short*& rstates)
{
	bool rc = false;
	std::swap(rstates, fst.rstates);//����� ��������
	for (short i = 0; i < fst.nstates; i++)
	{
		if (rstates[i] == fst.position)
			for (short j = 0; j < fst.nodes[i].n_relation; j++)
			{
				if (fst.nodes[i].relation[j].symbol == fst.string[fst.position])
				{
					fst.rstates[fst.nodes[i].relation[j].nnode] = fst.position + 1;
					rc = true;
				};
			}
	};
	return rc;
};

bool FST::execute(FST& fst)//��������� ������������ �������
{
	short* rstates = new short[fst.nstates]; memset(rstates, 0xff, sizeof(short) * fst.nstates);
	short lstring = strlen(fst.string);
	bool rc = true;
	for (short i = 0; i < lstring && rc; i++)
	{
		fst.position++;//���������� �������
		rc = step(fst, rstates);//�
	};
	delete[] rstates;
	return (rc ? (fst.rstates[fst.nstates - 1] == lstring) : rc);
};

void FST::FST_linecheck(char* someline) {
	FST myFST(// ���  ab(c)* ((d+e+f)b)^+ c* gb
		someline,// ������ ��� ������������� 
		7,// ���������� ���������
		NODE(1, RELATION('a', 1)),// S0
		NODE(1, RELATION('b', 2)),// S1
		NODE(4, RELATION('c', 2), RELATION('d', 3), RELATION('e', 3), RELATION('f', 3)), // S2
		NODE(2, RELATION('b', 4), RELATION('b', 2)),// S3
		NODE(2, RELATION('c',4),RELATION('g', 5) ),// S4
		NODE(1, RELATION('b', 6)),// S5
		NODE()// S6
	);

	if (execute(myFST)) {
		std::cout << "������� " << myFST.string << " ����������." << std::endl;
	}
	else {
		std::cout << "������� " << myFST.string << " �� ����������." << std::endl;
	}
}