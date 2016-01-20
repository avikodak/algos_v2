/****************************************************************************************************************************************************
 *  File Name                   : findpair.h
 *  File Location               : /algos_v2/src/main/avikodak/sites/geeksforgeeks/arrays/page04/findpair.h
 *  Created on                  : Jan 20, 2016 :: 11:36:31 PM
 *  Author                      : avikodak
 *  Testing Status              : TODO
 *  URL                         : http://www.geeksforgeeks.org/write-a-c-program-that-given-a-set-a-of-n-numbers-and-another-number-x-determines-whether-or-not-there-exist-two-elements-in-s-whose-sum-is-exactly-x/
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

#ifndef MAIN_AVIKODAK_SITES_GEEKSFORGEEKS_ARRAYS_PAGE04_FINDPAIR_H_
#define MAIN_AVIKODAK_SITES_GEEKSFORGEEKS_ARRAYS_PAGE04_FINDPAIR_H_

/****************************************************************************************************************************************************/
/*                                                            O(N) Algorithm                                                                        */
/****************************************************************************************************************************************************/
iPair *findPairON(int userInput[],unsigned int size,int key){
	if(size == 0){
		return null;
	}
	hash_map<unsigned int,bool> valuePresenceMap;
	for(unsigned int counter = 0;counter < size;counter++){
		if(valuePresenceMap.find(key-userInput[counter]) != valuePresenceMap.end()){
			return new iPair(userInput[counter],key-userInput[counter]);
		}
		valuePresenceMap.insert(pair<unsigned int,bool>(userInput[counter],true));
	}
	return null;
}

/****************************************************************************************************************************************************/
/*                                                          O(N*LOGN) Algorithm                                                                     */
/****************************************************************************************************************************************************/
iPair *findPairONLOGN(int userInput[],int size,int key){
	if(size == 0){
		return null;
	}
	sort(userInput,userInput+size);
	unsigned int frontCrawler = 0,rearCrawler = size-1;
	while(frontCrawler < rearCrawler){
		if(userInput[frontCrawler] + userInput[rearCrawler] == key){
			return new iPair(userInput[frontCrawler],userInput[rearCrawler]);
		}
		frontCrawler++;
		rearCrawler--;
	}
	return null;
}

/****************************************************************************************************************************************************/
/*                                                           O(N^2) Algorithm                                                                       */
/****************************************************************************************************************************************************/
iPair *findPairON2(int userInput[],int size,int key){
	if(size == 0){
		return null;
	}
	for(unsigned int outerCrawler = 0;outerCrawler < size-1;outerCrawler++){
		for(unsigned int innerCrawler = outerCrawler+1;innerCrawler < size;innerCrawler++){
			if(userInput[outerCrawler]+userInput[innerCrawler] == key){
				return new iPair(userInput[outerCrawler],userInput[innerCrawler]);
			}
		}
	}
	return null;
}

#endif /* MAIN_AVIKODAK_SITES_GEEKSFORGEEKS_ARRAYS_PAGE04_FINDPAIR_H_ */
