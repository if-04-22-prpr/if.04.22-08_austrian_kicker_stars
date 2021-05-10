/*----------------------------------------------------------
 *				HTBLA-Leonding
 * ---------------------------------------------------------
 * Exercise Number: S08
 * Title:			Comparator functions
 * Author:			*/<your name>;/*
 * ----------------------------------------------------------
 * Description:
 * Interface for comparator functions
 * ----------------------------------------------------------
 */

#ifndef ___COMPARATORS_H
#define ___COMPARATORS_H

#include "award_aggregation.h"

/** 
 * Declaration of function pointer for comparator functions. 
 * A comparator function determines whether the first record
 * is less than, equal to, or greater than the second record 
 * based on dedicated record attributes.
 * 
 * @param fst The first record to compare.
 * @param snd The second record to compare.
 * @return A value less than 0 if the value of the compared attributes
 * of `fst` is less than the same attribute of `snd`, 
 * 0 if both attribtue values are equal, and a value larger than 0 otherwise. 
 */
typedef int comparator_fn(AwardAggregation fst, AwardAggregation snd);

/**
 * Compares two aggregation records by their total votes values.
 * 
 * Note: May be used as comparator function.
 * 
 * @param fst The first record to compare.
 * @param snd The second record to compare.
 * @return A value less than 0 if `total votes` of `fst` is less 
 * than the same attribute of `snd` or `fst` is not valid but `snd` is, 
 * 0 if both attribtue values are equal and both items are valid or invalid, 
 * or a value larger than 0 otherwise. 
 */
int compare_by_votes(AwardAggregation fst, AwardAggregation snd);

/**
 * Compares two aggregation records by their number of awards.
 * 
 * Note: May be used as comparator function.
 * 
 * @param fst The first record to compare.
 * @param snd The second record to compare.
 * @return A value less than 0 if `award count` of `fst` is less 
 * than the same attribute of `snd` or `fst` is not valid but `snd` is, 
 * 0 if both attribtue values are equal and both parameter are valid or invalid, 
 * or a value larger than 0 otherwise. 
 */
int compare_by_awards(AwardAggregation fst, AwardAggregation snd);

/**
 * Compares two aggregation records by their number of associated texts.
 * 
 * Note: May be used as comparator function.
 * 
 * @param fst The first record to compare.
 * @param snd The second record to compare.
 * @return A value less than 0 if the number of associated texts of `fst` is less 
 * than the same attribute of `snd` or `fst` is not valid but `snd` is, 
 * 0 if both attribtue values are equal and both parameter are valid or invalid, 
 * or a value larger than 0 otherwise. 
 */
int compare_by_assoc_text_count(AwardAggregation fst, AwardAggregation snd);


#endif