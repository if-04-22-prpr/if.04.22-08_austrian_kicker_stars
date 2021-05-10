/*----------------------------------------------------------
 *				HTBLA-Leonding
 * ---------------------------------------------------------
 * Exercise Number: S08
 * Title:			Aggregator functions
 * Author:			*/<your name>;/*
 * ----------------------------------------------------------
 * Description:
 * Interface for aggregator functions
 * ----------------------------------------------------------
 */

#ifndef ___AGGREGATORS_H
#define ___AGGREGATORS_H

#include "award_aggregation.h"
#include "awarded_kicker.h"

/** 
 * Declaration of function pointer for aggregator functions. 
 * An aggregator function behaves like a comparator for the 
 * aspect of the aggregation record and the corresponding attribute
 * of the kicker. 
 * In addition, the kicker's attributes are aggregated into the aggregation
 * record if compared attribute values of both are identical. Otherwise
 * such functions behave as comperator functions.
 * 
 * @param aggregation The aggregation record into which the kicker record is aggregated.
 * @param kicker The kicker record to aggregate.
 * @return A value less than 0 if `aspect_text` of the aggregation record is less 
 * than the corresponding property of the kicker or `aggregation` is not valid but `kicker` is, 
 * 0 if both properties are equal and both parameter are valid or invalid (the kicker record is aggregated), 
 * or a value larger than 0 otherwise.
 */
typedef int aggregator_fn(AwardAggregation aggregation, AwardedKicker kicker);

/**
 * Aggregates the given kicker into the given aggregation record based on the 
 * kicker's name. This means, the aspect text of the aggregation record
 * must be equal (not necessarily identical -> use strcmp!) to the name
 * of the kicker to aggregate the kicker.  
 * If the aspect text of the aggregation record is 0, the `club` name 
 * of the kicker is applied as aspect text. This is useful for 
 * generic instantiation of aggregation records during tree traversal.
 * Otherwise the kicker is NOT aggregated.
 * 
 * Aggregation involves adding the kicker's votes, incrementing the number
 * of received awards and appending the kickers's club to the associated
 * text list of the aggregation record.
 * 
 * The function returns 0, if the kicker was aggregated, otherwise it behaves
 * like a comparator function.
 *  
 * @param aggregation The record into which the kicker instance is aggregated.
 * @param kicker The kicker to aggregate.
 * @return A value less than 0 if `aspect_text` of the aggregation record is less 
 * than the name of the kicker or `aggregation` is not valid but `kicker` is, 
 * 0 if both values are equal or at least one parameter is invalid (the kicker record is aggregated), 
 * or a value larger than 0 otherwise.
 */
int aggregate_by_name(AwardAggregation aggregation, AwardedKicker kicker);

/**
 * Aggregates the given kicker into the given aggregation record based on the 
 * kicker's club. This means, the aspect text of the aggregation record
 * must be equal (not necessarily identical -> use strcmp!) to the club
 * of the kicker to aggregate the kicker. 
 * If the aspect text of the aggregation record is 0, the `club` name 
 * of the kicker is applied as aspect text. This is useful for 
 * generic instantiation of aggregation records during tree traversal.
 * Otherwise the kicker is NOT aggregated.
 * 
 * Aggregation involves adding the kicker's votes, incrementing the number
 * of received awards and appending the kickers's name to the associated
 * text list of the aggregation record.
 * 
 * The function returns 0, if the kicker was aggregated, otherwise it behaves
 * like a comparator function.
 *  
 * @param aggregation The record into which the kicker instance is aggregated.
 * @param kicker The kicker to aggregate.
 * @return A value less than 0 if `aspect_text` of the aggregation record is less 
 * than the club of the kicker or `aggregation` is not valid but `kicker` is, 
 * 0 if both values are equal or at least one parameter is invalid (the kicker record is aggregated), 
 * or a value larger than 0 otherwise.
 */
int aggregate_by_club(AwardAggregation aggregation, AwardedKicker kicker);



#endif