/****************************************************************************************************************************************************
 *  File Name                   : subgcd.h
 *  File Location               : /home/avikodak/eclipse_ws/algos/algos/src/main/avikodak/sites/codechef/easy/subgcd.h
 *  Created on                  : 08-Sep-2015 :: 10:20:39 am
 *  Author                      : avikodak
 *  Testing Status              : Tested
 *  URL                         : https://www.codechef.com/problems/SUBGCD
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

#ifndef SUBGCD_H_
#define SUBGCD_H_

//Tested
unsigned int gcd(unsigned int a,unsigned int b){
	return b == 0?a:gcd(b,a%b);
}

//Tested
void printsubgcd(vector<unsigned int> userInput){
	unsigned int result = userInput[0];
	for(unsigned int counter = 1;counter < userInput.size();counter++){
		result = gcd(result,userInput[counter]);
	}
	if(result == 1){
		printf("%lu\n",userInput.size());
	}else{
		printf("-1\n");
	}
}

//Tested
void printResults(){
	unsigned int testCases,size,input;
	vector<unsigned int> userInput;
	scanf("%u",&testCases);
	while(testCases--){
		scanf("%u",&size);
		userInput.clear();
		while(size--){
			scanf("%u",&input);
			userInput.push_back(input);
		}
		printsubgcd(userInput);
	}
}


#endif /* SUBGCD_H_ */

/****************************************************************************************************************************************************/
/*                                                               MAIN CODE END                                                                      */
/****************************************************************************************************************************************************/
