#ifndef CTREE_H
#define CTREE_H

struct PersonRec;

class CTree {
private:
	PersonRec* root;
	void AddItem(PersonRec* prPtr, char* nam, int br);
	void DisplayTree(PersonRec* prPtr);
	void DeleteTree(PersonRec* prPtr);
public:
	CTree();
	~CTree();
	void Add();
	void View();
};
#endif