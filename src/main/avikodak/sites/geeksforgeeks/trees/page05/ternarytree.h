/****************************************************************************************************************************************************
 *  File Name   		: ternarytree.h 
 *	File Location		: D:\algos\algos_v2\src\main\avikodak\sites\geeksforgeeks\trees\page05\ternarytree.h
 *  Created on			: Nov 11, 2014 :: 6:03:18 PM
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
#include <lib/constants/constants.h>
#include <lib/ds/commonds.h>
#include <lib/ds/linkedlistds.h>
#include <lib/ds/mathds.h>
#include <lib/ds/treeds.h>
#include <lib/utils/arrayutil.h>
#include <lib/utils/avltreeutil.h>
#include <lib/utils/bplustreeutil.h>
#include <lib/utils/btreeutil.h>
#include <lib/utils/commonutil.h>
#include <lib/utils/dillutil.h>
#include <lib/utils/mathutil.h>
#include <lib/utils/redblacktreeutil.h>
#include <lib/utils/sillutil.h>
#include <lib/utils/treeutil.h>
#include <lib/utils/twofourtreeutil.h>

/****************************************************************************************************************************************************/
/* 															USER DEFINED CONSTANTS 																    */
/****************************************************************************************************************************************************/

/****************************************************************************************************************************************************/
/* 																MAIN CODE START 																    */
/****************************************************************************************************************************************************/

#ifndef TERNARYTREE_H_
#define TERNARYTREE_H_

void insertTernaryTree(cTernaryNode **ptr,char *userInput){
	if(*ptr == null  && *userInput == '\0'){
		return;
	}
	if(*userInput == '\0'){
		(*ptr)->isEnd = true;
		return;
	}
	if(*ptr == null){
		(*ptr) = new cTernaryNode(*userInput);
		insertTernaryTree(ptr,userInput+1);
	}else{
		if((*ptr)->ch == *userInput){
			insertTernaryTree(&((*ptr)->equal),userInput+1);
		}else if((*ptr)->ch > *userInput){
			insertTernaryTree(&((*ptr)->left),userInput);
		}else{
			insertTernaryTree(&((*ptr)->right),userInput);
		}
	}
}

bool search(cTernaryNode *ptr,char *userInput){
	if(ptr == null){
		return false;
	}
	if(userInput == '\0'){
		return ptr->isEnd;
	}
	char currentChar = *userInput;
	if(ptr->ch == currentChar){
		return search(ptr->equal,userInput+1);
	}else if(ptr->ch > currentChar){
		return search(ptr->left,userInput);
	}else{
		return search(ptr->right,userInput);
	}
}

void traverse(cTernaryNode *ptr,char *buffer,unsigned int depth){
	if(ptr == null){
		return;
	}
	traverse(ptr->left,buffer,depth);
	buffer[depth] = ptr->ch;
	if(ptr->isEnd){
		printf("%s\n",buffer);
	}
	traverse(ptr->equal,buffer,depth+1);
	traverse(ptr->right,buffer,depth);
}

#endif /* TERNARYTREE_H_ */

/****************************************************************************************************************************************************/
/* 																MAIN CODE END 																	    */
/****************************************************************************************************************************************************/
