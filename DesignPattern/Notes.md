Design Patterns - Design Patterns are blueprints or recipes that allow you to solve common software design problems.

1. Behavioural Design Pattern - How your objects are interconnected.
   Command/Action/Transaction Pattern -
   //Gaming Console Module

   Button [ JUMP ] -> upon clicking jump, -> create an instance/object (command_1) of commad class with "JUMP" as action_defining_param -> comand_1.execute("JUMP");

   class Command() {
   execute("action_defining_command"); // in our case JUMP.
   }

   Command Queue -
   Let's say you have multiple commands to execute,
   "JUMP", "RUN", "ATTACK", "JUMP", "ATTACK", "RUN", "RUN", "RUN", "ATTACK".
   Now for all these commands, you can have a command quque -> That will execute commands in FIFO (First In First Out) manner.

NOTE - When you create a virtual function for any parent class, child class for that parent class must have the virtual function defination in them. [execute] [undo]
