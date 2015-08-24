/****************************************************************************************************************************************************
 *  File Name                   : luckfour.h
 *  File Location               : D:\projects\cpp\algos_v2\src\main\avikodak\sites\codechef\school\luckfour.h
 *  Created on                  : Aug 24, 2015 :: 8:40:20 PM
 *  Author                      : avikodak
 *  Testing Status              : Tested
 *  URL                         : https://www.codechef.com/problems/LUCKFOUR
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

#ifndef LUCKFOUR_H_
#define LUCKFOUR_H_

//Tested
void printFourCount(unsigned long long int userInput){
	unsigned int counter = 0;
	while(userInput){
		if(userInput%10 == 4){
			counter++;
		}
		userInput/=10;
	}
	printf("%u\n",counter);
}

//Tested
void getFourCountsForInput(){
	unsigned int testCases;
	unsigned long long int userInput;
	scanf("%u",&testCases);
	while(testCases--){
		cin >> userInput;
		printFourCount(userInput);
	}
}

#endif /* LUCKFOUR_H_ */

/****************************************************************************************************************************************************/
/*                                                               MAIN CODE END                                                                      */
/****************************************************************************************************************************************************/
