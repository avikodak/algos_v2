/****************************************************************************************************************************************************
 *  File Name                   : flow007.h
 *  File Location               : D:\projects\cpp\algos_v2\src\main\avikodak\sites\codechef\school\flow007.h
 *  Created on                  : Aug 24, 2015 :: 9:45:45 PM
 *  Author                      : avikodak
 *  Testing Status              : Tested
 *  URL                         : https://www.codechef.com/problems/FLOW007
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

#ifndef FLOW007_H_
#define FLOW007_H_

//Tested
void printReverse(unsigned int userInput){
	unsigned int reverse = 0;
	while(userInput){
		reverse *= 10;
		reverse += userInput%10;
		userInput/=10;
	}
	printf("%u\n",reverse);
}

//Tested
void printReverseInput(){
	unsigned int testCases,input;
	scanf("%u",&testCases);
	while(testCases--){
		scanf("%u",&input);
		printReverse(input);
	}
}

#endif /* FLOW007_H_ */

/****************************************************************************************************************************************************/
/*                                                               MAIN CODE END                                                                      */
/****************************************************************************************************************************************************/
