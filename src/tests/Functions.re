open Framework;

let assertEqual = (a, b, message) =>
  assertEquality("Functions", a, b, message);

type tree('a) =
  | Node('a, tree('a), tree('a))
  | Leaf('a);

let add = (a, b) => a + b;
let add3 = (a, b, c) => a + b + c;
let sub = (~x, ~y) => x - y;

let tests = [
  {
    let greet = name => "Hello, " ++ name ++ "!";
    assertEqual(
      greet("Booster"),
      "Hello, Booster!",
      "A function is declared with a fat arrow (=>), and returns the value of the expression to the right of the arrow.",
    );
  },
  assertEqual(
    add(7, 6),
    13,
    "Fix the add function such that it returns the sum of its two arguments.",
  ),
  assertEqual(
    add3(4, 5, 6),
    15,
    "Multiple arguments are separated by commas.",
  ),
  {
    let reverseName = (name: (string, string)) => {
      let (first, last) = name;
      last ++ ", " ++ first;
    };
    assertEqual(
      reverseName(("Bernie", "Sanders")),
      "Sanders, Bernie",
      "Longer function bodies require curly braces.",
    );
  },
  assertEqual(sub(~x=10, ~y=7), 3, "Functions can have labelled arguments."),
  assertEqual(
    sub(~y=7, ~x=10),
    3,
    "Labelled arguments can be applied in any order.",
  ),
  {
    let add = (a, b) => a + b;
    let add5 = add(5);
    assertEqual(
      add5(6),
      11,
      "Functions are curried, and can be partially applied.",
    );
  },
  {
    let myTree = Node(1, Node(2, Leaf(3), Leaf(4)), Leaf(5));
    let rec treeSum = tree =>
      switch (tree) {
      | Leaf(value) => value
      | Node(value, left, right) => value + treeSum(left) + treeSum(right)
      };
    assertEqual(
      treeSum(myTree),
      15,
      "A recursive function must be declared with `let rec`.",
    );
  },
];