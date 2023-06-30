Suppose you have two objects. that are somewhat interconnected.
Object A and B. Object A manages state of your program. and Object B
monitors if the state of object A has changed. So it Keeps a check on
Object A for its state changed at a duration of some time maybe a second.
Like Maybe i am subscribed to TOI and each time TOI publises any article
I should be verified.
Now there can be multiple objects that wants to keep track of Object A's
state. so after each second they make a call to Object A and check if
its state has changed.
This is okay, but what if we have 100 objects keeping track of object A
and each second object A gets 100 requests.
So will it be better if Object A tell each of its dependent objects that
yes I have changed. please update/perform operations.
Simply put, Instead of me checking TOI site for new articles every 1 min or
5 mins. It is better that TOI informs me that yes a new article has been posted.

Observables -> The thing/object which is being observed.
Observes -> People/Objects observing it.

Defination -> The observer patterns defines a One-to-many dependency between
objects so that when one objects changes state, all of its dependencies are
notified and updates the state.

UML :
IObservable (Interface) : Methods -> Attach() , Detach(), Notify()
IObserver (Interface) : Methods -> Update()

ConcreteObservable (Inherits) IObserable
ConcreteObserver (Inherits) IObserver

Now each Concrete Class can have their own implementation of Attach/Detach/Notify/Update
For this we need to make out methods virtual.
