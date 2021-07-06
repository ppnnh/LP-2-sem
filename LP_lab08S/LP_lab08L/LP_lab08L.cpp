
#include "Dictionary.h"

using namespace std;


namespace Dictionary {

	Instance Create(char name[DICTNAMEMAXSIZE], int size) {
		if (strlen(name) > DICTNAMEMAXSIZE) throw (char*)THROW01;
		if (size > DICTMAXSIZE) throw(char*)THROW02;
		Instance newDict;
		strcpy_s(newDict.name, name);
		newDict.maxsize = size;
		newDict.size = 0;
		return newDict;
	}

	void AddEntry(Instance& inst, Entry ed) {
		if (inst.size == inst.maxsize) throw(char*)THROW03;
		for (int i = 0; i < inst.size; i++) {
			if (ed.id == inst.dictionary[i]->id) throw(char*)THROW04;
		}
		inst.dictionary[inst.size] = new Entry();
		inst.dictionary[inst.size]->id = ed.id;
		strcpy_s(inst.dictionary[inst.size]->name, ed.name);
		inst.size++;
	}

	void DelEntry(Instance& inst, int id) {
		for (int i = 0; i < inst.size; i++) {
			if (inst.dictionary[i]->id == id) {
				if (i == inst.size - 1) inst.dictionary[i] = NULL;
				else {
					for (int j = i; j < inst.size - 1; j++) {
						inst.dictionary[j] = inst.dictionary[j + 1];
					}
					inst.dictionary[inst.size - 1] = NULL;
				}
				inst.size--;
				return;
			}
			else if (id > inst.size) {
				throw(char*)THROW06;
			}
		}
	}

	void UpdEntry(Instance& inst, int id, Entry new_ed) {
		for (int i = 0; i < inst.size; i++) {
			if (inst.dictionary[i]->id == id) {
				if (inst.dictionary[i]->id == new_ed.id) throw(char*)THROW08;
				inst.dictionary[i]->id = new_ed.id;
				short clearName = 0;
				while (inst.dictionary[i]->name[clearName] != '\0') {
					inst.dictionary[i]->name[clearName] = NULL;
					clearName++;
				}
				inst.dictionary[i]->name[clearName] = NULL;
				for (int j = 0; j < strlen(new_ed.name); j++) {
					inst.dictionary[i]->name[j] = new_ed.name[j];
				}
				inst.dictionary[i]->name[strlen(new_ed.name)] = '\0';
			}
			else if (id > inst.size) {
				throw(char*)THROW07;
			}
		}
	}

	Entry GetEntry(Instance& inst, int id) {
		Entry getElement;
		for (int i = 0; i < inst.size; i++) {
			if (id == inst.dictionary[i]->id) {
				getElement.id = inst.dictionary[i]->id;
				for (int j = 0; j < strlen(inst.dictionary[i]->name); j++)
					getElement.name[j] = inst.dictionary[i]->name[j];
				return getElement;
			}
			else if (id > inst.size) {
				throw(char*)THROW05;
			}
		}
	}

	void Delete(Instance& d) {
		for (int i = 0; i < d.size; i++) {
			delete d.dictionary[i];
		}
		d.maxsize = NULL;
		d.size = NULL;
		*d.name = NULL;
	}


	void Print(Instance& d) {
		cout << "~~~~~~~~~~~~~~~~" << d.name << "~~~~~~~~~~~~~~~~~" << endl;
		for (int i = 0; i < d.size; i++) {
			cout << d.dictionary[i]->id << " " << d.dictionary[i]->name << endl;
		}
		cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;

	}
}
