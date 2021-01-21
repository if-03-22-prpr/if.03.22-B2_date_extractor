/*----------------------------------------------------------
 *				HTBLA-Leonding / Klasse: <your class name here>
 * ---------------------------------------------------------
 * Exercise Number: B2 - Strings
 * File:			extract_time.h
 * Author:			*/<your name>/*
 * ----------------------------------------------------------
 * Description:
 * Extracts the date/time part for a text.
 * ----------------------------------------------------------
 */

/**
*** Extracts date and/or time information if available out of a string and stores these
*** data into the given arguments of the function. The date
*** and time is embraced by $-signs and has the following format: $mm/dd/yyyy hh:mm:ss$.
*** mm and ss may be missing or only the time is given, i.e., mm, dd, and yyyy are
*** missing. In these cases, the arguments for the missing information are set to "00"
*** or "0000".
*** @param str String holding the date time information.
*** @param mm A two-character string holding month information.
*** @param dd A two-character string holding day information.
*** @param yyyy A four-character string holding year information.
*** @param hh A two-character string holding hour information.
*** @param min A two-character string holding minute information.
*** @param ss A two-character string holding second information.
*** @return The original string which is truncated to the date/time
*** information without the embracing $-signs or 0 in case of errors.
*/
<type> extract_date_time(<params>);
