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
