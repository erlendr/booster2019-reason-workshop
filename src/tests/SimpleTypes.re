open Framework;

let assertEquals = (a, b, message) =>
  assertEquality("SimpleTypes", a, b, message);

/* Types are the highlight of Reason! This is a gentle introduction, which
   showcases type annotations, and how Reason infers types, even if you don't write
   them out explicitly.
   */

let tests = [
  {
    let score = 10;
    assertEquals(
      score,
      10,
      "Types in Reason are inferred. Reason knows that `score` is an `int`.",
    );
  },
  {
    let anotherScore: int = 20;
    assertEquals(anotherScore, 20, "Types can be explicit.");
  },
  {
    let totalScore = (10: int) + (20: int);
    assertEquals(
      totalScore,
      30,
      "Any expression can be wrapped in parentheses and annotated with types.",
    );
  },
  {
    let add = (a: int, b: int): int => a + b;
    assertEquals(
      add(10, 20),
      30,
      "Functions can be annotated, both arguments and return type.",
    );
  },
];