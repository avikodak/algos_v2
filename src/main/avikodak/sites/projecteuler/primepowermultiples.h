/****************************************************************************************************************************************************
 *  File Name                   : primepowermultiples.h
 *  File Location               : D:\projects\cpp\algos_v2\src\main\avikodak\sites\projecteuler\primepowermultiples.h
 *  Created on                  : Aug 22, 2015 :: 4:45:06 PM
 *  Author                      : avikodak
 *  Testing Status              : Tested
 *  URL                         : https://projecteuler.net/problem=87
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

#ifndef PRIMEPOWERMULTIPLES_H_
#define PRIMEPOWERMULTIPLES_H_

//Tested
unsigned long long int upow(unsigned int base,unsigned int power){
	unsigned long long int result=1;
	while(power--){
		result *= base;
	}
	return result;
}

//Tested
//Ans : 1097343
void getTotalPrimePowerMultiples(){
	vector<unsigned int> primeNumbers = generatePrimeNumbers(7071);
	set<unsigned long long int> resultingList;
	unsigned long long int result;
	for(unsigned int outerCounter = 0;outerCounter < primeNumbers.size();outerCounter++){
		for(unsigned int middleCounter = 0;middleCounter < primeNumbers.size();middleCounter++){
			for(unsigned int innerCounter = 0;innerCounter < primeNumbers.size();innerCounter++){
				result = upow(primeNumbers[outerCounter],2) + upow(primeNumbers[middleCounter],3) + upow(primeNumbers[innerCounter],4);
				if(result < 50000000){
					resultingList.insert(result);
				}else{
					break;
				}
			}
		}
	}
	cout << resultingList.size() << endl;
}

#endif /* PRIMEPOWERMULTIPLES_H_ */

/****************************************************************************************************************************************************/
/*                                                               MAIN CODE END                                                                      */
/****************************************************************************************************************************************************/
