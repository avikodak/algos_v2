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
