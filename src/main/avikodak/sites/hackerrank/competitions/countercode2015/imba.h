/****************************************************************************************************************************************************
 *  File Name                   : imba.h
 *  File Location               : D:\projects\cpp\algos_v2\src\main\avikodak\sites\hackerrank\competitions\countercode2015\imba.h
 *  Created on                  : Aug 2, 2015 :: 12:03:36 PM
 *  Author                      : avikodak
 *  Testing Status              : TODO
 *  URL                         : https://www.hackerrank.com/contests/countercode/challenges/imba
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

#ifndef IMBA_H_
#define IMBA_H_

void printImbaFormat(unsigned int userInput){
	int backToFront = userInput/2,frontToBack = (userInput/2)+1;
	if(userInput%2 == 1){
		printf("%u ",(userInput/2)+1);
		frontToBack = (userInput/2)+2;
	}
	while(backToFront > 0){
		printf("%u %u",backToFront+1,frontToBack+1);
		backToFront--;
		frontToBack++;
	}
	printf("\n");
}

void getImbaFormat(){
	unsigned int testCases,userInput;
	scanf("%u",&testCases);
	while(testCases--){
		scanf("%u",&userInput);
		printImbaFormat(userInput);
	}
}

#endif /* IMBA_H_ */

/****************************************************************************************************************************************************/
/*                                                               MAIN CODE END                                                                      */
/****************************************************************************************************************************************************/
