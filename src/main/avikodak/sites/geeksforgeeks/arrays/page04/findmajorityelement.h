/****************************************************************************************************************************************************
 *  File Name                   : findmajorityelement.h
 *  File Location               : /algos_v2/src/main/avikodak/sites/geeksforgeeks/arrays/page04/findmajorityelement.h
 *  Created on                  : Jan 20, 2016 :: 11:54:42 PM
 *  Author                      : avikodak
 *  Testing Status              : TODO
 *  URL                         : http://www.geeksforgeeks.org/majority-element/
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

#ifndef MAIN_AVIKODAK_SITES_GEEKSFORGEEKS_ARRAYS_PAGE04_FINDMAJORITYELEMENT_H_
#define MAIN_AVIKODAK_SITES_GEEKSFORGEEKS_ARRAYS_PAGE04_FINDMAJORITYELEMENT_H_

/****************************************************************************************************************************************************/
/*                                                            O(N) Algorithm                                                                        */
/****************************************************************************************************************************************************/
int findMajorityElement(int userInput[],int size){
	if(size == 0){
		throw exception;
	}
	hash_map<int,unsigned int> frequencyMap;
	unsigned int maxFrequency = 0;
	int maxFreqVal;
	for(unsigned int counter = 0;counter < size;counter++){
		if(frequencyMap.find(userInput[counter]) != frequencyMap.end()){
			frequencyMap[userInput[counter]]++;
		}else{
			frequencyMap[userInput[counter]] = 1;
		}
		if(maxFrequency > frequencyMap[userInput[counter]]){
			maxFrequency = frequencyMap[userInput[counter]];
			maxFreqVal = userInput[counter];
		}
	}
	return maxFrequency > size/2?maxFreqVal:INT_MIN;
}

/****************************************************************************************************************************************************/
/*                                                          O(N*LOGN) Algorithm                                                                     */
/****************************************************************************************************************************************************/


/****************************************************************************************************************************************************/
/*                                                           O(N^2) Algorithm                                                                       */
/****************************************************************************************************************************************************/


#endif /* MAIN_AVIKODAK_SITES_GEEKSFORGEEKS_ARRAYS_PAGE04_FINDMAJORITYELEMENT_H_ */
