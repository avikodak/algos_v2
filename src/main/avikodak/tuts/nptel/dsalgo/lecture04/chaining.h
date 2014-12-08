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
#include <algorithm/constants/constants.h>
#include <algorithm/ds/commonds.h>
#include <algorithm/ds/linkedlistds.h>
#include <algorithm/ds/mathds.h>
#include <algorithm/ds/treeds.h>
#include <algorithm/utils/arrayutil.h>
#include <algorithm/utils/avltreeutil.h>
#include <algorithm/utils/bplustreeutil.h>
#include <algorithm/utils/btreeutil.h>
#include <algorithm/utils/commonutil.h>
#include <algorithm/utils/dillutil.h>
#include <algorithm/utils/mathutil.h>
#include <algorithm/utils/redblacktreeutil.h>
#include <algorithm/utils/sillutil.h>
#include <algorithm/utils/treeutil.h>
#include <algorithm/utils/trieutil.h>
#include <algorithm/utils/twofourtreeutil.h>

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
