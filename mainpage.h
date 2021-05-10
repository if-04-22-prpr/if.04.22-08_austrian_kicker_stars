/**
* @mainpage
* @section intro Introduction
*
* The implementation of an aggregating application using a Binary Search Tree.
* 
* @section objective Assignment Objective
*
* Each year one Austria football player is elected as 'Fußballer des Jahres'.
* People can vote for their favorite players. The player that earns the most votes
* is awarded and also earns honors for the football club he or she is playing for.
* 
* This assignment aggregates the awards by player or football clubs to calculate and list
* players that got the most votes, won the most awards, or clubs that contracted the most players
* that won awards and so on.
*
* The heart of this assignment is Binary Search Tree (BST), which is used for sorting and indexing
* aggregated records. Aggregation means, that all kicker-award records that share the same value of 
* one specific property (the aggregation aspect) - such as the name of a player or the name of a club - are combined in a way
* that accumulates all other properties. Votes are accumulated by adding them, awards are simply counted 
* by the number of appropriate award records (since one record describes the winner of exactly one award)
* and club names of player name - as the opposite of the aspect - are attached to a list of 'associated texts'.
*
* When a player-award record is added to the tree, the corresponding aggregation record needs to be found. 
* If such an aggregation record exists, the records is aggregated with that aggregation record. Otherwise
* a new aggregation record is added to the tree in a ordered manner.
*
* The tree can be traversed in various ways and nodes, respectively their payload (the aggregation record),
* can be visited (e.g. printed). Traversing the tree in the appropriate manner allows to list the aggregations
* in an ordered way by the aggregation aspect. If, .e.g., award-player records are aggregated by the name of the 
* kickers, a list of all players can easily be printed in alphabethical order.
*
* To produce listing of the aggregated records for other properties, such as votes or number of clubs a kicker played for,
* the tree need to be reindexed. Reindexing creates a new tree, which is sorted by the wanted property. The source
* tree is left untouched for this operation.
*
* To support different aggregations, index orders, or visitors, those functionality is provided via function pointer
* to the according functions of the tree. Using function pointers allows to implement the functions generically
* regarding orders and aggregation and avoids re-implementing common tree functionality for different indexing or aggregation schemes.
*
* @section assignment Assignment
*
* This assignment consists of multiple files and ADTs that need to be implemented.
* Although not required, it is recommended to implement the function in the order stated below.
*
* - Implement all missing but required functions of all files mentioned below empty to make the
* application compilable and runnable. Most unit tests will be red.
* - Implement all functions as states in the section below.
*
* @section instructions Working Instructions
*
* -# Implement all missing but required functions of all files mentioned below empty to make the
*    application compilable and runnable. Most unit tests will be red.
*   - **Important:** Special data types, such as `size_t` and `c_str` are included via `general.h`
*   - **Important:** Don't forget to release ALL! acquired instance after usage.
*   - **--COMMIT--**
*
* -# 'awarded_kicker.c': Implement all functions of the ADT defined by this file. 
*   - Hint: Most functions are one liners and can be implemented easily as 'return valid(...) ? value : error_value'.
*   - Obey comments in header files. Run the unit tests frequently and fix failures.
*   - Make all unit tests associated with this ADT green.
*   - **--COMMIT-- **
*
* -# 'award_aggregation.c': Implement all functions of the ADT defined by this file.
*   - Obey comments in header files, esp. regarding how properties shall be aggregated. Note that this ADT is generic regarding aggregation aspect.
*   - Run the unit tests frequently and fix failures.
*   - Make all unit tests associated with this ADT green.
*   - **--COMMIT--**
*
* -# 'aggregations.c': Implement all functions that are used as aggregating functions.
*   - Obey comments in header files, esp. regarding how properties shall be aggregated.
*   - Run the unit tests frequently and fix failures.
*   - Make all unit tests associated with these functions green.
*   - **--COMMIT--**
*
* -# 'comparators.c': Implement all functions that are used as comparison functions.
*   - Obey comments in header files, esp. regarding how properties shall be aggregated.
*   - Run the unit tests frequently and fix failures.
*   - Make all unit tests associated with these functions green.
*   - **--COMMIT--**
*
* -# 'visitors.c': Implement all functions that are used as visitor functions.
*   - Obey comments in header files, esp. regarding how properties shall be aggregated.
*   - Run the unit tests frequently and fix failures.
*   - Make all unit tests associated with these functions green.
*   - **--COMMIT--**
*
* -# 'bst.c': Implement all functions of the binary tree ADT.
*   - Obey comments in header files, esp. regarding how properties shall be aggregated.
*   - The source file declares private functions. These functions need to be implemented as well.
*   - Run the unit tests frequently and fix failures.
*   - Make all unit tests associated with this ADT green.
*   - **--COMMIT--**
*
* -# 'austrian_kicker_stars_main_driver.c': Implement the main application:
*   - Features:
*     -# List all **football players** that won at least one award in **alphabethically ascending** order. 
*       Include the total votes they received, how many awards they won and for which clubs they won the awards.
*     -# List all **football players** that won at least one award in **alphabethically descending** order. 
*       Include the total votes they received, how many awards they won and for which clubs they won the awards.
*     -# List all **football players** that won at least one award **by the number of awards** they won. 
*       Include the total votes they received, how many awards they won and for which clubs they won the awards.
*     -# List all **football clubs** for which player won at least one award in **alphabethically ascending** order. 
*       Include the total votes they received, how many awards they won and which players won awards for that club.
*     -# List all **football clubs** for which player won at least one award **by the number of total votes** their player received. 
*       Include the total votes they received, how many awards they won and which players won awards for that club.
*     -# List all **football clubs** for which player won at least one award **by the number of players** who won awards for that club. 
*       Include the total votes they received, how many awards they won and which players won awards for that club.
*     -# You may add additional listings as you wish.
*   - The list of award-player records is provided by functions found in 'award_data.h'
*   - Use the same visitor function for all listings to print an aggregation record.
*   - Obey singular and plural forms of words.
*   - Separate different list visually, so that lists can easily be distinguished.
*   - For sample output see below.
*   - Obey comments in header files, esp. regarding how properties shall be aggregated.
*   - The source file declares private functions. These functions need to be implemented as well.
*   - Run the unit tests frequently and fix failures.
*   - Make all unit tests associated with this ADT green.
*   - **--COMMIT--**
*
*    The print outs of the application shall be as follows:
*    
*    Austrian Kicker Stars from A-Z\n
*    'Andreas Herzog' won 1 award with 201507 votes in total for 'Werder Bremen'\n
*    'David Alaba' won 3 awards with 1004380 votes in total for 'FC Bayern München'\n
*    'Dietmar Kühbauer' won 6 awards with 3540472 votes in total for 'SK Rapid Wien', 'Real Sociedad', 'SV Mattersburg'\n
*    'Geza Gallos' won 1 award with 26367 votes in total for 'SK Rapid Wien'\n
*    ...\n
*    \n
*    Austrian Kicker Stars from Z-A\n
*    'Zlatko Junuzović' won 1 award with 283900 votes in total for 'FK Austria Wien'\n
*    'Walter Schachner' won 3 awards with 624215 votes in total for 'Donawitzer SV Alpine', 'FK Austria Wien'\n
*    'Thomas Parits' won 1 award with 8925 votes in total for 'FK Austria Wien'\n
*    'Steffen Hofmann' won 5 awards with 1321939 votes in total for 'SK Rapid Wien'\n
*    ...\n
*    \n
*    Austrian Kicker Awards\n
*    'Dietmar Kühbauer' won 6 awards with 3540472 votes in total for 'SK Rapid Wien', 'Real Sociedad', 'SV Mattersburg'\n
*    'Hans Krankl' won 5 awards with 1391495 votes in total for 'SK Rapid Wien', 'SV Austria Salzburg'\n
*    'Steffen Hofmann' won 5 awards with 1321939 votes in total for 'SK Rapid Wien'\n
*    'David Alaba' won 3 awards with 1004380 votes in total for 'FC Bayern München'\n
*    ...\n
*    \n
*    Austrian Kicker Clubs from A-Z\n
*    'Donawitzer SV Alpine' won 2 awards with 198305 votes in total for 'Peter Pumm', 'Walter Schachner'\n
*    'FC Bayern München' won 3 awards with 1004380 votes in total for 'David Alaba'\n
*    'FK Austria Wien' won 8 awards with 3053575 votes in total for 'Thomas Parits', 'Herbert Prohaska', 'Walter Schachner', 'Robert Sara', 'Zlatko Junuzović', 'Philipp Hosiner'\n
*    'Real Sociedad' won 2 awards with 828928 votes in total for 'Dietmar Kühbauer'\n
*    ...\n
*    \n
*    Austrian Kicker Award Votes\n
*    'SK Rapid Wien' won 26 awards with 7576147 votes in total for 'Johnny Bjerregaard', 'Leopold Grausam', 'Geza Gallos', 'Hans Krankl', 'Herbert Feurer', 'Peter Pacult', 'Reinhard Kienast', 'Michael Konsel', 'Jan Åge Fjørtoft', 'Robert Pecl', 'Dietmar Kühbauer', 'Roman Wallner', 'Steffen Hofmann', 'Louis Schaub'\n
*    'FK Austria Wien' won 8 awards with 3053575 votes in total for 'Thomas Parits', 'Herbert Prohaska', 'Walter Schachner', 'Robert Sara', 'Zlatko Junuzović', 'Philipp Hosiner'\n
*    ...\n
*    \n
*    Austrian Club Kickers\n
*    'SK Rapid Wien' won 26 awards with 7576147 votes in total for 'Johnny Bjerregaard', 'Leopold Grausam', 'Geza Gallos', 'Hans Krankl', 'Herbert Feurer', 'Peter Pacult', 'Reinhard Kienast', 'Michael Konsel', 'Jan Åge Fjørtoft', 'Robert Pecl', 'Dietmar Kühbauer', 'Roman Wallner', 'Steffen Hofmann', 'Louis Schaub'\n
*    'FK Austria Wien' won 8 awards with 3053575 votes in total for 'Thomas Parits', 'Herbert Prohaska', 'Walter Schachner', 'Robert Sara', 'Zlatko Junuzović', 'Philipp Hosiner'\n
*    'SK Sturm Graz' won 3 awards with 1157131 votes in total for 'Ivica Vastić', 'Markus Schopp', 'Sebastian Prödl'\n
*    ...\n
*
* -# Run the application. 
* 
*
* @section notes Notes
* -# `general.h` contains macros for finding the minimum, maximum, and absolute value 
* -# make cleantest: This new make target for clearing the console, building, and running unit test is available.
* -# Sometimes changes are not properly detected by incremental builds. If something very strange 
*    happens during compilation, try to run `make clean` followed by `make` to start a clean build.
*    This approach is also recommended after everthing is done, because some compiler warning appears
*    only in clean builds. 
*/