/*----------------------------------------------------------
 *				HTBLA-Leonding
 * ---------------------------------------------------------
 * Exercise Number: S08
 * Title:			Awarded Kicker
 * Author:			*/<your name>;/*
 * ----------------------------------------------------------
 * Description:
 * ADT representing an entry for a football player who won an award.
 * ----------------------------------------------------------
 */
#ifndef ___AWARDED_KICKER_H
#define ___AWARDED_KICKER_H

#include "general.h"
#include <stdbool.h>

/** The type of an awarded kicker record named AwardedKicker. */

/**
 * Acquires a new record that represents a football player who received an award.
 * Any instance acquired via this function MUST be released using
 * function `kicker_release()`.
 * 
 * @param name The player's name
 * @param club The club for which the player played when the award was received
 * @param award_year The year when the award was won
 * @param votes The number of votes the player received
 * @return The acquired instance.
 */
<type> kicker_acquire(c_str name, c_str club, int award_year, int votes);

/**
 * Releases an `AwardedKicker` that was obtained earlier via function `kicker_acquire`.
 * Released instances MUST NOT be used anymore.
 * 
 * Note: The implementation of this function does not make any assumptions
 * about the allocation method of instances, but MUST match the implementation
 * of function `kicker_acquire` as its inverse function.
 * 
 * @param p_kicker The pointer to the `AwardedKicker` instance to release. The value of the pointer
 * is set to 0, if the instance was successfully released, otherwise it is left untouched.
 */
void kicker_release(AwardedKicker* p_kicker);

/**
 * Determines whether or not the given instance is valid.
 * An instance is valid, if it is neither 0, nor the name or the club is 0.
 * 
 * @param kicker The kicker to evaluate.
 * @return `True` if the instance is valid, false otherwise.
 */
<type> kicker_is_valid(<params>);

/**
 * Provides the name of the awarded kicker.
 * 
 * @param kicker The kicker to evaluate.
 * @return c_str The kicker's name.
 */
c_str kicker_get_name(<params>);

/**
 * Provides the name of the club the football player played for when the award was received.
 * 
 * @param kicker The kicker to evaluate.
 * @return c_str The kicker's club.
 */
c_str kicker_get_club(<params>);

/**
 * Provides the number of votes the football player received.
 * 
 * @param kicker The kicker to evaluate.
 * @return int The number of votes.
 */
<type> kicker_get_votes(<params>);

/**
 * Provides the year when the kicker received the award.
 * 
 * @param kicker The kicker to evaluate.
 * @return int The award year.
 */
<type> kicker_get_award_year(<params>);

#endif
