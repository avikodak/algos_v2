/****************************************************************************************************************************************************
 *  File Name   		: treeds.h 
 *	File Location		: D:\algos\algos_v2\src\lib\ds\treeds.h
 *  Created on			: Oct 9, 2014 :: 12:29:29 PM
 *  Author				: AVINASH
 *  Testing Status 		: TODO
 *  URL 				: TODO
 ****************************************************************************************************************************************************/

/****************************************************************************************************************************************************/
/* 														NAMESPACE DECLARATION AND IMPORTS 														    */
/****************************************************************************************************************************************************/

using namespace std;
using namespace __gnu_cxx;

/****************************************************************************************************************************************************/
/* 																INCLUDES		 																    */
/****************************************************************************************************************************************************/

#include <string>
#include <vector>
#include <cstdlib>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <ctime>
#include <list>
#include <map>
#include <set>
#include <bitset>
#include <functional>
#include <numeric>
#include <utility>
#include <iostream>
#include <fstream>
#include <sstream>
#include <string.h>
#include <hash_map>
#include <stack>
#include <queue>
#include <limits.h>
#include <stdint.h>

/****************************************************************************************************************************************************/
/* 															USER DEFINED CONSTANTS 																    */
/****************************************************************************************************************************************************/
#define TRIE_ALPHABET_SIZE 26
#define TWO_FOUR_TREE_CHILDREN 4

/****************************************************************************************************************************************************/
/* 																MAIN CODE START 																    */
/****************************************************************************************************************************************************/

#ifndef TREEDS_H_
#define TREEDS_H_

struct itNode{
	int value;
	itNode *left;
	itNode *right;

	itNode(){
		this->left = null;
		this->right = null;
	}

	itNode(int value){
		this->left = null;
		this->right = null;
		this->value = value;
	}
};

struct ctNode{
	char ch;
	ctNode *left;
	ctNode *right;

	ctNode(){
		this->left = null;
		this->right = null;
	}

	ctNode(char ch){
		this->ch = ch;
		this->left = null;
		this->right = null;
	}
};

struct itAuxNode{
	int value;
	unsigned int auxValue;
	itAuxNode *left;
	itAuxNode *right;

	itAuxNode(){
		this->left = null;
		this->right = null;
	}

	itAuxNode(int value){
		this->value = value;
		this->auxValue = 0;
		this->left = null;
		this->right = null;
	}

	itAuxNode(int value,unsigned int auxValue){
		this->value = value;
		this->auxValue = auxValue;
		this->left = null;
		this->right = null;
	}
};

struct iptNode{
	int value;
	iptNode *left;
	iptNode *right;
	iptNode *parent;

	iptNode(){
		this->left = null;
		this->right = null;
		this->parent = null;
	}

	iptNode(int value){
		this->value = value;
		this->left = null;
		this->right = null;
		this->parent = null;
	}
};

struct iftNode{
	int value;
	unsigned int frequency;
	iftNode *left;
	iftNode *right;

	iftNode(){
		this->left = null;
		this->right = null;
	}

	iftNode(int value){
		this->value = value;
		this->frequency = 1;
		this->left = null;
		this->right = null;
	}

};

struct cftNode{
	char ch;
	unsigned int frequency;
	cftNode *left;
	cftNode *right;

	cftNode(){
		this->frequency = 0;
		this->left = null;
		this->right = null;
	}

	cftNode(char ch){
		this->ch = ch;
		this->frequency = 1;
		this->left = null;
		this->right = null;
	}

};

struct irtNode{
	int value;
	unsigned int rank;
	irtNode *left;
	irtNode *right;

	irtNode(){
		this->left = null;
		this->right = null;
	}

	irtNode(int value,int rank){
		this->value = value;
		this->rank = rank;
		this->left = null;
		this->right = null;
	}
};

struct isuccesssorNode{
	int value;
	isuccesssorNode *left;
	isuccesssorNode *right;
	isuccesssorNode *successor;

	isuccesssorNode(){
		this->left = null;
		this->right = null;
		this->successor = null;
	}

	isuccesssorNode(int value){
		this->value = value;
		this->left = null;
		this->right = null;
		this->successor = null;
	}
};

struct inrNode{
	int value;
	inrNode *left;
	inrNode *right;
	inrNode *nextRight;

	inrNode(){
		this->left = null;
		this->right = null;
		this->nextRight = null;
	}

	inrNode(int value){
		this->value = value;
		this->left = null;
		this->right = null;
		this->nextRight = null;
	}

};

struct iAvlNode{
	int value;
	unsigned int height;
	iAvlNode *left;
	iAvlNode *right;

	iAvlNode(){
		this->left = null;
		this->right = null;
	}

	iAvlNode(int value){
		this->value = value;
		this->height = 1;
		this->left = null;
		this->right = null;
	}
};

struct cAvlNode{
	char ch;
	unsigned int height;
	cAvlNode *left;
	cAvlNode *right;

	cAvlNode(){
		this->height = 0;
		this->left = null;
		this->right = null;
	}

	cAvlNode(char ch){
		this->ch = ch;
		this->height = 1;
		this->left = null;
		this->right = null;
	}

};

struct ifAvlNode{
	int value;
	unsigned int frequency;
	unsigned int height;
	ifAvlNode *left;
	ifAvlNode *right;

	ifAvlNode(){
		this->frequency = 0;
		this->left = null;
		this->right = null;
	}

	ifAvlNode(int value){
		this->value = value;
		this->height = 1;
		this->frequency = 1;
		this->left = null;
		this->right = null;
	}
};

struct cfAvlNode{
	char ch;
	unsigned int frequency;
	unsigned int height;
	cfAvlNode *left;
	cfAvlNode *right;

	cfAvlNode(){
		this->frequency = 0;
		this->height = 0;
		this->left = null;
		this->right = null;
	}

	cfAvlNode(char ch){
		this->ch = ch;
		this->frequency = 1;
		this->height = 1;
		this->left = null;
		this->right = null;
	}
};

struct ipAvlNode{
	int value;
	unsigned int height;
	ipAvlNode *left;
	ipAvlNode *right;
	ipAvlNode *parent;

	ipAvlNode(){
		this->left = null;
		this->right = null;
		this->parent = null;
	}

	ipAvlNode(int value){
		this->value = value;
		this->height = 1;
		this->left = null;
		this->right = null;
		this->parent = null;
	}
};

struct cpAvlNode{
	char ch;
	unsigned int height;
	cAvlNode *left;
	cAvlNode *right;
	cAvlNode *parent;

	cpAvlNode(){
		this->height = 0;
		this->left = null;
		this->right = null;
		this->parent = null;
	}

	cpAvlNode(char ch){
		this->ch = ch;
		this->height = 1;
		this->left = null;
		this->right = null;
		this->parent = null;
	}
};

struct ifpAvlNode{
	int value;
	unsigned int height;
	unsigned int frequency;
	ifpAvlNode *left;
	ifpAvlNode *right;
	ifpAvlNode *parent;

	ifpAvlNode(){
		this->left = null;
		this->right = null;
		this->parent = null;
	}

	ifpAvlNode(int value){
		this->value = value;
		this->height = 1;
		this->frequency = 1;
		this->left = null;
		this->right = null;
		this->parent = null;
	}
};

struct cfpAvlNode{
	char ch;
	unsigned int height;
	unsigned int frequency;
	cfpAvlNode *left;
	cfpAvlNode *right;
	cfpAvlNode *parent;

	cfpAvlNode(){
		this->height = 0;
		this->frequency = 0;
		this->left = null;
		this->right = null;
		this->parent = null;
	}

	cfpAvlNode(char ch){
		this->ch = ch;
		this->height = 1;
		this->frequency = 1;
		this->left = null;
		this->right = null;
		this->parent = null;
	}
};

struct ipAuxAvlNode{
	int value;
	int auxVal;
	unsigned int height;
	ipAuxAvlNode *left;
	ipAuxAvlNode *right;
	ipAuxAvlNode *parent;

	ipAuxAvlNode(){
		this->auxVal = 0;
		this->height = 0;
		this->left = null;
		this->right = null;
		this->parent = null;
	}

	ipAuxAvlNode(int value){
		this->value = value;
		this->auxVal = 0;
		this->left = null;
		this->right = null;
		this->parent = null;
	}

};

struct cTernaryNode{
	char ch;
	cTernaryNode *left;
	cTernaryNode *equal;
	cTernaryNode *right;
	bool isEnd;

	cTernaryNode(){
		this->ch = '\0';
		this->left = null;
		this->equal = null;
		this->right = null;
		this->isEnd = false;
	}

	cTernaryNode(char ch){
		this->ch = ch;
		this->left = null;
		this->equal = null;
		this->right = null;
		this->isEnd = false;
	}
};

struct cpTernaryNode{
	char ch;
	cpTernaryNode *left;
	cpTernaryNode *right;
	cpTernaryNode *equal;
	cpTernaryNode *parent;
	bool isEnd;

	cpTernaryNode(){
		this->ch = '\0';
		this->left = null;
		this->equal = null;
		this->right = null;
		this->parent = null;
		this->isEnd = false;
	}

	cpTernaryNode(char ch){
		this->ch = ch;
		this->left = null;
		this->equal = null;
		this->right = null;
		this->parent = null;
		this->isEnd = false;
	}
};

struct cTrieNode{
	cTrieNode *children[TRIE_ALPHABET_SIZE];
	bool isLeafNode;

	cTrieNode(){
		for(unsigned int counter = 0;counter < TRIE_ALPHABET_SIZE;counter++){
			this->children[counter] = null;
			this->isLeafNode = false;
		}
	}
};

struct cpTrieNode{
	cpTrieNode *children[TRIE_ALPHABET_SIZE];
	cpTrieNode *parent;
	bool isLeafNode;

	cpTrieNode(){
		for(unsigned int counter = 0;counter < TRIE_ALPHABET_SIZE;counter++){
			this->children[counter] = null;
			this->isLeafNode = false;
		}
		this->parent = null;
	}

	cpTrieNode(cpTrieNode *parent){
		for(unsigned int counter = 0;counter < TRIE_ALPHABET_SIZE;counter++){
			this->children[counter] = null;
			this->isLeafNode = false;
		}
		this->parent = parent;
	}
};

struct bpTrieNode{
	bpTrieNode *children[2];
	bpTrieNode *parent;
	bool isEOW; // end of word

	bpTrieNode(){
		this->children[0] = null;
		this->children[1] = null;
		this->parent = null;
		this->isEOW = false;
	}

	bpTrieNode(bpTrieNode *parent){
		this->isEOW = false;
		this->children[0] = null;
		this->children[1] = null;
		this->parent = null;
	}

};

struct i24Node{
	int value[3];
	unsigned int noOfKeys;
	unsigned int noOfChildren;
	i24Node *parent;
	i24Node *children[TWO_FOUR_TREE_CHILDREN];

	i24Node(){
		for(unsigned int counter = 0;counter < TWO_FOUR_TREE_CHILDREN;counter++){
			this->children[counter] = null;
		}
		this->parent = null;
		this->noOfKeys = 0;
		this->noOfChildren = 0;
	}

	i24Node(int value){
		this->value[0] = value;
		this->noOfKeys = 1;
		this->noOfChildren = 0;
		this->parent = null;
		for(unsigned int counter = 0;counter < TWO_FOUR_TREE_CHILDREN;counter++){
			this->children[counter] = null;
		}
	}
};

struct i24fNode{
	int value[3];
	i24Node *parent;
	unsigned int noOfKeys;
	unsigned int noOfChildren;
	unsigned int frequency[3];
	i24Node *children[TWO_FOUR_TREE_CHILDREN];

	i24fNode(){
		for(unsigned int counter = 0;counter < TWO_FOUR_TREE_CHILDREN;counter++){
			this->children[counter] = null;
		}
		this->parent = null;
		this->noOfKeys = 0;
		this->noOfChildren = 0;
	}

	i24fNode(int value){
		this->value[0] = value;
		this->frequency[0] = 1;
		this->noOfKeys = 1;
		this->parent = null;
		for(unsigned int counter = 0;counter < TWO_FOUR_TREE_CHILDREN;counter++){
			this->children[counter] = null;
		}
	}
};

struct i24TreeSearchResult{
	int index;
	i24Node *node;

	i24TreeSearchResult(){
		this->node = null;
	}

	i24TreeSearchResult(int index,i24Node *node){
		this->index = index;
		this->node = node;
	}
};

struct iRbTreeNode{
	int value;
	bool isRedNode;
	iRbTreeNode *left;
	iRbTreeNode *right;
	iRbTreeNode *parent;

	iRbTreeNode(){
		this->isRedNode = true;
		this->left = null;
		this->right = null;
		this->parent = null;
	}

	iRbTreeNode(int value){
		this->value = value;
		this->isRedNode = true;
		this->left = null;
		this->right = null;
		this->parent = null;
	}
};

struct cpRbTNode{
	char ch;
	bool isRedNode;
	cpRbTNode *left;
	cpRbTNode *right;
	cpRbTNode *parent;

	cpRbTNode(){
		this->isRedNode = true;
		this->left = null;
		this->right = null;
		this->parent = null;
	}

	cpRbTNode(char ch){
		this->ch = ch;
		this->isRedNode = true;
		this->left = null;
		this->right = null;
		this->parent = null;
	}
};

struct ifRbTreeNode{
	int value;
	bool isRedNode;
	unsigned int frequency;
	ifRbTreeNode *left;
	ifRbTreeNode *right;
	ifRbTreeNode *parent;

	ifRbTreeNode(){
		this->frequency = 0;
		this->left = null;
		this->right = null;
		this->parent = null;
	}

	ifRbTreeNode(int value){
		this->frequency = 1;
		this->value = value;
		this->isRedNode = true;
		this->left = null;
		this->right = null;
		this->parent = null;
	}
};

struct cfpRbTNode{
	char ch;
	bool isRedNode;
	unsigned int frequency;
	cfpRbTNode *left;
	cfpRbTNode *right;
	cfpRbTNode *parent;

	cfpRbTNode(){
		this->frequency = 0;
		this->left = null;
		this->right = null;
		this->parent = null;
	}

	cfpRbTNode(char ch){
		this->frequency = 1;
		this->ch = ch;
		this->isRedNode = true;
		this->left = null;
		this->right = null;
		this->parent = null;
	}
};

struct ipAuxRbTreeNode{
	int value;
	bool isRedNode;
	int auxVal;
	ipAuxRbTreeNode *left;
	ipAuxRbTreeNode *right;
	ipAuxRbTreeNode *parent;

	ipAuxRbTreeNode(){
		this->auxVal = 0;
		this->left = null;
		this->right = null;
		this->parent = null;
	}

	ipAuxRbTreeNode(int value){
		this->auxVal = 1;
		this->value = value;
		this->isRedNode = true;
		this->left = null;
		this->right = null;
		this->parent = null;
	}
};

struct itHashmap{
	hash_map<unsigned int,itNode *> indexNodeMap;
	hash_map<intptr_t,unsigned int> nodeIndexMap;
};

#endif /* TREEDS_H_ */

/****************************************************************************************************************************************************/
/* 																MAIN CODE END 																	    */
/****************************************************************************************************************************************************/
