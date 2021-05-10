/*----------------------------------------------------------
 *				HTBLA-Leonding
 * ---------------------------------------------------------
 * Exercise Number: S08
 * Title:			Aggregates kicker awards
 * Author:			*/<your name>;/*
 * ----------------------------------------------------------
 * Description:
 * ADT that aggregates awards of kickers.
 * ----------------------------------------------------------
 */
#ifndef ___AWARD_AGGREGATION_H
#define ___AWARD_AGGREGATION_H

#include "general.h"
#include "awarded_kicker.h"

/** The type of award aggregations named AwardAggregation. */

/**
 * Acquires a new aggregation record of football players or clubs that 
 * received awards.
 * Any instance acquired via this function MUST be released using
 * function `aggr_release()`.
 * 
 * @param aspect_text The text of the aggregation aspect. This may be e.g.
 * the name of the player OR the name of the club, depending which aspect is aggregated.
 * @return The acquired instance.
 */
<type> aggr_acquire(c_str aspect_text);

/**
 * Acquires a new aggregation record of football players or clubs that 
 * received awards and copies all attribute values from the source record.
 * Any instance acquired via this function MUST be released using
 * function `aggr_release()`.
 * 
 * @param source The aggregation record to copy
 * @return The copy.
 */
<type> aggr_acquire_copy(<params>);

/**
 * Releases an `AwardAggregation` instance that was obtained earlier via function `aggr_acquire`
 * or function `aggr_acquire_copy`.
 * Released instances MUST NOT be used anymore.
 * 
 * Note: The implementation of this function does not make any assumptions
 * about the allocation method of instances, but MUST match the implementation
 * of function `aggr_acquire` as its inverse function.
 * 
 * @param p_aggregation The pointer to the `AwardAggregation` instance to release. 
 * The value of the pointer is set to 0, if the instance was successfully released, 
 * otherwise it is left untouched.
 */
void aggr_release(AwardAggregation* p_aggregation);

/**
 * Determines whether or not the given instance is valid.
 * 
 * @param aggregation The record to evaluate.
 * @return `True` if the instance is valid, false otherwise.
 */
<type> aggr_is_valid(<params>);

/**
 * Provides the text of the aggregation aspect.
 * Depending on the aggregation aspect (the kind of value 
 * multiple records are grouped by), this may e.g. the 
 * name of a kicker (if aggregated by kicker's names) or 
 * the name of the club (if aggregated by kicker's club).
 * 
 * @param aggregation The record to evaluate.
 * @return The aspect text.
 */
c_str aggr_get_aspect_text(<params>);

/**
 * Applies the text of the aggregation aspect IF AND ONLY IF the 
 * current aspect text is 0.
 * 
 * @param aggregation The record to evaluate.
 * @param aspect_text The aspect text to apply.
 */
void aggr_set_aspect_text(<params>, c_str aspect_text);

/**
 * Associates the given text with this record by appending it
 * to the list of text IF that list does not contain the text already.
 * If the equal (not necessarily identical -> strcmp!) text is 
 * already present or the given text is 0, this call is ignored.
 * 
 * The appended values are the opposite to the aspect text. E.g.
 * if the aspect text is used for a player's name, the associated
 * texts are the clubs where the player played and vice versa.
 * 
 * Note: A maximum amount of 16 associated texts is sufficient.
 * 
 * @param aggregation The record to evaluate.
 * @param text The text to add.
 */
void aggr_add_associated_text(<params>, c_str text);

/**
 * Provides the array of up to 16 associated texts.
 * 
 * @param aggregation The record to evaluate.
 * @param index The index of the associated text to receive.
 * @return c_str The associated text at the given index or 0.
 */
c_str aggr_get_associated_text(<params>, size_t index);

/**
 * Provides the number of how many texts are associated.
 * This is the length of the array provided by `aggr_get_associated_texts(…)`.
 * 
 * @param aggregation The record to evaluate.
 * @return size_t The number of associated texts.
 */
size_t aggr_get_associated_text_count(A<params>);

/**
 * Adds the given votes to the votes already stored by this instance.
 * Votes are therefore summed up.
 * 
 * @param aggregation The record to evaluate.
 * @param votes The number of votes to add.
 */
void aggr_add_votes(<params>);

/**
 * Provides the number of total votes of this aggregation (kicker or club). 
 *  
 * @param aggregation The record to evaluate.
 * @return int The total number of received votes.
 */
int aggr_get_total_votes(<params>;

/**
 * Increments the number of awards a kicker or club (aggregation aspect) received
 * by one.
 * @param aggregation The record to evaluate.
 */
void aggr_increment_award_count(<params>);

/**
 * Provides the number of awards the kicker or club (aggregation aspect) received in total.
 * 
 * @param aggregation The record to evaluate.
 * @return int The total number of received awards.
 */
int aggr_get_award_count(<params>);


#endif
