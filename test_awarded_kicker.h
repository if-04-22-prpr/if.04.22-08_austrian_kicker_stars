/*----------------------------------------------------------
 *				HTBLA-Leonding / Klasse: n/a
 * ---------------------------------------------------------
 * Title:			Unit Tests for Awarded Kicker ADT implementation
 * Author:			S. Schraml
 * ----------------------------------------------------------
 * Description:
 * Tests functions of Awarded Kicker ADT.
 * ----------------------------------------------------------
 */
#ifndef ___TEST_AWARDED_KICKER_H
#define ___TEST_AWARDED_KICKER_H

#include "shortcut.h"

TEST(test_kicker_acquire__shall_allocate_a_kicker);
TEST(test_kicker_release__shall_release_an_allocated_kicker);
TEST(test_kicker_release__shall_not_release_an_invalid_kicker);

TEST(test_kicker_is_valid__shall_return_true_for_a_valid_kicker);
TEST(test_kicker_is_valid__shall_return_false_for_an_invalid_kicker);

TEST(test_kicker_get_name__shall_return_the_name);
TEST(test_kicker_get_club__shall_return_the_club);
TEST(test_kicker_get_votes__shall_return_the_votes);
TEST(test_kicker_get_award_year__shall_return_the_award_year);

#endif
