/* Program name: main.cpp
 * Author: Chad Carmickle
 * Date last updated: 8/31/26
 * Purpose: Clocktype input into object. 
*/

/* Assignment: Module 2 Programming Assignment 1
Assignment: Time
You will be given a class clockType. This class holds time as it is displayed on a clock. 
An object of this class is one of two types: a 12-hour clock or a 24-hour clock. For all clocks, 
valid minutes and seconds are in the range of 0 - 59. For a 12-hour clock, hours are in the range 
from 1 - 12, and the time of day is set to AM or PM. For a 24-hour clock, the valid hours are in the range of 0 - 23.

You will write a program that gets times from the user. The time might fit any of the following formats: 

h:mm:ss AM
h:mm:ss PM
hh:mm:ss AM
hh:mm:ss PM
h:mm AM
h:mm PM
h:mm:ss
hh:mm:ss
h:mm
The formats that do not have an AM/PM represent times for a 24-hour clock. 
The AM/PM may be entered in uppercase or lowercase. Set up a loop that asks the user for a time. 
Validate the time using a regular expression, create a clockType object if the time is valid, 
and add the object to a vector of clockType objects. Otherwise, go back and get a new time from the user.
If the user enters the word quit then the program should display all the valid times in the vector and 
exit the program.
*/


/* 
 classroom50 autograde: 14/14
Test	Result	Score
Compile	PASS	1 / 1
Comment Test	PASS	1 / 1
Heading Test	PASS	1 / 1
Valgrind Test	PASS	1 / 1
Functionality Test	PASS	10 / 10
Status: classroom50 autograde: 14/14 (all tests passed)
 */

#include "clock.h" // Calls to the clock.h object. 
#include <regex> // Regex allows us to pull text from a string. 
#include <iostream> 
#include <string>
#include <vector>
#include <algorithm> // std::transform
#include <cctype>    // std::toupper

using std::string;
using std::cout;
using std::endl;
using std::cin;
using std::getline;
using std::vector;

// Changes the entered word into uppercase.
void ToUpper(string& text) {
    std::transform(
        text.begin(),
        text.end(),
        text.begin(),
        [](unsigned char c) {
            return static_cast<char>(std::toupper(c));
        }
    );
}

// Removes spaces and other whitespace from the beginning and end
// of a string.
void Trim(string& text) {
    text.erase(
        text.begin(),
        std::find_if(
            text.begin(),
            text.end(),
            [](unsigned char c) {
                return !std::isspace(c);
            }
        )
    );

    text.erase(
        std::find_if(
            text.rbegin(),
            text.rend(),
            [](unsigned char c) {
                return !std::isspace(c);
            }
        ).base(),
        text.end()
    );
}

int main() {
    //cout << "Program starting.";
    // Notes on the pattern:
    // - Hour can be 1 or 2 digits, 0-23 (we let the clockType constructor
    //   enforce the stricter 1-12 rule for 12-hour clocks)
    // - Minutes and seconds are always 2 digits (00-59)
    // - Seconds are optional
    // - AM/PM is optional, case-insensitive

    // This allows us to create a pattern we can use for all of the time abriviations. 
    /* 

    r                                 -> allows raw string literal. 
    ^                                 -> anchor to start of the string. 
   ([01]|?[0-9]|2[0-3])              -> this is the first group the first digit entered. This checks if the entered number is between 0-9, 10-19, 20-23 (Covers all 24- hours values plus single digit 12 hour values. )
   :                                  -> this seperates the group.  
   ([0-5][0-9])                       -> this is the start of group 2 minutes always two digits 00 to 59. 
   (?::([0-5][0-9]))?                 -> This part captures the group 3 which would be seconds. Set as opitional if no seconds are entered. 
   (?:\s*([AaPp][Mm]))?               -> This section captures the AM PM if eneted. 
   $                                  -> Ends the anchor of the string. 
   */

    static const std::regex pattern(
        R"(^([01]?[0-9]|2[0-3]):([0-5][0-9])(?::([0-5][0-9]))?(?:\s*([AaPp][Mm]))?$)",
        std::regex_constants::icase
    );

    // This is the creation of the clocktype object using a vector to store the times. 
    vector<clockType> clocks;
    // This vector is used alongside clocktypes to add true or flase when a clock is 24 vs 12 hours. Used to help display data. 
    vector<bool> is24Hour;

    // User's input. 
    string userInput;

    // user enters infinite loop to enter times, types "quit" to exit. 
    while (true) {
        if(!getline(cin, userInput)) { 
            break; 
        }

        // Remove spaces before and after the input.
        Trim(userInput);

        // Adds new variable to hold. 
        string command = userInput;
        // Makes quit Capital. 
        ToUpper(command);

        // If capital exists program. 
        if (command == "QUIT") {
            break;
        }

        // This will take each of the captured groups from usersInput and attempt to match them to the code below. 
        std::smatch match;

        // Ignore inputs that do not match the required format.
        if (!std::regex_match(userInput, match, pattern)) {
            continue;
        }

        int hour = std::stoi(match[1].str());
        int minute = std::stoi(match[2].str());

        int second = 0;

        if (match[3].matched) {
            second = std::stoi(match[3].str());
        }

        string ampm;

        if (match[4].matched) {
            ampm = match[4].str();
            ToUpper(ampm);
        }

            // Start of building the clocktype object. 
            try {
                if (!ampm.empty()) {
                    // 12-hour clock
                    amPmType tod = clockType::strToAmPm.at(ampm);
                    clockType c(hour, minute, second, TWELVE, tod);
                    clocks.push_back(c);
                    is24Hour.push_back(false);
                } else {
                    // 24-hour clock
                    clockType c(hour, minute, second, TWENTYFOUR, PM);
                    clocks.push_back(c);
                    is24Hour.push_back(true);

                }
            } catch (hourException&) {
            } catch (minuteException&) {
            } catch (secondException&) {
            }
            catch (...) {
            }

        } // end of catch block. 

// used to index and measure the container size. 
size_t initial24HourCount = 0;


// creates a loop to display the valid clocks. I used a 2nd vector to flag 24 vs 12 hour clocks entries. 
while (initial24HourCount < is24Hour.size() &&
       is24Hour[initial24HourCount]) {
    ++initial24HourCount;
}

    for (size_t i = 0; i < clocks.size(); ++i) {
        cout << clocks[i];

        bool lastValue = (i == clocks.size() - 1);
        bool nextValueIs24Hour =
            !lastValue && is24Hour[i + 1];

        bool endOfInitial24HourGroup =
            i + 1 == initial24HourCount;

        if (!is24Hour[i] ||
            nextValueIs24Hour ||
            endOfInitial24HourGroup) {
            cout << '\n';
        }
    }
    return 0;
}