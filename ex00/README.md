# CPP Module 06 - Exercise 00

## Scalar Converter

Convert a single input into four scalar types:

* `char`
* `int`
* `float`
* `double`

The converter must recognize the input type, perform the appropriate conversions, and handle invalid or impossible conversions.

---

## Class Structure

```text
             +---------------------------+
             |     ScalarConverter       |
             +---------------------------+
             | + convert()               |
             +-------------+-------------+
                           |
                           ▼
                  Detect Input Type
                           |
        +---------+--------+--------+---------+
        |         |        |        |         |
        ▼         ▼        ▼        ▼         ▼
     Special    Char      Int     Float    Double
                           |
                           ▼
                   Convert & Print
                           |
                           ▼
              char / int / float / double
```

---

## Conversion Flow

```text
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

---

## Supported Input Types

### Character

```text
a
Z
*
```

### Integer

```text
0
42
-100
+12
```

### Float

```text
42.0f
-3.14f
```

### Double

```text
42.0
3.14159
```

### Special Literals

```text
nan
nanf
+inf
+inff
-inf
-inff
```

---

## Concepts Learned

* Static member functions
* Type detection
* Scalar conversion
* `static_cast`
* Input validation
* Numeric ranges
* Special floating-point literals
* Exception-safe conversion

---

## Program Flow

```text
main()

    │
    ▼

ScalarConverter::convert(input)

    │
    ▼

checkType(input)

    │
    ▼

switch(type)

    ├── CHAR
    ├── INT
    ├── FLOAT
    ├── DOUBLE
    ├── SPECIAL
    └── INVALID

    │
    ▼

Print

char
int
float
double
```

---

## Test Cases

### Character

```bash
./convert a
```

### Integer

```bash
./convert 42
```

### Float

```bash
./convert 42.0f
```

### Double

```bash
./convert 42.0
```

### Special Literals

```bash
./convert nan
./convert +inf
./convert -inff
```

### Invalid Input

```bash
./convert hello
./convert 42abc
./convert 1.2.3
```
