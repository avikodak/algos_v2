/****************************************************************************************************************************************************
 *  File Name                   : alk1105.h
 *  File Location               : /home/avikodak/Desktop/projects/algos_v2/src/main/avikodak/sites/codechef/peer/alk1105.h
 *  Created on                  : 24-Sep-2015 :: 12:02:33 am
 *  Author                      : avikodak
 *  Testing Status              : TODO
 *  URL                         : https://www.codechef.com/problems/ALK1105
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
#define LIMIT 10000000
/****************************************************************************************************************************************************/
/*                                                             MAIN CODE START                                                                      */
/****************************************************************************************************************************************************/

#ifndef ALK1105_H_
#define ALK1105_H_

vector<unsigned int> initialize(){
	vector<unsigned int> divisorSum;
	divisorSum.assign(LIMIT+1,1);
	unsigned int innerCounter;
	for(unsigned int outerCounter = 2;outerCounter <= LIMIT/2;outerCounter++){
		innerCounter = 1;
		while(outerCounter*innerCounter < LIMIT){
			divisorSum[outerCounter*innerCounter] += outerCounter;
			innerCounter++;
		}
	}
	for(unsigned int counter = 1;counter < divisorSum.size();counter++){
		divisorSum[counter] += divisorSum[counter-1];
	}
	return divisorSum;
}

void printResults(){
	vector<unsigned int> sumOfDivisors = init();
	unsigned int testCases,input;
	scanf("%u",&testCases);
	while(testCases--){
		scanf("%u",&input);
		cout << sumOfDivisors[input] << endl;
	}
}

#endif /* ALK1105_H_ */

/****************************************************************************************************************************************************/
/*                                                               MAIN CODE END                                                                      */
/****************************************************************************************************************************************************/
