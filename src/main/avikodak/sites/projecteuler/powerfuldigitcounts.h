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
