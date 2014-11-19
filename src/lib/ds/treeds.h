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

/****************************************************************************************************************************************************/
/* 															USER DEFINED CONSTANTS 																    */
/****************************************************************************************************************************************************/
#define TRIE_ALPHABET_SIZE 26
#define TWO_FOUR_TREE_CHILDREN 4
#define null NULL

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

struct itHashmap{
	hash_map<unsigned int,itNode *> indexNodeMap;
	hash_map<uint32_t,unsigned int> nodeIndexMap;
};

#endif /* TREEDS_H_ */

/****************************************************************************************************************************************************/
/* 																MAIN CODE END 																	    */
/****************************************************************************************************************************************************/
