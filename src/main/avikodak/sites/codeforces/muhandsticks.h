/****************************************************************************************************************************************************
 *  File Name                   : muhandsticks.h
 *  File Location               : D:\projects\cpp\algos_v2\src\main\avikodak\sites\codeforces\muhandsticks.h
 *  Created on                  : Apr 8, 2015 :: 1:05:32 AM
 *  Author                      : avikodak
 *  Testing Status              : Tested
 *  URL                         : http://codeforces.com/problemset/problem/471/A
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
#include <lib/constants/constants.h>
#include <lib/ds/commonds.h>
#include <lib/ds/linkedlistds.h>
#include <lib/ds/graphds.h>
#include <lib/ds/mathds.h>
#include <lib/ds/treeds.h>
#include <lib/utils/arrayutil.h>
#include <lib/utils/avltreeutil.h>
#include <lib/utils/bplustreeutil.h>
#include <lib/utils/btreeutil.h>
#include <lib/utils/commonutil.h>
#include <lib/utils/dillutil.h>
#include <lib/utils/graphutil.h>
#include <lib/utils/mathutil.h>
#include <lib/utils/redblacktreeutil.h>
#include <lib/utils/sillutil.h>
#include <lib/utils/treeutil.h>
#include <lib/utils/twofourtreeutil.h>

/****************************************************************************************************************************************************/
/*                                                            USER DEFINED CONSTANTS                                                                */
/****************************************************************************************************************************************************/

/****************************************************************************************************************************************************/
/*                                                             MAIN CODE START                                                                      */
/****************************************************************************************************************************************************/

#ifndef MUHANDSTICKS_H_
#define MUHANDSTICKS_H_

//Tested
void identifyAnimal(){
	int frequency[9] = {0};
	int userInput;
	for(unsigned int counter = 0;counter < 6;counter++){
		scanf("%d",&userInput);
		frequency[userInput-1]++;
	}
	bool fourFlag = false,fiveFlag = false,sixFlag = false,twoFlag = false;
	for(unsigned int counter = 0;counter < 9;counter++){
		if(frequency[counter] ==  2){
			twoFlag = true;
		}else if(frequency[counter] == 4){
			fourFlag = true;
		}else if(frequency[counter] == 5){
			fiveFlag = true;
		}else if(frequency[counter] == 6){
			sixFlag = true;
		}
	}
	if(fourFlag || fiveFlag || sixFlag){
		if(fourFlag){
			printf("%s",twoFlag?"Elephant":"Bear");
		}else{
			if(sixFlag){
				printf("Elephant");
			}else{
				printf("Bear");
			}
		}
	}else{
		printf("Alien");
	}
}
#endif /* MUHANDSTICKS_H_ */

/****************************************************************************************************************************************************/
/*                                                               MAIN CODE END                                                                      */
/****************************************************************************************************************************************************/
