/****************************************************************************************************************************************************
 *  File Name                   : longestcollatzsequence.h
 *  File Location               : D:\projects\cpp\algos_v2\src\main\avikodak\sites\projecteuler\longestcollatzsequence.h
 *  Created on                  : Aug 1, 2015 :: 2:31:43 PM
 *  Author                      : avikodak
 *  Testing Status              : Tested
 *  URL                         : https://projecteuler.net/problem=14
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

#ifndef LONGESTCOLLATZSEQUENCE_H_
#define LONGESTCOLLATZSEQUENCE_H_

//Tested
unsigned long long int computeLengthCollatzSequence(map<unsigned int,unsigned long long int> &auxSpace,unsigned int value){
	if(value == 1){
		return 1;
	}
	map<unsigned int,unsigned long long int>::iterator itToAuxSpace;
	if((itToAuxSpace = auxSpace.find(value)) != auxSpace.end()){
		return itToAuxSpace->second;
	}
	unsigned long long int length;
	if(value%2 == 0){
		length =  1 + computeLengthCollatzSequence(auxSpace,value/2);
	}else{
		length = 1 + computeLengthCollatzSequence(auxSpace,3*value+1);
	}
	auxSpace.insert(pair<unsigned int,unsigned long long int>(value,length));
	return length;
}

//Tested
//Ans : 837799
void printLongestCollatzSequence(unsigned int limit){
	map<unsigned int,unsigned long long int> auxSpace;
	unsigned long long int maxLength = 0,result;
	unsigned int startingNumber = 1;
	for(unsigned int counter = 2;counter <= limit;counter++){
		result = computeLengthCollatzSequence(auxSpace,counter);
		if(result > maxLength){
			maxLength = result;
			startingNumber = counter;
		}
	}
	cout << startingNumber << endl;
}

#endif /* LONGESTCOLLATZSEQUENCE_H_ */

/****************************************************************************************************************************************************/
/*                                                               MAIN CODE END                                                                      */
/****************************************************************************************************************************************************/
