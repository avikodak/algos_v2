/****************************************************************************************************************************************************
 *  File Name                   : dpc101.h
 *  File Location               : /home/avikodak/Desktop/projects/algos_v2/src/main/avikodak/sites/codechef/peer/dpc101.h
 *  Created on                  : 12-Sep-2015 :: 5:56:07 pm
 *  Author                      : avikodak
 *  Testing Status              : Tested
 *  URL                         : https://www.codechef.com/problems/DPC101
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

/****************************************************************************************************************************************************/
/*                                                             MAIN CODE START                                                                      */
/****************************************************************************************************************************************************/

#ifndef DPC101_H_
#define DPC101_H_

//Tested
void printTotalCarryOperations(long long int firstUserInput,long long int secondUserInput){
	long long int carry = 0,operations = 0,sum;
	while(firstUserInput > 0 || secondUserInput > 0){
		sum = (firstUserInput%10) + (secondUserInput%10) + carry;
		if(sum > 9){
			operations++;
		}
		carry = sum/10;
		firstUserInput /= 10;
		secondUserInput /= 10;
	}
	if(operations == 0){
		printf("No carry operation.\n");
	}else if(operations == 1){
		printf("%lld carry operation.\n",operations);
	}else{
		printf("%lld carry operations.\n",operations);
	}
}

//Tested
void printResults(){
	long long int firstUserInput,secondUserInput;
	while(scanf("%lld",&firstUserInput) && scanf("%lld",&secondUserInput) && firstUserInput != 0 && secondUserInput != 0){
		printTotalCarryOperations(firstUserInput,secondUserInput);
	}
}

#endif /* DPC101_H_ */

/****************************************************************************************************************************************************/
/*                                                               MAIN CODE END                                                                      */
/****************************************************************************************************************************************************/
