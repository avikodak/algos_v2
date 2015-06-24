/****************************************************************************************************************************************************
 *  File Name                   : palindromeindex.h
 *  File Location               : D:\projects\cpp\algos_v2\src\main\avikodak\sites\hackerrank\strings\palindromeindex.h
 *  Created on                  : Jun 23, 2015 :: 8:29:36 PM
 *  Author                      : avikodak
 *  Testing Status              : Tested
 *  URL                         : https://www.hackerrank.com/challenges/palindrome-index
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

#ifndef PALINDROMEINDEX_H_
#define PALINDROMEINDEX_H_

//Tested
void getPalindromeIndex(){
	unsigned int testCases,frontCrawler,rearCrawler;
	scanf("%u",&testCases);
	string userInput;
	bool indexFound;
	while(testCases--){
		cin >> userInput;
		frontCrawler = 0;
		rearCrawler = userInput.size()-1;
		indexFound = false;
		while(frontCrawler < rearCrawler){
			if(userInput[frontCrawler] != userInput[rearCrawler]){
				if(frontCrawler+1 == rearCrawler || frontCrawler+1 == rearCrawler-1){
					printf("%d\n",frontCrawler);
				}else if(userInput[frontCrawler+1] == userInput[rearCrawler]){
					printf("%d\n",frontCrawler);
				}else{
					printf("%d\n",rearCrawler);
				}
				indexFound = true;
				break;
			}
			frontCrawler++;
			rearCrawler--;
		}
		if(!indexFound){
			printf("-1\n");
		}
	}
}

#endif /* PALINDROMEINDEX_H_ */

/****************************************************************************************************************************************************/
/*                                                               MAIN CODE END                                                                      */
/****************************************************************************************************************************************************/
