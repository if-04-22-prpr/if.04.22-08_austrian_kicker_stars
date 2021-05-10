/*----------------------------------------------------------
 *				HTBLA-Leonding
 * ---------------------------------------------------------
 * Exercise Number: S08
 * Title:			Visitor functions
 * Author(s):		S. Schraml
 * ----------------------------------------------------------
 * Description:
 * Interface for visitor functions
 * ----------------------------------------------------------
 */


#ifndef ___VISITORS_H
#define ___VISITORS_H

#include "general.h"
#include "award_aggregation.h"

/** 
 * Declaration of function pointer for visitor functions. 
 * A visitor function is invoked when a node is visited
 * and processes the payload of the node in a specific manner.
 * 
 * @param record The record of the visited node.
 */
typedef void visitor_fn(<params>);

/**
 * Prints the aggregation record. 
 * 
 * Note: May be used as visitor function.
 * 
 * @param aggregation The record to print.
 */
void print_aggregation(<params>);

#endif