/*----------------------------------------------------------
 *				HTBLA-Leonding / Klasse: 2AHDV
 * ---------------------------------------------------------
 * Exercise Number: 0
 * Title:			Extract Time
 * Author:			P. Bauer
 * Due Date:		November 03, 2010
 * ----------------------------------------------------------
 * Description:
 * Extract date and time out of a string.
 * ----------------------------------------------------------
 */
#include <stdio.h>
#include <string.h>

#include "shortcut.h"
#include "test_extract_date_time.h"

int main(int argc, char *argv[])
{
	ADD_TEST(find_start_of_date);
	ADD_TEST(find_start_of_date_later);
	ADD_TEST(extract_date_only);
	ADD_TEST(normal_case);
	ADD_TEST(no_date_time);
	ADD_TEST(no_date);
	ADD_TEST(date_time_with_hour_only);
	ADD_TEST(hour_only);
	ADD_TEST(no_closing_dollar);

	run_tests();
	return 0;
}
