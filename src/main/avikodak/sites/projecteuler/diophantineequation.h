/****************************************************************************************************************************************************
 *  File Name                   : diophantineequation.h
 *  File Location               : D:\projects\cpp\algos_v2\src\main\avikodak\sites\projecteuler\diophantineequation.h
 *  Created on                  : Aug 25, 2015 :: 7:56:36 AM
 *  Author                      : avikodak
 *  Testing Status              : TODO
 *  URL                         : https://projecteuler.net/problem=66
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

#ifndef DIOPHANTINEEQUATION_H_
#define DIOPHANTINEEQUATION_H_

bool isPerfectSquare(unsigned long long int userInput){
	unsigned long long int sqrtVal = sqrtl(userInput);
	return sqrtVal*sqrtVal == userInput;
}

unsigned long long int findSolutionDiophantineEqu(unsigned long long int userInput){
	unsigned long long int counter = 1;
	unsigned long long int value;
	while(true){
		value = 1 + userInput*counter*counter;
		if(isPerfectSquare(value)){
			return sqrtl(value);
		}
		counter++;
	}
}

void printDValForMaxX(){
	unsigned long long int maxX = 0,dValue,result;
	for(unsigned long long int counter = 2;counter <= 1000;counter++){
		cout << counter << endl;
		result = findSolutionDiophantineEqu(counter);
		if(maxX < result){
			maxX = result;
			dValue = counter;
		}
	}
	cout << dValue << endl;
}

#endif /* DIOPHANTINEEQUATION_H_ */

/****************************************************************************************************************************************************/
/*                                                               MAIN CODE END                                                                      */
/****************************************************************************************************************************************************/
