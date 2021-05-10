/*----------------------------------------------------------
 *				HTBLA-Leonding
 * ---------------------------------------------------------
 * Exercise Number: S08
 * Title:			Award Data
 * Author:			S. Schraml
 * ----------------------------------------------------------
 * Description:
 * The list of awards.
 * ----------------------------------------------------------
 */
#ifndef ___AWARD_DATA_H
#define ___AWARD_DATA_H

#include "general.h"
#include "awarded_kicker.h"

/**
 * Provides the number of awards granted.
 * 
 * @return The number of awarded kicker records. 
 */
size_t get_award_data_count();

/**
 * Acquires the awarded kicker of the given index.
 * 
 * Note: The provided instance MUST be released using
 * `kicker_release(…)` function after usage!
 * 
 * @param idx The index for the kicker data to receive.
 * @return The data record.
 */
AwardedKicker acquire_awarded_kicker(size_t idx);

#endif
