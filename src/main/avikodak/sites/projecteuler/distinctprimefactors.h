/****************************************************************************************************************************************************
 *  File Name                   : distinctprimefactors.h
 *  File Location               : D:\projects\cpp\algos_v2\src\main\avikodak\sites\projecteuler\distinctprimefactors.h
 *  Created on                  : Aug 18, 2015 :: 9:02:45 PM
 *  Author                      : avikodak
 *  Testing Status              : Tested
 *  URL                         : https://projecteuler.net/problem=47
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

#ifndef DISTINCTPRIMEFACTORS_H_
#define DISTINCTPRIMEFACTORS_H_

//Tested
map<unsigned long long int,unsigned long long int> primeFactorization(unsigned long long int userInput){
	unsigned long long int squareRoot = sqrtl(userInput);
	map<unsigned long long int,unsigned long long int> factorsCounter;
	map<unsigned long long int,unsigned long long int>::iterator itToFactorsCount;
	bool flag = true;
	while(flag){
		flag = false;
		while(!(userInput&1)){
			if((itToFactorsCount = factorsCounter.find(2)) == factorsCounter.end()){
				factorsCounter[2] = 1;
			}else{
				factorsCounter[2]++;
			}
			flag = true;
			userInput /= 2;
		}
		for(unsigned long long int counter = 3;counter <= squareRoot;counter+=2){
			if(userInput%counter == 0){
				if(factorsCounter.find(counter) == factorsCounter.end()){
					factorsCounter[counter] = 1;
				}else{
					factorsCounter[counter]++;
				}
				flag = true;
				userInput /= counter;
				break;
			}
		}
		if(!flag && userInput != 1){
			if(factorsCounter.find(userInput) == factorsCounter.end()){
				factorsCounter[userInput] = 1;
			}else{
				factorsCounter[userInput]++;
			}
		}
	}
	return factorsCounter;
}

//Tested
//Ans : 134043
void findFirstFourDistinctPrimeFactors(){
	unsigned long long int counter = 2;
	unsigned int consecutiveCounter  = 0;
	map<unsigned long long int,unsigned long long int> primeFactors;
	map<unsigned long long int,unsigned long long int>::iterator itToPrimeFactors;
	while(true){
		primeFactors = primeFactorization(counter);
		if(primeFactors.size() == 4){
			consecutiveCounter++;
			if(consecutiveCounter == 4){
				cout << counter-3 << endl;
				return;
			}
		}else{
			consecutiveCounter = 0;
		}
		counter++;
	}
}

#endif /* DISTINCTPRIMEFACTORS_H_ */

/****************************************************************************************************************************************************/
/*                                                               MAIN CODE END                                                                      */
/****************************************************************************************************************************************************/
