Creational Designe Pattern - It is a way to abstract or provide a safer option to create object instances.
Singleton - It allows you to create only a single instance of a class.

The singleton pattern can be implemented in a number of ways, but the most common approach
is to make the class's constructor private and provide a static method that returns the
class's only instance. This ensures that only one instance of the class can ever be created,
and that all code that needs to access the class can do so through the static method.

Now the question arises how would you ensure that only one instance of a class is created?

Answer - static, When you create any function or variable as static, only one copy of that
function/variable is created throughtout the life cycle of the program.

Using static member variables is like creating a global variable that can be accessed from
anywhere in the class, Which is good as well as bad.
