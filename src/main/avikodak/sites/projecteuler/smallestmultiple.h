/****************************************************************************************************************************************************
 *  File Name                   : smallestmultiple.h
 *  File Location               : D:\projects\cpp\algos_v2\src\main\avikodak\sites\projecteuler\smallestmultiple.h
 *  Created on                  : Jul 28, 2015 :: 10:05:41 PM
 *  Author                      : avikodak
 *  Testing Status              : Tested
 *  URL                         : https://projecteuler.net/problem=5
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

#ifndef SMALLESTMULTIPLE_H_
#define SMALLESTMULTIPLE_H_

//Tested
long long int gcd(long long int firstUserInput,long long int secondUserInput){
	if(firstUserInput == 1 || secondUserInput == 1){
		return 1;
	}
	if(secondUserInput%firstUserInput == 0){
		return firstUserInput;
	}
	return gcd(secondUserInput%firstUserInput,firstUserInput);
}

//Tested
long long int lcm(long long int first,long long int second){
	return (first*second)/gcd(first,second);
}

//Tested
//232792560
long long int lcm(vector<long long int> userInputs){
	if(userInputs.size() < 2){
		return 0;
	}
	long long int lcm = (userInputs[0]*userInputs[1])/gcd(userInputs[0],userInputs[1]);
	for(unsigned int counter = 2;counter < userInputs.size();counter++){
		lcm = (lcm * userInputs[counter])/(gcd(userInputs[counter],lcm));
	}
	return lcm;
}

#endif /* SMALLESTMULTIPLE_H_ */

/****************************************************************************************************************************************************/
/*                                                               MAIN CODE END                                                                      */
/****************************************************************************************************************************************************/
