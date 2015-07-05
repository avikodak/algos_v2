/****************************************************************************************************************************************************
 *  File Name                   : sherlockandthebeast.h
 *  File Location               : D:\projects\cpp\algos_v2\src\main\avikodak\sites\hackerrank\implementation\sherlockandthebeast.h
 *  Created on                  : Jun 28, 2015 :: 8:52:36 PM
 *  Author                      : avikodak
 *  Testing Status              : Tested
 *  URL                         : https://www.hackerrank.com/challenges/sherlock-and-the-beast
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

#ifndef SHERLOCKANDTHEBEAST_H_
#define SHERLOCKANDTHEBEAST_H_

//Tested
void getVirusNumber(){
	unsigned int testCases,userInput;
	scanf("%u",&testCases);
	int largestThreeMultiple,remainder;
	while(testCases--){
		scanf("%u",&userInput);
		largestThreeMultiple = (userInput/3)*3;
		remainder = userInput - largestThreeMultiple;
		bool flag=false;
		while(largestThreeMultiple >= 0){
			if(remainder%5 == 0){
				for(unsigned int counter = 0;counter < largestThreeMultiple;counter++){
					printf("5");
				}
				for(unsigned int counter = 0;counter < remainder;counter++){
					printf("3");
				}
				break;
			}
			largestThreeMultiple -= 3;
			remainder += 3;
		}
		if(!flag){
			printf("-1");
		}
		printf("\n");
	}
}

#endif /* SHERLOCKANDTHEBEAST_H_ */

/****************************************************************************************************************************************************/
/*                                                               MAIN CODE END                                                                      */
/****************************************************************************************************************************************************/
