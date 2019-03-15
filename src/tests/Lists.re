open Framework;

let assertEqual = (a, b, message) => assertEquality("Lists", a, b, message);

let list: list(int) = [1, 2, 3];
let array: array(int) = [|1, 2, 3|];

let addOne = x => x + 1;
let even = x => x mod 2 == 0;
let sum = (a, b) => a + b;
let tests = [
  assertEqual(
    list,
    [1, 2, 3],
    "Lists are immutable, homogenous collections.",
  ),
  assertEqual(
    [0, ...list],
    [0, 1, 2, 3],
    "Lists are very fast at prepending items.",
  ),
  {
    let hd =
      switch (list) {
      | [] => 0
      | [hd, ..._] => hd
      };
    assertEqual(
      hd,
      1,
      "You can access the head of a list by pattern matching.",
    );
  },
  assertEqual(
    List.hd(list),
    1,
    "You can also access the head with the hd function from the List module.",
  ),
  assertEqual(
    List.nth(list, 2),
    3,
    "You can access the nth item in the list with List.nth, in O(n) time.",
  ),
  assertEqual(
    List.map(addOne, list),
    [2, 3, 4],
    "Map a function over a list with List.map.",
  ),
  assertEqual(
    List.filter(even, list),
    [2],
    "Filter a list with List.filter.",
  ),
  assertEqual(
    List.fold_left(sum, 0, list),
    6,
    "Fold over a list with List.fold_left.",
  ),
  assertEqual(
    List.fold_right(sum, list, 0),
    6,
    "Right fold over a list with fold_right.",
  ),
  assertEqual(
    array,
    [|1, 2, 3|],
    "Arrays are mutable collections, which are fast at random access and updates.",
  ),
  {
    let firstItem = array[0];
    assertEqual(
      firstItem,
      1,
      "You can access an item in an array with square brackets notation.",
    );
  },
  {
    array[1] = 4;
    assertEqual(
      array,
      [|1, 4, 3|],
      "Arrays are mutable, and the notation is the same as in JavaScript.",
    );
  },
];