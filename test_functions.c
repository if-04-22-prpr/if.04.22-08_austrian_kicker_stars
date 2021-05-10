/*----------------------------------------------------------
 *				HTBLA-Leonding / Klasse: n/a
 * ---------------------------------------------------------
 * Title:			Implementation of UTs for Award Aggregation ADT
 * Author:			S. Schraml
 * ----------------------------------------------------------
 * Description:
 * Tests functions for Award Aggregation ADT.
 * ----------------------------------------------------------
 */

#include "test_award_aggregation.h"
#include "aggregators.h"
#include "comparators.h"
#include "award_aggregation.h"
#include "awarded_kicker.h"
#include "allocator.h"

#include <stdio.h>
#include <string.h>

#define ASSERT_VALID_AWARD_AGGR(text) _assert_valid_award_aggr(tc, text)
static AwardAggregation _assert_valid_award_aggr(struct TestCase* tc, c_str text) {
    AwardAggregation aggr = aggr_acquire(text);
    ASSERT_TRUE(aggr != 0, MSG("Could not acquire the award aggregation record, expected a non-null pointer"));
    ASSERT_TRUE(aggr_is_valid(aggr), MSG("Expected a valid award aggregation instance"));
    return aggr;
}

#define ASSERT_VALID_AWARDED_KICKER(name, club, year, votes) _assert_valid_awarded_kicker(tc, name, club, year, votes)
static AwardedKicker _assert_valid_awarded_kicker(struct TestCase* tc, c_str name, c_str club, int year, int votes) {
    AwardedKicker kicker = kicker_acquire(name, club, year, votes);
    ASSERT_TRUE(kicker != 0, MSG("Could not acquire the kicker records, expected a non-null pointer"));
    ASSERT_TRUE(kicker_is_valid(kicker), MSG("Expected a valid kicker instance"));
    return kicker;
}

/* ------------------------------------------------------------------- */


TEST(test_aggregate_by_name) {
    AwardAggregation a = ASSERT_VALID_AWARD_AGGR(0);
    c_str name = "H";
    c_str club_1 = "C1";
    c_str club_2 = "C2";
    int votes = 2;
    AwardedKicker k = ASSERT_VALID_AWARDED_KICKER(name, club_1, 1234, votes);

    int act_cmp = aggregate_by_name(a, k);
    ASSERT_TRUE(act_cmp == 0, MSG("1: Expected aggregation result of 0 but was %d", act_cmp));
    ASSERT_TRUE(aggr_get_aspect_text(a) == name, MSG("1: Expected the kicker name as aspect text"));
    ASSERT_TRUE(aggr_get_associated_text_count(a) == 1, MSG("1: Expected one associated text"));
    ASSERT_TRUE(aggr_get_associated_text(a, 0) == club_1, MSG("1: Expected club name as associated text"));
    ASSERT_TRUE(aggr_get_award_count(a) == 1, MSG("1: Expected one award"));
    ASSERT_TRUE(aggr_get_total_votes(a) == votes, MSG("1: Expected sum of all votes"));

    act_cmp = aggregate_by_name(a, k);
    ASSERT_TRUE(act_cmp == 0, MSG("2: Expected aggregation result of 0 but was %d", act_cmp));
    ASSERT_TRUE(aggr_get_aspect_text(a) == name, MSG("2: Expected the kicker name as aspect text"));
    ASSERT_TRUE(aggr_get_associated_text_count(a) == 1, MSG("2: Expected one associated text"));
    ASSERT_TRUE(aggr_get_associated_text(a, 0) == club_1, MSG("2: Expected club name as associated text"));
    ASSERT_TRUE(aggr_get_award_count(a) == 2, MSG("2: Expected two awards"));
    ASSERT_TRUE(aggr_get_total_votes(a) == (2 * votes), MSG("2: Expected sum of all votes"));

    kicker_release(&k);

    k = ASSERT_VALID_AWARDED_KICKER(name, club_2, 1234, votes);
    act_cmp = aggregate_by_name(a, k);
    ASSERT_TRUE(act_cmp == 0, MSG("3: Expected aggregation result of 0 but was %d", act_cmp));
    ASSERT_TRUE(aggr_get_aspect_text(a) == name, MSG("3: Expected the kicker name as aspect text"));
    ASSERT_TRUE(aggr_get_associated_text_count(a) == 2, MSG("3: Expected two associated text"));
    ASSERT_TRUE(aggr_get_associated_text(a, 0) == club_1, MSG("3: Expected 1st club name as associated text"));
    ASSERT_TRUE(aggr_get_associated_text(a, 1) == club_2, MSG("3: Expected 2nd club name as associated text"));
    ASSERT_TRUE(aggr_get_award_count(a) == 3, MSG("3: Expected two awards"));
    ASSERT_TRUE(aggr_get_total_votes(a) == (3 * votes), MSG("3: Expected sum of all votes"));
    kicker_release(&k);

    k = ASSERT_VALID_AWARDED_KICKER("B", club_1, 1234, votes);
    act_cmp = aggregate_by_name(a, k);
    ASSERT_TRUE(act_cmp < 0, MSG("4: Expected aggregation result of less than 0 but was %d", act_cmp));
    ASSERT_TRUE(aggr_get_aspect_text(a) == name, MSG("4: Expected the kicker name as aspect text"));
    ASSERT_TRUE(aggr_get_associated_text_count(a) == 2, MSG("4: Expected two associated text"));
    ASSERT_TRUE(aggr_get_associated_text(a, 0) == club_1, MSG("4: Expected 1st club name as associated text"));
    ASSERT_TRUE(aggr_get_associated_text(a, 1) == club_2, MSG("4: Expected 2nd club name as associated text"));
    ASSERT_TRUE(aggr_get_award_count(a) == 3, MSG("4: Expected two awards"));
    ASSERT_TRUE(aggr_get_total_votes(a) == (3 * votes), MSG("4: Expected sum of all votes"));
    kicker_release(&k);

    k = ASSERT_VALID_AWARDED_KICKER("X", club_1, 1234, votes);
    act_cmp = aggregate_by_name(a, k);
    ASSERT_TRUE(act_cmp > 0, MSG("5: Expected aggregation result of greater than 0 but was %d", act_cmp));
    ASSERT_TRUE(aggr_get_aspect_text(a) == name, MSG("5: Expected the kicker name as aspect text"));
    ASSERT_TRUE(aggr_get_associated_text_count(a) == 2, MSG("5: Expected two associated text"));
    ASSERT_TRUE(aggr_get_associated_text(a, 0) == club_1, MSG("5: Expected 1st club name as associated text"));
    ASSERT_TRUE(aggr_get_associated_text(a, 1) == club_2, MSG("5: Expected 2nd club name as associated text"));
    ASSERT_TRUE(aggr_get_award_count(a) == 3, MSG("5: Expected two awards"));
    ASSERT_TRUE(aggr_get_total_votes(a) == (3 * votes), MSG("5: Expected sum of all votes"));
    kicker_release(&k);

    aggr_release(&a);
}

TEST(test_aggregate_by_club) {
    AwardAggregation a = ASSERT_VALID_AWARD_AGGR(0);
    c_str club = "H_CLUB";
    c_str name_1 = "N1";
    c_str name_2 = "N2";
    int votes = 2;
    AwardedKicker k = ASSERT_VALID_AWARDED_KICKER(name_1, club, 1234, votes);

    int act_cmp = aggregate_by_club(a, k);
    ASSERT_TRUE(act_cmp == 0, MSG("1: Expected aggregation result of 0 but was %d", act_cmp));
    ASSERT_TRUE(aggr_get_aspect_text(a) == club, MSG("1: Expected the kicker club as aspect text"));
    ASSERT_TRUE(aggr_get_associated_text_count(a) == 1, MSG("1: Expected one associated text"));
    ASSERT_TRUE(aggr_get_associated_text(a, 0) == name_1, MSG("1: Expected kicker name as associated text"));
    ASSERT_TRUE(aggr_get_award_count(a) == 1, MSG("1: Expected one award"));
    ASSERT_TRUE(aggr_get_total_votes(a) == votes, MSG("1: Expected sum of all votes"));

    act_cmp = aggregate_by_club(a, k);
    ASSERT_TRUE(act_cmp == 0, MSG("2: Expected aggregation result of 0 but was %d", act_cmp));
    ASSERT_TRUE(aggr_get_aspect_text(a) == club, MSG("2: Expected the kicker club as aspect text"));
    ASSERT_TRUE(aggr_get_associated_text_count(a) == 1, MSG("2: Expected one associated text"));
    ASSERT_TRUE(aggr_get_associated_text(a, 0) == name_1, MSG("2: Expected kicker name as associated text"));
    ASSERT_TRUE(aggr_get_award_count(a) == 2, MSG("2: Expected two awards"));
    ASSERT_TRUE(aggr_get_total_votes(a) == (2 * votes), MSG("2: Expected sum of all votes"));

    kicker_release(&k);

    k = ASSERT_VALID_AWARDED_KICKER(name_2, club, 1234, votes);
    act_cmp = aggregate_by_club(a, k);
    ASSERT_TRUE(act_cmp == 0, MSG("3: Expected aggregation result of 0 but was %d", act_cmp));
    ASSERT_TRUE(aggr_get_aspect_text(a) == club, MSG("3: Expected the kicker club as aspect text"));
    ASSERT_TRUE(aggr_get_associated_text_count(a) == 2, MSG("3: Expected two associated text"));
    ASSERT_TRUE(aggr_get_associated_text(a, 0) == name_1, MSG("3: Expected 1st kicker name as associated text"));
    ASSERT_TRUE(aggr_get_associated_text(a, 1) == name_2, MSG("3: Expected 2nd kicker name as associated text"));
    ASSERT_TRUE(aggr_get_award_count(a) == 3, MSG("3: Expected two awards"));
    ASSERT_TRUE(aggr_get_total_votes(a) == (3 * votes), MSG("3: Expected sum of all votes"));
    kicker_release(&k);

    k = ASSERT_VALID_AWARDED_KICKER("B", "B-CLUB", 1234, votes);
    act_cmp = aggregate_by_club(a, k);
    ASSERT_TRUE(act_cmp < 0, MSG("4: Expected aggregation result of less than 0 but was %d", act_cmp));
    ASSERT_TRUE(aggr_get_aspect_text(a) == club, MSG("4: Expected the kicker club as aspect text"));
    ASSERT_TRUE(aggr_get_associated_text_count(a) == 2, MSG("4: Expected two associated text"));
    ASSERT_TRUE(aggr_get_associated_text(a, 0) == name_1, MSG("4: Expected 1st kicker name as associated text"));
    ASSERT_TRUE(aggr_get_associated_text(a, 1) == name_2, MSG("4: Expected 2nd kicker name as associated text"));
    ASSERT_TRUE(aggr_get_award_count(a) == 3, MSG("4: Expected two awards"));
    ASSERT_TRUE(aggr_get_total_votes(a) == (3 * votes), MSG("4: Expected sum of all votes"));
    kicker_release(&k);

    k = ASSERT_VALID_AWARDED_KICKER("X", "X_CLUB", 1234, votes);
    act_cmp = aggregate_by_club(a, k);
    ASSERT_TRUE(act_cmp > 0, MSG("5: Expected aggregation result of greater than 0 but was %d", act_cmp));
    ASSERT_TRUE(aggr_get_aspect_text(a) == club, MSG("5: Expected the kicker club as aspect text"));
    ASSERT_TRUE(aggr_get_associated_text_count(a) == 2, MSG("5: Expected two associated text"));
    ASSERT_TRUE(aggr_get_associated_text(a, 0) == name_1, MSG("5: Expected 1st kicker name as associated text"));
    ASSERT_TRUE(aggr_get_associated_text(a, 1) == name_2, MSG("5: Expected 2nd kicker name as associated text"));
    ASSERT_TRUE(aggr_get_award_count(a) == 3, MSG("5: Expected two awards"));
    ASSERT_TRUE(aggr_get_total_votes(a) == (3 * votes), MSG("5: Expected sum of all votes"));
    kicker_release(&k);

    aggr_release(&a);
}

TEST(test_compare_by_votes) {
    AwardAggregation a = ASSERT_VALID_AWARD_AGGR("A");
    aggr_add_votes(a, 42);
    AwardAggregation b = ASSERT_VALID_AWARD_AGGR("B");
    aggr_add_votes(b, 84);

    ASSERT_TRUE(compare_by_votes(a, b) < 0, MSG("Expected a comparison value less than 0 if first aggregation has less votes"));
    ASSERT_TRUE(compare_by_votes(a, a) == 0, MSG("Expected a comparison value of 0 if first aggregation has equal votes"));
    ASSERT_TRUE(compare_by_votes(b, a) > 0, MSG("Expected a comparison value greater than 0 if first aggregation has more votes"));

    aggr_release(&a);
    aggr_release(&b);
}

TEST(test_compare_by_awards) {
    AwardAggregation a = ASSERT_VALID_AWARD_AGGR("A");
    aggr_increment_award_count(a);
    AwardAggregation b = ASSERT_VALID_AWARD_AGGR("B");
    aggr_increment_award_count(b);
    aggr_increment_award_count(b);

    ASSERT_TRUE(compare_by_awards(a, b) < 0, MSG("Expected a comparison value less than 0 if first aggregation has less awards"));
    ASSERT_TRUE(compare_by_awards(a, a) == 0, MSG("Expected a comparison value of 0 if first aggregation has equal awards"));
    ASSERT_TRUE(compare_by_awards(b, a) > 0, MSG("Expected a comparison value greater than 0 if first aggregation has more awards"));

    aggr_release(&a);
    aggr_release(&b);
}

TEST(test_compare_by_assoc_text_count) {
    AwardAggregation a = ASSERT_VALID_AWARD_AGGR("A");
    aggr_add_associated_text(a, "A1");
    AwardAggregation b = ASSERT_VALID_AWARD_AGGR("B");
    aggr_add_associated_text(b, "B1");
    aggr_add_associated_text(b, "B2");

    ASSERT_TRUE(compare_by_assoc_text_count(a, b) < 0, MSG("Expected a comparison value less than 0 if first aggregation has less associated texts"));
    ASSERT_TRUE(compare_by_assoc_text_count(a, a) == 0, MSG("Expected a comparison value of 0 if first aggregation has equal number of associated texts"));
    ASSERT_TRUE(compare_by_assoc_text_count(b, a) > 0, MSG("Expected a comparison value greater than 0 if first aggregation has more associated texts"));

    aggr_release(&a);
    aggr_release(&b);

}
