/****************************************************************************************************************************************************
 *  File Name                   : submin.h
 *  File Location               : /home/avikodak/Desktop/projects/algos_v2/src/main/avikodak/sites/codechef/easy/submin.h
 *  Created on                  : 31-Oct-2015 :: 3:38:13 pm
 *  Author                      : avikodak
 *  Testing Status              : Tested
 *  URL                         : https://www.codechef.com/problems/SUBMIN
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
#include <iomanip>
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

#ifndef SUBMIN_H_
#define SUBMIN_H_

//Tested
void printResults(){
	long long int size,input,minValue;
	vector<long long int> userInput;
	scanf("%lld",&size);
	while(size--){
		scanf("%lld",&input);
		userInput.push_back(input);
	}
	map<long long int,long long int> minValFreqMap;
	for(unsigned int outerCounter = 0;outerCounter < userInput.size();outerCounter++){
		minValue = userInput[outerCounter];
		for(unsigned int innerCounter = outerCounter;innerCounter < userInput.size();innerCounter++){
			minValue = min(minValue,userInput[innerCounter]);
			if(minValFreqMap.find(minValue) == minValFreqMap.end()){
				minValFreqMap[minValue] = 1;
			}else{
				minValFreqMap[minValue]++;
			}
		}
	}
	scanf("%lld",&size);
	while(size--){
		scanf("%lld",&input);
		if(minValFreqMap.find(input) == minValFreqMap.end()){
			printf("0\n");
		}else{
			printf("%lld\n",minValFreqMap[input]);
		}
	}
}

#endif /* SUBMIN_H_ */

/****************************************************************************************************************************************************/
/*                                                               MAIN CODE END                                                                      */
/****************************************************************************************************************************************************/
