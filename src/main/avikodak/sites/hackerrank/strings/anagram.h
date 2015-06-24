/****************************************************************************************************************************************************
 *  File Name                   : anagram.h
 *  File Location               : D:\projects\cpp\algos_v2\src\main\avikodak\sites\hackerrank\strings\anagram.h
 *  Created on                  : May 24, 2015 :: 8:38:29 PM
 *  Author                      : avikodak
 *  Testing Status              : Tested
 *  URL                         : https://www.hackerrank.com/challenges/anagram
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
#define MAX_SIZE_INPUT 10001

/****************************************************************************************************************************************************/
/*                                                             MAIN CODE START                                                                      */
/****************************************************************************************************************************************************/

#ifndef ANAGRAM_H_
#define ANAGRAM_H_

void countReplaceChars(){
	unsigned int testCases;
	string userInput,firstStr,secondStr;
	scanf("%u",&testCases);
	while(testCases--){
		cin >> userInput;
		if(userInput.size()&1){
			printf("-1\n");
		}else{
			firstStr = userInput.substr(0,userInput.size()/2);
			secondStr = userInput.substr(userInput.size()/2);
			sort(firstStr.begin(),firstStr.end());
			sort(secondStr.begin(),secondStr.end());
			unsigned int firstCrawler = 0,secondCrawler = 0,charCount = 0;
			while(firstCrawler < firstStr.size() && secondCrawler < secondStr.size()){
				if(firstStr[firstCrawler] != secondStr[secondCrawler]){
					if(firstStr[firstCrawler] < secondStr[secondCrawler]){
						firstCrawler++;
					}else{
						secondCrawler++;
					}
					charCount++;
				}else{
					firstCrawler++;
					secondCrawler++;
				}
			}
			if(firstCrawler < firstStr.size()){
				charCount += firstStr.size() - firstCrawler;
			}else if(secondCrawler < secondStr.size()){
				charCount += secondStr.size() - secondCrawler;
			}
			printf("%d\n",(charCount/2));
		}
	}
}

#endif /* ANAGRAM_H_ */

/****************************************************************************************************************************************************/
/*                                                               MAIN CODE END                                                                      */
/****************************************************************************************************************************************************/
