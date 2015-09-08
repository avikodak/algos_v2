/****************************************************************************************************************************************************
 *  File Name                   : printpermutation.h
 *  File Location               : D:\projects\cpp\algos_v2\src\main\avikodak\sites\projecteuler\printpermutation.h
 *  Created on                  : Aug 16, 2015 :: 12:43:20 PM
 *  Author                      : avikodak
 *  Testing Status              : Tested
 *  URL                         : https://projecteuler.net/problem=49
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
#include <strings.h>
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

#ifndef PRINTPERMUTATION_H_
#define PRINTPERMUTATION_H_

//Tested
map<unsigned int,bool> generatePrimeNumberMap(unsigned int start,unsigned int end){
	vector<bool> flags;
	flags.assign(end+2,true);
	map<unsigned int,bool> primeNumberMap;
	for(unsigned int counter = 2;counter <= end;counter++){
		if(flags[counter]){
			unsigned int innerCounter = 2;
			while(counter*innerCounter <= end){
				flags[counter*innerCounter] = false;
				innerCounter+=1;
			}
		}
	}
	for(unsigned int counter = start;counter <= end;counter++){
		if(flags[counter]){
			primeNumberMap.insert(pair<unsigned int,bool>(counter,true));
		}
	}
	return primeNumberMap;
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
map<unsigned int,bool> getValuesMap(vector<unsigned int> userInput){
	map<unsigned int,bool> valuesMap;
	for(unsigned int counter = 0;counter < userInput.size();counter++){
		valuesMap.insert(pair<unsigned int,bool>(userInput[counter],true));
	}
	return valuesMap;
}

//Tested
void printIncreasingLength(map<string,vector<unsigned int> > permutationList){
	map<unsigned int,bool> valuesMap;
	map<string,vector<unsigned int> >::iterator itToPermutationList;
	vector<unsigned int> values;
	unsigned int difference;
	for(itToPermutationList = permutationList.begin();itToPermutationList != permutationList.end();itToPermutationList++){
		valuesMap = getValuesMap(itToPermutationList->second);
		values = itToPermutationList->second;
		for(unsigned int outerCounter = 0;outerCounter < values.size()-1;outerCounter++){
			if(values[outerCounter] == 1487){
				continue;
			}
			for(unsigned int innerCounter = outerCounter+1;innerCounter < values.size();innerCounter++){
				difference = values[innerCounter] - values[outerCounter];
				cout << difference << endl;
				if(valuesMap.find(values[innerCounter]+difference) != valuesMap.end()){
					cout << values[outerCounter] << values[innerCounter]  << difference+values[innerCounter] << endl;
					return;
				}
			}
		}
	}
}

//Tested
//Ans : 296962999629
void printPermutation(){
	map<unsigned int,bool> primeNumberMap = generatePrimeNumberMap(1000,9999);
	map<unsigned int,bool>::iterator itToPrimeNumberMap;
	map<string,vector<unsigned int> > permutationList;
	map<string,vector<unsigned int> >::iterator itToPermutaionList;
	for(itToPrimeNumberMap = primeNumberMap.begin();itToPrimeNumberMap != primeNumberMap.end();itToPrimeNumberMap++){
		string strValue = convertToString(itToPrimeNumberMap->first);
		sort(strValue.begin(),strValue.end());
		if((itToPermutaionList = permutationList.find(strValue)) != permutationList.end()){
			itToPermutaionList->second.push_back(itToPrimeNumberMap->first);
		}else{
			vector<unsigned int> list;
			list.push_back(itToPrimeNumberMap->first);
			permutationList.insert(pair<string,vector<unsigned int> >(strValue,list));
		}
	}
	printIncreasingLength(permutationList);
}

#endif /* PRINTPERMUTATION_H_ */

/****************************************************************************************************************************************************/
/*                                                               MAIN CODE END                                                                      */
/****************************************************************************************************************************************************/
