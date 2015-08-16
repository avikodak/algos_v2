/****************************************************************************************************************************************************
 *  File Name                   : distinctpowers.h
 *  File Location               : D:\projects\cpp\algos_v2\src\main\avikodak\sites\projecteuler\distinctpowers.h
 *  Created on                  : Aug 15, 2015 :: 7:48:52 PM
 *  Author                      : avikodak
 *  Testing Status              : Tested
 *  URL                         : https://projecteuler.net/problem=29
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

#ifndef DISTINCTPOWERS_H_
#define DISTINCTPOWERS_H_

//Tested
map<unsigned int,unsigned int> primeFactorization(unsigned int userInput){
	unsigned int squareRoot = sqrtl(userInput);
	map<unsigned int,unsigned int> factorsCounter;
	map<unsigned int,unsigned int>::iterator itToFactorsCount;
	bool flag = true;
	while(flag && userInput > 1){
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
		for(unsigned int counter = 3;counter <= squareRoot;counter+=2){
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
		if(!flag){
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
string convertToString(unsigned int userInput){
	stringstream stream;
	stream << userInput;
	string str = stream.str();
	stream.str("");
	return str;
}

//Tested
string getStringValuePrimeFactorization(map<unsigned int,unsigned int> &primeFactorization,unsigned int userInput){
	map<unsigned int,unsigned int>::iterator itToPrimeFactorization;
	string result;
	for(itToPrimeFactorization = primeFactorization.begin();itToPrimeFactorization != primeFactorization.end();itToPrimeFactorization++){
		result.append(convertToString(itToPrimeFactorization->first));
		result.append("&&");
		result.append(convertToString(userInput*itToPrimeFactorization->second));
		result.append("$$");
	}
	return result;
}

//Tested
void generateStringValue(map<unsigned int,unsigned int> primeFactorization,map<string,bool> &distinctPowers){
	string result;
	for(unsigned int counter = 2;counter <= 100;counter++){
		result = getStringValuePrimeFactorization(primeFactorization,counter);
		if(distinctPowers.find(result) == distinctPowers.end()){
			distinctPowers.insert(pair<string,bool>(result,true));
		}
	}
}

//Tested
//Ans : 9183
void printDistinctPowers(){
	map<string,bool> distinctPowers;
	for(unsigned int counter = 2;counter <= 100;counter++){
		generateStringValue(primeFactorization(counter),distinctPowers);
	}
	cout << distinctPowers.size() << endl;
}

#endif /* DISTINCTPOWERS_H_ */

/****************************************************************************************************************************************************/
/*                                                               MAIN CODE END                                                                      */
/****************************************************************************************************************************************************/
