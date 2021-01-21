/*-----------------------------------------------------------------------------
 *				HTBLA-Leonding / Class: <your class name here>
 *-----------------------------------------------------------------------------
 * Exercise Number: 10 - Strings
 * File:			test_extract_date_time.c
 * Author(s):		Peter Bauer
 *-----------------------------------------------------------------------------
 * Description:
 * Test case for the assignment
 *-----------------------------------------------------------------------------
*/
#include <string.h>

#include "extract_date_time.h"
#include "test_extract_date_time.h"

static char mm[3];
static char dd[3];
static char yyyy[5];
static char hh[3];
static char min[3];
static char ss[3];

TEST(find_start_of_date)
{
	char txt[80] = "$11/01/2017$";
	char* dts = extract_date_time(txt, mm, dd, yyyy, hh, min, ss);

	ASSERT_EQUALS_STR("11/01/2017", dts);
}

TEST(find_start_of_date_later)
{
	char txt[80] = "Some text before $11/01/2017$";
	char* dts = extract_date_time(txt, mm, dd, yyyy, hh, min, ss);

	ASSERT_EQUALS_STR("11/01/2017", dts);
}

TEST(extract_date_only)
{
	char txt[80] = "Some text before $11/01/2017$";
	extract_date_time(txt, mm, dd, yyyy, hh, min, ss);

	ASSERT_EQUALS_STR("11", mm);
	ASSERT_EQUALS_STR("01", dd);
	ASSERT_EQUALS_STR("2017", yyyy);
}

/******************************************************************************
 * test_normal_case
 *
 *
 ******************************************************************************/
TEST(normal_case)
{
	char txt[80] = "Today is $11/01/2012 08:00$";
	extract_date_time(txt, mm, dd, yyyy, hh, min, ss);

	ASSERT_EQUALS_STR("11", mm);
	ASSERT_EQUALS_STR("01", dd);
	ASSERT_EQUALS_STR("2012", yyyy);

	ASSERT_EQUALS_STR("08", hh);
	ASSERT_EQUALS_STR("00", min);
	ASSERT_EQUALS_STR("00", ss);
}


/******************************************************************************
 * test_no_date_time
 *
 *
 ******************************************************************************/
TEST(no_date_time)
{
	char txt[80] = "This is a string with no date time token";
	char* dts = extract_date_time(txt, mm, dd, yyyy, hh, min, ss);

	ASSERT_TRUE(dts == 0, "dts expected to be 0");
}

/******************************************************************************
 * test_no_date
 *
 *
 ******************************************************************************/
TEST(no_date)
{
	char txt[80] = "$08:30:25$";
	extract_date_time(txt, mm, dd, yyyy, hh, min, ss);

	ASSERT_EQUALS_STR("08", hh);
	ASSERT_EQUALS_STR("30", min);
	ASSERT_EQUALS_STR("25", ss);
}

/******************************************************************************
 * test_mini_time
 *
 *
 ******************************************************************************/
TEST(date_time_with_hour_only)
{
	char txt1[80] = "$01/11/2012 08$";
	extract_date_time(txt1, mm, dd, yyyy, hh, min, ss);

	ASSERT_EQUALS_STR("01", mm);
	ASSERT_EQUALS_STR("11", dd);
	ASSERT_EQUALS_STR("2012", yyyy);

	ASSERT_EQUALS_STR("08", hh);
	ASSERT_EQUALS_STR("00", min);
	ASSERT_EQUALS_STR("00", ss);
}

TEST(hour_only)
{
	char txt2[80] = "$08$";
	extract_date_time(txt2, mm, dd, yyyy, hh, min, ss);

	ASSERT_TRUE(strcmp(hh, "08") == 0, "hh expected to be '08'");
	ASSERT_TRUE(strcmp(min, "00") == 0, "min expected to be '00'");
	ASSERT_TRUE(strcmp(ss, "00") == 0,  "ss expected to be '00'");
}

/******************************************************************************
 * test_no_closing_dollar
 *
 *
 ******************************************************************************/
TEST(no_closing_dollar)
{
	char txt1[80] = "$01/11/2012 08";
	char* dts = extract_date_time(txt1, mm, dd, yyyy, hh, min, ss);
	ASSERT_TRUE(dts == 0, "dts expected to be 0");
}
