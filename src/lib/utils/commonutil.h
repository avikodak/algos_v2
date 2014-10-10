/****************************************************************************************************************************************************
 *  File Name   		: commonutil.h 
 *	File Location		: D:\algos\algos_v2\src\lib\utils\commonutil.h
 *  Created on			: Oct 9, 2014 :: 12:38:51 PM
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

/****************************************************************************************************************************************************/
/* 															USER DEFINED CONSTANTS 																    */
/****************************************************************************************************************************************************/


/****************************************************************************************************************************************************/
/* 																MAIN CODE START 																    */
/****************************************************************************************************************************************************/

#ifndef COMMONUTIL_H_
#define COMMONUTIL_H_

//Tested
void printIVector(vector<int> userInput,bool withHeadersAndFooters = true){
	if(withHeadersAndFooters){
		printf("\n====================================================================================================================================\n");
		printf("PRINTING VECTOR START\n");
		printf("====================================================================================================================================\n");
	}
	for(unsigned int counter = 0;counter < userInput.size();counter++){
		printf("%d\t",userInput[counter]);
	}
	if(withHeadersAndFooters){
		printf("\n====================================================================================================================================\n");
		printf("PRINTING VECTOR END\n");
		printf("====================================================================================================================================\n");
	}
}

//Tested
void printTIndexNodeMap(hash_map<unsigned int,itNode *> nodeIndexMap){
	hash_map<unsigned int,itNode *>::iterator itToNodeIndexMap;
	for(itToNodeIndexMap = nodeIndexMap.begin();itToNodeIndexMap != nodeIndexMap.end();itToNodeIndexMap++){
		printf("%d %d\n",itToNodeIndexMap->first,itToNodeIndexMap->second->value);
	}
}

//Tested
void printTNodeIndexMap(hash_map<uint32_t,unsigned int> indexNodeMap){
	hash_map<uint32_t,unsigned int>::iterator itToIndexNodeMap;
	for(itToIndexNodeMap = indexNodeMap.begin();itToIndexNodeMap != indexNodeMap.end();itToIndexNodeMap++){
		printf("%d %d\n",((itNode *)itToIndexNodeMap->first)->value,itToIndexNodeMap->second);
	}
}


#endif /* COMMONUTIL_H_ */

/****************************************************************************************************************************************************/
/* 																MAIN CODE END 																	    */
/****************************************************************************************************************************************************/
