/****************************************************************************************************************************************************
 *  File Name                   : iqtest.h
 *  File Location               : D:\projects\cpp\algos_v2\src\main\avikodak\sites\codeforces\iqtest.h
 *  Created on                  : Apr 11, 2015 :: 5:20:08 PM
 *  Author                      : avikodak
 *  Testing Status              : Tested
 *  URL                         : http://codeforces.com/problemset/problem/25/A
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

#ifndef IQTEST_H_
#define IQTEST_H_

//Tested
void getNumberEvenness(){
	unsigned int testCases,firstInput,secondInput,thirdInput,input;
	scanf("%u",&testCases);
	cin >> firstInput >> secondInput >> thirdInput;
	bool printOddNumber = false;
	if(firstInput%2 == 0 && secondInput%2 == 0){
		if(thirdInput%2 == 1){
			printf("%u",thirdInput);
			return;
		}
		printOddNumber = true;
	}else if(firstInput%2 == 0 && thirdInput%2 == 0){
		printf("%u",secondInput);
		return;
	}else if(secondInput%2 == 0 && thirdInput%2 == 0){
		printf("%u",firstInput);
		return;
	}
	testCases -= 3;
	while(testCases--){
		scanf("%u",&input);
		if(printOddNumber){
			if(input%2 == 1){
				printf("%u",input);
				return;
			}
		}else{
			if(input%2 == 0){
				printf("%u",input);
				return;
			}
		}
	}
}

#endif /* IQTEST_H_ */

/****************************************************************************************************************************************************/
/*                                                               MAIN CODE END                                                                      */
/****************************************************************************************************************************************************/
