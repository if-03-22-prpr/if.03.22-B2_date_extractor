/** @file mainpage.h
* @brief Description of Extract Date and Time.
*
* @mainpage Extract Date and Time
*
* @author Peter Bauer, Stefan Schraml
*
* @section intro Introduction
* Extracting parts of a string which follows a predefined pattern is a good training
* to work with strings. We want to do this by finding parts of a text which represent
* a date and time information. In our case we make it simpler and assume that this
* kind of information is embraced by two $-signs. E.g., the string "Today is
* Wednesday, $01/11/2012 08:00$" would be an input, we want to deal with.
*
* @section rules The Rules of the Game
* The following specific situations may occur:
* - General format: The date/time is given in `$mm/dd/yyyy hh:min:ss$`. Note that this is English
* notation where month comes before day. `mm`, `dd`, `hh`, `min`, and `ss` has always a length of 2. 
* `yyyy` has always a length of 4. The parts of the date are always separated by slashes, the parts of
* the time are always separated by colons. Date and time is always separated by a blank.
*
* - Missing seconds or minutes: `mm` or `ss` may be missing. E.g., `$01/11/2012 08$` is a valid input
* for January 11th, 2012, 8 o'clock.
*
* - Missing time: The complete time part may be missing. E.g., `$01/11/2012$` is a valid input.
*
* - Missing date: The complete date part may be missing. E.g., `$08:00:25$` is a valid input.
*
* @section assignment Assignment
* Implement the function `extract_date_time()` in `extract_date_time.c` such that it passes all unit tests
* of `test_extract_date_time.c`.
*
* __Note__: Try to **avoid** any boolean switches (e.g. `bool is_in_day = true;`).
*
*/
