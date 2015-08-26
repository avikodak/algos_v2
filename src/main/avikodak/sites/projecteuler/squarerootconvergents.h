/****************************************************************************************************************************************************
 *  File Name                   : squarerootconvergents.h
 *  File Location               : D:\projects\cpp\algos_v2\src\main\avikodak\sites\projecteuler\squarerootconvergents.h
 *  Created on                  : Aug 26, 2015 :: 11:09:57 PM
 *  Author                      : avikodak
 *  Testing Status              : TODO
 *  URL                         : https://projecteuler.net/problem=57
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

#ifndef SQUAREROOTCONVERGENTS_H_
#define SQUAREROOTCONVERGENTS_H_

unsigned int countDigits(unsigned long int userInput){
	unsigned int counter = 0;
	while(userInput){
		counter++;
		userInput/=10;
	}
	return counter;
}

void getTotalFraction(){
	unsigned long int numerator = 3,denominator = 2;
	unsigned int total = 0;
	for(unsigned int counter = 1;counter < 1000;counter++){
		numerator = numerator + 2*denominator;
		denominator = numerator + denominator;
		if(countDigits(numerator) > countDigits(denominator)){
			total++;
		}
	}
	cout << total << endl;
}

#endif /* SQUAREROOTCONVERGENTS_H_ */

/****************************************************************************************************************************************************/
/*                                                               MAIN CODE END                                                                      */
/****************************************************************************************************************************************************/
