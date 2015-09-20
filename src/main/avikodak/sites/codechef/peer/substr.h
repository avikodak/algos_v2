/****************************************************************************************************************************************************
 *  File Name                   : substr.h
 *  File Location               : /home/avikodak/Desktop/projects/algos_v2/src/main/avikodak/sites/codechef/peer/substr.h
 *  Created on                  : 20-Sep-2015 :: 10:39:30 am
 *  Author                      : avikodak
 *  Testing Status              : Tested
 *  URL                         : https://www.codechef.com/problems/SUBSTR
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
#include <iomanip>
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

#ifndef SUBSTR_H_
#define SUBSTR_H_

//Tested
string convert(unsigned int userInput){
	stringstream stream;
	stream << userInput;
	return stream.str();
}

//Tested
void countOccurence(unsigned int N,unsigned int K){
	string needle = convert(K);
	string hayStack;
	for(unsigned int counter = 1;counter <= N;counter++){
		hayStack.append(convert(counter));
	}
	size_t position = hayStack.find(needle);
	unsigned int occurences = 0;
	while(position != string::npos){
		occurences++;
		position = hayStack.find(needle,position+1);
	}
	cout << occurences << endl;
}

//Tested
//Slow check java version
void printResults(){
	unsigned int testCases,N,K;
	scanf("%u",&testCases);
	while(testCases--){
		scanf("%u %u",&N,&K);
		countOccurence(N,K);
	}
}

#endif /* SUBSTR_H_ */

/****************************************************************************************************************************************************/
/*                                                               MAIN CODE END                                                                      */
/****************************************************************************************************************************************************/
