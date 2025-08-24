#ifndef __FUNCTION_POINTERS__
#define __FUNCTION_POINTERS__


//////////////////////////////////////////////////////////////////////////
/// POINTERS TO FUNCTIONS
//////////////////////////////////////////////////////////////////////////

/**
 * Stores a pointer to a function that returns void
 * and takes no parameters
 */
using FuncPtr = void (*) ();


/**
 * Stores a pointer to a function that returns a value of type R
 * and takes no parameters
 */
template <typename R>
using FuncPtrR = R (*) ();


/**
 * Stores a pointer to a function that returns void
 * and takes one parameter
 */
template <typename P1>
using FuncPtrP1 = void (*) (P1 p1);


/**
 * Stores a pointer to a function that returns a value of type R
 * and takes one parameter
 */
template <typename R, typename P1>
using FuncPtrRP1 = R (*) (P1 p1);


/**
 * Stores a pointer to a function that void
 * and takes two parameters.
 */
template <typename P1, typename P2>
using FuncPtrP2 = void (*) (P1 p1, P2 p2);


/**
 * Stores a pointer to a function that returns a value of type R
 * and takes two parameters.
 */
template <typename R, typename P1, typename P2>
using FuncPtrRP2 = R (*) (P1 p1, P2 p2);


/**
 * Stores a pointer to a function that returns void
 * and takes three parameters.
 */
template <typename P1, typename P2, typename P3>
using FuncPtrP3 = void (*) (P1 p1, P2 p2, P3 p3);


/**
 * Stores a pointer to a function that returns a value of type R
 * and takes three parameters.
 */
template <typename R, typename P1, typename P2, typename P3>
using FuncPtrRP3 = R (*) (P1 p1, P2 p2, P3 p3);


/**
 * Stores a pointer to a function that returns void
 * and takes four parameters.
 */
template <typename P1, typename P2, typename P3, typename P4>
using FuncPtrP4 = void (*) (P1 p1, P2 p2, P3 p3, P4 p4);


/**
 * Stores a pointer to a function that returns a value of type R
 * and takes four parameters.
 */
template <typename R, typename P1, typename P2, typename P3, typename P4>
using FuncPtrRP4 = R (*) (P1 p1, P2 p2, P3 p3, P4 p4);


/**
 * Stores a pointer to a function that returns void
 * and takes five parameters.
 */
template <typename P1, typename P2, typename P3, typename P4,
          typename P5>
using FuncPtrP5 = void (*) (P1 p1, P2 p2, P3 p3, P4 p4,
                            P5 p5);


/**
 * Stores a pointer to a function that returns a value of type R
 * and takes five parameters.
 */
template <typename R, typename P1, typename P2, typename P3, typename P4,
                      typename P5>
using FuncPtrRP5 = R (*) (P1 p1, P2 p2, P3 p3, P4 p4,
                          P5 p5);


/**
 * Stores a pointer to a function that returns void
 * and takes six parameters.
 */
template <typename P1, typename P2, typename P3, typename P4,
          typename P5, typename P6>
using FuncPtrP6 = void (*) (P1 p1, P2 p2, P3 p3, P4 p4,
                            P5 p5, P6 p6);


/**
 * Stores a pointer to a function that returns a value of type R
 * and takes six parameters.
 */
template <typename R, typename P1, typename P2, typename P3, typename P4,
                      typename P5, typename P6>
using FuncPtrRP6 = R (*) (P1 p1, P2 p2, P3 p3, P4 p4,
                          P5 p5, P6 p6);


/**
 * Stores a pointer to a function that returns void
 * and takes seven parameters.
 */
template <typename P1, typename P2, typename P3, typename P4,
          typename P5, typename P6, typename P7>
using FuncPtrP7 = void (*) (P1 p1, P2 p2, P3 p3, P4 p4,
                            P5 p5, P6 p6, P7 p7);


/**
 * Stores a pointer to a function that returns a value of type R
 * and takes seven parameters.
 */
template <typename R, typename P1, typename P2, typename P3, typename P4,
                      typename P5, typename P6, typename P7>
using FuncPtrRP7 = R (*) (P1 p1, P2 p2, P3 p3, P4 p4,
                          P5 p5, P6 p6, P7 p7);


/**
 * Stores a pointer to a function that returns void
 * and takes eight parameters.
 */
template <typename P1, typename P2, typename P3, typename P4,
          typename P5, typename P6, typename P7, typename P8>
using FuncPtrP8 = void (*) (P1 p1, P2 p2, P3 p3, P4 p4,
                            P5 p5, P6 p6, P7 p7, P8 p8);


/**
 * Stores a pointer to a function that returns a value of type R
 * and takes eight parameters.
 */
template <typename R, typename P1, typename P2, typename P3, typename P4,
                      typename P5, typename P6, typename P7, typename P8>
using FuncPtrRP8 = R (*) (P1 p1, P2 p2, P3 p3, P4 p4,
                          P5 p5, P6 p6, P7 p7, P8 p8);




//////////////////////////////////////////////////////////////////////////
/// POINTERS TO OBJECTS METHODS
//////////////////////////////////////////////////////////////////////////

/**
 * Stores a pointer to a method belonging to class C.
 * To refer to a class method, use format &ClassName:MethodName.
 * 
 * The method cannot require any parameters.
 */
template <typename C>
using MethodPtr = void (C::*) ();


/**
 * Stores a pointer to a method belonging to class C.
 * To refer to a class method, use format &ClassName:MethodName.
 * 
 * The method requires one parameter.
 */
template <typename C, typename P1>
using MethodPtr1P = void (C::*) (P1 p1);


/**
 * Stores a pointer to a method belonging to class C.
 * To refer to a class method, use format &ClassName:MethodName.
 * 
 * The method requires two parameters.
 */
template <typename C, typename P1,
                      typename P2>
using MethodPtr2P = void (C::*) (P1 p1, P2 p2);


/**
 * Stores a pointer to a method belonging to class C.
 * To refer to a class method, use format &ClassName:MethodName.
 * 
 * The method requires three parameters.
 */
template <typename C, typename P1,
                      typename P2,
                      typename P3>
using MethodPtr3P = void (C::*) (P1 p1, P2 p2, P3 p3);


/**
 * Stores a pointer to a method belonging to class C.
 * To refer to a class method, use format &ClassName:MethodName.
 * 
 * The method requires four parameters.
 */
template <typename C, typename P1,
                      typename P2,
                      typename P3,
                      typename P4>
using MethodPtr4P = void (C::*) (P1 p1, P2 p2, P3 p3, P4 p4);


/**
 * Stores a pointer to a method belonging to class C.
 * To refer to a class method, use format &ClassName:MethodName.
 * 
 * The method requires five parameters.
 */
template <typename C, typename P1,
                      typename P2,
                      typename P3,
                      typename P4,
                      typename P5>
using MethodPtr5P = void (C::*) (P1 p1, P2 p2, P3 p3, P4 p4,
                                 P5 p5);


/**
 * Stores a pointer to a method belonging to class C.
 * To refer to a class method, use format &ClassName:MethodName.
 * 
 * The method requires six parameters.
 */
template <typename C, typename P1,
                      typename P2,
                      typename P3,
                      typename P4,
                      typename P5,
                      typename P6>
using MethodPtr6P = void (C::*) (P1 p1, P2 p2, P3 p3, P4 p4,
                                 P5 p5, P6 p6);


/**
 * Stores a pointer to a method belonging to class C.
 * To refer to a class method, use format &ClassName:MethodName.
 * 
 * The method requires seven parameters.
 */
template <typename C, typename P1,
                      typename P2,
                      typename P3,
                      typename P4,
                      typename P5,
                      typename P6,
                      typename P7>
using MethodPtr7P = void (C::*) (P1 p1, P2 p2, P3 p3, P4 p4,
                                 P5 p5, P6 p6, P7 p7);


/**
 * Stores a pointer to a method belonging to class C.
 * To refer to a class method, use format &ClassName:MethodName.
 * 
 * The method requires eight parameters.
 */
template <typename C, typename P1,
                      typename P2,
                      typename P3,
                      typename P4,
                      typename P5,
                      typename P6,
                      typename P7,
                      typename P8>
using MethodPtr8P = void (C::*) (P1 p1, P2 p2, P3 p3, P4 p4,
                                 P5 p5, P6 p6, P7 p7, P8 p8);


/**
 * Calls a method of an object of type InstanceClass
 * using the pointer methodPtr
 */
template <typename InstanceClass>
void CallMethodPtr (InstanceClass instance,
                    MethodPtr<InstanceClass> methodPtr)
{
    (instance.*methodPtr) ();
}


/**
 * Calls a method of an object of type InstanceClass
 * using the pointer methodPtr and the provided parameters.
 */
template <typename InstanceClass, typename P1>
void CallMethodPtr (InstanceClass instance,
                    MethodPtr1P<InstanceClass, P1> methodPtr,
                    P1 p1)
{
    (instance.*methodPtr) (p1);
}


/**
 * Calls a method of an object of type InstanceClass
 * using the pointer methodPtr and the provided parameters.
 */
template <typename InstanceClass, typename P1, typename P2>
void CallMethodPtr (InstanceClass instance,
                    MethodPtr2P<InstanceClass, P1, P2> methodPtr,
                    P1 p1, P2 p2)
{
    (instance.*methodPtr) (p1, p2);
}


/**
 * Calls a method of an object of type InstanceClass
 * using the pointer methodPtr and the provided parameters.
 */
template <typename InstanceClass, typename P1, typename P2,
                                  typename P3>
void CallMethodPtr (InstanceClass instance,
                    MethodPtr3P<InstanceClass, P1, P2, P3> methodPtr,
                    P1 p1, P2 p2, P3 p3)
{
    (instance.*methodPtr) (p1, p2, p3);
}


/**
 * Calls a method of an object of type InstanceClass
 * using the pointer methodPtr and the provided parameters.
 */
template <typename InstanceClass, typename P1, typename P2,
                                  typename P3, typename P4>
void CallMethodPtr (InstanceClass instance,
                    MethodPtr4P<InstanceClass, P1, P2, P3, P4> methodPtr,
                    P1 p1, P2 p2, P3 p3, P4 p4)
{
    (instance.*methodPtr) (p1, p2, p3, p4);
}


/**
 * Calls a method of an object of type InstanceClass
 * using the pointer methodPtr and the provided parameters.
 */
template <typename InstanceClass, typename P1, typename P2,
                                  typename P3, typename P4,
                                  typename P5>
void CallMethodPtr (InstanceClass instance,
                    MethodPtr5P<InstanceClass, P1, P2, P3, P4,
                                               P5> methodPtr,
                    P1 p1, P2 p2, P3 p3, P4 p4, P5 p5)
{
    (instance.*methodPtr) (p1, p2, p3, p4, p5);
}


/**
 * Calls a method of an object of type InstanceClass
 * using the pointer methodPtr and the provided parameters.
 */
template <typename InstanceClass, typename P1, typename P2,
                                  typename P3, typename P4,
                                  typename P5, typename P6>
void CallMethodPtr (InstanceClass instance,
                    MethodPtr6P<InstanceClass, P1, P2, P3, P4,
                                               P5, P6> methodPtr,
                    P1 p1, P2 p2, P3 p3, P4 p4, 
                    P5 p5, P6 p6)
{
    (instance.*methodPtr) (p1, p2, p3, p4, p5, p6);
}


/**
 * Calls a method of an object of type InstanceClass
 * using the pointer methodPtr and the provided parameters.
 */
template <typename InstanceClass, typename P1, typename P2,
                                  typename P3, typename P4,
                                  typename P5, typename P6,
                                  typename P7>
void CallMethodPtr (InstanceClass instance,
                    MethodPtr7P<InstanceClass, P1, P2, P3, P4,
                                               P5, P6, P7> methodPtr,
                    P1 p1, P2 p2, P3 p3, P4 p4, 
                    P5 p5, P6 p6, P7 p7)
{
    (instance.*methodPtr) (p1, p2, p3, p4, p5, p6, p7);
}


/**
 * Calls a method of an object of type InstanceClass
 * using the pointer methodPtr and the provided parameters.
 */
template <typename InstanceClass, typename P1, typename P2,
                                  typename P3, typename P4,
                                  typename P5, typename P6,
                                  typename P7, typename P8>
void CallMethodPtr (InstanceClass instance,
                    MethodPtr8P<InstanceClass, P1, P2, P3, P4,
                                               P5, P6, P7, P8> methodPtr,
                    P1 p1, P2 p2, P3 p3, P4 p4, 
                    P5 p5, P6 p6, P7 p7, P8 p8)
{
    (instance.*methodPtr) (p1, p2, p3, p4, p5, p6, p7, p8);
}

#endif










