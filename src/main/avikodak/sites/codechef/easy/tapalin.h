/****************************************************************************************************************************************************
 *  File Name                   : tapalin.h
 *  File Location               : /home/avikodak/Desktop/projects/algos_v2/src/main/avikodak/sites/codechef/easy/tapalin.h
 *  Created on                  : 15-Sep-2015 :: 10:43:14 pm
 *  Author                      : avikodak
 *  Testing Status              : TODO
 *  URL                         : https://www.codechef.com/problems/TAPALIN
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
#include <stdint.h>
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
#define MODN 10000009
/****************************************************************************************************************************************************/
/*                                                             MAIN CODE START                                                                      */
/****************************************************************************************************************************************************/

#ifndef TAPALIN_H_
#define TAPALIN_H_

//Tested
long long int getPossibilitiesForLength(long long int userInput,map<long long int,long long int> &auxSpace){
	if(userInput <= 0){
		return 0;
	}
	if(auxSpace.find(userInput) != auxSpace.end()){
		return auxSpace.find(userInput)->second;
	}
	long long int result;
	for(long long int counter = 1;counter <= userInput;counter++){
		if(auxSpace.find(counter) == auxSpace.end()){
			result =  (26*auxSpace[counter-2])%MODN;
			auxSpace.insert(pair<long long int,long long int>(counter,result));
		}
	}

	return result;
}

//Tested
long long int getTotalPalindromes(long long int userInput,map<long long int,long long int> &totalPalindromes,map<long long int,long long int> &auxSpace){
	if(userInput <= 0){
		return 0;
	}
	if(totalPalindromes.find(userInput) != totalPalindromes.end()){
		return totalPalindromes.find(userInput)->second;
	}
	long long result;
	for(long long int counter = 1;counter <= userInput;counter++){
		if(auxSpace.find(counter) == auxSpace.end()){
			result = (getPossibilitiesForLength(counter,auxSpace) + totalPalindromes[counter-1])%MODN;
			totalPalindromes.insert(pair<long long int,long long int>(counter,result));
		}
	}
	return result;
}

//Tested
//Takes more time
void printResults2(){
	map<long long int,long long int> auxSpace,totalPalindromes;
	auxSpace.insert(pair<long long int,long long int>(0,0));
	auxSpace.insert(pair<long long int,long long int>(1,26));
	auxSpace.insert(pair<long long int,long long int>(2,26));
	totalPalindromes.insert(pair<long long int,long long int>(0,0));
	totalPalindromes.insert(pair<long long int,long long int>(1,26));
	totalPalindromes.insert(pair<long long int,long long int>(2,52));
	unsigned int testCases;
	scanf("%u",&testCases);
	long long int userInput;
	while(testCases--){
		scanf("%lld",&userInput);
		cout << getTotalPalindromes(userInput,totalPalindromes,auxSpace) << endl;
	}
}



#endif /* TAPALIN_H_ */

/****************************************************************************************************************************************************/
/*                                                               MAIN CODE END                                                                      */
/****************************************************************************************************************************************************/
