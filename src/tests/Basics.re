open Framework;

let assertEqual = (a, b, message) => assertEquality("Basics", a, b, message);
/* let assertEqual: ('a, 'a, string) => unit = assertEquality("Basics"); */

let tests = [
  assertEqual(
    "Hello Reason!",
    "Hello Reason!",
    "A string is a sequence of characters between double quotes.",
  ),
  assertEqual(
    "Hello Reason!",
    "Hello " ++ "Reason!",
    "++ concatenates two strings.",
  ),
  assertEqual(99, 99, "An integer is a sequence of digits."),
  assertEqual(23.0, 23.0, "A floating point number has decimal marker."),
  assertEqual(
    100,
    99 + 2 - 1,
    "+ and - does integer addition and subtraction.",
  ),
  assertEqual(
    100,
    200 * 1 / 2,
    "* and / does integer multiplication and division.",
  ),
  assertEqual(
    24.0,
    23.9 +. 0.3 -. 0.2,
    "+. and -. does floating point addition.",
  ),
  assertEqual(
    100.0,
    50.0 *. 4.0 /. 2.0,
    "*. and /. does floating point multiplication and division.",
  ),
  assertEqual(9.0, 3.0 ** 2.0, "** does floating point exponentiation."),
  assertEqual(
    'c',
    'c',
    "A character is a single character between single quotes.",
  ),
  assertEqual(
    1 < 2 && 3 > 2,
    3 >= 5 || 4 <= 4,
    "Boolean operators are the same as in JavaScript, and many other languages.",
  ),
];