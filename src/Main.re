let tests = [Tutorial.tests, Basics.tests, LetBindings.tests];

List.iter(f => f(), tests);

print_string({js|Congratulations, you have completed all the tests 🙌|js});