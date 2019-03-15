open Framework;
let assertEqual = (a, b, message) => assertEquality("Tuples", a, b, message);

let tests = [
  {
    let aTuple: (int, string) = (1, "two");
    assertEqual(
      aTuple,
      (1, "two"),
      "A tuple is an immutable, ordered, fix-sized, and heterogenous collection.",
    );
  },
  {
    let aTuple: (int, string) = (1, "two");

    assertEqual(
      fst(aTuple),
      1,
      "You can access the first element in a tuple with `fst`.",
    );
  },
  {
    let aTuple: (int, string) = (1, "two");

    assertEqual(
      snd(aTuple),
      "two",
      "You can access the second element in a tuple with `snd`.",
    );
  },
  {
    let anotherTuple = (1, "two", 3, "four");
    let (number, _, _, _) = anotherTuple;
    assertEqual(
      number,
      1,
      "Elements in larger tuples are accessed by destructuring.",
    );
  },
];