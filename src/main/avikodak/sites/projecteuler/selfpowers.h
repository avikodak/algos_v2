/****************************************************************************************************************************************************
 *  File Name                   : selfpowers.h
 *  File Location               : D:\projects\cpp\algos_v2\src\main\avikodak\sites\projecteuler\selfpowers.h
 *  Created on                  : Jul 31, 2015 :: 3:03:20 PM
 *  Author                      : avikodak
 *  Testing Status              : Tested
 *  URL                         : https://projecteuler.net/problem=48
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
#define MOD_CONSTANT 10000000000

/****************************************************************************************************************************************************/
/*                                                             MAIN CODE START                                                                      */
/****************************************************************************************************************************************************/

#ifndef SELFPOWERS_H_
#define SELFPOWERS_H_

//Tested
//Ans : 9110846700
void getLastTenDigitsSelfPowers(){
	unsigned long long int sum = 1,product = 1;
	for(unsigned int outerCounter = 2;outerCounter <= 1000;outerCounter++){
		product = 1;
		for(unsigned int innerCounter = 0;innerCounter < outerCounter;innerCounter++){
			product *= outerCounter;
			product = product%MOD_CONSTANT;
		}
 		sum += product;
		sum = sum%MOD_CONSTANT;
	}
	cout << sum;
}

#endif /* SELFPOWERS_H_ */

/****************************************************************************************************************************************************/
/*                                                               MAIN CODE END                                                                      */
/****************************************************************************************************************************************************/
