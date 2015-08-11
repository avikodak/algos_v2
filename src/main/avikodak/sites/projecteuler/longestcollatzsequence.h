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
