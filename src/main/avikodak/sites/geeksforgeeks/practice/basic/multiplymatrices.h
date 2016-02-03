/****************************************************************************************************************************************************
 *  File Name                   : multiplymatrices.h
 *  File Location               : /algos_v2/src/main/avikodak/sites/geeksforgeeks/practice/basic/multiplymatrices.h
 *  Created on                  : Feb 3, 2016 :: 11:06:10 PM
 *  Author                      : avikodak
 *  Testing Status              : Tested
 *  URL                         : http://www.practice.geeksforgeeks.org/problem-page.php?pid=230
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
#define ROWS_COUNT 3
#define COLUMNS_COUNT 3
/****************************************************************************************************************************************************/
/*                                                             MAIN CODE START                                                                      */
/****************************************************************************************************************************************************/

#ifndef MAIN_AVIKODAK_SITES_GEEKSFORGEEKS_PRACTICE_BASIC_MULTIPLYMATRICES_H_
#define MAIN_AVIKODAK_SITES_GEEKSFORGEEKS_PRACTICE_BASIC_MULTIPLYMATRICES_H_

//Tested
void solveProblem(){
	unsigned int testCases;
	int fUserInput[ROWS_COUNT][COLUMNS_COUNT],sUserInput[ROWS_COUNT][COLUMNS_COUNT];
	scanf("%u",&testCases);
	while(testCases--){
		for(unsigned int rowCounter = 0;rowCounter < ROWS_COUNT;rowCounter++){
			for(unsigned int columnCounter = 0;columnCounter < COLUMNS_COUNT;columnCounter++){
				scanf("%d",&fUserInput[rowCounter][columnCounter]);
			}
		}
		for(unsigned int rowCounter = 0;rowCounter < ROWS_COUNT;rowCounter++){
			for(unsigned int columnCounter = 0;columnCounter < COLUMNS_COUNT;columnCounter++){
				scanf("%d",&sUserInput[rowCounter][columnCounter]);
			}
		}
		for(unsigned int rowCounter = 0;rowCounter < ROWS_COUNT;rowCounter++){
			for(unsigned int columnCounter = 0;columnCounter < COLUMNS_COUNT;columnCounter++){
				int sum = 0;
				for(unsigned int innerColumnCounter = 0;innerColumnCounter < COLUMNS_COUNT;innerColumnCounter++){
					sum += fUserInput[rowCounter][innerColumnCounter]*sUserInput[innerColumnCounter][columnCounter];
				}
				printf("%d ",sum);
			}
			printf("\n");
		}
	}
}


#endif /* MAIN_AVIKODAK_SITES_GEEKSFORGEEKS_PRACTICE_BASIC_MULTIPLYMATRICES_H_ */
