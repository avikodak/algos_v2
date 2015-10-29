/****************************************************************************************************************************************************
 *  File Name                   : modifiedkaprekarnumbers.h
 *  File Location               : /home/avikodak/Desktop/projects/algos_v2/src/main/avikodak/sites/hackerrank/implementation/modifiedkaprekarnumbers.h
 *  Created on                  : 28-Oct-2015 :: 6:44:19 pm
 *  Author                      : avikodak
 *  Testing Status              : Tested
 *  URL                         : https://www.hackerrank.com/challenges/kaprekar-numbers
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

#ifndef MODIFIEDKAPREKARNUMBERS_H_
#define MODIFIEDKAPREKARNUMBERS_H_

//Tested
vector<long long int> generateKaprekarNumbers(){
	long long int leftHalf,rightHalf,noOfDigits,result;
	vector<long long int> kaprekarNumbers;
	long long int tenPowers[] = {1,10,100,1000,10000,100000,1000000,10000000};
	for(long long int counter = 1;counter < 100001;counter++){
		noOfDigits = log10(counter)+1;
		result = counter*counter;
		rightHalf = result%tenPowers[noOfDigits];
		leftHalf = result/tenPowers[noOfDigits];
		if(leftHalf + rightHalf == counter){
			kaprekarNumbers.push_back(counter);
		}
	}
	return kaprekarNumbers;
}

//Tested
void printResults(){
	unsigned int kaprekarNumbers[] = {1,9,45,55,99,297,703,999,2223,2728,4950,5050,7272,7777,9999,17344,22222,77778,82656,95121,99999};
	unsigned int startNumber,endNumbers;
	scanf("%u %u",&startNumber,&endNumbers);
	bool isPresent = false;
	for(unsigned int counter = 0;counter < sizeof(kaprekarNumbers)/sizeof(unsigned int);counter++){
		if(kaprekarNumbers[counter] >= startNumber && kaprekarNumbers[counter] <= endNumbers){
			printf("%u ",kaprekarNumbers[counter]);
			isPresent = true;
		}
	}
	if(!isPresent){
		printf("INVALID RANGE");
	}
}

#endif /* MODIFIEDKAPREKARNUMBERS_H_ */

/****************************************************************************************************************************************************/
/*                                                               MAIN CODE END                                                                      */
/****************************************************************************************************************************************************/
