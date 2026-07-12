<p align="center">
  <img src="https://cdn-icons-png.flaticon.com/512/6132/6132222.png" width="60" alt="C++ Logo">
</p>

<h1 align="center">CPP Module 06</h1>

<h3 align="center">
    C++ Casts • Scalar Conversion • Serialization • RTTI
</h3>


**CPP Module 06** introduces the four C++ cast operators, with a focus on
**`static_cast`**, **`reinterpret_cast`**, and **`dynamic_cast`**. 


Each exercise demonstrates a different casting mechanism:

<!---
    --------- EX00 ---------
-->

<details>
    <summary>
        <b>
            ex00: Convert between scalar types (`char`, `int`, `float`, `double`).
        </b>
    </summary>

---

## About

- This exercise introduces **`static_cast`**, a C++ cast used to safely convert
between compatible scalar types.

- It detects the input literal type, converts it to its actual type, then
explicitly converts it to the remaining scalar types (`char`, `int`, `float`,
and `double`).

- It also handles **pseudo-literals** (`nan`, `nanf`, `+inf`, `-inf`, `+inff`,
`-inff`) and reports impossible or non-displayable conversions when necessary.


## Conversion Flow

```c++

                        Input string
                            │
                            ▼
                    checkType(input)
                            │
        ┌──────────────────┼────────────────────┐
        │                  │                    │
        ▼                  ▼                    ▼
    PSEUDO_LITERAL          CHAR        INT / FLOAT / DOUBLE
        │                  │                    │
        ▼                  ▼                    ▼
    printPseudoLiteral()  printChar()        strtod(input)
                                                │
                                                ▼
                                        Check errno == ERANGE
                                            │           │
                                        Yes ▼           ▼ No
                                print all impossible  printNumber(value)
                                                            │
                                                            ▼
                                            static_cast to char / int / float
                                                            │
                                                            ▼
                                        print char / int / float / double
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

</details>

<!---
    --------- EX01 --------- 
-->

<details>
    <summary>
        <b>
            ex01: Convert pointers into integers and back using serialization.
        </b>
    </summary>

---

## About
- This exercise introduces **`reinterpret_cast`**, a C++ cast used to convert
between unrelated pointer and integer types.

- It converts a pointer into an integer (`uintptr_t`) and converts it back into the original pointer.


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

## Memory diagram
```bash
                 Data object
              +--------------+
              | value = 42   |
              +--------------+
              Address: 0x1000
                     ▲
                     │
      ptr -----------┘
      Type: Data*

                     │ reinterpret_cast
                     ▼

      raw
      Type: uintptr_t
      Value: 0x1000

                     │ reinterpret_cast
                     ▼

      restored
      Type: Data*
      Value: 0x1000
```

## Responsibility

### `serialize(Data* ptr)`

- Receives a pointer.
- Converts it into a `uintptr_t`.
- Returns the integer.

```cpp
    uintptr_t Serializer::serialize(Data* ptr)
    {
        return reinterpret_cast<uintptr_t>(ptr);
    }
```

---

### `deserialize(uintptr_t raw)`

- Receives an integer.
- Converts it back into a pointer.
- Returns the original pointer.

```cpp
    Data* Serializer::deserialize(uintptr_t raw)
    {
        return reinterpret_cast<Data*>(raw);
    }
```


---

### The goal is to prove that:

```cpp
    deserialize(serialize(ptr)) == ptr
```

</details>

<!---
    --------- EX02 ---------
-->

<details>
    <summary>
        <b>
        ex02: Identify the real object type at runtime using `dynamic_cast`.
        </b>
    </summary>

---
## Class Hierarchy

```cpp
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
```

```cpp
             generate()
                 │
                 ▼
            returns Base*
```

```cpp
            identify()
                │
                ▼
            Uses dynamic_cast
                │
                ▼
            Prints A, B, or C
```

## generate()

```cpp
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


```cpp
        Base
       / | \
      A  B  C

Upcasting:
    A*  ─────────► Base*

Downcasting:
    Base* ───────► A*
            (dynamic_cast)
```


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

- `dynamic_cast` returns `nullptr` when the pointer is not actually pointing to the requested derived type.

- The first successful cast reveals the object's real type.

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

- Unlike pointer casting, reference casting cannot return `nullptr`.

- Instead, a failed `dynamic_cast` throws a `std::bad_cast` exception, so each attempt is wrapped inside a `try/catch` block until the correct type is found.

---

## Responsibility

- This exercise demonstrates **Runtime Type Information (RTTI)**.

- Although every object is accessed through a `Base` pointer or reference, 

- `dynamic_cast` allows the program to discover the object's real derived type during runtime.

- This is only possible because `Base` is polymorphic, 

- Polymorphic meants that it contains at least one virtual function (its virtual destructor).

</details>

---

<!---
    --------- OOP Concepts ---------
-->

## OOP Concepts by Exercise

| Exercise | Concepts Introduced                                                        |
|----------|----------------------------------------------------------------------------|
| **ex00** | Static Utility Class, Scalar Types, Explicit Casting (`static_cast`)       |
| **ex01** | `reinterpret_cast`, Pointer Serialization, `uintptr_t`, Memory Addresses   |
| **ex02** | Runtime Type Information (RTTI), `dynamic_cast`, Upcasting, Downcasting    |

----

## Concepts Learned

<details>
<summary><b>Cast Operators</b></summary>

| Cast Operator | Purpose | Example | Notes |
|--------------|---------|---------|-------|
| **`static_cast`** | Performs safe conversions between related or compatible types. | `int n = static_cast<int>(3.14);` | Used for scalar conversions (`int`, `float`, `char`, `double`) and upcasting in inheritance. |
| **`reinterpret_cast`** | Reinterprets the same bits as a different type. | `uintptr_t raw = reinterpret_cast<uintptr_t>(ptr);` | Used for low-level memory operations such as converting between pointers and integer types. No runtime safety checks are performed. |
| **`dynamic_cast`** | Checks an object's actual type at runtime. | `A* a = dynamic_cast<A*>(basePtr);` | Only works with **polymorphic classes** (classes with at least one virtual function). Returns `nullptr` for failed pointer casts and throws `std::bad_cast` for failed reference casts. |
| **`const_cast`** | Adds or removes `const` or `volatile` qualifiers. | `int* p = const_cast<int*>(constPtr);` | Only changes `const`/`volatile` qualifiers. It does **not** change the object's type. |

</details>

---

<details>
<summary><b>Runtime Type Information (RTTI)</b></summary>

Runtime Type Information (**RTTI**) allows C++ to determine an object's **actual type** during program execution. It is mainly used with **`dynamic_cast`** in polymorphic class hierarchies.

</details>

---

<details>
<summary><b>dynamic_cast</b></summary>

Safely converts pointers or references within an inheritance hierarchy by checking the object's **real type** at runtime.

- Pointer cast → returns **`nullptr`** if the cast fails.
- Reference cast → throws **`std::bad_cast`** if the cast fails.
- Requires a **polymorphic base class** (at least one virtual function).

</details>

---

<details>
<summary><b>Upcasting</b></summary>

Converting a **derived class** pointer or reference to a **base class** pointer or reference.

```cpp
A* derived = new A();
Base* base = derived;
```

- Usually **implicit**.
- Always safe.

</details>

---

<details>
<summary><b>Downcasting</b></summary>

Converting a **base class** pointer or reference back to a **derived class**.

```cpp
Base* base = new A();
A* derived = dynamic_cast<A*>(base);
```

- Requires **`dynamic_cast`** for runtime safety.
- Pointer casts return `nullptr` on failure.
- Reference casts throw `std::bad_cast` on failure.

</details>

