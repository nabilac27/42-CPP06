<p align="center">
  <img src="https://cdn-icons-png.flaticon.com/512/6132/6132222.png" width="60" alt="C++ Logo">
</p>

<h1 align="center">CPP Module 06</h1>


**CPP Module 06** introduces C++ cast operators, with a focus on
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

- It detects the input literal type, converts it to its actual type.
- Then explicitly converts it to the remaining scalar types (`char`, `int`, `float`,
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
          +---------------+
          | value = 42    |
          +---------------+
          Address: 0x1000
                  ▲
                  │
       ptr ───────┘
       Type: Data*
       Value: 0x1000

                  │ reinterpret_cast
                  ▼

       raw
       Type: uintptr_t
       Value: 4096
       Same address as 0x1000

                  │ reinterpret_cast
                  ▼

       restored
       Type: Data*
       Value: 0x1000
                  │
                  ▼
       restored->value = 42
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

## About
- `dynamic_cast` checks the real type of an object while the program is running.
- It does not change the object. It only asks: "What is this object really?"

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

## Member Functions

### Base*   generate(void)

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

---

### void    identify(Base* p)

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
- It prints the actual type of the object pointed to by p: "A", "B", or "C"
- `dynamic_cast` returns `nullptr` when the pointer is not actually pointing to the requested derived type.

- The first successful cast reveals the object's real type.

---

### void identify(Base& p)

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
- It prints the actual type of the object referenced by p: "A", "B", or "C". 
- Unlike pointer casting, reference casting cannot return `nullptr`.

- Instead, a failed `dynamic_cast` throws a `std::bad_cast` exception, so each attempt is wrapped inside a `try/catch` block until the correct type is found.

---

## Responsibility

- Although every object is accessed through a `Base` pointer or reference,  `dynamic_cast` allows the program to discover the object's real derived type during runtime.

- This is only possible because `Base` is polymorphic, 

- Polymorphic meants that it contains at least one virtual function (its virtual destructor).

</details>

---

## Concepts Learned

<details>
<summary><b>Cast Operators</b></summary>

| Cast Operator          | Purpose                                      | Example                                             | Simple Explanation                                                                                                                    |
| ---------------------- | -------------------------------------------- | --------------------------------------------------- | ------------------------------------------------------------------------------------------------------------------------------------- |
| **`static_cast`**      | Converts between **compatible types**.       | `int n = static_cast<int>(3.14);`                   | Used for normal conversions such as `int`, `float`, `char`, `double`, and safe upcasting.                                             |
| **`reinterpret_cast`** | Converts between **unrelated types**.        | `uintptr_t raw = reinterpret_cast<uintptr_t>(ptr);` | Reinterprets the same memory as another type, such as a pointer ↔ integer.                                                            |
| **`dynamic_cast`**     | Checks an object's **real type at runtime**. | `A* a = dynamic_cast<A*>(basePtr);`                 | Safely downcasts in an inheritance hierarchy. Returns `NULL` for pointers or throws `std::bad_cast` for references if the cast fails. |


**Summary**
```bash
    static_cast<int>(x);        // Normal type conversion
    reinterpret_cast<long>(p);  // Low-level bit reinterpretation
    dynamic_cast<Base*>(ptr);   // Runtime checked inheritance cast
    const_cast<char*>(ptr);     // Add/remove const
```
</details>

---

<details>
<summary><b>Scalar Types</b></summary>

---

Scalar types store **a single value**. They are the basic built-in data types in C++.

| Type | Stores | Example | `printf` | Range | Size |
|------|--------|---------|----------|-------|------|
| `char` | One character (ASCII) | `'A'` | `%c` | -128 to 127 *(signed)* / 0 to 255 *(unsigned)* | 1 byte |
| `int` | Whole numbers | `42` | `%d` / `%i` | -2,147,483,648 to 2,147,483,647 | 4 bytes |
| `float` | Decimal numbers | `3.14f` | `%f` | ±3.4 × 10³⁸ (~7 digits) | 4 bytes |
| `double` | More precise decimals | `3.141592` | `%lf` | ±1.7 × 10³⁰⁸ (~15–16 digits) | 8 bytes |
| `bool` | Boolean value | `true`, `false` | `%d` *(0 or 1)* | `false` / `true` | 1 byte |

</details>

---

<details>
<summary><b>Non-Scalar Types</b></summary>

---

Unlike scalar types, non-scalar types can store **multiple values**.

| Type | Stores | Example | Why it's **not** scalar |
|------|--------|---------|-------------------------|
| `std::string` | Sequence of characters | `"Hello"` | Stores multiple `char` values |
| `int array[10]` | Fixed-size collection | `{1, 2, 3, ...}` | Stores several `int` values |

</details>

---

<details>
<summary><b>Common Literals</b></summary>

---

A **literal** is a fixed value written directly in the source code.

| Input | Literal Type |
|-------|--------------|
| `"a"` | `char` |
| `"42"` | `int` |
| `"42.0f"` | `float` |
| `"42.0"` | `double` |
| `"nan"` | Special `double` |
| `"nanf"` | Special `float` |
| `"+inf"` | Special `double` |
| `"-inff"` | Special `float` |

</details>

---

<details>
<summary><b>Pseudo-Literals</b></summary>

---

Pseudo-literals are **special floating-point values** that do not represent ordinary numbers.

- `nan` means **Not A Number**
- `+inf` means **Positive Infinity**
- `-inf` means **Negative Infinity**
- Literals ending with `f` are `float`
- Literals without `f` are `double`

| Literal | Meaning | Type |
|---------|---------|------|
| `nan` | Not A Number | `double` |
| `nanf` | Not A Number | `float` |
| `+inf` | Positive Infinity | `double` |
| `+inff` | Positive Infinity | `float` |
| `-inf` | Negative Infinity | `double` |
| `-inff` | Negative Infinity | `float` |

</details>

---

<details>
<summary><b><code>strtod()</code>, <code>errno</code>, and <code>ERANGE</code></b></summary>

---

### `strtod()`

`strtod()` (**String To Double**) converts a numeric string into a `double`.

```cpp
double value = std::strtod(input.c_str(), NULL);
```

Example:

| Input | Result |
|-------|--------|
| `"42"` | `42.0` |
| `"3.14"` | `3.14` |
| `"-2.5"` | `-2.5` |

---

### `errno`

`errno` is a global variable used by C/C++ library functions to report runtime errors.

Before calling `strtod()`, it is reset to `0`:

```cpp
errno = 0;
```

This **does not check for an error**.

---

### `ERANGE`

After conversion, check whether the value is outside the range of a `double`:

```cpp
errno = 0;

double value = std::strtod(input.c_str(), NULL);

if (errno == ERANGE)
{
    // Range error
}
```

If the value is **too large** or **too small** to fit into a `double`,
`strtod()` sets:

```cpp
errno = ERANGE;
```

`ERANGE` stands for **Range Error**.

---

### Conversion Flow

```text
Input String
     │
     ▼
errno = 0
     │
     ▼
strtod()
     │
     ▼
double value
     │
     ├── errno == 0
     │      ✔ Conversion succeeded
     │
     └── errno == ERANGE
            ✘ Value is outside the range of double
```

</details>

---

<details>
<summary><b>Static vs Non-Static Members</b></summary>

---

| Non-static | Static |
|------------|--------|
| Belongs to an object | Belongs to the class |
| Requires an object | No object required |
| Called with `object.function()` | Called with `Class::function()` |
| Has access to `this` | No `this` pointer |
| Can access non-static members | Cannot access non-static members directly |
| Example: `dog.bark()` | Example: `Serializer::serialize(ptr)` |

</details>

---

<details>
<summary><b>dynamic_cast</b></summary>

Safely converts pointers or references within an inheritance hierarchy by checking the object's **real type** at runtime.

- Pointer cast → returns **`nullptr`** if the cast fails.
- Reference cast → throws **`std::bad_cast`** if the cast fails.
- Requires a **polymorphic base class** (at least one virtual function).

**Pointer vs reference**
| Cast                  | Failure result         |
| --------------------- | ---------------------- |
| `dynamic_cast<A*>(p)` | Returns `NULL`         |
| `dynamic_cast<A&>(p)` | Throws `std::bad_cast` |

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

---
