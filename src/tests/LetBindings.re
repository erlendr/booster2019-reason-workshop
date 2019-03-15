open Framework;

let assertEquals = (a, b, message) =>
  assertEquality("LetBindings", a, b, message);

let tests = [
  {
    let company = "Kantega";
    assertEquals(
      company,
      "Kantega",
      "A let binding binds a value to a name.",
    );
  },
  {
    let city: string = "Bergen";
    assertEquals(
      city,
      "Bergen",
      "A let binding can have an optional type annotation.",
    );
  },
  {
    let message = "hello!";
    /* message = "bye!" <-- Mutation is not allowed. */
    let message = "bye!";
    assertEquals(
      message,
      "bye!",
      "Bindings are immutable, but can be shadowed by a later binding with the same name.",
    );
  },
  {
    let city = "Bergen";
    {
      let city = "Trondheim";
      ();
    };
    assertEquals(
      city,
      "Bergen",
      "Bindings can be scoped through {}. Bindings are not visible outside their scope.",
    );
  },
  {
    let greeting = {
      let salutation = "Hey ";
      let company = "Kantega";
      salutation ++ company ++ "!";
    };
    assertEquals(
      greeting,
      "Hey Kantega!",
      "{} are expressions, and can be used to create anonymous scopes.",
    );
  },
];