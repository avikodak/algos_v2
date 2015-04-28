/****************************************************************************************************************************************************
 *  File Name                   : queueatschool.h
 *  File Location               : D:\projects\cpp\algos_v2\src\main\avikodak\sites\codeforces\queueatschool.h
 *  Created on                  : Apr 28, 2015 :: 12:25:07 AM
 *  Author                      : avikodak
 *  Testing Status              : Tested
 *  URL                         : http://codeforces.com/problemset/problem/266/B
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

#ifndef QUEUEATSCHOOL_H_
#define QUEUEATSCHOOL_H_

//Tested
void getArrangement(){
	unsigned int people,noOfRounds;
	scanf("%u %u",&people,&noOfRounds);
	string userInput;
	cin >> userInput;
	for(unsigned int outerCounter = 0;outerCounter < noOfRounds;outerCounter++){
		for(unsigned int innerCounter = 0;innerCounter < userInput.size();){
			if(userInput[innerCounter] == 'B'){
				if(innerCounter+1 < userInput.size() && userInput[innerCounter+1] =='G'){
					swap(userInput[innerCounter],userInput[innerCounter+1]);
					innerCounter+= 2;
				}else{
					innerCounter++;
				}
			}else{
				innerCounter++;
			}
		}
	}
	for(unsigned int counter = 0;counter < userInput.size();counter++){
		printf("%c",userInput[counter]);
	}
}
#endif /* QUEUEATSCHOOL_H_ */

/****************************************************************************************************************************************************/
/*                                                               MAIN CODE END                                                                      */
/****************************************************************************************************************************************************/
