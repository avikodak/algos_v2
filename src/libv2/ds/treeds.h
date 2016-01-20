/****************************************************************************************************************************************************
 *  File Name                   : treeds.h
 *  File Location               : /algos_v2/src/libv2/ds/treeds.h
 *  Created on                  : Jan 18, 2016 :: 8:28:56 PM
 *  Author                      : avikodak
 *  Testing Status              : TODO
 *  URL                         : TODO
 ****************************************************************************************************************************************************/

/****************************************************************************************************************************************************/
/*                                                         NAMESPACE DECLARATION AND IMPORTS                                                        */
/****************************************************************************************************************************************************/

using namespace std;
using namespace __gnu_cxx;

/****************************************************************************************************************************************************/
/*                                                                 INCLUDES                                                                         */
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
/*                                                            USER DEFINED CONSTANTS                                                                */
/****************************************************************************************************************************************************/

/****************************************************************************************************************************************************/
/*                                                             MAIN CODE START                                                                      */
/****************************************************************************************************************************************************/

#ifndef LIBV2_DS_TREEDS_H_
#define LIBV2_DS_TREEDS_H_

struct itNode{
	int value;
	itNode *left;
	itNode *right;

	itNode(){
		this->value = 0;
		this->left = null;
		this->right = null;
	}

	itNode(int value){
		this->value = value;
		this->left = null;
		this->right = null;
	}
};

struct itnrNode{
	int value;
	itnrNode *left;
	itnrNode *right;
	itnrNode *nextRight;

	itnrNode(){
		this->value = 0;
		this->left = null;
		this->right = null;
		this->nextRight = null;
	}

	itnrNode(int value){
		this->value = value;
		this->left = null;
		this->right = null;
		this->nextRight = null;
	}
};

struct itHashMap{
	hash_map<unsigned int,itNode *> indexNodeMap;
	hash_map<intptr_t,unsigned int> nodeIndexMap;

	itHashMap(hash_map<unsigned int,itNode *> indexNodeMap,hash_map<intptr_t,unsigned int> nodeIndexMap){
		this->indexNodeMap = indexNodeMap;
		this->nodeIndexMap = nodeIndexMap;
	}
};

struct itMap{
	map<unsigned int,itNode *> indexNodeMap;
	map<intptr_t,unsigned int> nodeIndexMap;

	itMap(map<unsigned int,itNode *> indexNodeMap,map<intptr_t,unsigned int> nodeIndexMap){
		this->indexNodeMap = indexNodeMap;
		this->nodeIndexMap = nodeIndexMap;
	}
};

#endif /* LIBV2_DS_TREEDS_H_ */
