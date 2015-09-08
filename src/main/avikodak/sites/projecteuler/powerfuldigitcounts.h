/****************************************************************************************************************************************************
 *  File Name                   : powerfuldigitcounts.h
 *  File Location               : D:\projects\cpp\algos_v2\src\main\avikodak\sites\projecteuler\powerfuldigitcounts.h
 *  Created on                  : Aug 18, 2015 :: 8:07:57 PM
 *  Author                      : avikodak
 *  Testing Status              : TODO
 *  URL                         : https://projecteuler.net/problem=63
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

#ifndef POWERFULDIGITCOUNTS_H_
#define POWERFULDIGITCOUNTS_H_

unsigned int getDigitCount(unsigned int userInput){
	if(userInput == 0){
		return 0;
	}
	unsigned int counter = 0;
	while(userInput){
		counter++;
		userInput /= 10;
	}
	return counter;
}

unsigned int pow(unsigned int base,unsigned int power){
	if(power == 0){
		return 1;
	}
	unsigned int result = 1;
	for(unsigned int counter = 0;counter < power;counter++){
		result *= base;
	}
	return result;
}

void getNthPowerWithNthDigits(){
	unsigned int total = 0;
	unsigned int innerCounter = 0,powResult,digitCount;
	for(unsigned int outerCounter = 2;outerCounter < 11;outerCounter++){
		innerCounter = 1;
		while(true){
			powResult = pow(outerCounter,innerCounter++);
			digitCount = getDigitCount(powResult);
			if(digitCount == innerCounter){
				cout << outerCounter << " " << innerCounter-1 << endl;
				total++;
			}else if(digitCount > innerCounter){
				break;
			}
		}
	}
	cout << total << endl;
}

#endif /* POWERFULDIGITCOUNTS_H_ */

/****************************************************************************************************************************************************/
/*                                                               MAIN CODE END                                                                      */
/****************************************************************************************************************************************************/
