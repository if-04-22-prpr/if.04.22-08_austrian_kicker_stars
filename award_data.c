/*-----------------------------------------------------------------------------
 *				HTBLA-Leonding
 *-----------------------------------------------------------------------------
 * Exercise Number: S08
 * Title:			Award Data
 * Author:			S. Schraml
 *-----------------------------------------------------------------------------
 * Description:
 * Provides the data records to process.
 *-----------------------------------------------------------------------------
*/

#include "award_data.h"
#include "awarded_kicker.h"

struct AwardData {
    c_str name;
    c_str club;
    int year;
    int votes;
};

struct AwardData award_data[] = {
    {"Johnny Bjerregaard", "SK Rapid Wien",        1968,    4461},
    {"Leopold Grausam",    "SK Rapid Wien",        1967,    6616},
    {"Thomas Parits",      "FK Austria Wien",      1969,    8925},
    {"Johnny Bjerregaard", "SK Rapid Wien",        1970,    8426},
    {"Peter Pumm",         "Donawitzer SV Alpine", 1971,   45669},
    {"Geza Gallos",        "SK Rapid Wien",        1972,   26367},
    {"Hans Krankl",        "SK Rapid Wien",        1973,   24882},
    {"Hans Krankl",        "SK Rapid Wien",        1974,   17306},
    {"Herbert Prohaska",   "FK Austria Wien",      1975,   17780},
    {"Walter Schachner",   "Donawitzer SV Alpine", 1976,  152636},
    {"Hans Krankl",        "SK Rapid Wien",        1977,  154706},
    {"Walter Schachner",   "FK Austria Wien",      1978,  181032},
    {"Walter Schachner",   "FK Austria Wien",      1979,  290547},
    {"Herbert Feurer",     "SK Rapid Wien",        1980,  419762},
    {"Herbert Feurer",     "SK Rapid Wien",        1981,  613741},
    {"Hans Krankl",        "SK Rapid Wien",        1982,  806986},
    {"Robert Sara",        "FK Austria Wien",      1983, 1129165},
    {"Peter Pacult",       "SK Rapid Wien",        1984, 1007349},
    {"Herbert Prohaska",   "FK Austria Wien",      1985,  886491},
    {"Reinhard Kienast",   "SK Rapid Wien",        1986,  446371},
    {"Michael Konsel",     "SK Rapid Wien",        1987,  320780},
    {"Hans Krankl",        "SV Austria Salzburg",  1988,  387615},
    {"Jan Åge Fjørtoft",   "SK Rapid Wien",        1989,  428754},
    {"Robert Pecl",        "SK Rapid Wien",        1990,  455107},
    {"Robert Pecl",        "SK Rapid Wien",        1991,  330915},
    {"Andreas Herzog",     "Werder Bremen",        1992,  201507},
    {"Otto Konrad",        "SV Austria Salzburg",  1993,  186948},
    {"Otto Konrad",        "SV Austria Salzburg",  1994,  236261},
    {"Michael Konsel",     "SK Rapid Wien",        1995,  212373},
    {"Dietmar Kühbauer",   "SK Rapid Wien",        1996,  304808},
    {"Dietmar Kühbauer",   "Real Sociedad",        1997,  368904},
    {"Dietmar Kühbauer",   "Real Sociedad",        1998,  460024},
    {"Ivica Vastić",       "SK Sturm Graz",        1999,  478640},
    {"Markus Schopp",      "SK Sturm Graz",        2000,  430769},
    {"Roman Wallner",      "SK Rapid Wien",        2001,  362913},
    {"Dietmar Kühbauer",   "SV Mattersburg",       2002,  536520},
    {"Dietmar Kühbauer",   "SV Mattersburg",       2003,  882533},
    {"Dietmar Kühbauer",   "SV Mattersburg",       2004,  987683},
    {"Steffen Hofmann",    "SK Rapid Wien",        2005,  221278},
    {"Steffen Hofmann",    "SK Rapid Wien",        2006,  274922},
    {"Sebastian Prödl",    "SK Sturm Graz",        2007,  247722},
    {"Steffen Hofmann",    "SK Rapid Wien",        2008,  260296},
    {"Steffen Hofmann",    "SK Rapid Wien",        2009,  283969},
    {"Zlatko Junuzović",   "FK Austria Wien",      2010,  283900},
    {"Steffen Hofmann",    "SK Rapid Wien",        2011,  281474},
    {"Philipp Hosiner",    "FK Austria Wien",      2012,  255735},
    {"David Alaba",        "FC Bayern München",    2013,  264272},
    {"David Alaba",        "FC Bayern München",    2014,  308631},
    {"David Alaba",        "FC Bayern München",    2015,  431477},
    {"Louis Schaub",       "SK Rapid Wien",        2016,  175689},
    {"Louis Schaub",       "SK Rapid Wien",        2017,  125896},
    {"Marko Arnautovic",   "West Ham United",      2018,  133456}
};

void init_award_data() {
}

size_t get_award_data_count() {
    return sizeof(award_data) / sizeof(award_data[0]);
}

AwardedKicker acquire_awarded_kicker(size_t idx) {
    AwardedKicker record = 0;
    if (idx < get_award_data_count()) {
        record = kicker_acquire(award_data[idx].name, award_data[idx].club, award_data[idx].year, award_data[idx].votes);
    }
    return record;
}
