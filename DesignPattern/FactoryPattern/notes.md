Okay so while moving forward with the design patterns learnings, I came across Factory Design Patterns.
Quite neet and easy to use design pattern. that helps maintaining the abstraction and provide safety
while creating object by having inheritance based polymorphism.

Creational Designe Pattern - It is a way to abstract or provide a safer option to create object instances.

Factory Pattern -

1. Generalized way for creating object instances.
2. Hiding implementation details for derived class.

Inheritance based polymorphism
Inheritance - Property through which child classes, inherits the methods and variables of parent class.
Polymorphism - Poly = Many, Morphism = Forms.

Virtual Function - When you create any function as virtual function in the parent class, all the functions
inheriting the parent class must have their implementation of that function.

Note - The purpose of a factory method is to avoid the selection what object to create.

shared_ptr - When you create a function return type as share_ptr it manages the lifetime of the dynamically
allocatedobject ans ensures that the object is deleted properly when the lifecycle is complete. making sure
there are no memoryleaks.
make_ptr - is used to create a smart pointer. that are helpful for memory management.
