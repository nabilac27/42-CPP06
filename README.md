# CPP Module 06

## Overview

CPP Module 06 introduces the four **C++ casts** and **Runtime Type Information (RTTI)**.

The focus is  more on understanding how C++ treats object types at runtime.

Each exercise demonstrates a different casting mechanism:

- 🔢 **ex00**: Convert between scalar types (`char`, `int`, `float`, `double`).
- 💾 **ex01**: Convert pointers into integers and back using serialization.
- 🔍 **ex02**: Identify the real object type at runtime using `dynamic_cast`.

---

# Exercise 00

## Class Structure

```bash
               +----------------------------+
               |      ScalarConverter       |
               +----------------------------+
               | <<static utility class>>   |
               +----------------------------+
               | + convert(string)          |
               +----------------------------+
                        |
                        ▼
              Detect literal type
                        |
                        ▼
          Convert to original scalar type
                        |
                        ▼
      Explicitly cast to remaining types
                        |
                        ▼
          Print conversion results
```

## Conversion Flow

```bash
                Input
                  │
                  ▼
           checkType(input)
                  │
      ┌───────────┼───────────┐
      │           │           │
      ▼           ▼           ▼
  Special       Char      Number
      │           │           │
      └───────────┼───────────┘
                  ▼
         Convert and Print
                  │
                  ▼
     char / int / float / double
```

Example:

```bash
    "42.0f"
        │
        ▼
    float value = 42.0f
        │
        ├──► char
        ├──► int
        ├──► double
        ▼
    Print all four values
```

## Responsibility

`ScalarConverter` is a utility class responsible for converting a string literal into every scalar type.

It also handles:

- impossible conversions
- overflow
- non-displayable characters
- pseudo literals (`nan`, `inf`, `nanf`, etc.)

Since the class stores no state, every function is static and objects of the class should never be created.

---

# Exercise 01

## Serialization Diagram

```bash
            Data object
         +---------------+
         | id            |
         | name          |
         +---------------+
                ▲
                │
            Data*
                │
      serialize(ptr)
                │
                ▼
           uintptr_t
                │
      deserialize(raw)
                │
                ▼
            Data*
                │
                ▼
      Same original object
```

## Flow

```bash
        Data object
            │
            ▼
        Data* pointer
            │
            ▼
    serialize(pointer)
            │
            ▼
    uintptr_t integer
            │
            ▼
    deserialize(integer)
            │
            ▼
        Data* pointer
            │
            ▼
    Compare with original pointer
```

## Responsibility

`Serializer` demonstrates that pointers can be converted into an integer representation and later reconstructed without changing the memory address.

No object is copied.

No data is serialized into bytes.

Only the pointer value is converted using `reinterpret_cast`.

The goal is to prove that:

```cpp
    deserialize(serialize(ptr)) == ptr
```

---

# Exercise 02

## RTTI / Class Hierarchy

```bash
                     +---------------+
                     |     Base      |
                     +---------------+
                     | virtual ~Base |
                     +-------^-------+
                             |
          +------------------+------------------+
          |                  |                  |
          ▼                  ▼                  ▼
      +-------+          +-------+          +-------+
      |   A   |          |   B   |          |   C   |
      +-------+          +-------+          +-------+

                generate()
                    │
                    ▼
                returns Base*

                identify()
                    │
                    ▼
                Uses dynamic_cast
                    │
                    ▼
                Prints A, B, or C
```

## generate()

```bash
    Random choice
        │
        ├──► new A
        ├──► new B
        └──► new C
                │
                ▼
        Returned as Base*
```

`generate()` randomly creates an object of type `A`, `B`, or `C`, but returns it as a `Base*`.

This demonstrates **upcasting**, where a derived object is viewed through a base class pointer.

---

## identify(Base*)

```bash
        Base*
            │
            ▼
    dynamic_cast<A*>
            │
            ├── success → print "A"
            │
            ▼
    dynamic_cast<B*>
            │
            ├── success → print "B"
            │
            ▼
    dynamic_cast<C*>
            │
            └── success → print "C"
```

`dynamic_cast` returns `nullptr` when the pointer is not actually pointing to the requested derived type.

The first successful cast reveals the object's real type.

---

## identify(Base&)

```bash
        Base&
            │
            ▼
    dynamic_cast<A&>
            │
            ├── success
            └── throws std::bad_cast
                    │
                    ▼
                catch(...)
            │
            ▼
    Try next type
```

Unlike pointer casting, reference casting cannot return `nullptr`.

Instead, a failed `dynamic_cast` throws a `std::bad_cast` exception, so each attempt is wrapped inside a `try/catch` block until the correct type is found.

---

## Responsibility

This exercise demonstrates **Runtime Type Information (RTTI)**.

Although every object is accessed through a `Base` pointer or reference, 

`dynamic_cast` allows the program to discover the object's real derived type during runtime.

This is only possible because `Base` is polymorphic, 

meaning it contains at least one virtual function (its virtual destructor).

---

# OOP Concepts by Exercise

| Exercise | Concepts Introduced                                                                                     |
|----------|---------------------------------------------------------------------------------------------------------|
| **ex00** | Static Utility Class, Scalar Types, Literal Detection, Explicit Casting (`static_cast`), Numeric Limits |
| **ex01** | `reinterpret_cast`, Pointer Serialization, `uintptr_t`, Memory Addresses                                |
| **ex02** | Runtime Type Information (RTTI), `dynamic_cast`, Upcasting, Downcasting                                 |