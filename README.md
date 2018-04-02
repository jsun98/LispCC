# LispCC
A simple and fun Scheme interpreter written in C++ (C++11). 

Scheme is a simple but powerful functional language first developed in the 1990s at MIT. 

I've enjoyed reading Peter Norvig's blog [(How to Write a (Lisp) Interpreter (in Python))](http://norvig.com/lispy.html), in which he writes a Scheme interpreter in 90+ lines of Python. The C++ implementation is a bit more challenging and I thought I'd give it a try. 

UC Berkley's [CS61A: Structure and Interpretation of Computer Programs](https://cs61a.org) has also been very helpful.


## Core Concepts

The interpreter is divided into 2 parts.

```
1. Parsing (Lexical Analysis)
  - Read input program
  - Break program into tokens
  - Analysis of tokens according our Abstract Syntax Tree
2. Evaluation & Execution 
  - Tokens are processed according to the semantics of Scheme
  - Carry out the computation
```

Storing Scheme Expressions
  - Scheme objects - defined in SList.cpp
  - Environment - stored as STL unordered_map

Overview of internal processes
```
Program => Parse => Abstract Syntax Tree => eval => result
```

Simple Demo Program
```
(define square (lambda (x) (* x x))
=> LAMBDA
(define pi 3.1416)
=> 3.141600
(if (> pi (square (pi))) (square (pi)) else (sin (sqrt (square (pi)))))
=> -0.000007
```

## Installation

### Prerequisites

```
GNU g++ -std=c++11
```

### Installing

To clone this repo to your local machine:
```
$ git clone
$ cd SchemePlusPlus
```

Compile and Link:
```
$ make build
```

Run:
```
$ ./scheme
```

Clean:
```
$ make clean
```

## How it works

### Representation of Scheme objects in C++
| __Scheme Data Type__  | __Our Internal Representation__                  |
|-----------------------|--------------------------------------------------|
| Numbers               | C++'s 'int' and 'double'                         |
| Symbols               | C++'s built-in `std::string` data type.          |
| Booleans (`#t`, `#f`) | C++'s built-in `std::string` data type.          |
| Pairs and Lists       | The `SList` class, defined in `SList.cpp`.       |

### List of Supported Scheme Expressions
```
quote, '
if ... else ...
define
set!
lambda
+, -, *, /, >, <, >=, <=
=, eqv?
abs
append
apply
begin
car
cdr
cons
length
list
list?
map
max
min
null?
number?
procedure?
symbol?
mod
sqrt
sin
cos
tan
asin
acos
atan
```

### Files
- FormattedIO.cpp: reading input from stdin
- Parser.cpp: lexical analysis
- SList.cpp: stores any scheme expression
- NativeProcedures.cpp: defines the standard Scheme procedures
- Environment.cpp: execution environement, can be nested
- Main.cpp: REPL

### Example Scheme Programs

## Running Tests

## Contributing

Feel free to contribute and/or create new issues

## Versioning

I use [SemVer](http://semver.org/) for versioning. For the versions available, see the [tags on this repository](https://github.com/jsun98/SchemePlusPlus/tags). 

## Authors

* **Joshua Sun** - [github](https://github.com/jsun98)

See also the list of [contributors](https://github.com/your/project/contributors) who participated in this project.

## License

This project is licensed under the MIT License - see the [LICENSE](LICENSE) file for details

## Acknowledgments

* Peter Norvig, Director of Research, Google Inc.

