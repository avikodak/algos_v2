/****************************************************************************************************************************************************
 *  File Name   		: linkedlistds.h 
 *	File Location		: D:\algos\algos_v2\src\lib\ds\linkedlistds.h
 *  Created on			: Oct 9, 2014 :: 12:36:07 PM
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

#define null NULL

/****************************************************************************************************************************************************/
/* 																MAIN CODE START 																    */
/****************************************************************************************************************************************************/

#ifndef LINKEDLISTDS_H_
#define LINKEDLISTDS_H_

struct sillNode{
	int value;
	sillNode *next;

	sillNode(){
		this->next = null;
	}

	sillNode(int value){
		this->value = value;
		this->next = null;
	}

};

struct xorSillNode{
	int value;
	uint32_t addressesXor;

	xorSillNode(){
		this->addressesXor = 0;
	}

	xorSillNode(int value){
		this->value = value;
		this->addressesXor = 0;
	}
};

struct sillArbitNode{
	int value;
	sillArbitNode *arbitraryPtr;
	sillArbitNode *next;

	sillArbitNode(){
		this->arbitraryPtr = null;
		this->next = null;
	}

	sillArbitNode(int value){
		this->value = value;
		this->next = null;
		this->arbitraryPtr = null;
	}
};

struct svillNode{
	int value;
	bool isVisited;
	svillNode *next;

	svillNode(){
		this->next = null;
	}

	svillNode(int value,unsigned int frequency){
		this->value = value;
		this->isVisited = false;
		this->next = null;
	}
};

struct dillNode{
	int value;
	dillNode *next;
	dillNode *prev;

	dillNode(){
		this->next = null;
		this->prev = null;
	}

	dillNode(int value){
		this->value = value;
		this->next = null;
		this->prev = null;
	}
};

struct iSillHashmap{
	hash_map<unsigned int,sillNode *> indexNodeMap;
	hash_map<uint32_t,unsigned int> nodeIndexMap;
};

struct iDillHashmap{
	hash_map<unsigned int,dillNode *> indexNodeMap;
	hash_map<uint32_t,unsigned int> nodeIndexMap;
};

#endif /* LINKEDLISTDS_H_ */

/****************************************************************************************************************************************************/
/* 																MAIN CODE END 																	    */
/****************************************************************************************************************************************************/
