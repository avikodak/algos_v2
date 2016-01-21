/****************************************************************************************************************************************************
 *  File Name                   : findoddoccuring.h
 *  File Location               : /algos_v2/src/main/avikodak/sites/geeksforgeeks/arrays/page04/findoddoccuring.h
 *  Created on                  : Jan 21, 2016 :: 11:00:44 PM
 *  Author                      : avikodak
 *  Testing Status              : TODO
 *  URL                         : http://www.geeksforgeeks.org/find-the-number-occurring-odd-number-of-times/
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
#include <libv2/common/commonincludes.h>
#include <libv2/constants/constants.h>
#include <libv2/ds/commonds.h>
#include <libv2/ds/graphds.h>
#include <libv2/ds/linkedlistds.h>
#include <libv2/ds/mathds.h>
#include <libv2/ds/treeds.h>
#include <libv2/utils/abtreeutil.h>
#include <libv2/utils/arrayutil.h>
#include <libv2/utils/avltreeutil.h>
#include <libv2/utils/bplustreeutil.h>
#include <libv2/utils/bstutil.h>
#include <libv2/utils/btreeutil.h>
#include <libv2/utils/commonutil.h>
#include <libv2/utils/dillutil.h>
#include <libv2/utils/graphutil.h>
#include <libv2/utils/ioutil.h>
#include <libv2/utils/mathutil.h>
#include <libv2/utils/redblacktreeutil.h>
#include <libv2/utils/sillutil.h>
#include <libv2/utils/treeutil.h>
#include <libv2/utils/trieutil.h>
#include <libv2/utils/twofourtreeutil.h>

/****************************************************************************************************************************************************/
/*                                                            USER DEFINED CONSTANTS                                                                */
/****************************************************************************************************************************************************/

/****************************************************************************************************************************************************/
/*                                                             MAIN CODE START                                                                      */
/****************************************************************************************************************************************************/

#ifndef MAIN_AVIKODAK_SITES_GEEKSFORGEEKS_ARRAYS_PAGE04_FINDODDOCCURING_H_
#define MAIN_AVIKODAK_SITES_GEEKSFORGEEKS_ARRAYS_PAGE04_FINDODDOCCURING_H_

/****************************************************************************************************************************************************/
/*                                                            O(N) Algorithm                                                                        */
/****************************************************************************************************************************************************/
int findOddOccuringVal(int userInput[],int size){
	int xorValue = 0;
	for(unsigned int counter = 0;counter < size;counter++){
		xorValue ^= userInput[counter];
	}
	return xorValue;
}

int findOddOccuringValHashMap(int userInput[],int size){
	if(size == 0){
		return INT_MIN;
	}
	hash_map<int,unsigned int> frequencyMap;
	hash_map<int,unsigned int>::iterator itToFrequencyMap;
	for(unsigned int counter = 0;counter < size;counter++){
		if(frequencyMap.find(userInput[counter]) == frequencyMap.end()){
			frequencyMap[userInput[counter]] = 1;
		}else{
			frequencyMap[userInput[counter]]++;
		}
	}
	for(itToFrequencyMap = frequencyMap.begin();itToFrequencyMap != frequencyMap.end();itToFrequencyMap++){
		if(itToFrequencyMap->second&1){
			return itToFrequencyMap->first;
		}
	}
	return INT_MIN;
}

/****************************************************************************************************************************************************/
/*                                                          O(N*LOGN) Algorithm                                                                     */
/****************************************************************************************************************************************************/
int findOddOccuringValONLOGN(int userInput[],int size){
	if(size == 0){
		return INT_MIN;
	}
	sort(userInput,userInput+size);
	unsigned int outerCrawler = 0,innerCrawler,frequency = 0;
	while(outerCrawler < size){
		frequency = 0;
		innerCrawler = outerCrawler;
		while(innerCrawler < size && userInput[innerCrawler] == userInput[outerCrawler]){
			frequency++;
		}
		if(frequency&1){
			return userInput[outerCrawler];
		}
		outerCrawler += frequency;
	}
	return INT_MIN;
}

/****************************************************************************************************************************************************/
/*                                                           O(N^2) Algorithm                                                                       */
/****************************************************************************************************************************************************/
int findOddOccuringValON2(int userInput[],int size){
	if(size == 0){
		return INT_MIN;
	}
	hash_map<int,bool> valPresenceMap;
	unsigned int frequency = 0;
	for(unsigned int outerCrawler = 0;outerCrawler < size;outerCrawler++){
		if(valPresenceMap.find(userInput[outerCrawler]) == valPresenceMap.end()){
			frequency = 0;
			for(unsigned int innerCrawler = outerCrawler;innerCrawler < size;innerCrawler++){
				if(userInput[outerCrawler] == userInput[innerCrawler]){
					frequency++;
				}
			}
			if(frequency&2){
				return userInput[outerCrawler];
			}
			valPresenceMap.insert(pair<int,bool>(userInput[outerCrawler],true));
		}
	}
	return INT_MIN;
}

#endif /* MAIN_AVIKODAK_SITES_GEEKSFORGEEKS_ARRAYS_PAGE04_FINDODDOCCURING_H_ */
