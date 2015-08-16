/****************************************************************************************************************************************************
 *  File Name                   : pandigitalprimes.h
 *  File Location               : D:\projects\cpp\algos_v2\src\main\avikodak\sites\projecteuler\pandigitalprimes.h
 *  Created on                  : Aug 15, 2015 :: 5:47:40 PM
 *  Author                      : avikodak
 *  Testing Status              : Tested
 *  URL                         : https://projecteuler.net/problem=41
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
#include <algorithm/constants/constants.h>
#include <algorithm/ds/commonds.h>
#include <algorithm/ds/linkedlistds.h>
#include <algorithm/ds/graphds.h>
#include <algorithm/ds/mathds.h>
#include <algorithm/ds/treeds.h>
#include <algorithm/utils/arrayutil.h>
#include <algorithm/utils/avltreeutil.h>
#include <algorithm/utils/bplustreeutil.h>
#include <algorithm/utils/btreeutil.h>
#include <algorithm/utils/commonutil.h>
#include <algorithm/utils/dillutil.h>
#include <algorithm/utils/graphutil.h>
#include <algorithm/utils/mathutil.h>
#include <algorithm/utils/redblacktreeutil.h>
#include <algorithm/utils/sillutil.h>
#include <algorithm/utils/treeutil.h>
#include <algorithm/utils/twofourtreeutil.h>

/****************************************************************************************************************************************************/
/*                                                            USER DEFINED CONSTANTS                                                                */
/****************************************************************************************************************************************************/

/****************************************************************************************************************************************************/
/*                                                             MAIN CODE START                                                                      */
/****************************************************************************************************************************************************/

#ifndef PANDIGITALPRIMES_H_
#define PANDIGITALPRIMES_H_

//Tested
unsigned int isPanDigital(unsigned long long int userInput){
	unsigned int digitCount[10] = {0};
	while(userInput){
		digitCount[userInput%10]++;
		if(userInput%10 == 0 ||digitCount[userInput%10] > 1){
			return 0;
		}
		userInput /= 10;
	}
	if(digitCount[1] == 0){
		return 0;
	}
	unsigned int length = 1;
	unsigned int counter;
	for(counter = 2;counter < 10;counter++){
		if(digitCount[counter] == 1){
			length++;
		}else{
			break;
		}
	}
	for(;counter < 10;counter++){
		if(digitCount[counter] == 1){
			return 0;
		}
	}
	return length;
}

//Tested
//Ans : 7652413
void printLargestPanDigitalPrime(){
	unsigned long int limit = 987654322;
	vector<bool> flags;
	flags.assign(limit,true);
	unsigned long int maxPanDigital = 0;
	for(unsigned int counter = 2;counter < limit;counter++){
		if(flags[counter]){
			if(isPanDigital(counter)){
				maxPanDigital = maxPanDigital > counter?maxPanDigital:counter;
				cout << maxPanDigital << endl;
			}
			unsigned int innerCounter = 2;
			while(counter*innerCounter <= limit){
				flags[counter*innerCounter] = false;
				innerCounter+=1;
			}
		}
	}
	cout << maxPanDigital << endl;
}

#endif /* PANDIGITALPRIMES_H_ */

/****************************************************************************************************************************************************/
/*                                                               MAIN CODE END                                                                      */
/****************************************************************************************************************************************************/
