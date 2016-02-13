/****************************************************************************************************************************************************
 *  File Name                   : countincsubarrays.h
 *  File Location               : /algos_v2/src/main/avikodak/sites/geeksforgeeks/practice/basic/countincsubarrays.h
 *  Created on                  : Feb 14, 2016 :: 12:26:42 AM
 *  Author                      : avikodak
 *  Testing Status              : Tested
 *  URL                         : http://www.practice.geeksforgeeks.org/problem-page.php?pid=405
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
#include <libv2/common/commonincludes.h>
#include <libv2/constants/constants.h>
#include <libv2/ds/commonds.h>
#include <libv2/ds/graphds.h>
#include <libv2/ds/linkedlistds.h>
#include <libv2/ds/mathds.h>
#include <libv2/ds/treeds.h>
#include <libv2/utils/abtreeutil.h>
#include <libv2/utils/arrayutil.h>
#include <libv2/utils/avltreeutil.h>
#include <libv2/utils/bplustreeutil.h>
#include <libv2/utils/bstutil.h>
#include <libv2/utils/btreeutil.h>
#include <libv2/utils/commonutil.h>
#include <libv2/utils/dillutil.h>
#include <libv2/utils/graphutil.h>
#include <libv2/utils/ioutil.h>
#include <libv2/utils/mathutil.h>
#include <libv2/utils/redblacktreeutil.h>
#include <libv2/utils/sillutil.h>
#include <libv2/utils/treeutil.h>
#include <libv2/utils/trieutil.h>
#include <libv2/utils/twofourtreeutil.h>

/****************************************************************************************************************************************************/
/*                                                            USER DEFINED CONSTANTS                                                                */
/****************************************************************************************************************************************************/

/****************************************************************************************************************************************************/
/*                                                             MAIN CODE START                                                                      */
/****************************************************************************************************************************************************/

#ifndef MAIN_AVIKODAK_SITES_GEEKSFORGEEKS_PRACTICE_BASIC_COUNTINCSUBARRAYS_H_
#define MAIN_AVIKODAK_SITES_GEEKSFORGEEKS_PRACTICE_BASIC_COUNTINCSUBARRAYS_H_

//Tested
void solveProblem(){
	unsigned int testCases,size;
	long long int input;
	vector<long long int> userInput;
	scanf("%u",&testCases);
	unsigned int outerCrawler,innerCrawler,subArrayCount;
	while(testCases--){
		scanf("%u",&size);
		userInput.clear();
		for(unsigned int counter = 0;counter < size;counter++){
			scanf("%lld",&input);
			userInput.push_back(input);
		}
		outerCrawler = 0;
		subArrayCount = 0;
		while(outerCrawler < size){
			innerCrawler = outerCrawler+1;
			while(innerCrawler < size && userInput[innerCrawler] > userInput[innerCrawler-1]){
				innerCrawler++;
			}
			subArrayCount+= (innerCrawler-outerCrawler)*(innerCrawler-outerCrawler+1)/2;
			outerCrawler = innerCrawler;
		}
		printf("%u\n",subArrayCount-size);
	}
}

#endif /* MAIN_AVIKODAK_SITES_GEEKSFORGEEKS_PRACTICE_BASIC_COUNTINCSUBARRAYS_H_ */
