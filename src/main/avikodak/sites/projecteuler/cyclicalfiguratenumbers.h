/****************************************************************************************************************************************************
 *  File Name                   : cyclicalfiguratenumbers.h
 *  File Location               : D:\projects\cpp\algos_v2\src\main\avikodak\sites\projecteuler\cyclicalfiguratenumbers.h
 *  Created on                  : Aug 22, 2015 :: 6:14:56 PM
 *  Author                      : avikodak
 *  Testing Status              : Tested
 *  URL                         : https://projecteuler.net/problem=61
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

#ifndef CYCLICALFIGURATENUMBERS_H_
#define CYCLICALFIGURATENUMBERS_H_

//Tested
struct valueType{
	unsigned int value;
	unsigned int type;

	valueType(){}

	valueType(unsigned int value,unsigned int type){
		this->value = value;
		this->type = type;
	}
};

//Tested
unsigned int getTriangleNumber(unsigned int userInput){
	return ((userInput)*(userInput+1))/2;
}

//Tested
unsigned int getSquareNumber(unsigned int userInput){
	return userInput * userInput;
}

//Tested
unsigned int getPentagonalNumber(unsigned int userInput){
	return (userInput*(3*userInput-1))/2;
}

//Tested
unsigned int getHexagonalNumber(unsigned int userInput){
	return (userInput)*(2*userInput-1);
}

//Tested
unsigned int getHeptagonalNumber(unsigned int userInput){
	return ((userInput) * (5*userInput-3))/2;
}

//Tested
unsigned int getOctagonalNumber(unsigned int userInput){
	return (userInput)*(3*userInput-2);
}

//Tested
//Ans : 28684
void getSumOfCyclicFigurateNumber(){
	map<unsigned int,vector<valueType *> > firstTwoDigitNumbersMap;
	map<unsigned int,vector<valueType *> >::iterator itToFirstTwoDigitNumbersMap,itFirst,itSecond,itThird,itFourth,itFifth;
	vector<valueType *> firstList,secondList,thirdList,fourthList,fifthList;
	unsigned int counter = 1;
	unsigned int squareNumber,pentagonalNumber,hexagonalNumber,heptagonalNumber,octagonalNumber,triangleNumber;
	while(getOctagonalNumber(counter) < 999){
		counter++;
	}
	while(true){
		triangleNumber = getTriangleNumber(counter);
		squareNumber = getSquareNumber(counter);
		pentagonalNumber = getPentagonalNumber(counter);
		hexagonalNumber = getHexagonalNumber(counter);
		heptagonalNumber = getHeptagonalNumber(counter);
		octagonalNumber = getOctagonalNumber(counter);
		if(squareNumber > 999 && (itToFirstTwoDigitNumbersMap = firstTwoDigitNumbersMap.find(squareNumber/100)) != firstTwoDigitNumbersMap.end()){
			itToFirstTwoDigitNumbersMap->second.push_back(new valueType(squareNumber,1));
		}else if(squareNumber > 999){
			vector<valueType *> valueTypeList;
			valueTypeList.push_back(new valueType(squareNumber,1));
			firstTwoDigitNumbersMap.insert(pair<unsigned int,vector<valueType *> >(squareNumber/100,valueTypeList));
		}
		if(pentagonalNumber > 999 && (itToFirstTwoDigitNumbersMap = firstTwoDigitNumbersMap.find(pentagonalNumber/100)) != firstTwoDigitNumbersMap.end()){
			itToFirstTwoDigitNumbersMap->second.push_back(new valueType(pentagonalNumber,2));
		}else if(pentagonalNumber > 999){
			vector<valueType *> valueTypeList;
			valueTypeList.push_back(new valueType(pentagonalNumber,2));
			firstTwoDigitNumbersMap.insert(pair<unsigned int,vector<valueType *> >(pentagonalNumber/100,valueTypeList));
		}
		if(hexagonalNumber > 999 && (itToFirstTwoDigitNumbersMap = firstTwoDigitNumbersMap.find(hexagonalNumber/100)) != firstTwoDigitNumbersMap.end()){
			itToFirstTwoDigitNumbersMap->second.push_back(new valueType(hexagonalNumber,3));
		}else if(hexagonalNumber > 999){
			vector<valueType *> valueTypeList;
			valueTypeList.push_back(new valueType(hexagonalNumber,3));
			firstTwoDigitNumbersMap.insert(pair<unsigned int,vector<valueType *> >(hexagonalNumber/100,valueTypeList));
		}
		if(heptagonalNumber > 999 && (itToFirstTwoDigitNumbersMap = firstTwoDigitNumbersMap.find(heptagonalNumber/100)) != firstTwoDigitNumbersMap.end()){
			itToFirstTwoDigitNumbersMap->second.push_back(new valueType(heptagonalNumber,4));
		}else if(heptagonalNumber > 999){
			vector<valueType *> valueTypeList;
			valueTypeList.push_back(new valueType(heptagonalNumber,4));
			firstTwoDigitNumbersMap.insert(pair<unsigned int,vector<valueType *> >(heptagonalNumber/100,valueTypeList));
		}
		if(octagonalNumber > 999 && (itToFirstTwoDigitNumbersMap = firstTwoDigitNumbersMap.find(octagonalNumber/100)) != firstTwoDigitNumbersMap.end()){
			itToFirstTwoDigitNumbersMap->second.push_back(new valueType(octagonalNumber,5));
		}else if(octagonalNumber > 999){
			vector<valueType *> valueTypeList;
			valueTypeList.push_back(new valueType(octagonalNumber,5));
			firstTwoDigitNumbersMap.insert(pair<unsigned int,vector<valueType *> >(octagonalNumber/100,valueTypeList));
		}
		if(triangleNumber > 999 && (itFirst = firstTwoDigitNumbersMap.find(triangleNumber%100)) != firstTwoDigitNumbersMap.end()){
			bool flags[6] = {false};
			firstList = itFirst->second;
			flags[0] = true;
			for(unsigned int firstCounter = 0;firstCounter < firstList.size();firstCounter++){
				if(!flags[firstList[firstCounter]->type] && (itSecond = firstTwoDigitNumbersMap.find(firstList[firstCounter]->value%100)) != firstTwoDigitNumbersMap.end()){
					secondList = itSecond->second;
					flags[firstList[firstCounter]->type] = true;
					for(unsigned int secondCounter = 0;secondCounter < secondList.size();secondCounter++){
						if(!flags[secondList[secondCounter]->type] && (itThird = firstTwoDigitNumbersMap.find(secondList[secondCounter]->value%100)) != firstTwoDigitNumbersMap.end()){
							thirdList = itThird->second;
							flags[secondList[secondCounter]->type] = true;
							for(unsigned int thirdCounter = 0;thirdCounter < thirdList.size();thirdCounter++){
								if(!flags[thirdList[thirdCounter]->type] && (itFourth = firstTwoDigitNumbersMap.find(thirdList[thirdCounter]->value%100)) != firstTwoDigitNumbersMap.end()){
									fourthList = itFourth->second;
									flags[thirdList[thirdCounter]->type] = true;
									for(unsigned int fourthCounter = 0;fourthCounter < fourthList.size();fourthCounter++){
										if(!flags[fourthList[fourthCounter]->type] && (itFifth = firstTwoDigitNumbersMap.find(fourthList[fourthCounter]->value%100))!=firstTwoDigitNumbersMap.end()){
											fifthList = itFifth->second;
											flags[fourthList[fourthCounter]->type] = true;
											for(unsigned int fifthCounter = 0;fifthCounter < fifthList.size();fifthCounter++){
												if(!flags[fifthList[fifthCounter]->type] && fifthList[fifthCounter]->value%100 == triangleNumber/100){
													cout << triangleNumber + firstList[firstCounter]->value + secondList[secondCounter]->value + thirdList[thirdCounter]->value + fourthList[fourthCounter]->value + fifthList[fifthCounter]->value << endl;
													return;
												}
											}
											flags[fourthList[fourthCounter]->type] = false;
										}
									}
									flags[thirdList[thirdCounter]->type] = false;
								}
							}
							flags[secondList[secondCounter]->type] = false;
						}
					}
					flags[firstList[firstCounter]->type] = false;
				}
			}
		}
		if(triangleNumber > 999 && (itToFirstTwoDigitNumbersMap = firstTwoDigitNumbersMap.find(triangleNumber/100)) != firstTwoDigitNumbersMap.end()){
			itToFirstTwoDigitNumbersMap->second.push_back(new valueType(triangleNumber,0));
		}else if(triangleNumber > 999){
			vector<valueType *> valueTypeList;
			valueTypeList.push_back(new valueType(triangleNumber,0));
			firstTwoDigitNumbersMap.insert(pair<unsigned int,vector<valueType *> >(triangleNumber/100,valueTypeList));
		}
		if(triangleNumber > 9999){
			break;
		}
		counter++;
	}
}

#endif /* CYCLICALFIGURATENUMBERS_H_ */

/****************************************************************************************************************************************************/
/*                                                               MAIN CODE END                                                                      */
/****************************************************************************************************************************************************/
