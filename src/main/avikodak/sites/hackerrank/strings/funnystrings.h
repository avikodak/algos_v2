/****************************************************************************************************************************************************
 *  File Name                   : funnystrings.h
 *  File Location               : D:\projects\cpp\algos_v2\src\main\avikodak\sites\hackerrank\strings\funnystrings.h
 *  Created on                  : May 24, 2015 :: 7:37:41 PM
 *  Author                      : avikodak
 *  Testing Status              : Tested
 *  URL                         : https://www.hackerrank.com/challenges/funny-string
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

#ifndef FUNNYSTRINGS_H_
#define FUNNYSTRINGS_H_

//Tested
void areStringsFunny(){
	unsigned int testCases;
	int diffFirst,diffSecond;
	scanf("%u",&testCases);
	string userInput,revUserInput;
	while(testCases--){
		cin >> userInput;
		revUserInput.clear();
		revUserInput.resize(userInput.size());
		reverse_copy(userInput.begin(),userInput.end(),revUserInput.begin());
		bool flag = true;
		for(unsigned int outerCrawler = 1;outerCrawler < userInput.size();outerCrawler++){
			diffFirst = abs(userInput[outerCrawler] - userInput[outerCrawler-1]);
			diffSecond = abs(revUserInput[outerCrawler] - revUserInput[outerCrawler-1]);
			if(diffFirst != diffSecond){
				printf("Not Funny\n");
				flag = false;
				break;
			}
		}
		if(flag){
			printf("Funny\n");
		}

	}
}

#endif /* FUNNYSTRINGS_H_ */

/****************************************************************************************************************************************************/
/*                                                               MAIN CODE END                                                                      */
/****************************************************************************************************************************************************/
