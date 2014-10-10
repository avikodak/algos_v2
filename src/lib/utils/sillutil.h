/****************************************************************************************************************************************************
 *  File Name   		: sillutil.h 
 *	File Location		: D:\algos\algos_v2\src\lib\utils\sillutil.h
 *  Created on			: Oct 9, 2014 :: 12:36:41 PM
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
#include <algorithm/utils/commonutil.h>


/****************************************************************************************************************************************************/
/* 															USER DEFINED CONSTANTS 																    */
/****************************************************************************************************************************************************/

#define null NULL

/****************************************************************************************************************************************************/
/* 																MAIN CODE START 																    */
/****************************************************************************************************************************************************/

#ifndef SILLUTIL_H_
#define SILLUTIL_H_

class sillutils {
private:

public:
	//Tested
	sillNode *getSillFromVector(vector<int> userInput,unsigned int currentIndex = 0){
		if(currentIndex >= userInput.size()){
			return null;
		}
		sillNode *node = new sillNode(userInput[currentIndex]);
		node->next = getSillFromVector(userInput,currentIndex+1);
		return node;
	}

	//Tested
	sillNode *getRandomSill(unsigned int numberOfNodes,int minValue = INT_MIN,int maxValue = INT_MAX){
		vector<int> randomVector = generateIRandomVector(numberOfNodes,minValue,maxValue);
		printIVector(randomVector);
		return getSillFromVector(randomVector);
	}

	//Tested
	unsigned int lengthOfSill(sillNode *ptr){
		return ptr == null?0:1+lengthOfSill(ptr->next);
	}

	//Tested
	iSillHashmap *getSillAsHashmap(sillNode *ptr,unsigned int startIndex = 0){
		if(ptr == null){
			return null;
		}
		hash_map<unsigned int,sillNode *> indexNodeMap;
		hash_map<uint32_t,unsigned int> nodeIndexMap;
		while(ptr != null){
			indexNodeMap.insert(pair<unsigned int,sillNode *>(startIndex,ptr));
			nodeIndexMap.insert(pair<uint32_t,unsigned int>((uint32_t)ptr,startIndex));
			startIndex += 1;
			ptr = ptr->next;
		}
		iSillHashmap *hashMapOfSill = new iSillHashmap();
		hashMapOfSill->indexNodeMap = indexNodeMap;
		hashMapOfSill->nodeIndexMap = nodeIndexMap;
		return hashMapOfSill;
	}

	//Tested
	void printSill(sillNode *ptr){
		while(ptr != null){
			printf("%d\t",ptr->value);
			ptr = ptr->next;
		}
	}
};

#endif /* SILLUTIL_H_ */

/****************************************************************************************************************************************************/
/* 																MAIN CODE END 																	    */
/****************************************************************************************************************************************************/
