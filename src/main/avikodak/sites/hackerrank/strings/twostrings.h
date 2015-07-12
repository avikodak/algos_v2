/****************************************************************************************************************************************************
 *  File Name                   : twostrings.h
 *  File Location               : D:\projects\cpp\algos_v2\src\main\avikodak\sites\hackerrank\strings\twostrings.h
 *  Created on                  : Jul 11, 2015 :: 1:59:21 PM
 *  Author                      : avikodak
 *  Testing Status              : Tested
 *  URL                         : https://www.hackerrank.com/challenges/two-strings
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

#ifndef TWOSTRINGS_H_
#define TWOSTRINGS_H_

//Tested
void anyCommonSubstring(){
	unsigned int testCases;
	scanf("%u",&testCases);
	string firstUserInput,secondUserInput;
	string alphabets = "abcdefghijklmnopqrstuvwxyz";
	bool flag;
	while(testCases--){
		cin >> firstUserInput >> secondUserInput;
		flag = false;
		for(unsigned int counter = 0;counter < alphabets.size();counter++){
			if(firstUserInput.find(alphabets[counter]) != string::npos && secondUserInput.find(alphabets[counter]) != string::npos){
				printf("YES\n");
				flag = true;
				break;
			}
		}
		if(!flag){
			printf("NO\n");
		}
	}
}

#endif /* TWOSTRINGS_H_ */

/****************************************************************************************************************************************************/
/*                                                               MAIN CODE END                                                                      */
/****************************************************************************************************************************************************/
