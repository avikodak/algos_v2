/****************************************************************************************************************************************************
 *  File Name                   : axr3p3.h
 *  File Location               : /home/avikodak/Desktop/projects/algos_v2/src/main/avikodak/sites/codechef/peer/axr3p3.h
 *  Created on                  : 17-Oct-2015 :: 5:23:02 pm
 *  Author                      : avikodak
 *  Testing Status              : Tested
 *  URL                         : https://www.codechef.com/problems/AXR3P3
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

#ifndef AXR3P3_H_
#define AXR3P3_H_

//Tested
void printResults() {
    unsigned int testCases;
    string userInput;
    scanf("%u",&testCases);
    stack<char> operators;
    map<char,unsigned int> precedenceMap;
    precedenceMap.insert(pair<char,unsigned int>('(',0));
    precedenceMap.insert(pair<char,unsigned int>('+',1));
    precedenceMap.insert(pair<char,unsigned int>('-',2));
    precedenceMap.insert(pair<char,unsigned int>('*',3));
    precedenceMap.insert(pair<char,unsigned int>('/',4));
    precedenceMap.insert(pair<char,unsigned int>('^',5));
    while(testCases--) {
        cin >> userInput;
        for(unsigned int counter = 0; counter < userInput.size(); counter++) {
            if(userInput[counter] == '(') {
                operators.push('(');
            } else if(userInput[counter] == ')') {
                while(!operators.empty() && operators.top() != '(') {
                    printf("%c",operators.top());
                    operators.pop();
                }
                operators.pop();
            } else if(userInput[counter] == '+' || userInput[counter] == '-' || userInput[counter] == '*' || userInput[counter] == '/' || userInput[counter] == '^') {
                while(!operators.empty() && precedenceMap.find(userInput[counter])->second < precedenceMap.find(operators.top())->second) {
                    printf("%c",operators.top());
                    operators.pop();
                }
                operators.push(userInput[counter]);
            } else if(isalpha(userInput[counter])) {
                printf("%c",userInput[counter]);
            }
        }
        while(!operators.empty()) {
            if(operators.top() != '(') {
                printf("%c",operators.top());
            }
            operators.pop();
        }
        printf("\n");
    }
}

#endif /* AXR3P3_H_ */

/****************************************************************************************************************************************************/
/*                                                               MAIN CODE END                                                                      */
/****************************************************************************************************************************************************/
