#include "tree.h"
#include <cstdlib>
#include <iostream>
using namespace std;

struct PersonRec
{
	char name[20];	//contains person's name
	int bribe;
	PersonRec* lChild;
	PersonRec* rChild;
	
	PersonRec() {
		name[0] = '\0';
		bribe = 0;
		lChild = nullptr;
		rChild = nullptr;
	}

	PersonRec(char* nam, int br, PersonRec* left, PersonRec* right) {
		strcpy_s(name, 20, nam);
		bribe = br;
		lChild = left;
		rChild = right;
	}
};

CTree::CTree() {
	root = nullptr;
}

CTree::~CTree() {
	DeleteTree(root);
}

void CTree::Add() {
	char aName[20];
	int aBribe;
	cout << "\nEnter the person's name: ";
	cin >> aName; // assumes no embedded spaces in name
	cout << "\nEnter the person's contribution: ";
	cin >> aBribe;

	AddItem(root, aName, aBribe);
}

void CTree::AddItem(PersonRec* prPtr, char* nam, int br) {
	//check if tree is empty
	if (root == nullptr)
	{
		PersonRec* n = new PersonRec;
		n->bribe = br;
		strcpy_s(n->name, 20, nam);

		root = n;
	}
	//if bribe is less than
	else if (br < prPtr->bribe)
	{
		//check if theres a child
		if (prPtr->lChild != nullptr)
		{
			AddItem(prPtr->lChild, nam, br);
		}
		//if no child add new leaf
		else
		{
			PersonRec* n = new PersonRec;
			n->bribe = br;
			strcpy_s(n->name, 20, nam);

			prPtr->lChild = n;
		}
	}
	//if bribe greater than
	else if (br > prPtr->bribe)
	{
		if (prPtr->rChild != nullptr)
		{
			AddItem(prPtr->rChild, nam, br);
		}
		else
		{
			PersonRec* n = new PersonRec;
			n->bribe = br;
			strcpy_s(n->name, 20, nam);

			prPtr->rChild = n;
		}
	}
	//if bribe equal to
	else
	{
		cout << "The bribe offered, has already been added.\n";
	}
}

void CTree::View() {
	if (root == nullptr)
	{
		cout << "The tree is empty\n";
	}
	else
	{
		cout << "\nName Contribution" << endl;
		cout << "=====================================" << endl;

		DisplayTree(root);
	}
	
}

void CTree::DisplayTree(PersonRec* prPtr) {

	if (prPtr != nullptr) {
		DisplayTree(prPtr->rChild);
		cout << prPtr->name << " $" << prPtr->bribe << endl;
		DisplayTree(prPtr->lChild);
	}

}

void CTree::DeleteTree(PersonRec* prPtr) {
	if (prPtr != nullptr)
	{
			DeleteTree(prPtr->lChild);
			DeleteTree(prPtr->rChild);
			delete prPtr;
	}

}
