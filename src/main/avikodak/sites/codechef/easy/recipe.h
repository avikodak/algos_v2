/****************************************************************************************************************************************************
 *  File Name                   : recipe.h
 *  File Location               : \algos_v2\src\main\avikodak\sites\codechef\easy\recipe.h
 *  Created on                  : Feb 9, 2015 :: 10:13:41 AM
 *  Author                      : avikodak
 *  Testing Status              : Tested
 *  URL                         : http://www.codechef.com/problems/RECIPE
****************************************************************************************************************************************************/

/****************************************************************************************************************************************************/
/*                                                         NAMESPACE DECLARATION AND IMPORTS                                                             */
/****************************************************************************************************************************************************/

using namespace std;
using namespace __gnu_cxx;

/****************************************************************************************************************************************************/
/*                                                                 INCLUDES                                                                             */
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
/*                                                             USER DEFINED CONSTANTS                                                                     */
/****************************************************************************************************************************************************/

/****************************************************************************************************************************************************/
/*                                                                 MAIN CODE START                                                                     */
/****************************************************************************************************************************************************/

#ifndef RECIPE_H_
#define RECIPE_H_

//Tested
int gcd(int firstUserInput,int secondUserInput) {
    if(firstUserInput == 1 || secondUserInput == 1) {
        return 1;
    }
    if(secondUserInput % firstUserInput == 0) {
        return firstUserInput;
    }
    return gcd(secondUserInput%firstUserInput,firstUserInput);
}

//Tested
int gcdOfSequence(vector<int> userInput) {
    if(userInput.size() == 1) {
        return userInput[0];
    }
    int result;
    result = gcd(userInput[0],userInput[1]);
    for(unsigned int counter = 2; counter < userInput.size(); counter++) {
        result = gcd(result,userInput[counter]);
    }
    return result;
}

//Tested
void reduceRecipe() {
    int testCases,input,size,gcd;
    scanf("%d",&testCases);
    vector<int> userInput;
    while(testCases--) {
        scanf("%d",&size);
        userInput.clear();
        while(size--) {
            scanf("%d",&input);
            userInput.push_back(input);
        }
        gcd = gcdOfSequence(userInput);
        for(unsigned int counter = 0; counter < userInput.size(); counter++) {
            printf("%d\t",userInput[counter]/gcd);
        }
        printf("\n");
    }
}

#endif /* RECIPE_H_ */

/****************************************************************************************************************************************************/
/*                                                                 MAIN CODE END                                                                         */
/****************************************************************************************************************************************************/
