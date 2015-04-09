/****************************************************************************************************************************************************
 *  File Name                   : gravityflip.h
 *  File Location               : D:\projects\cpp\algos_v2\src\main\avikodak\sites\codeforces\gravityflip.h
 *  Created on                  : Apr 8, 2015 :: 9:54:14 AM
 *  Author                      : avikodak
 *  Testing Status              : Tested
 *  URL                         : http://codeforces.com/problemset/problem/405/A
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

#ifndef GRAVITYFLIP_H_
#define GRAVITYFLIP_H_

//Tested
void postGravityFlip(){
	unsigned int testCases;
	scanf("%u",&testCases);
	vector<unsigned int> userInput;
	unsigned int input;
	while(testCases--){
		scanf("%u",&input);
		userInput.push_back(input);
	}
	sort(userInput.begin(),userInput.end());
	for(unsigned int counter = 0;counter < userInput.size();counter++){
		printf("%u",userInput[counter]);
	}
}

#endif /* GRAVITYFLIP_H_ */

/****************************************************************************************************************************************************/
/*                                                               MAIN CODE END                                                                      */
/****************************************************************************************************************************************************/
