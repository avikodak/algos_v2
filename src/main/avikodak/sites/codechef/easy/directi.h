/****************************************************************************************************************************************************
 *  File Name                   : directi.h
 *  File Location               : /home/avikodak/eclipse_ws/algos/algos/src/main/avikodak/sites/codechef/easy/directi.h
 *  Created on                  : 08-Sep-2015 :: 9:55:22 pm
 *  Author                      : avikodak
 *  Testing Status              : Tested
 *  URL                         : https://www.codechef.com/problems/DIRECTI
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

#ifndef DIRECTI_H_
#define DIRECTI_H_

//Tested
void reverseDirections() {
    unsigned int size;
    scanf("%u",&size);
    string userInput;
    getline(cin,userInput);
    stack<string> place,direction;
    while(size--) {
        getline(cin,userInput);
        if(userInput[0] == 'B'||userInput[0] == 'b') {
            place.push(userInput.substr(9));
        } else if(userInput[0] == 'L' || userInput[0] == 'l') {
            place.push(userInput.substr(8));
            direction.push("Right on ");
        } else if(userInput[0] == 'R' || userInput[0] == 'r') {
            place.push(userInput.substr(9));
            direction.push("Left on ");
        }
    }
    cout << "Begin on " << place.top() << endl;
    place.pop();
    while(!place.empty()) {
        cout << direction.top() << place.top() << endl;
        place.pop();
        direction.pop();
    }
}

//Tested
void printResults() {
    unsigned int testCases;
    scanf("%u",&testCases);
    while(testCases--) {
        reverseDirections();
    }
}

#endif /* DIRECTI_H_ */

/****************************************************************************************************************************************************/
/*                                                               MAIN CODE END                                                                      */
/****************************************************************************************************************************************************/
