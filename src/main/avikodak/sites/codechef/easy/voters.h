/****************************************************************************************************************************************************
 *  File Name                   : voters.h
 *  File Location               : D:\projects\cpp\algos_v2\src\main\avikodak\sites\codechef\easy\voters.h
 *  Created on                  : May 24, 2015 :: 6:13:01 PM
 *  Author                      : avikodak
 *  Testing Status              : Tested
 *  URL                         : http://www.codechef.com/problems/VOTERS
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
#include <lib/constants/constants.h>
#include <lib/ds/commonds.h>
#include <lib/ds/linkedlistds.h>
#include <lib/ds/graphds.h>
#include <lib/ds/mathds.h>
#include <lib/ds/treeds.h>
#include <lib/utils/arrayutil.h>
#include <lib/utils/avltreeutil.h>
#include <lib/utils/bplustreeutil.h>
#include <lib/utils/btreeutil.h>
#include <lib/utils/commonutil.h>
#include <lib/utils/dillutil.h>
#include <lib/utils/graphutil.h>
#include <lib/utils/mathutil.h>
#include <lib/utils/redblacktreeutil.h>
#include <lib/utils/sillutil.h>
#include <lib/utils/treeutil.h>
#include <lib/utils/twofourtreeutil.h>

/****************************************************************************************************************************************************/
/*                                                            USER DEFINED CONSTANTS                                                                */
/****************************************************************************************************************************************************/

/****************************************************************************************************************************************************/
/*                                                             MAIN CODE START                                                                      */
/****************************************************************************************************************************************************/

#ifndef VOTERS_H_
#define VOTERS_H_

//Tested
void printFinalList(){
	unsigned int firstSize,secondSize,thirdSize,userInput,size;
	scanf("%u %u %u",&firstSize,&secondSize,&thirdSize);
	map<unsigned int ,unsigned int> frequencyMap;
	map<unsigned int,unsigned int>::iterator itToFrequencyMap;
	size = firstSize + secondSize + thirdSize;
	while(size--){
		scanf("%u",&userInput);
		if(frequencyMap.find(userInput) == frequencyMap.end()){
			frequencyMap[userInput] = 1;
		}else{
			frequencyMap[userInput] += 1;
		}
	}
	vector<int> finalList;
	for(itToFrequencyMap = frequencyMap.begin();itToFrequencyMap != frequencyMap.end();itToFrequencyMap++){
		if(itToFrequencyMap->second > 1){
			finalList.push_back(itToFrequencyMap->first);
		}
	}
	printf("%u\n",finalList.size());
	for(unsigned int counter = 0;counter < finalList.size();counter++){
		printf("%d\n",finalList[counter]);
	}
}

#endif /* VOTERS_H_ */

/****************************************************************************************************************************************************/
/*                                                               MAIN CODE END                                                                      */
/****************************************************************************************************************************************************/
