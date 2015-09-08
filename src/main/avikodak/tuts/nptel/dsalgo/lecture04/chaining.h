/****************************************************************************************************************************************************
 *  File Name   		: chaining.h 
 *	File Location		: D:\algos\algos_v2\src\main\avikodak\tuts\nptel\dsalgo\lecture04\chaining.h
 *  Created on			: Oct 22, 2014 :: 12:51:59 PM
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
#include <lib/utils/trieutil.h>
#include <lib/utils/twofourtreeutil.h>

/****************************************************************************************************************************************************/
/* 															USER DEFINED CONSTANTS 																    */
/****************************************************************************************************************************************************/
#define SIZE_OF_HASHMAP 10
/****************************************************************************************************************************************************/
/* 																MAIN CODE START 																    */
/****************************************************************************************************************************************************/

#ifndef CHAINING_H_
#define CHAINING_H_

//Tested
class iHashmap{
private:
	sillNode *headPtr[SIZE_OF_HASHMAP];

	//Tested
	int getHashValue(int userInput){
		return userInput % SIZE_OF_HASHMAP;
	}
public:
	//Tested
	void insert(int userInput){
		int hashVal = getHashValue(userInput);
		sillNode *crawler = headPtr[hashVal];
		if(crawler == null){
			headPtr[hashVal] = new sillNode(userInput);
			return;
		}else{
			while(crawler->next != null){
				if(crawler->value == userInput){
					return;
				}
				crawler = crawler->next;
			}
			if(crawler->value != userInput){
				crawler->next = new sillNode(userInput);
			}
		}
	}

	//Tested
	bool search(int userInput){
		int hashVal = getHashValue(userInput);
		sillNode *crawler = headPtr[hashVal];
		while(crawler != null){
			if(crawler->value == userInput){
				return true;
			}
			crawler = crawler->next;
		}
		return false;
	}

	//Tested
	void remove(int userInput){
		int hashVal = getHashValue(userInput);
		sillNode *crawler = headPtr[hashVal],*nodeToBeDeleted = null;
		if(crawler == null){
			throw "Value not found";
		}
		if(crawler->value == userInput){
			nodeToBeDeleted = crawler;
			crawler->next = crawler->next->next;
			free(nodeToBeDeleted);
		}else{
			while(crawler->next != null){
				if(crawler->next->value == userInput){
					nodeToBeDeleted = crawler->next;
					crawler->next = crawler->next->next;
					break;
				}
				crawler = crawler->next;
			}
		}
	}
};

#endif /* CHAINING_H_ */

/****************************************************************************************************************************************************/
/* 																MAIN CODE END 																	    */
/****************************************************************************************************************************************************/
