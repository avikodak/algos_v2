/****************************************************************************************************************************************************
 *  File Name                   : qbit01.h
 *  File Location               : /home/avikodak/Desktop/projects/algos_v2/src/main/avikodak/sites/codechef/contest/qbit15/qbit01.h
 *  Created on                  : 15-Oct-2015 :: 6:49:07 pm
 *  Author                      : avikodak
 *  Testing Status              : Tested
 *  URL                         : https://www.codechef.com/QBIT15/problems/QBIT01
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

#ifndef QBIT01_H_
#define QBIT01_H_

//Tested
bool sortFunc(long long int first,long long int second){
	return first > second;
}

//Tested
void printResults(){
	unsigned int testCases,size;
	long long int input,sum,choosenSum,minCoins;
	scanf("%u",&testCases);
	vector<long long int> userInput;
	while(testCases--){
		scanf("%u",&size);
		userInput.clear();
		sum = 0;
		for(unsigned int counter = 0;counter < size;counter++){
			scanf("%lld",&input);
			sum += input;
			userInput.push_back(input);
		}
		sort(userInput.begin(),userInput.end(),sortFunc);
		choosenSum = 0;
		minCoins = 0;
		for(unsigned int counter = 0;counter < size;counter++){
			if(choosenSum <= sum){
				sum -= userInput[counter];
				choosenSum += userInput[counter];
				minCoins++;
			}else{
				break;
			}
		}
		printf("%lld\n",minCoins);
	}
}

#endif /* QBIT01_H_ */

/****************************************************************************************************************************************************/
/*                                                               MAIN CODE END                                                                      */
/****************************************************************************************************************************************************/
